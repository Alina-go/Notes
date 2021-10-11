#include <iostream>
#include <QDomDocument>

#include "Notes.h"
#include "TddSorting.h"

#include "test_runner.h"

Notes::Notes(): QWidget()
{
    QVBoxLayout *vbox1 = new QVBoxLayout();
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QHBoxLayout *hbox1 = new QHBoxLayout();
    QHBoxLayout *hbox2 = new QHBoxLayout();
    QList<QString> list;
    m_name = new QLineEdit;
    m_line = new QTextEdit;
    m_table = new CustomTableWidget(0, 2, this);
    m_save = new QPushButton("Save");
    m_deleteNote = new QPushButton("Delete");
    m_saveNote = new QPushButton("Save Note");
    m_add = new QPushButton("Add");
    m_sortAscButton = new QPushButton("Sort Dec");
    m_sortDecButton = new QPushButton("Sort Asc");

    hbox1->addWidget(m_sortAscButton);
    hbox1->addWidget(m_sortDecButton);
    hbox1->addWidget(m_save);
    hbox1->addWidget(m_deleteNote);
    hbox1->addWidget(m_add);

    vbox1->addWidget(m_table);
    vbox1->addLayout(hbox1);

    vbox2->addWidget(m_name);
    vbox2->addWidget(m_line);
    vbox2->addWidget(m_saveNote);

    hbox2->addLayout(vbox1);
    hbox2->addLayout(vbox2);

    list.append("Name");
    list.append("Date");
    m_table->setHorizontalHeaderLabels(QStringList(list));
    m_table->horizontalHeader()->setStretchLastSection(true);
    m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    m_saveNote->setDisabled(true);
    m_line->setDisabled(true);
    m_name->setDisabled(true);
    m_table->setMouseTracking(true);

    connect(m_table, SIGNAL(DeactivateTE()), this, SLOT(deactivateTE()));
    m_notes = loadFromXML();
    fillTable(m_notes);

//    TddSorting* tdd = new TddSorting(this);

    connect(m_table,SIGNAL(cellClicked(int,int)), this,SLOT(activateTextEdit(int)));
    connect(m_save,SIGNAL(clicked(bool)),this,SLOT(saveToXML()));
    connect(m_deleteNote,SIGNAL(clicked(bool)),this,SLOT(dellNote()));
    connect(m_add,SIGNAL(clicked(bool)),this,SLOT(addField()));
    connect(m_sortAscButton,SIGNAL(clicked(bool)),this,SLOT(SortAcs()));
    connect(m_sortDecButton,SIGNAL(clicked(bool)),this,SLOT(SortDec()));
    connect(m_saveNote,SIGNAL(clicked(bool)), this,SLOT(updateNote()));

    this->setLayout(hbox2);

    setStyleSheet("QPushButton{"
                  "background: #7B68EE;"
                  "}"
                  "QPushButton:disabled{"
                  "background: #DCDCDC; "
                  "}"
                  "QHeaderView{"
                  "background: #7B68EE;"
                  "border: none;"
                  "font-style: italic;"
                  "}"
                  "QTableWidget QTableCornerButton::section {"
                  "background: #7B68EE;"
                  "}"
                  "QTextEdit{"
                  "background: #FAFAD2;"
                  "font-style: italic;"
                  "}"
                  "QLineEdit{"
                  "background: #FAFAD2;"
                  "font-style: italic ;"
                  "}"
                  );
}

void Notes::deactivateTE() {
    m_saveNote->setDisabled(true);
    m_name->setDisabled(true);
    m_line->setDisabled(true);
}

void Notes::SortAcs()
{
    sortAcsNotes(m_notes, NoteSortCriterion::Name);
    m_table->setRowCount(0);
    fillTable(m_notes);
}

void Notes::SortDec()
{
    sortDecNotes(m_notes, NoteSortCriterion::Name);
    m_table->setRowCount(0);
    fillTable(m_notes);
}

void Notes::sortAcsNotes(QList<Note>& notes, NoteSortCriterion criterion) {
    switch(criterion)
    {
    case NoteSortCriterion::Name:
        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getName() < b.getName(); });
        break;
    case NoteSortCriterion::Date:
        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getDate()< b.getDate(); });
        break;
    }
}

void Notes::sortDecNotes(QList<Note> &notes, NoteSortCriterion criterion)
{
    switch(criterion)
    {
    case NoteSortCriterion::Name:
        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getName() > b.getName(); });
        break;
    case NoteSortCriterion::Date:
        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getDate() > b.getDate(); });
        break;
    }
}


void Notes::fillTable(QList<Note> notes) {
    for (int i = 0; i < notes.count(); i++) {
        qDebug() << notes[i].getName() << ":" << notes[i].getDate() << ":" << notes[i].getText();
        m_table->insertRow(0);
        m_table->setItem(0, 0, new QTableWidgetItem(notes[i].getName()));
        m_table->setItem(0, 1, new QTableWidgetItem(notes[i].getDate()));
        m_table->item(0,0)->setFlags(Qt::ItemIsEnabled);
        m_table->item(0,1)->setFlags(Qt::ItemIsEnabled);
    }
}

void Notes::updateNote() {
    int row = m_table->currentIndex().row();
    for (int i = 0; i < m_notes.count(); i++) {
        if (m_notes[i].getName() == m_name->text()
                && m_notes[i].getDate() == m_table->item(row,1)->text()
                && m_notes[i].getUuid() != m_curUuid) {
            QMessageBox::information(this, "Notes", "Please rename the note.");
            return;
        }
    }
    for (int i = 0; i < m_notes.count(); i++) {
        if (m_notes[i].getUuid() == m_curUuid) {
            m_notes[i].setName(m_name->text());
            m_notes[i].setText(m_line->toPlainText());
            m_table->item(row, 0)->setText(m_name->text());

        }
    }
    deactivateTE();
}

void Notes::saveToXML(){    //сохраняет xml файл
    QFile file("fileName.xml");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "", tr("Error save to file.\n%1").arg(file.errorString()));
        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("ROWDATA");

    for (int i = 0; i < m_notes.count(); i++) {
        stream.writeStartElement("ROW");
        stream.writeTextElement("name",m_notes[i].getName());
        stream.writeTextElement("date", m_notes[i].getDate());
        stream.writeTextElement("text", m_notes[i].getText());
        stream.writeEndElement();
    }
    stream.writeEndElement();
    stream.writeEndDocument();
    file.close();
}

QList<Note> Notes::loadFromXML() {     //автоматически подгружает сохраненные заметки
    QList<Note> notes;
    QFile* file = new QFile("fileName.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this,
                              "QXSRExample::parseXML",
                              "Couldn't open example.xml",
                              QMessageBox::Ok);
        return notes;
    }
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        if(token == QXmlStreamReader::StartElement) {
            if(xml.name() == "ROWDATA") {
                continue;
            }
            if(xml.name() == "ROW") {
                notes.append(addField(xml));
            }
        }
    }
    if(xml.hasError()) {
        QMessageBox::critical(this,
                              "QXSRExample::parseXML",
                              xml.errorString(),
                              QMessageBox::Ok);
    }
   xml.clear();
   return notes;
}

void Notes::closeEvent(QCloseEvent *event)
{
    saveToXML();
    event->accept();
}

void Notes::setTE(int id) {
    for (int i = 0; i < m_notes.count(); i++) {
        if (m_notes[i].getName() == m_table->item(id,0)->text() && m_notes[i].getDate() == m_table->item(id,1)->text())
            m_line->setText(m_notes[i].getText());
    }
}

CustomTableWidget *Notes::getTable() const
{
    return m_table;
}

QList<Note> Notes::getNotes()
{
    return m_notes;
}

Note Notes::addField(QXmlStreamReader& xml){
    QString name;
    QString date;
    QString text;

    xml.readNext();
    while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
            xml.name() == "ROW")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
             if(xml.name() == "name") {
                xml.readNext();
                name = xml.text().toString();
            }
             if(xml.name() == "date") {
                xml.readNext();
                date = xml.text().toString();

            }
             if(xml.name() == "text") {
                 xml.readNext();
                 text = xml.text().toString();
             }
        }
        xml.readNext();
    }
    return Note(name, date, text, QUuid::createUuid());
}

void Notes::dellNote(){//удаляет поле
    deactivateTE();

    int x = m_table->currentRow();
    qDebug() << x;
    if (x < 0)
        return;
    for (int i = 0; i < m_notes.count(); i++) {
        if (m_notes[i].getName() == m_table->item(x,0)->text() && m_notes[i].getDate() == m_table->item(x,1)->text())
            m_notes.removeAt(i);
    }
    m_table->removeRow(x);
}

void Notes::activateTextEdit(int id) {
    m_saveNote->setDisabled(false);
    m_name->setDisabled(0);
    m_name->setText(m_table->item(id,0)->text());
    m_line->setDisabled(0);
    for (int i = 0; i < m_notes.count(); i++) {
        if (m_notes[i].getName() == m_table->item(id,0)->text() && m_notes[i].getDate() == m_table->item(id,1)->text()) {
            m_curUuid = m_notes[i].getUuid();
            m_line->setText(m_notes[i].getText());
            break;
        }
    }
}

void Notes::addField(){//добавляет поле
    QString name;
    QString date;
    QString text;
    bool repeat = true;
    int iter = 0;
    m_table->insertRow(0);
    date = QDate::currentDate().toString(Qt::ISODate);
    int count = m_table->rowCount();
    while (repeat) {
        repeat = false;
        name = QString("Заметка " + QString::number(count + iter));
        for (int i = 0; i < m_notes.count(); i++) {
            if (m_notes[i].getName() == name && m_notes[i].getDate() == date) {
                iter++;
                repeat = true;
                break;
            }
        }
    }
    QTableWidgetItem *item = new QTableWidgetItem(name);
    m_table->setItem(0, 0, item);
    m_table->item(0,0)->setFlags(Qt::ItemIsEnabled);
    m_table->setItem(0, 1, new QTableWidgetItem(date, QTableWidgetItem::Type));
    m_table->item(0,1)->setFlags(Qt::ItemIsEnabled);
    text = name;
//    m_table->setSortingEnabled(true);
    QItemSelectionModel::SelectionFlags flags = QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows;
    QModelIndex index = m_table->model()->index(item->row(), 0);
    m_table->selectionModel()->select(index, flags);
    m_table->scrollToItem(item);
    m_notes.append(Note(name, date, text, QUuid::createUuid()));
    saveToXML();
}

void Notes::TestAscSortingName() {
    QList<QUuid> uuids;
    for (int i = 0; i < 7; ++i)
        uuids.push_back(QUuid::createUuid());

    QList<Note> before_sort;
    before_sort.push_back(Note("Ezhednevnik", "2020-20-12", "lorem ipsum", uuids[0]));
    before_sort.push_back(Note("Otdykh", "2020-20-12", "lorem ipsum", uuids[1]));
    before_sort.push_back(Note("Otpusk", "2020-20-12", "lorem ipsum", uuids[2]));
    before_sort.push_back(Note("Olphovit", "2020-20-12", "lorem ipsum", uuids[3]));
    before_sort.push_back(Note("Alfavit", "2020-20-12", "lorem ipsum", uuids[4]));
    before_sort.push_back(Note("Zheraf", "2020-20-12", "lorem ipsum", uuids[5]));
    before_sort.push_back(Note("Zhara", "2020-20-12", "lorem ipsum", uuids[6]));

    QList<Note> after_sort;
    after_sort.push_back(Note("Alfavit", "2020-20-12", "lorem ipsum", uuids[4]));
    after_sort.push_back(Note("Ezhednevnik", "2020-20-12", "lorem ipsum", uuids[0]));
    after_sort.push_back(Note("Olphovit", "2020-20-12", "lorem ipsum", uuids[3]));
    after_sort.push_back(Note("Otdykh", "2020-20-12", "lorem ipsum", uuids[1]));
    after_sort.push_back(Note("Otpusk", "2020-20-12", "lorem ipsum", uuids[2]));
    after_sort.push_back(Note("Zhara", "2020-20-12", "lorem ipsum", uuids[6]));
    after_sort.push_back(Note("Zheraf", "2020-20-12", "lorem ipsum", uuids[5]));

    sortAcsNotes(before_sort, NoteSortCriterion::Name);
    AssertEqual(before_sort, after_sort, "Sort ASC by name");
}

void Notes::TestAscSortingDate()
{
    QList<QUuid> uuids;
    for (int i = 0; i < 7; ++i)
        uuids.push_back(QUuid::createUuid());

    QList<Note> date_before_sort;
    date_before_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
    date_before_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
    date_before_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
    date_before_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
    date_before_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));
    date_before_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));
    date_before_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));

    QList<Note> date_after_sort;
    date_after_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));
    date_after_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));
    date_after_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
    date_after_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
    date_after_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
    date_after_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
    date_after_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));

    sortAcsNotes(date_before_sort, NoteSortCriterion::Date);
    AssertEqual(date_before_sort, date_after_sort, "Sort ASC by date");
}

void Notes::TestDecSortingName()
{
    QList<QUuid> uuids;
    for (int i = 0; i < 7; ++i)
        uuids.push_back(QUuid::createUuid());

    QList<Note> name_before_sort;
    name_before_sort.push_back(Note("f", "2020-20-12", "lorem ipsum", uuids[0]));
    name_before_sort.push_back(Note("x", "2020-20-12", "lorem ipsum", uuids[1]));
    name_before_sort.push_back(Note("h", "2020-20-12", "lorem ipsum", uuids[2]));
    name_before_sort.push_back(Note("a", "2020-20-12", "lorem ipsum", uuids[3]));
    name_before_sort.push_back(Note("z", "2020-20-12", "lorem ipsum", uuids[4]));
    name_before_sort.push_back(Note("j", "2020-20-12", "lorem ipsum", uuids[5]));
    name_before_sort.push_back(Note("e", "2020-20-12", "lorem ipsum", uuids[6]));

    QList<Note> name_after_sort;
    name_after_sort.push_back(Note("z", "2020-20-12", "lorem ipsum", uuids[4]));
    name_after_sort.push_back(Note("x", "2020-20-12", "lorem ipsum", uuids[1]));
    name_after_sort.push_back(Note("j", "2020-20-12", "lorem ipsum", uuids[5]));
    name_after_sort.push_back(Note("h", "2020-20-12", "lorem ipsum", uuids[2]));
    name_after_sort.push_back(Note("f", "2020-20-12", "lorem ipsum", uuids[0]));
    name_after_sort.push_back(Note("e", "2020-20-12", "lorem ipsum", uuids[6]));
    name_after_sort.push_back(Note("a", "2020-20-12", "lorem ipsum", uuids[3]));

    sortDecNotes(name_before_sort, NoteSortCriterion::Name);
    AssertEqual(name_before_sort, name_after_sort, "Sort DEC by name");

}

void Notes::TestDecSortingDate() {
    QList<QUuid> uuids;
    for (int i = 0; i < 7; ++i)
        uuids.push_back(QUuid::createUuid());

    QList<Note> date_before_sort;
    date_before_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
    date_before_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));
    date_before_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
    date_before_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
    date_before_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
    date_before_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));
    date_before_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));


    QList<Note> date_after_sort;
    date_after_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));
    date_after_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
    date_after_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
    date_after_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
    date_after_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
    date_after_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));
    date_after_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));

    sortDecNotes(date_before_sort, NoteSortCriterion::Date);
    AssertEqual(date_before_sort, date_after_sort, "Sort DEC by date");
}

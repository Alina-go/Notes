#pragma once

#include <../Notes/CustomTableWidget.h>
#include <QtWidgets>
#include "AboutNote.h"

enum NoteSortCriterion {
    Name,
    Date
};

class Notes : public QWidget {
    Q_OBJECT
public:
    Notes();
    void fillTable(QList<Note> m_notes);
    QList<Note> loadFromXML();
    void closeEvent(QCloseEvent *event);

//    template<class T>
//    void sortAcsNotes(const T& notes, NoteSortCriterion criterion);
//    template<class Tt>
//    void sortDecNotes(const Tt& notes, NoteSortCriterion criterion);

    static void sortAcsNotes(QList<Note>& getNotes, NoteSortCriterion criterion);
    static void sortDecNotes(QList<Note>& getNotes, NoteSortCriterion criterion);

    QList<Note> getNotes();
    CustomTableWidget *getTable() const;

    static void TestAscSortingName();
    static void TestAscSortingDate();
    static void TestDecSortingName();
    static void TestDecSortingDate();

public slots:
    void SortAcs();
    void SortDec();
    void updateNote();
    void deactivateTE();
    void activateTextEdit(int row);
    void dellNote();
    void addField();
    Note addField(QXmlStreamReader& xml);
    void saveToXML();
    void setTE(int id);
private:
    QUuid m_curUuid;
    QTableWidgetItem* m_field;
    CustomTableWidget* m_table;
    QTextEdit* m_line;
    QLineEdit* m_name;
    QPushButton* m_save;
    QPushButton* m_deleteNote;
    QPushButton* m_add;
    QPushButton* m_saveNote;
    QList<Note> m_notes;
    QPushButton *m_sortAscButton;
    QPushButton *m_sortDecButton;
};



#include <QtTest>
#include <QMetaType>
#include "../Notes/AboutNote.h"
//#include "../Notes/Notes.h"
//#include "../Notes/TddSorting.h"

typedef QList<Note> NotesList;
Q_DECLARE_METATYPE(NotesList)


class TestTDDSorting : public QObject
{
    Q_OBJECT

public:
    TestTDDSorting();
    ~TestTDDSorting();

private slots:
    void initNotesListTest();
    void initNotesListTest_data();
};

TestTDDSorting::TestTDDSorting()
{
}

TestTDDSorting::~TestTDDSorting()
{
}

void TestTDDSorting::initNotesListTest()
{
    QFETCH(NotesList, list);
    QFETCH(NotesList, result);

//    QCOMPARE(SortAcsName(notesList), result);
}

void TestTDDSorting::initNotesListTest_data()
{
    QTest::addColumn<NotesList>("list");
    QTest::addColumn<NotesList>("result");

    QTest::newRow("Empty list") << NotesList { { } } << NotesList { { } };
}

QTEST_APPLESS_MAIN(TestTDDSorting)

#include "tst_testtddsorting.moc"

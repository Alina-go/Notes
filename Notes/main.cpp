#include <QtWidgets>
#include "Notes.h"
//#include "test_runner.h"

//void TestAscSorting() {
//    QList<QUuid> uuids;
//    for (int i = 0; i < 7; ++i)
//        uuids.push_back(QUuid::createUuid());

//    QList<Note> before_sort;
//    before_sort.push_back(Note("Ezhednevnik", "2020-20-12", "lorem ipsum", uuids[0]));
//    before_sort.push_back(Note("Otdykh", "2020-20-12", "lorem ipsum", uuids[1]));
//    before_sort.push_back(Note("Otpusk", "2020-20-12", "lorem ipsum", uuids[2]));
//    before_sort.push_back(Note("Olphovit", "2020-20-12", "lorem ipsum", uuids[3]));
//    before_sort.push_back(Note("Alfavit", "2020-20-12", "lorem ipsum", uuids[4]));
//    before_sort.push_back(Note("Zheraf", "2020-20-12", "lorem ipsum", uuids[5]));
//    before_sort.push_back(Note("Zhara", "2020-20-12", "lorem ipsum", uuids[6]));

//    QList<Note> after_sort;
//    after_sort.push_back(Note("Alfavit", "2020-20-12", "lorem ipsum", uuids[4]));
//    after_sort.push_back(Note("Ezhednevnik", "2020-20-12", "lorem ipsum", uuids[0]));
//    after_sort.push_back(Note("Olphovit", "2020-20-12", "lorem ipsum", uuids[3]));
//    after_sort.push_back(Note("Otdykh", "2020-20-12", "lorem ipsum", uuids[1]));
//    after_sort.push_back(Note("Otpusk", "2020-20-12", "lorem ipsum", uuids[2]));
//    after_sort.push_back(Note("Zhara", "2020-20-12", "lorem ipsum", uuids[6]));
//    after_sort.push_back(Note("Zheraf", "2020-20-12", "lorem ipsum", uuids[5]));

//    Notes::sortAcsNotes(before_sort, NoteSortCriterion::Name);
//    AssertEqual(before_sort, after_sort, "Sort ASC by name");

//    QList<Note> date_before_sort;
//    date_before_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
//    date_before_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
//    date_before_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
//    date_before_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
//    date_before_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));
//    date_before_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));
//    date_before_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));

//    QList<Note> date_after_sort;
//    date_after_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));
//    date_after_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));
//    date_after_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
//    date_after_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
//    date_after_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
//    date_after_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
//    date_after_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));

//    Notes::sortAcsNotes(date_before_sort, NoteSortCriterion::Date);
//    AssertEqual(date_before_sort, date_after_sort, "Sort ASC by date");
//}

//void TestDecSorting() {}
//    QList<QUuid> uuids;
//    for (int i = 0; i < 7; ++i)
//        uuids.push_back(QUuid::createUuid());

//    QList<Note> name_before_sort;
//    name_before_sort.push_back(Note("f", "2020-20-12", "lorem ipsum", uuids[0]));
//    name_before_sort.push_back(Note("x", "2020-20-12", "lorem ipsum", uuids[1]));
//    name_before_sort.push_back(Note("h", "2020-20-12", "lorem ipsum", uuids[2]));
//    name_before_sort.push_back(Note("a", "2020-20-12", "lorem ipsum", uuids[3]));
//    name_before_sort.push_back(Note("z", "2020-20-12", "lorem ipsum", uuids[4]));
//    name_before_sort.push_back(Note("j", "2020-20-12", "lorem ipsum", uuids[5]));
//    name_before_sort.push_back(Note("e", "2020-20-12", "lorem ipsum", uuids[6]));

//    QList<Note> name_after_sort;
//    name_after_sort.push_back(Note("z", "2020-20-12", "lorem ipsum", uuids[4]));
//    name_after_sort.push_back(Note("x", "2020-20-12", "lorem ipsum", uuids[1]));
//    name_after_sort.push_back(Note("j", "2020-20-12", "lorem ipsum", uuids[5]));
//    name_after_sort.push_back(Note("h", "2020-20-12", "lorem ipsum", uuids[2]));
//    name_after_sort.push_back(Note("f", "2020-20-12", "lorem ipsum", uuids[0]));
//    name_after_sort.push_back(Note("e", "2020-20-12", "lorem ipsum", uuids[6]));
//    name_after_sort.push_back(Note("a", "2020-20-12", "lorem ipsum", uuids[3]));

//    Notes::sortDecNotes(name_before_sort, NoteSortCriterion::Name);
//    AssertEqual(name_before_sort, name_after_sort, "Sort DEC by name");

//    QList<Note> date_before_sort;
//    date_before_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
//    date_before_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));
//    date_before_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
//    date_before_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
//    date_before_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
//    date_before_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));
//    date_before_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));


//    QList<Note> date_after_sort;
//    date_after_sort.push_back(Note("Alfavit", "4200-09-01", "lorem ipsum", uuids[4]));
//    date_after_sort.push_back(Note("Otpusk", "3002-10-02", "lorem ipsum", uuids[2]));
//    date_after_sort.push_back(Note("Otdykh", "2020-22-11", "lorem ipsum", uuids[1]));
//    date_after_sort.push_back(Note("Ezhednevnik", "1920-20-12", "lorem ipsum", uuids[0]));
//    date_after_sort.push_back(Note("Olphovit", "1120-24-11", "lorem ipsum", uuids[3]));
//    date_after_sort.push_back(Note("Zhara", "0230-30-06", "lorem ipsum", uuids[6]));
//    date_after_sort.push_back(Note("Zheraf", "0230-02-03", "lorem ipsum", uuids[5]));

//    Notes::sortDecNotes(date_before_sort, NoteSortCriterion::Date);
//    AssertEqual(date_before_sort, date_after_sort, "Sort DEC by date");
//}

int main(int argc, char *argv[]){
//    {
//        TestRunner tr;
//        tr.RunTest(TestAscSorting, "TestAscSorting");
//        tr.RunTest(TestDecSorting, "TestDecSorting");
//    }

    QApplication app(argc, argv);
    Notes *win = new Notes();

    win->show();
    return app.exec();
}

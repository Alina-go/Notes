#include "TddSorting.h"

TddSorting::TddSorting(QObject *parent)
{
}

void TddSorting::sort(int column, Qt::SortOrder order)
{
    emit layoutAboutToBeChanged();

    if(order == Qt::AscendingOrder)
//        std::sort(m_notes.begin(), m_notes.end(), std::less<Note>());
//                  []
//                  (Note a, Note b) { return a.getName() < b.getName(); });
//    else
//        std::sort(m_notes.begin(), m_notes.end(), std::greater<Note>());
//                  [] (Note a, Note b) { return a.getName() > b.getName(); });
    emit layoutChanged();

}

QVariant TddSorting::data(const QModelIndex &index, int role) const
{
//    if(!index.isValid())
//        return QVariant();

//    if(role == Qt::DisplayRole)
//        return note.getNotes().at(index.row());
//    else
//        return QVariant();
}

int TddSorting::rowCount(const QModelIndex &parent) const
{
    return m_notes.count();
}


//void TddSorting::SortAcs()
//{
//    sortAcsNotes(note.getNotes(), NoteSortCriterion::Name);
//    note.getTable()->setRowCount(0);
//    note.fillTable(note->getNotes());
//}

//void TddSorting::SortDec()
//{
//    sortDecNotes(note->getNotes(), NoteSortCriterion::Name);
//    note->getTable()->setRowCount(0);
//    note->fillTable(note->getNotes());
//}

//void TddSorting::sortAcsNotes(QList<Note>& notes, NoteSortCriterion criterion) {
//    switch(criterion)
//    {
//    case NoteSortCriterion::Name:
//        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getName() < b.getName(); });
//        break;
//    case NoteSortCriterion::Date:
//        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getDate()< b.getDate(); });
//        break;
//    }
//}

//void TddSorting::sortDecNotes(QList<Note> &notes, NoteSortCriterion criterion)
//{
//    switch(criterion)
//    {
//    case NoteSortCriterion::Name:
//        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getName() > b.getName(); });
//        break;
//    case NoteSortCriterion::Date:
//        std::sort(notes.begin(), notes.end(), [] (Note a, Note b) { return a.getDate() > b.getDate(); });
//        break;
//    }
//}


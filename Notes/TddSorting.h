#pragma once

#include "CustomTableWidget.h"
#include "Notes.h"

class TddSorting : public QAbstractListModel
{
    Q_OBJECT
public:
    TddSorting(QObject* parent = 0);

    void sort(int column, Qt::SortOrder order) override;
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent) const override;

//    static void sortAcsNotes(QList<Note>& notes, NoteSortCriterion criterion);
//    static void sortDecNotes(QList<Note>& notes, NoteSortCriterion criterion);

public slots:
//    void SortAcs();
//    void SortDec();

private:
    QList<Note> m_notes;
    Notes note;
};

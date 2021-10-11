#include "CustomTableWidget.h"

CustomTableWidget::CustomTableWidget(int rows, int columns,
                                     QWidget *parent = nullptr) : QTableWidget(rows, columns, parent) {}

void CustomTableWidget::mousePressEvent(QMouseEvent *event)
{
    if (itemAt(event->pos()))
        QTableWidget::mousePressEvent(event);
    else
    {
        clearSelection();
        emit DeactivateTE();
    }
}

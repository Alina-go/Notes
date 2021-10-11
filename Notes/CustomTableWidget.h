#pragma once

#include <iostream>
#include <QtWidgets>

class CustomTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    CustomTableWidget(int rows, int columns, QWidget *parent);
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void DeactivateTE();
};

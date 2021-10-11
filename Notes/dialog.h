#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class Dialog: public QDialog{
    Q_OBJECT
public:
    Dialog();
private:
    QPushButton *close;


#endif // DIALOG_H

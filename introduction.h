#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include "struct.h"

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class Introduction : public QDialog
{
    Q_OBJECT //使用信号与槽需要的宏

public:
    Introduction(bool manage, Point *point, QString destination);

    QPushButton *button_save;
    QPushButton *button_close;

    QTextEdit *decrible;

    Point *point_in;

signals:

public slots:
    void save();



};

#endif // INTRODUCTION_H

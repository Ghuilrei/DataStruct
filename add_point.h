#ifndef ADD_POINT_H
#define ADD_POINT_H

#include "struct.h"

#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QLineEdit>

class Add_Point: public QDialog
{
public:
    explicit Add_Point(Point point[MaxVertexNum], bool use_point[MaxVertexNum], int *point_num, int *current, QDialog *parent = nullptr);

    Point *point;
    bool *use_point;
    int *point_num;
    int *current;

    // x
    QLabel *label1;
    // y
    QLabel *label2;
    // name
    QLabel *label3;
    // describe
    QLabel *label4;

    QLineEdit *x;
    QLineEdit *y;
    QLineEdit *name;
    QTextEdit *describe;

    QPushButton *confirm;
    QPushButton *cancel;

    void updata();

    bool isDigitStr(QString str);
};

#endif // ADD_POINT_H

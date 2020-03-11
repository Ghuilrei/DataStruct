#ifndef ADD_PATH_H
#define ADD_PATH_H

#include "struct.h"

#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QLineEdit>

class Add_Path : public QDialog
{
public:

    // 起始结束点
    QComboBox *begin;
    QComboBox *end;
    QLineEdit *distance;
    QPushButton *confirm;
    QPushButton *cancel;

    Line *line;
    bool *use_line;
    int *edge_num;
    Point *point;

    explicit Add_Path(Point point[MaxVertexNum], Line line[MaxVertexNum * MaxVertexNum], bool use_line[MaxVertexNum * MaxVertexNum], int *edge_num, QDialog *parent = nullptr);

    bool isDigitStr(QString str);

    void updata();
};

#endif // ADD_PATH_H

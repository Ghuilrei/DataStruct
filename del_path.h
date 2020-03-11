#ifndef DEL_PATH_H
#define DEL_PATH_H

#include "struct.h"

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>


class Del_Path: public QDialog
{
public:
    explicit Del_Path(Line line[MaxVertexNum * MaxVertexNum], Point point[MaxVertexNum], bool use_line[MaxVertexNum * MaxVertexNum], bool use_point[MaxVertexNum], int* edge_num, int *point_num, int* current, QDialog *parent = nullptr);

    Line* line;
    Point* point;
    bool* use_line;
    bool* use_point;
    int* edge_num;
    int* point_num;
    int* current;

    // 起始结束点
    QComboBox *begin;
    QComboBox *end;
    QTextEdit *distance;
    QPushButton *confirm;
    QPushButton *cancel;

    bool isDigitStr(QString str);

    void updata();
};

#endif // DEL_PATH_H

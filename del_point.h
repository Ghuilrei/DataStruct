#ifndef DEL_POINT_H
#define DEL_POINT_H

#include "struct.h"

#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>

#define MaxVertexNum 50
#define Max 10000

class Del_Point: public QDialog
{
public:
    explicit Del_Point(Line line[MaxVertexNum * MaxVertexNum], Point point[MaxVertexNum], bool use_line[MaxVertexNum * MaxVertexNum], bool use_point[MaxVertexNum], int* edge_num, int *point_num, int* current, QDialog *parent = nullptr);

    Line* line;
    Point* point;
    bool* use_line;
    bool* use_point;
    int* edge_num;
    int* point_num;
    int* current;

    QComboBox *delet_point;

    QPushButton *button_confirm;
    QPushButton *button_cancel;

    void confirm();
};

#endif // DEL_POINT_H

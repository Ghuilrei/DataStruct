#include "del_point.h"

Del_Point::Del_Point(Line line[MaxVertexNum * MaxVertexNum], Point point[MaxVertexNum], bool use_line[MaxVertexNum * MaxVertexNum], bool use_point[MaxVertexNum], int* edge_num, int* point_num, int* current,  QDialog *parent) :
    QDialog(parent)
{
    this->line = line;
    this->point = point;
    this->use_line = use_line;
    this->use_point = use_point;
    this->edge_num = edge_num;
    this->point_num = point_num;
    this->current = current;

    this->resize(300, 130);

    QLabel *label1 = new QLabel("请选择要删除的结点:", this, Qt::WindowFlags());
    label1->move(30, 35);

    delet_point = new QComboBox(this);
    delet_point->move(160, 30);

    button_cancel = new QPushButton("取消",this);
    button_cancel->move(120, 70);
    connect(button_cancel,&QPushButton::clicked,this,&Del_Point::close);

    button_confirm = new QPushButton("确认",this);
    button_confirm->move(120, 70);
    connect(button_confirm,&QPushButton::clicked,this,&Del_Point::confirm);
}

void Del_Point::confirm(){
    *current = delet_point->currentIndex();
    use_point[delet_point->currentIndex()] = false;
    if (point[delet_point->currentIndex()].name == "已删除") {
        QMessageBox::warning(this, tr("错误"),tr("该结点不存在或已被删除！"),QMessageBox::Yes);
        close();
    }
    point[delet_point->currentIndex()].set(delet_point->currentIndex(), 0, 0, "已删除", nullptr);
//    (*point_num)--;
    for (int i = 0; i < *edge_num; ++i) {
        if(line[i].begin == delet_point->currentIndex() || line[i].end == delet_point->currentIndex()){
            use_line[i] = false;
            line[i].set(i, 0, 0, 0, false);
        }
    }
    accept();
}

#include "del_path.h"

#include <QLabel>
#include <QMessageBox>

Del_Path::Del_Path(Line line[MaxVertexNum * MaxVertexNum], Point point[MaxVertexNum], bool use_line[MaxVertexNum * MaxVertexNum], bool use_point[MaxVertexNum], int* edge_num, int *point_num, int* current, QDialog *parent) :
    QDialog(parent)
{
    this->line = line;
    this->point = point;
    this->use_line = use_line;
    this->use_point = use_point;
    this->edge_num = edge_num;
    this->point_num = point_num;
    this->current = current;

    this->resize(230, 190);

    QLabel *label1 = new QLabel("起始点：", this, Qt::WindowFlags());
    label1->move(35, 35);

    begin = new QComboBox(this);
    begin->move(100, 30);


    QLabel *label2 = new QLabel("终止点:", this, Qt::WindowFlags());
    label2->move(35, 80);

    end = new QComboBox(this);
    end->move(100, 75);

    confirm = new QPushButton("确认", this);
    confirm->move(110, 130);

    cancel = new QPushButton("取消", this);
    cancel->move(20, 130);

    connect(confirm,&QPushButton::clicked,this,&Del_Path::updata);
    connect(cancel,&QPushButton::clicked,this,&Del_Path::close);

}

void Del_Path::updata(){
    int num_begin, num_end;
    bool change = false;
    num_begin = begin->currentIndex();
    num_end = end->currentIndex();
    for (int i = 0; i < *edge_num; ++i) {
        if ((line[i].begin == num_begin && line[i].end == num_end) || (line[i].begin == num_end && line[i].end == num_begin)) {
            use_line[i] = false;
            line[i].set(i, 0, 0, 0, false);
            change = true;
        }
    }
    if(change){
        accept();
    }
    else {
        QMessageBox::warning(this, tr("错误"),tr("路径不存在或已被删除！"),QMessageBox::Yes);
        close();
    }
}

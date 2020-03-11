#include "introduction.h"

Introduction::Introduction(bool manage, Point *point, QString destination)
{
    this->resize(300, 500);

    this->point_in = point;

    QLabel *label1 = new QLabel(point_in->name + "的简介：", this, Qt::WindowFlags());
    label1->move(20, 10);

    decrible = new QTextEdit(this);
    decrible->setText(point_in->describe);
    decrible->setReadOnly(!manage);
    decrible->move(20, 30);
    decrible->resize(240,150);

    QLabel *label2 = new QLabel(destination, this, Qt::WindowFlags());
    label2->move(20,200);

    button_close = new QPushButton("关闭", this);
    connect(button_close,&QPushButton::clicked,this,&Introduction::close);


    if(manage) {
        button_save = new QPushButton("保存", this);
        button_save->move(70, 450);
        connect(button_save,&QPushButton::clicked,this,&Introduction::save);
        button_close->move(160, 450);
    }
    else {
        button_close->move(115,450);
    }

}

void Introduction::save(){
    point_in->describe = decrible->toPlainText();
    accept();
}

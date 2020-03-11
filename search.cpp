#include "search.h"
#include <QMessageBox>
#include <QLabel>

Search::Search(QDialog *parent) :
    QDialog(parent)
{
    this->resize(230, 200);

    QLabel *label1 = new QLabel("出发地点:", this, Qt::WindowFlags());
    label1->move(30, 35);

    begin = new QComboBox(this);
    begin->move(100, 30);

    QLabel *label2 = new QLabel("目的地:", this, Qt::WindowFlags());
    label2->move(35, 85);

    end = new QComboBox(this);
    end->move(100, 80);

    search = new QPushButton(this);
    search->setText("搜索");
    search->move(110, 150);

    exit = new QPushButton(this);
    exit->setText("退出");
    exit->move(20, 150);

    connect(search,&QPushButton::clicked,this,&Search::send);
    connect(exit,&QPushButton::clicked,this,&Search::close);
}

void Search::send(){
    accept();
    return;
}

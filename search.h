#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>

#include "struct.h"

class Search : public QDialog
{
    Q_OBJECT //使用信号与槽需要的宏

public:
    // 构造方法
    explicit Search(QDialog *parent = nullptr);  //explicit 防止歧义

    // 搜索按钮函数
    void send();

public slots:

public:
    QComboBox *begin;
    QComboBox *end;
    QPushButton *search;
    QPushButton *exit;

};

#endif // SEARCH_H

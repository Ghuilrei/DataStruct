#ifndef STRUCT_H
#define STRUCT_H

#include <QString>

#define MaxVertexNum 50
#define Max 10000

// 边的结构体
struct Line{
    int num;
    int begin;
    int end;
    int length;
    bool selection;

    // 设置边的函数
    void set (int num, int begin, int end, int length, bool selection){
        this->num = num;
        this->begin = begin;
        this->end = end;
        this->length = length;
        this->selection = selection;
    }
};

// 点的结构体
struct Point{
    int num;
    int x;
    int y;
    QString name;
    QString describe;

    // 设置点的函数
    void set (int num, int x, int y, QString name, QString describe){
        this->num = num;
        this->x = x;
        this->y = y;
        this->name = name;
        this->describe = describe;
    }
};

#endif // STRUCT_H

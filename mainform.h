#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QComboBox>
#include <QPainter>

#include "loginform.h"
#include "reloginform.h"
#include "add_path.h"
#include "add_point.h"
#include "del_path.h"
#include "del_point.h"
#include "struct.h"

class MainForm : public QMainWindow
{
    Q_OBJECT
public:
    // 构造函数？
    explicit MainForm(bool manager, QWidget *parent = nullptr);

    void build();

    void closeEvent(QCloseEvent *event);

    // 点数&边数
    int point_num = 12;
    int edge_num = 20;

    // 图的结构体
    typedef int EdgeType;   // 边的权值类型
    typedef struct{
        EdgeType edge[MaxVertexNum][MaxVertexNum];
    }MGraph;

    // 图
    MGraph G;

    // 点、线的数组
    Point point[MaxVertexNum];
    Line line[MaxVertexNum * MaxVertexNum];
    bool use_point[MaxVertexNum] = {false};
    bool use_path[MaxVertexNum*MaxVertexNum] = {false};

    // 可达矩阵 & 可达权值矩阵
    int path[MaxVertexNum][MaxVertexNum];
    int dist[MaxVertexNum][MaxVertexNum];

    // 要画的点->线
    int draw_line[MaxVertexNum];
    int draw_point[MaxVertexNum * MaxVertexNum];

    // 开始 & 结束 点
    int begin, end;

    // 导航按钮
    QPushButton *search;

    // 返回登陆界面
    QPushButton *back;

    // 返回登陆界面
    QPushButton *guest;

    // 添加景点按钮
    QPushButton *button_add_point;

    // 删除景点按钮
    QPushButton *button_del_point;

    // 添加路径按钮
    QPushButton *button_add_path;

    // 删除路径按钮
    QPushButton *button_del_path;

    // 添加景点按钮
    void add_point();

    // 删除景点按钮
    void del_point();

    // 添加路径按钮
    void add_path();

    // 删除路径按钮
    void del_path();

    // 按钮信号函数
    void describe();
    void find();
    void login_manager();

    // 画板函数
    void paintEvent(QPaintEvent *);

    // 更新
    void print();

    // 寻找要画的线
    bool paint_line(int begin, int end);

    // 建立图
    void creatMGraph();

    // 弗洛伊德算法
    void floyd();

    // 切换访客模式
    void change_guest();

private:
    // 是否为管理员
    bool manager;

private slots:

private:

    // 按钮地址、名字地址
    QPushButton *button_place[20];
    QString *name[20];

};

#endif // MAINFORM_H

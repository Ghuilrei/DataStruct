#include "mainform.h"
#include "search.h"
#include "introduction.h"

#include <QSignalMapper>
#include <QMessageBox>
#include <QComboBox>
#include <string>
#include <QMouseEvent>


MainForm::MainForm(bool manager, QWidget *parent) :
    QMainWindow(parent)
{
    /*
     * 测试专用
     * Add_Point *canvas_add_point = new Add_Point(point, use_point, nullptr);
     * canvas_add_point->show();
     * */


    // 管理员
    this->manager = manager;

    // 构造函数
    this->resize(900, 450);

    point[0].set(0, 40, 40, "体检中心", "体检的地方。");
    point[1].set(0, 40, 140, "邯郸音乐厅", "听音乐的地方。");
    point[2].set(0, 40, 240, "网计学院", "我爱学习！");
    point[3].set(0, 290, 400, "学校南门", "出去浪！");
    point[4].set(0, 170, 260, "信息学部", "一个神奇的地方。");
    point[5].set(0, 310, 130, "图书馆", "学习是我快乐。");
    point[6].set(0, 280, 40, "操场", "You can really dance!");
    point[7].set(0, 440, 40, "学校北门", "该吃饭了。");
    point[8].set(0, 590, 40, "银杏景观", "美！");
    point[9].set(0, 310, 210, "花园景观", "没水的湖");
    point[10].set(0, 440, 250, "学校东门", "吃饭。。。");
    point[11].set(0, 550, 170, "食堂", "emmm。。吃饭。");
    for (int i = 0; i < 12; ++i) {
        use_point[i] = true;
    }

    // 添加按钮
    for(int i = 0; i < point_num; ++i) {
        if(use_point[i]){
            button_place[i] = new QPushButton(point[i].name, this);
            button_place[i]->move(point[i].x, point[i].y);
            button_place[i]->setObjectName(QString::number(i, 10));
            button_place[i]->show();
            connect(button_place[i],&QPushButton::clicked,this,&MainForm::describe);
        }
    }

    // 线数组
    line[0].set(0, 0, 1, 200, false);
    line[1].set(1, 0, 6, 350, false);
    line[2].set(2, 1, 2, 500, false);
    line[3].set(3, 1, 4, 500, false);
    line[4].set(4, 1, 5, 400, false);
    line[5].set(5, 1, 6, 480, false);
    line[6].set(6, 2, 3, 400, false);
    line[7].set(7, 3, 4, 400, false);
    line[8].set(8, 3, 9, 500, false);
    line[9].set(9, 3, 10, 600, false);
    line[10].set(10, 4, 9, 150, false);
    line[11].set(11, 5, 6, 280, false);
    line[12].set(12, 5, 9, 160, false);
    line[13].set(13, 5, 10, 300, false);
    line[14].set(14, 6, 7, 200, false);
    line[15].set(15, 7, 8, 100, false);
    line[16].set(16, 7, 11, 100, false);
    line[17].set(17, 8, 11, 100, false);
    line[18].set(18, 9, 10, 200, false);
    line[19].set(18, 10, 11, 100, false);
    for (int i = 0; i < 20; ++i) {
        use_path[i] = true;
    }

    // 添加导航按钮
    search = new QPushButton("导航", this);
    search->move(770,40);
    search->resize(100,40);
    connect(search,&QPushButton::clicked,this,&MainForm::find);

    // 管理员登陆
    back = new QPushButton("管理员登陆", this);
    back->move(770, 100);
    back->resize(100,40);
    connect(back,&QPushButton::clicked,this,&MainForm::login_manager);

    // 添加景点按钮
    button_add_point = new QPushButton("添加景点", this);
    button_add_point->move(770, 100);
    button_add_point->resize(100,40);
    connect(button_add_point,&QPushButton::clicked, this, &MainForm::add_point);

    // 删除景点按钮
    button_del_point = new QPushButton("删除景点", this);
    button_del_point->move(770, 160);
    button_del_point->resize(100,40);
    connect(button_del_point,&QPushButton::clicked, this, &MainForm::del_point);

    // 添加路径按钮
    button_add_path = new QPushButton("添加路径", this);
    button_add_path->move(770, 220);
    button_add_path->resize(100,40);
    connect(button_add_path,&QPushButton::clicked, this, &MainForm::add_path);

    // 删除路径按钮
    button_del_path = new QPushButton("删除路径", this);
    button_del_path->move(770, 280);
    button_del_path->resize(100,40);
    connect(button_del_path,&QPushButton::clicked, this, &MainForm::del_path);

    // 游客登陆按钮
    guest = new QPushButton("访客模式", this);
    guest->move(770, 340);
    guest->resize(100,40);
    connect(guest,&QPushButton::clicked, this, &MainForm::change_guest);

    // 新建图
    creatMGraph();

    build();
}

void MainForm::build(){

    if(!manager){
        button_del_path->hide();
        button_add_path->hide();
        button_del_point->hide();
        button_add_point->hide();
        guest->hide();
        back->show();
    }
    else {
        button_del_path->show();
        button_add_path->show();
        button_del_point->show();
        button_add_point->show();
        guest->show();
        back->hide();
    }
}


// 画路径
void MainForm::paintEvent(QPaintEvent *) {

    QPen pen;
    QPainter painter(this);

    //画线
    for (int i = 0; i < edge_num; ++i) {
        int begin = line[i].begin;
        int end = line[i].end;
        if(use_path[i]){
            pen.setWidth(7);
            pen.setColor(Qt::gray);
            painter.setPen(pen);
            QLine line_index(button_place[begin]->x() + 40, button_place[begin]->y() + 15, button_place[end]->x() + 40, button_place[end]->y() + 15);
            painter.drawLine(line_index);
            if(line[i].selection) {
                pen.setWidth(3);
                pen.setColor(Qt::blue);
                painter.setPen(pen);
                QLine line_index(button_place[begin]->x() + 40, button_place[begin]->y() + 15, button_place[end]->x() + 40, button_place[end]->y() + 15);
                painter.drawLine(line_index);
            }
        }
    }
}

// 简介
void MainForm::describe(){
    int index;
    QObject *object = QObject::sender();
    QPushButton *push_button = qobject_cast<QPushButton *>(object);
    QString object_name = push_button->objectName();
    index = object_name.toInt();
    QString destination;
    for (int i = 0; i < point_num; ++i) {
        if(i == index) {
            continue;
        }
        else if(dist[index][i] < Max) {
            destination = destination + "距  " + point[i].name + "  " + QString::number(dist[index][i], 10) + "米\n";
        }
        else {
            destination = destination + "⚠️无法到达  " + point[i].name + "\n";
        }
    }
    Introduction *introduction = new Introduction(manager, &point[index], destination);
    introduction->setWindowTitle(point[index].name);
    introduction->show();
//    QMessageBox::information(nullptr, point[index].name, point[index].name + ":\n" + point[index].describe + "\n\n" + destination);
}

// 导航按钮
void MainForm::find(){
    // 新建界面
    Search *search = new Search();
    search->setWindowTitle("导航");
    search->show();

    for (int i = 0; i < point_num; ++i) {
        search->begin->addItem(point[i].name);
        search->end->addItem(point[i].name);
    }

    for (int i = 0; i < edge_num; ++i) {
        line[i].selection = false;
    }

    // 接收起始点 & 终止点
    int exec = search->exec();
    if(exec == QDialog::Accepted){
        this->begin = search->begin->currentIndex();
        this->end  = search->end->currentIndex();
        if(begin == end){
            QMessageBox::warning(this, tr("查找成功！"),"从 " + point[begin].name + " 到 " + point[end].name + "：\n往北走到第一个路口右转，\n然后继续直行到第一个十字路口，\n接着右转，\n遇到路口，\n右转，\n目的地就在往前走的路口附近。", QMessageBox::Yes);
        }
        else if(dist[begin][end] < Max){
            print();
            QMessageBox::warning(this, tr("查找成功！"),"从 " + point[begin].name + " 到 " + point[end].name + "：\n全程" + QString::number(dist[begin][end], 10) + "米, 大约需要" + QString::number(dist[begin][end]/60, 10) + "分钟。",QMessageBox::Yes);
        }
        else {
            QMessageBox::warning(this, tr("查找失败。"),"从 " + point[begin].name + " 到 " + point[end].name + "：\n不可达", QMessageBox::Yes);
        }
    }
}

// 重画函数
void MainForm::print(){

    qDebug("0:%d->%d", begin, end);
    if(path[begin][end] == end){
        qDebug("1.1:%d->%d", begin, end);
        paint_line(begin, end);
    }
    else if(begin > end){
        int k = begin;
        int h = k;
        while (path[end][k] != k) {
            h = k;
            k = path[end][k];
            paint_line(h, k);
        }
        paint_line(k,end);
    }
    else {
        int k = end;
        int h = k;
        while (path[begin][k] != k) {
            h = k;
            k = path[begin][k];
            paint_line(h, k);
        }
        paint_line(k,begin);
    }
    update();
}

bool MainForm::paint_line(int begin, int end){
    qDebug("2:%d->%d", begin, end);
    for (int i = 0; i < edge_num; ++i) {
        if((line[i].begin == begin && line[i].end == end) || (line[i].end == begin && line[i].begin == end)){
            line[i].selection = true;
            return true;
        }
    }
    return false;
}

// 建图
void MainForm::creatMGraph(){

    // 初始化
    for (int i = 0; i < MaxVertexNum; ++i) {
        for (int j = 0; j < MaxVertexNum; ++j) {
            G.edge[i][j] = Max;
        }
    }

    // 路径设置为1
    for (int i = 0; i < edge_num; ++i){
        G.edge[line[i].begin][line[i].end] = line[i].length;
        G.edge[line[i].end][line[i].begin] = line[i].length;
    }

//    qDebug("%2d : %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d",0 , 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
//    for (int i = 0; i < point_num; ++i) {
//        qDebug("%2d : %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d", i, G.edge[i][0], G.edge[i][1], G.edge[i][2], G.edge[i][3], G.edge[i][4], G.edge[i][5], G.edge[i][6], G.edge[i][7], G.edge[i][8], G.edge[i][9], G.edge[i][10], G.edge[i][11]);
//    }

    floyd();
}

// 弗洛伊德算法
void MainForm::floyd(){
    int i, j, k;
    int temp;

    // 初始化
    for (i = 0; i < point_num; ++i) {
        for(j = 0; j < point_num; ++j){
            dist[i][j] = G.edge[i][j];
            path[i][j] = j;
        }
    }

    // 计算最短路径
    for (k = 0; k < point_num; ++k) {\
        for (i = 0; i < point_num; ++i) {
            for (j = 0; j < point_num; ++j) {
                temp = dist[i][k] + dist[k][j];
                if(dist[i][j] > temp) {
                    dist[i][j] = temp;
                    path[i][j] = k;
                }
            }
        }
    }

//    qDebug("\n%2d : %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d",0 , 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
//    for (int i = 0; i < point_num; ++i) {
//        qDebug("%2d : %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d", i, path[i][0], path[i][1], path[i][2], path[i][3], path[i][4], path[i][5], path[i][6], path[i][7], path[i][8], path[i][9], path[i][10], path[i][11]);
//    }

//    qDebug("\n%2d : %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d",0 , 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
//    for (int i = 0; i < point_num; ++i) {
//        qDebug("%2d : %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d %5d", i, dist[i][0], dist[i][1], dist[i][2], dist[i][3], dist[i][4], dist[i][5], dist[i][6], dist[i][7], dist[i][8], dist[i][9], dist[i][10], dist[i][11]);
//    }
}

// 设置管理员/游客登陆
void MainForm::login_manager(){
    ReLoginForm relogin;
    int exec = relogin.exec();
    if(exec == QDialog::Accepted){
        manager = true;
        build();
    }
}

void MainForm::change_guest(){
    manager = false;
    build();
}

// 添加景点按钮
void MainForm::add_point(){
    int current;
    Add_Point *canvas_add_point = new Add_Point(point, use_point, &point_num, &current, nullptr);
    canvas_add_point->show();
    int exec = canvas_add_point->exec();
    if(exec == QDialog::Accepted){
        button_place[current] = new QPushButton(point[current].name, this);
        button_place[current]->move(point[current].x, point[current].y);
        button_place[current]->setObjectName(QString::number(current, 10));
        button_place[current]->show();
        connect(button_place[current],&QPushButton::clicked,this,&MainForm::describe);
        button_place[current]->show();
        creatMGraph();
    }
}

// 删除景点按钮
void MainForm::del_point(){
    int current = 0;
    Del_Point *canvas_del_point = new Del_Point(line, point, use_path, use_point,&edge_num, &point_num, &current, nullptr);
    for (int i = 0; i < point_num; ++i) {
        canvas_del_point->delet_point->addItem(point[i].name);
    }
    canvas_del_point->show();
    int exec = canvas_del_point->exec();
    if(exec == QDialog::Accepted){
        button_place[current]->hide();
        update();
        creatMGraph();
    }
}

// 添加路径按钮
void MainForm::add_path(){
    Add_Path *canvas_add_path = new Add_Path(point, line, use_path, &edge_num, nullptr);

    for (int i = 0; i < point_num; ++i) {
        canvas_add_path->begin->addItem(point[i].name);
        canvas_add_path->end->addItem(point[i].name);
    }

    canvas_add_path->show();
    int exec = canvas_add_path->exec();
    if(exec == QDialog::Accepted){
        update();
        creatMGraph();
    }
}

// 删除路径按钮
void MainForm::del_path(){
    int current;
    Del_Path *canvas_del_path = new Del_Path(line, point, use_path, use_point, &edge_num, &point_num, &current, nullptr);
    for (int i = 0; i < point_num; ++i) {
        canvas_del_path->begin->addItem(point[i].name);
        canvas_del_path->end->addItem(point[i].name);
    }
    canvas_del_path->show();
    int exec = canvas_del_path->exec();
    if(exec == QDialog::Accepted){
        update();
        creatMGraph();
    }
}

// 关闭询问
void MainForm::closeEvent(QCloseEvent *ev)
{
    int a = QMessageBox::warning(this,"退出","确认退出吗？",QMessageBox::No | QMessageBox::Yes);
    if(a ==QMessageBox::Yes)
        {
            int b = QMessageBox::warning(this,"退出","有点小bug。\n\n时间不够;\n错误未定;\n方案暂无;\n\n跪求好评☺️☺️☺️☺️☺️☺️",QMessageBox::No | QMessageBox::Yes);
            while (b == QMessageBox::No) {
                b = QMessageBox::warning(this,"退出","有点小bug。\n\n时间不够;\n错误未定;\n方案暂无;\n\n跪求好评☺️☺️☺️☺️☺️☺️",QMessageBox::No | QMessageBox::Yes);
            }
            QMessageBox::warning(this,"退出","谢谢大哥 or 小姐姐☺️☺️",QMessageBox::Yes);
            std::exit(0);
        }
        else
        {
             ev->ignore();
        }
}

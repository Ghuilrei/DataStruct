#include "add_point.h"

Add_Point::Add_Point(Point point[MaxVertexNum], bool use_point[MaxVertexNum], int *point_num, int *current, QDialog *parent) :
    QDialog(parent)
{
    this->point = point;
    this->use_point = use_point;
    this->point_num = point_num;
    this->current = current;

    this->setWindowTitle("添加景点");
    this->resize(250, 300);

    QLabel *label1 = new QLabel("x:", this, Qt::WindowFlags());
    label1->move(55, 25);

    x = new QLineEdit(this);
    x->move(77, 20);
    x->resize(100,27);
    x->setPlaceholderText("输入横坐标");

    QLabel *label2 = new QLabel("y:", this, Qt::WindowFlags());
    label2->move(55, 65);

    y = new QLineEdit(this);
    y->move(77, 60);
    y->resize(100,27);
    y->setPlaceholderText("输入纵坐标");

    QLabel *label3 = new QLabel("名称:", this, Qt::WindowFlags());
    label3->move(35, 105);

    name = new QLineEdit(this);
    name->move(77, 100);
    name->resize(100,27);
    name->setPlaceholderText("输入景点名称");

    QLabel *label4 = new QLabel("简介:", this, Qt::WindowFlags());
    label4->move(35, 145);

    describe = new QTextEdit(this);
    describe->move(77, 140);
    describe->resize(150,100);
    describe->setPlaceholderText("输入景点简介");

    confirm = new QPushButton("确认", this);
    confirm->move(150, 250);

    cancel = new QPushButton("取消", this);
    cancel->move(60, 250);

    connect(confirm,&QPushButton::clicked,this,&Add_Point::updata);
    connect(cancel,&QPushButton::clicked,this,&Add_Point::close);

}

void Add_Point::updata(){
    if(x->text() == "" || !isDigitStr(x->text())){
        QMessageBox::warning(this, "Warnning!", "请输入有效的横坐标值。", QMessageBox::Ok);
    }
    else if (y->text() == "" || !isDigitStr(y->text())) {
        QMessageBox::warning(this, "Warnning!", "请输入有效的纵坐标值。", QMessageBox::Ok);
    }
    else if (name->text() == "") {
        QMessageBox::warning(this, "Warnning!", "请输入景点名称。", QMessageBox::Ok);
    }
    else {
        int i = 0;
        while (use_point[i]) {
            ++i;
            if(i >= MaxVertexNum) {
                QMessageBox::warning(this, "Error!", "储存器已满，请联系开发者扩容", QMessageBox::Ok);
                return;
            }
        }
        if(i >= *point_num){
            (*point_num)++;
        }
        point[i].set(i, x->text().toInt(), y->text().toInt(), name->text(), describe->toPlainText());
        use_point[i] = true;
        *current = i;
        accept();
    }
}

/***
  *判断一个字符串是否为纯数字
  */
bool Add_Point::isDigitStr(QString str)
{
    QByteArray ba = str.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }
}

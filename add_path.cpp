#include "add_path.h"

Add_Path::Add_Path(Point point[MaxVertexNum], Line line[MaxVertexNum * MaxVertexNum], bool use_line[MaxVertexNum * MaxVertexNum], int *edge_num, QDialog *parent) :
    QDialog(parent)
{
    this->line = line;
    this->use_line = use_line;
    this->edge_num = edge_num;
    this->point = point;

    this->resize(230, 230);

    QLabel *label1 = new QLabel("起始点：", this, Qt::WindowFlags());
    label1->move(35, 35);

    begin = new QComboBox(this);
    begin->move(100, 30);


    QLabel *label2 = new QLabel("终止点:", this, Qt::WindowFlags());
    label2->move(35, 80);

    end = new QComboBox(this);
    end->move(100, 75);

    QLabel *label3 = new QLabel("距离:                                  米", this, Qt::WindowFlags());
    label3->move(38, 127);

    distance = new QLineEdit(this);
    distance->setPlaceholderText("输入权值");
    distance->resize(80,27);
    distance->move(105,125);

    confirm = new QPushButton("确认", this);
    confirm->move(110, 170);

    cancel = new QPushButton("取消", this);
    cancel->move(20, 170);

    connect(confirm,&QPushButton::clicked,this,&Add_Path::updata);
    connect(cancel,&QPushButton::clicked,this,&Add_Path::close);
}

void Add_Path::updata(){
    if(distance->text() == "" || !isDigitStr(distance->text())){
        QMessageBox::warning(this, "Warnning!", "请输入有效的路径长度。", QMessageBox::Ok);
        close();
    }
    else if (begin->currentIndex() == end->currentIndex()) {
        QMessageBox::warning(this, "Error!", "起点和终点不可相同。", QMessageBox::Ok);
        close();
    }
    else if (point[begin->currentIndex()].name == "已删除") {
        QMessageBox::warning(this, "Error!", "结点不存在或已删除。", QMessageBox::Ok);
        close();
    }
    else {
        int i = 0;
        while (use_line[i]) {
            ++i;
            if(i >= MaxVertexNum * MaxVertexNum) {
                QMessageBox::warning(this, "Error!", "储存器已满，请联系开发者扩容", QMessageBox::Ok);
                return;
            }
        }
        if(i >= *edge_num){
            (*edge_num)++;
        }
        line[i].set(i, begin->currentIndex(), end->currentIndex(), distance->text().toInt(),false);
        use_line[i] = true;
        accept();
    }
}

/***
  *判断一个字符串是否为纯数字
  */
bool Add_Path::isDigitStr(QString str)
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

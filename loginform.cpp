#include "loginform.h"
#include <QMessageBox>
#include <QMouseEvent>

LoginForm::LoginForm(QDialog *parent) :
    QDialog(parent)
{
    //设置窗体标题
    this->setWindowTitle(tr("登录界面"));
    this->resize(330, 280);

    //用户名Label
    userNameLbl = new QLabel(this);   //new一个标签对象
    userNameLbl->move(70,60);         //移动到(70,80)位置(Label左上角坐标，相对于父窗体)
    userNameLbl->setText("用户名:");  //设置标签文本

    //用户名输入框
    userNameLEd = new QLineEdit(this);
    userNameLEd->move(120,60);
    userNameLEd->setPlaceholderText(tr("请输入用户名!"));//占位符

    //密码Label
    pwdLbl = new QLabel(this);
    pwdLbl->move(80,110);
    pwdLbl->setText("密码:");

    //密码输入框
    pwdLEd = new QLineEdit(this);
    pwdLEd->move(120,110);
    pwdLEd->setPlaceholderText("请输入密码!");
    pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

    //登录按钮
    loginBtn = new QPushButton(this);
    loginBtn->move(35,180);
    loginBtn->setText("登录");

    //退出按钮
    exitBtn = new QPushButton(this);
    exitBtn->move(135,180);
    exitBtn->setText("退出");

    //访客按钮
    guestBtn = new QPushButton(this);
    guestBtn->move(230,180);
    guestBtn->setText("访客");

    //单击登录按钮时 执行 LoginForm::login 槽函数(自定义)；单击退出按钮时 执行 LoginForm::close 槽函数(窗体的关闭函数，不用自己写)
    connect(loginBtn,&QPushButton::clicked,this,&LoginForm::login);
    connect(guestBtn,&QPushButton::clicked,this,&LoginForm::reject);
    connect(exitBtn,&QPushButton::clicked,this,&LoginForm::exit);


}

void LoginForm::login()
{
    //获得userNameLEd输入框的文本：userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，防止设置中文时乱码
    if(userNameLEd->text().trimmed() == tr("123") && pwdLEd->text() == tr("123"))
    {
       accept();    //关闭窗体，并设置返回值为Accepted
    }
    else
    {                               //标题              内容                OK按钮
       QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

       // 清空输入框内容
       userNameLEd->clear();
       pwdLEd->clear();

       //光标定位
       userNameLEd->setFocus();
    }
}

void LoginForm::exit() {
    std::exit(0);
}

void LoginForm::closeEvent(QCloseEvent *ev)
{
    int a = QMessageBox::warning(this,"退出","确认退出吗？",QMessageBox::Yes | QMessageBox::No);
    if(a ==QMessageBox::Yes)
        {
              std::exit(0);
        }
        else
        {
             ev->ignore();
        }

}

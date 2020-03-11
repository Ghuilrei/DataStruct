#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "struct.h"

class LoginForm : public QDialog
{
    Q_OBJECT //使用信号与槽需要的宏

public:
    explicit LoginForm(QDialog *parent = nullptr);  //explicit 防止歧义

    void closeEvent(QCloseEvent *event);

signals:

public slots:
    void login();//点击登录按钮是执行的槽函数
    void exit();

private:
    QLabel *userNameLbl;         //"用户名"标签
    QLabel *pwdLbl;              //"密码"标签
    QLineEdit *userNameLEd;      //用户名编辑行
    QLineEdit *pwdLEd;           //密码编辑行
    QPushButton *loginBtn;       //登录按钮
    QPushButton *exitBtn;        //退出按钮
    QPushButton *guestBtn;       //退出按钮
};

#endif // LOGINFORM_H

#include <QApplication>
#include "mainform.h"
#include "loginform.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    LoginForm login;
    int exec = login.exec();
    if (exec == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
    {

        MainForm *main = new MainForm(true);
        main->setWindowTitle("校园导航系统");//设置窗体标题
        main->show();
        return app.exec();
    } else{
        MainForm *main = new MainForm(false);
        main->setWindowTitle("校园导航系统");//设置窗体标题
        main->show();
        return app.exec();
    }
}

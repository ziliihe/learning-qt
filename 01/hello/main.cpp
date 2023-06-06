#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // QApplication 是Qt的标准应用程序类，第1行代码定义了一个QApplication类的实例a，就是应用程序对象。
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // 开始应用程序的消息循环和事件处理
    return a.exec();
}

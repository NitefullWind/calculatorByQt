/***********************************************************\
*简单表达式运算，支持加减乘除和括号，但：
*1.仅支持输入一个小数
*2.不支持大数
*4.不支持负号
*5.不支持换行输出
*6.屏幕暴丑
*7.窗口大小会随字符串长度改变
*8.待补充……
\***********************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

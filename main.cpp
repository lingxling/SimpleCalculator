/*
 * 简单计算器 - v1.0
 * 已实现：小数四则运算、优先级运算；
 *        清除表达式；
 *        回退表达式；
 * 不支持：大数运算；
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

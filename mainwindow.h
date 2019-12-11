#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculate.h"
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <string>
#include <QLineEdit>
#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>

QT_BEGIN_NAMESPACE
class MainWindow;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {}
    void keyPressEvent(QKeyEvent * event);
private:
    QString result;  // 输出结果
    QString expr; // 输入的运算式
    QLabel *textLine; // 显示输入和输出文本
    QGridLayout *layout;  // 计算器布局

    QPushButton *btn0, *btn1, *btn2, *btn3, *btn4, *btn5, *btn6, *btn7, *btn8, *btn9;
    QPushButton *btnPlus, *btnMultiply, *btnMinus, *btnDivide;
    QPushButton *btnEqual;
    QPushButton *btnClear, *btnBackspace;
    QPushButton *btnDot;
    QPushButton *btnLeftBracket, *btnRightBracket;

private slots:
    void btn0Clicked();
    void btn1Clicked();
    void btn2Clicked();
    void btn3Clicked();
    void btn4Clicked();
    void btn5Clicked();
    void btn6Clicked();
    void btn7Clicked();
    void btn8Clicked();
    void btn9Clicked();
    void btnPlusClicked();
    void btnMulClicked();
    void btnMinusClicked();
    void btnDivClicked();
    void btnEqualClicked();
    void btnClearClicked();
    void btnBackspaceClicked();
    void btnDotClicked();
    void btnLeftBracketClicked();
    void btnRightBracketClicked();
};
#endif // MAINWINDOW_H

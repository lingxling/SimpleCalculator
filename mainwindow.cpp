#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowIcon(QIcon(":images\\icon.jpg"));
    this->setWindowTitle("Simple Calculator");
    this->setFixedSize(496, 460);  // 设置运行窗口大小，设置好后大小不可调整,4*120+6+10, 5*70+90+10+10

    result = "";
    expr = "";
    textLine = new QLabel("");
    layout = new QGridLayout();

    textLine->setFont(QFont("Consolas", 24));  // 设置文本框字体和字体大小
    textLine->setFixedHeight(90);  // 设置文本框大小
    textLine->setAlignment(Qt::AlignRight|Qt::AlignVCenter);  // 右边居中对齐

    btn0 = new QPushButton("0");  // 新建按钮"0"
    btn1 = new QPushButton("1");
    btn2 = new QPushButton("2");
    btn3 = new QPushButton("3");
    btn4 = new QPushButton("4");
    btn5 = new QPushButton("5");
    btn6 = new QPushButton("6");
    btn7 = new QPushButton("7");
    btn8 = new QPushButton("8");
    btn9 = new QPushButton("9");
    btnPlus = new QPushButton("+");
    btnMinus = new QPushButton("-");
    btnMultiply = new QPushButton("*");
    btnDivide = new QPushButton("/");
    btnEqual = new QPushButton("=");
    btnClear = new QPushButton("AC");
    btnDot = new QPushButton(".");
    btnLeftBracket = new QPushButton("(");
    btnRightBracket = new QPushButton(")");
    btnBackspace = new QPushButton();

    //设置按钮样式
    btn0->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209);}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn1->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn2->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn3->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn4->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn5->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn6->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn7->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn8->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btn9->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnClear->setStyleSheet("QPushButton{background-color:rgb(248, 185, 108);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(237, 142, 37)}"
                        "QPushButton:pressed{background-color:rgb(230, 109, 30)}");

    btnDot->setStyleSheet("QPushButton{background-color:rgb(250, 250, 250);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnLeftBracket->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnRightBracket->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnBackspace->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnDivide->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnPlus->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnMinus->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnMultiply->setStyleSheet("QPushButton{background-color:rgb(240, 240, 240);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(209, 209, 209)}"
                        "QPushButton:pressed{background-color:rgb(187, 187, 187)}");

    btnEqual->setStyleSheet("QPushButton{background-color:rgb(163, 201, 239);border:none;font-size:30px}"
                        "QPushButton:hover{background-color:rgb(113, 179, 246)}"
                        "QPushButton:pressed{background-color:rgb(64, 158, 254)}");
    textLine->setStyleSheet("background-color:rgb(230, 230, 230);border:none");
    btnBackspace->setIcon(QIcon(":images\\backspace.jpg"));

    btn0->setMinimumSize(120, 70);  // 设置按钮大小
    btn1->setMinimumSize(120, 70);
    btn2->setMinimumSize(120, 70);
    btn3->setMinimumSize(120, 70);
    btn4->setMinimumSize(120, 70);
    btn5->setMinimumSize(120, 70);
    btn6->setMinimumSize(120, 70);
    btn7->setMinimumSize(120, 70);
    btn8->setMinimumSize(120, 70);
    btn9->setMinimumSize(120, 70);
    btnPlus->setMinimumSize(120, 70);
    btnMinus->setMinimumSize(120, 70);
    btnMultiply->setMinimumSize(120, 70);
    btnDivide->setMinimumSize(120, 70);
    btnEqual->setMinimumSize(120, 70);
    btnClear->setMinimumSize(120, 70);
    btnDot->setMinimumSize(120, 70);
    btnLeftBracket->setMinimumSize(120, 70);
    btnRightBracket->setMinimumSize(120, 70);
    btnBackspace->setMinimumSize(120, 70);

    btn0->setShortcut(Qt::Key_0);  // 设置快捷键
    btn1->setShortcut(Qt::Key_1);
    btn2->setShortcut(Qt::Key_2);
    btn3->setShortcut(Qt::Key_3);
    btn4->setShortcut(Qt::Key_4);
    btn5->setShortcut(Qt::Key_5);
    btn6->setShortcut(Qt::Key_6);
    btn7->setShortcut(Qt::Key_7);
    btn8->setShortcut(Qt::Key_8);
    btn9->setShortcut(Qt::Key_9);
    btnDot->setShortcut(Qt::Key_Period);
    btnLeftBracket->setShortcut(Qt::Key_ParenLeft);
    btnRightBracket->setShortcut(Qt::Key_ParenRight);
    btnMinus->setShortcut(Qt::Key_Minus);
    btnDivide->setShortcut(Qt::Key_Slash);
    btnPlus->setShortcut(Qt::Key_Plus);
    btnMultiply->setShortcut(Qt::Key_Asterisk);
    btnBackspace->setShortcut(Qt::Key_Backspace);
    btnEqual->setShortcut(Qt::Key_Equal);
    btnClear->setShortcut(QKeySequence("Ctrl+c"));

    connect(btn0, &QPushButton::clicked, this, &MainWindow::btn0Clicked);  // 关联信号与槽函数
    connect(btn1, &QPushButton::clicked, this, &MainWindow::btn1Clicked);
    connect(btn2, &QPushButton::clicked, this, &MainWindow::btn2Clicked);
    connect(btn3, &QPushButton::clicked, this, &MainWindow::btn3Clicked);
    connect(btn4, &QPushButton::clicked, this, &MainWindow::btn4Clicked);
    connect(btn5, &QPushButton::clicked, this, &MainWindow::btn5Clicked);
    connect(btn6, &QPushButton::clicked, this, &MainWindow::btn6Clicked);
    connect(btn7, &QPushButton::clicked, this, &MainWindow::btn7Clicked);
    connect(btn8, &QPushButton::clicked, this, &MainWindow::btn8Clicked);
    connect(btn9, &QPushButton::clicked, this, &MainWindow::btn9Clicked);
    connect(btnPlus, &QPushButton::clicked, this, &MainWindow::btnPlusClicked);
    connect(btnMinus, &QPushButton::clicked, this, &MainWindow::btnMinusClicked);
    connect(btnMultiply, &QPushButton::clicked, this, &MainWindow::btnMulClicked);
    connect(btnDivide, &QPushButton::clicked, this, &MainWindow::btnDivClicked);
    connect(btnEqual, &QPushButton::clicked, this, &MainWindow::btnEqualClicked);
    connect(btnClear, &QPushButton::clicked, this, &MainWindow::btnClearClicked);
    connect(btnDot, &QPushButton::clicked, this, &MainWindow::btnDotClicked);
    connect(btnLeftBracket, &QPushButton::clicked, this, &MainWindow::btnLeftBracketClicked);
    connect(btnRightBracket, &QPushButton::clicked, this, &MainWindow::btnRightBracketClicked);
    connect(btnBackspace, &QPushButton::clicked, this, &MainWindow::btnBackspaceClicked);

    layout->setSpacing(2);  // 控件间隔
    layout->setMargin(5);  // 与边缘距离
    layout->addWidget(textLine,1,1,1,4);  // 控件名，行，列，占用行数，占用列数，对齐方式（默认左对齐）
    layout->addWidget(btnLeftBracket, 2, 1, 1, 1);
    layout->addWidget(btnRightBracket, 2, 2, 1, 1);
    layout->addWidget(btnBackspace, 2, 3, 1, 1);
    layout->addWidget(btnDivide, 2, 4, 1, 1);
    layout->addWidget(btn7, 3, 1, 1, 1);
    layout->addWidget(btn8, 3, 2, 1, 1);
    layout->addWidget(btn9, 3, 3, 1, 1);
    layout->addWidget(btnMultiply, 3, 4, 1, 1);
    layout->addWidget(btn4, 4, 1, 1, 1);
    layout->addWidget(btn5, 4, 2, 1, 1);
    layout->addWidget(btn6, 4, 3, 1, 1);
    layout->addWidget(btnMinus, 4, 4, 1, 1);
    layout->addWidget(btn1, 5, 1, 1, 1);
    layout->addWidget(btn2, 5, 2, 1, 1);
    layout->addWidget(btn3, 5, 3, 1, 1);
    layout->addWidget(btnPlus, 5, 4, 1, 1);
    layout->addWidget(btnClear, 6, 1, 1, 1);
    layout->addWidget(btn0, 6, 2, 1, 1);
    layout->addWidget(btnDot, 6, 3, 1, 1);
    layout->addWidget(btnEqual, 6, 4, 1, 1);

    QWidget *centerWindow = new QWidget;
    centerWindow->setStyleSheet("background-color:rgb(230,230,230)");
    this->setCentralWidget(centerWindow);
    centerWindow->setLayout(layout);
}
void MainWindow::btn0Clicked() { expr += "0"; textLine->setText(expr); }
void MainWindow::btn1Clicked() { expr += "1"; textLine->setText(expr); }
void MainWindow::btn2Clicked() { expr += "2"; textLine->setText(expr); }
void MainWindow::btn3Clicked() { expr += "3"; textLine->setText(expr); }
void MainWindow::btn4Clicked() { expr += "4"; textLine->setText(expr); }
void MainWindow::btn5Clicked() { expr += "5"; textLine->setText(expr); }
void MainWindow::btn6Clicked() { expr += "6"; textLine->setText(expr); }
void MainWindow::btn7Clicked() { expr += "7"; textLine->setText(expr); }
void MainWindow::btn8Clicked() { expr += "8"; textLine->setText(expr); }
void MainWindow::btn9Clicked() { expr += "9"; textLine->setText(expr); }
void MainWindow::btnPlusClicked() { expr += "+"; textLine->setText(expr); }
void MainWindow::btnMulClicked() { expr += "*"; textLine->setText(expr); }
void MainWindow::btnMinusClicked() { expr += "-"; textLine->setText(expr); }
void MainWindow::btnDivClicked() { expr += "/"; textLine->setText(expr); }
void MainWindow::btnEqualClicked() {
    result = Calculate::cal(expr);
    expr = result;
    textLine->setText(expr);
}
void MainWindow::btnClearClicked() { expr = ""; textLine->setText(expr); }
void MainWindow::btnBackspaceClicked() {
    if (expr.length() != 0) expr = expr.mid(0, expr.length()-1);
    else expr = "";
    textLine->setText(expr);}
void MainWindow::btnDotClicked() { expr += "."; textLine->setText(expr); }
void MainWindow::btnLeftBracketClicked() { expr += "("; textLine->setText(expr); }
void MainWindow::btnRightBracketClicked() { expr += ")"; textLine->setText(expr); }
void MainWindow::keyPressEvent(QKeyEvent * event){
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) btnEqualClicked();
}

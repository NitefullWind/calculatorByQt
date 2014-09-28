#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QObject>
#include <cmath>
#include <QKeyEvent>
#include <QEvent>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("计算器"));

    QPushButton *button0 = new QPushButton(tr("0"));
    QPushButton *button1 = new QPushButton(tr("1"));
    QPushButton *button2 = new QPushButton(tr("2"));
    QPushButton *button3 = new QPushButton(tr("3"));
    QPushButton *button4 = new QPushButton(tr("4"));
    QPushButton *button5 = new QPushButton(tr("5"));
    QPushButton *button6 = new QPushButton(tr("6"));
    QPushButton *button7 = new QPushButton(tr("7"));
    QPushButton *button8 = new QPushButton(tr("8"));
    QPushButton *button9 = new QPushButton(tr("9"));
    QPushButton *buttonPoint = new QPushButton(tr("."));
    QPushButton *buttonDel = new QPushButton(tr("Del"));
    QPushButton *buttonClean = new QPushButton(tr("C"));
    QPushButton *buttonLeftBracket = new QPushButton(tr("("));
    QPushButton *buttonRightBracket = new QPushButton(tr(")"));
    QPushButton *buttonAdd = new QPushButton(tr("+"));
    QPushButton *buttonSubtract = new QPushButton(tr("-"));
    QPushButton *buttonMultiply = new QPushButton(tr("×"));
    QPushButton *buttonDivide = new QPushButton(tr("÷"));
    QPushButton *buttonEqual = new QPushButton(tr("="));

    connect(button0,SIGNAL(clicked()),this,SLOT(inputStr0()));
    connect(button1,SIGNAL(clicked()),this,SLOT(inputStr1()));
    connect(button2,SIGNAL(clicked()),this,SLOT(inputStr2()));
    connect(button3,SIGNAL(clicked()),this,SLOT(inputStr3()));
    connect(button4,SIGNAL(clicked()),this,SLOT(inputStr4()));
    connect(button5,SIGNAL(clicked()),this,SLOT(inputStr5()));
    connect(button6,SIGNAL(clicked()),this,SLOT(inputStr6()));
    connect(button7,SIGNAL(clicked()),this,SLOT(inputStr7()));
    connect(button8,SIGNAL(clicked()),this,SLOT(inputStr8()));
    connect(button9,SIGNAL(clicked()),this,SLOT(inputStr9()));
    connect(buttonPoint,SIGNAL(clicked()),this,SLOT(inputStrPoint()));
    connect(buttonLeftBracket,SIGNAL(clicked()),this,SLOT(inputStrLeftBracket()));
    connect(buttonRightBracket,SIGNAL(clicked()),this,SLOT(inputStrRightBracket()));
    connect(buttonAdd,SIGNAL(clicked()),this,SLOT(inputAdd()));
    connect(buttonSubtract,SIGNAL(clicked()),this,SLOT(inputSubtract()));
    connect(buttonMultiply,SIGNAL(clicked()),this,SLOT(inputMultiply()));
    connect(buttonDivide,SIGNAL(clicked()),this,SLOT(inputDivide()));
    connect(buttonEqual,SIGNAL(clicked()),this,SLOT(equal()));
    connect(buttonClean,SIGNAL(clicked()),this,SLOT(clean()));
    connect(buttonDel,SIGNAL(clicked()),this,SLOT(del()));

    QGridLayout *keyLayout = new QGridLayout;
    keyLayout->addWidget(buttonLeftBracket,0,0);
    keyLayout->addWidget(buttonRightBracket,0,1);
    keyLayout->addWidget(buttonClean,0,2);
    keyLayout->addWidget(buttonDivide,0,3);
    keyLayout->addWidget(button7,1,0);
    keyLayout->addWidget(button8,1,1);
    keyLayout->addWidget(button9,1,2);
    keyLayout->addWidget(buttonMultiply,1,3);
    keyLayout->addWidget(button4,2,0);
    keyLayout->addWidget(button5,2,1);
    keyLayout->addWidget(button6,2,2);
    keyLayout->addWidget(buttonSubtract,2,3);
    keyLayout->addWidget(button1,3,0);
    keyLayout->addWidget(button2,3,1);
    keyLayout->addWidget(button3,3,2);
    keyLayout->addWidget(buttonAdd,3,3);
    keyLayout->addWidget(button0,4,0);
    keyLayout->addWidget(buttonPoint,4,1);
    keyLayout->addWidget(buttonDel,4,2);
    keyLayout->addWidget(buttonEqual,4,3);
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPalette pal;   // = buttonClean->palette();
    pal.setColor(QPalette::ButtonText,QColor(255,0,0));
    buttonClean->setPalette(pal);
    pal.setColor(QPalette::ButtonText,QColor(0,0,255));
    buttonEqual->setPalette(pal);
    screen.setStyleSheet("background-color:rgb(100,180,255)");  //设置样式表可改变部件颜色，背景色
    mainLayout->addWidget(&screen);
    mainLayout->addLayout(keyLayout);

    QWidget *mainWidget = new QWidget;

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Enter:
        equal();
        break;
    case Qt::Key_0:
        inputStr0();
        break;
    case Qt::Key_1:
        inputStr1();
        break;
    case Qt::Key_2:
        inputStr2();
        break;
    case Qt::Key_3:
        inputStr3();
        break;
    case Qt::Key_4:
        inputStr4();
        break;
    case Qt::Key_5:
        inputStr5();
        break;
    case Qt::Key_6:
        inputStr6();
        break;
    case Qt::Key_7:
        inputStr7();
        break;
    case Qt::Key_8:
        inputStr8();
        break;
    case Qt::Key_9:
        inputStr9();
        break;
    case 43:    //小键盘+
        inputAdd();
        break;
    case 45:    //小键盘-
        inputSubtract();
        break;
    case 47:    //小键盘/
        inputDivide();
        break;
    case 42:    //小键盘*
        inputMultiply();
        break;
    case 46:    //小键盘.
        inputStrPoint();
        break;
    case Qt::Key_Delete:
        clean();
        break;
    case Qt::Key_Backspace:
        del();
        break;
    }
}

int MainWindow::great(char c)
{
    if(c=='#')
        return 0;
    else if(c=='('||c==')')
        return 1;
    else if(c=='+'||c=='-')
        return 2;
    else
        return 3;
}

double MainWindow::caculate(char c, double n1, double n2){
    if(c=='+')
        return n1+n2;
    if(c=='-')
        return n1-n2;
    if(c=='*')
        return n1*n2;
    if(c=='/')
        return n1/n2;
}

void MainWindow::calculator()
{
    n=0, num1=0, num2=0, index=0;
    formula = inputStr.toStdString();
    formula = '#' + formula + '#';
    stack stackOfNum;
    stack stackOfChar;
    stackOfChar.push(formula[0]);
    for(int i=1;formula[i]!='\0';i++){
        //运算符操作
        if(formula[i]<'0'&&formula[i]!='.'){
            if(formula[i]=='('){
                stackOfChar.push(formula[i]);
                continue;
            }
            stackOfChar.getTop(topStr);
            if(great(formula[i])>great(topStr)) //当前元素优先级高则入栈
                stackOfChar.push(formula[i]);
            else if(topStr=='#'&&formula[i]=='#') break;
            else if(topStr=='('&&formula[i]==')') stackOfChar.pop();
            else if(great(formula[i])<=great(topStr)){	//当前元素优先级低则运算
                stackOfNum.getTop(num2);
                stackOfNum.pop();
                stackOfNum.getTop(num1);
                stackOfNum.pop();
                stackOfNum.push(caculate(topStr,num1,num2));
                stackOfChar.pop();
                i--;
            }
        }
        //运算数操作
        else{
            //整数部分
            if(formula[i]>='0'&&formula[i]<='9'){
                n *= 10;
                n += (formula[i]-'0');
            }
            //小数部分
            else if(formula[i]=='.') do{
                index++;
                n += (formula[++i]-'0')*pow(0.1,index);
            }while(formula[i+1]>='0');
            //数字入栈
            if(formula[i+1]<'0'&&formula[i+1]!='.'){
                stackOfNum.push(n);
                n=0;
            }
        }
    }
    //得到并输出结果
    stackOfNum.getTop(n);
    inputStr += " = " + QString::number(n);
}

MainWindow::~MainWindow()
{
    delete ui;
}

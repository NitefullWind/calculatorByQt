#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <string>
#include <QLabel>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include "stack.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    double n, num1, num2;
    int index, historicalCount, historicalList;
    char topStr;
    int great(char c);
    double caculate(char c, double n1, double n2);

    void keyPressEvent(QKeyEvent *event);

    void calculator();

    QString inputStr,historicalResult[100];
    string formula;
    QLabel screen;

    QAction *upAction, *downAction;

private slots:
    void inputStr0(){
        inputStr += '0';
        showResult();
    }
    void inputStr1(){
        inputStr += '1';
        showResult();
    }
    void inputStr2(){
        inputStr += '2';
        showResult();
    }
    void inputStr3(){
        inputStr += '3';
        showResult();
    }
    void inputStr4(){
        inputStr += '4';
        showResult();
    }
    void inputStr5(){
        inputStr += '5';
        showResult();
    }
    void inputStr6(){
        inputStr += '6';
        showResult();
    }
    void inputStr7(){
        inputStr += '7';
        showResult();
    }
    void inputStr8(){
        inputStr += '8';
        showResult();
    }
    void inputStr9(){
        inputStr += '9';
        showResult();
    }
    void inputStrPoint(){
        inputStr += '.';
        showResult();
    }
    void inputStrLeftBracket(){
        inputStr += '(';
        showResult();
    }
    void inputStrRightBracket(){
        inputStr += ')';
        showResult();
    }
    void inputAdd(){
        inputStr += '+';
        showResult();
    }
    void inputSubtract(){
        inputStr += '-';
        showResult();
    }
    void inputMultiply(){
        inputStr += '*';
        showResult();
    }
    void inputDivide(){
        inputStr += '/';
        showResult();
    }
    void equal(){
        calculator();
        showResult();
        historicalList = historicalCount;
        historicalResult[historicalCount++] = inputStr;
        inputStr.clear();
    }
    void showResult(){
        screen.setText("<h1>"+inputStr+"</h1>");
    }
    void clean(){
        inputStr.clear();
        showResult();
    }
    void del(){
        inputStr.chop(1);   //或者inputStr = inputStr.left(string.length() - 1);
        showResult();
    }
    void historyUp(){
        (historicalList>0) ? inputStr = historicalResult[--historicalList]: inputStr = "上面没有喽!";
        showResult();
        inputStr.clear();
    }
    void historyDown(){
        (historicalList<historicalCount) ? inputStr = historicalResult[historicalList++]: inputStr = "下面还没有呢!";
        showResult();
        inputStr.clear();
    }
    void aboutMessages();
};

#endif // MAINWINDOW_H

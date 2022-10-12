#include "mainWindow.h"
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include<bits/stdc++.h>

using namespace std;
mainWindow::mainWindow(){
    prevIsOperator = false;
    outputBox = new QLineEdit(tr(""));

    QPushButton *addition = new QPushButton(tr("+"));
    QPushButton *subtraction = new QPushButton(tr("-"));
    QPushButton *multiplication = new QPushButton(tr("*"));
    QPushButton *division = new QPushButton(tr("/"));
    
    
    QPushButton *point = new QPushButton(tr("."));
    QPushButton *clear = new QPushButton(tr("ac"));
    QPushButton *backSpace = new QPushButton(tr("<--"));
    QPushButton *execute = new QPushButton(tr("="));

    QPushButton *openBracket = new QPushButton(tr("("));
    QPushButton *closedBracket = new QPushButton(tr(")"));

    label = new QLabel(tr(""));

    QWidget *centralWidget = new QWidget;

    QPushButton *numbers[10];

    for(int i=0;i<=9;i++){
        numbers[i] = new QPushButton(QString::number(i));
    }


    connect(numbers[0],SIGNAL(clicked()),this,SLOT(zeroClicked()));
    connect(numbers[1],SIGNAL(clicked()),this,SLOT(oneClicked()));
    connect(numbers[2],SIGNAL(clicked()),this,SLOT(twoClicked()));
    connect(numbers[3],SIGNAL(clicked()),this,SLOT(threeClicked()));
    connect(numbers[4],SIGNAL(clicked()),this,SLOT(fourClicked()));
    connect(numbers[5],SIGNAL(clicked()),this,SLOT(fiveClicked()));
    connect(numbers[6],SIGNAL(clicked()),this,SLOT(sixClicked()));
    connect(numbers[7],SIGNAL(clicked()),this,SLOT(sevenClicked()));
    connect(numbers[8],SIGNAL(clicked()),this,SLOT(eightClicked()));
    connect(numbers[9],SIGNAL(clicked()),this,SLOT(nineClicked()));


    connect(addition,SIGNAL(clicked()),this,SLOT(additionClicked()));
    connect(subtraction,SIGNAL(clicked()),this,SLOT(subtractionClicked()));
    connect(multiplication,SIGNAL(clicked()),this,SLOT(multiplicationClicked()));
    connect(division,SIGNAL(clicked()),this,SLOT(divisionClicked()));
    connect(point,SIGNAL(clicked()),this,SLOT(pointClicked()));
    connect(clear,SIGNAL(clicked()),this,SLOT(clearClicked()));
    connect(backSpace,SIGNAL(clicked()),this,SLOT(backSpaceClicked()));
    connect(execute,SIGNAL(clicked()),this,SLOT(executeClicked()));
    connect(openBracket,SIGNAL(clicked()),this,SLOT(openBracketClicked()));
    connect(closedBracket,SIGNAL(clicked()),this,SLOT(closedBracketClicked()));


    QHBoxLayout *operationBox = new QHBoxLayout;

    operationBox->addWidget(addition);
    operationBox->addWidget(subtraction);
    operationBox->addWidget(multiplication);
    operationBox->addWidget(division);


    QHBoxLayout *row2 = new QHBoxLayout;
    
    row2->addWidget(backSpace);
    row2->addWidget(numbers[1]);
    row2->addWidget(numbers[2]);
    row2->addWidget(numbers[3]);

    QHBoxLayout *row3 = new QHBoxLayout;

    row3->addWidget(clear);
    row3->addWidget(numbers[4]);
    row3->addWidget(numbers[5]);
    row3->addWidget(numbers[6]);

    QHBoxLayout *row4 = new QHBoxLayout;

    row4->addWidget(point);
    row4->addWidget(numbers[7]);
    row4->addWidget(numbers[8]);
    row4->addWidget(numbers[9]);

    QHBoxLayout *row5 = new QHBoxLayout;

    row5->addWidget(openBracket);
    row5->addWidget(closedBracket);
    row5->addWidget(numbers[0]);
    row5->addWidget(execute);

    QVBoxLayout *fullLayout = new QVBoxLayout;

    fullLayout->addWidget(label);
    fullLayout->addWidget(outputBox);


    fullLayout->addLayout(operationBox);
    fullLayout->addLayout(row2);
    fullLayout->addLayout(row3);
    fullLayout->addLayout(row4);
    fullLayout->addLayout(row5);

    centralWidget->setLayout(fullLayout);

    setCentralWidget(centralWidget);

}






void mainWindow::zeroClicked(){

    QString x = "0";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::oneClicked(){

    QString x = "1";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::twoClicked(){

    QString x = "2";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::threeClicked(){

    QString x = "3";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::fourClicked(){

    QString x = "4";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
    cout<<prevIsOperator<<" ";
}
void mainWindow::fiveClicked(){

    QString x = "5";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::sixClicked(){

    QString x = "6";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::sevenClicked(){

    QString x = "7";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::eightClicked(){

    QString x = "8";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}
void mainWindow::nineClicked(){

    QString x = "9";
    outputBox->setText(outputBox->text() + x);
    prevIsOperator = false;
}



int mainWindow::precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

float mainWindow::applyOp(float a, float b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

float mainWindow::evaluate(string tokens){
    int i;
     
    stack <float> values;
     
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
        if(tokens[i] == ' ')
            continue;

        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
         
        else if(isdigit(tokens[i])||tokens[i]=='.'){
            float val = 0;
            bool flag = false;
            int afterpoint = 1;
.
            while(i < tokens.length() &&
                        (isdigit(tokens[i])||tokens[i]=='.'))
            {
                if(tokens[i]=='.'){
                    flag = true;
                    i++;
                    continue;
                }
                else if(flag==false){
                    val = (val*10) + (tokens[i]-'0');
                    i++;
                    cout<<val<<" ";
                } else if(flag==true){
                    val = val + ((float)(tokens[i]-'0'))/pow(10,afterpoint);
                    i++;
                    afterpoint++;
                    cout<<val<<" ";
                    cout<<"reached"<<" ";
                }
            }
             
            values.push(val);
             

              i--;
        }
         

        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                float val2 = values.top();
                values.pop();
                 
                float val1 = values.top();
                values.pop();
                 
                float op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            if(!ops.empty())
               ops.pop();
        }
         
        else
        {

            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                float val2 = values.top();
                values.pop();
                 
                float val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            ops.push(tokens[i]);
        }
    }
     

    while(!ops.empty()){
        float val2 = values.top();
        values.pop();
                 
        float val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    return values.top();
}




void mainWindow::additionClicked(){
    cout<<prevIsOperator<<" ";
    if(prevIsOperator==false){
        QString x = "+";
        outputBox->setText(outputBox->text() + x);
        pointRefresh = true;
    }
    prevIsOperator = true;
}
void mainWindow::subtractionClicked(){

    if(prevIsOperator==false){
        QString x = "-";
        outputBox->setText(outputBox->text() + x);
        pointRefresh = true;
    }
    prevIsOperator = true;
}
void mainWindow::multiplicationClicked(){

    if(prevIsOperator==false){
        QString x = "*";
        outputBox->setText(outputBox->text() + x);
        pointRefresh = true;
    }
    prevIsOperator = true;
}
void mainWindow::divisionClicked(){

    if(prevIsOperator==false){
        QString x = "/";
        outputBox->setText(outputBox->text() + x);
        pointRefresh = true;
    }
    prevIsOperator = true;
}
void mainWindow::pointClicked(){

    if(pointRefresh==true)
        outputBox->setText(outputBox->text() + tr("."));
    pointRefresh = false;

}
void mainWindow::clearClicked(){

    QString x = "";
    outputBox->setText(x);
    pointRefresh = true;
    prevIsOperator = false;
    label->setText(tr(""));
}
void mainWindow::backSpaceClicked(){
    QString text = outputBox->text();
    string s = text.toStdString();
    if(s[s.length()-1]=='.'){
        pointRefresh = true;
    }
    if(s[s.length()-1]=='+'||s[s.length()-1]=='-'||s[s.length()-1]=='*'||s[s.length()-1]=='/'){
        prevIsOperator = false;
    }
    text.chop(1);
    if (text.isEmpty()) {
        text = "";
    }
    outputBox->setText(text);
}
void mainWindow::executeClicked(){

    QString text = outputBox->text();

    string exp = text.toStdString();

    float res = evaluate(exp);

    outputBox->setText(QString::number(res));
    pointRefresh = true;
    prevIsOperator = false;

    label->setText(text);
}
void mainWindow::openBracketClicked(){

    QString x = "(";
    outputBox->setText(outputBox->text() + x);
    pointRefresh = true;
}
void mainWindow::closedBracketClicked(){

    QString x = ")";
    outputBox->setText(outputBox->text() + x);

}
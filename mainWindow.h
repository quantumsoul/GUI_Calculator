#include <QLineEdit>
#include <QMainWindow>
#include <QLabel>
#include<bits/stdc++.h>


using namespace std;
class mainWindow: public QMainWindow
{
    Q_OBJECT

    public:

        mainWindow();

        QLabel *label;
        QLineEdit *outputBox;
        bool pointRefresh;
        bool prevIsOperator;
    private slots:
        void zeroClicked();
        void oneClicked();
        void twoClicked();
        void threeClicked();
        void fourClicked();
        void fiveClicked();
        void sixClicked();
        void sevenClicked();
        void eightClicked();
        void nineClicked();


        void additionClicked();
        void subtractionClicked();
        void multiplicationClicked();
        void divisionClicked();
        void pointClicked();
        void clearClicked();
        void backSpaceClicked();
        void executeClicked();
        void openBracketClicked();
        void closedBracketClicked();


        int precedence(char op);
        float applyOp(float a, float b, char op);
        float evaluate(string tokens);
};
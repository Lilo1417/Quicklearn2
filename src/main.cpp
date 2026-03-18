
#include <QApplication>
#include <QPushButton>
#include <bits/stdc++.h>
#include <string>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    int testN=3;
    QString test = QString::number(testN);

    QPushButton button(test);
    button.resize(200, 60);
    button.show();

    return app.exec();
}


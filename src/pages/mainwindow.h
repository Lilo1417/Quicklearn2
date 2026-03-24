#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QVBoxLayout;
class QWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *m_centralWidget;
    QVBoxLayout *m_layout;
    QPushButton *m_button;
};

#endif // MAINWINDOW_H

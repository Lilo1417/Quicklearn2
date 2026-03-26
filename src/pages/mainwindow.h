#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class QPushButton;
class QVBoxLayout;
class QWidget;

class LernsetWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();

private:
    QWidget *m_centralWidget;
    QVBoxLayout *m_layout;
    QPushButton *m_button;
    std::unique_ptr<LernsetWindow> m_lernsetwindow;  
};

#endif // MAINWINDOW_H

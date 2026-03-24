#include "mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_centralWidget(new QWidget(this)),
      m_layout(new QVBoxLayout),
      m_button(new QPushButton("Click me", this))
{
    // Set up central widget and layout
    m_centralWidget->setLayout(m_layout);
    setCentralWidget(m_centralWidget);

    // Configure window
    setWindowTitle("My Qt App");
    resize(800, 600);

    // Add widgets to layout
    m_layout->addWidget(m_button);

    // Example: connect button
    connect(m_button, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Notification", "Test");
    });
}

MainWindow::~MainWindow() = default;

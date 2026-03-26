#include "mainwindow.h"
#include "lernsetwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <memory>
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_centralWidget(new QWidget(this)),
      m_layout(new QVBoxLayout),
      m_button(new QPushButton("Click me", this)) {
    // Set up central widget and layout
    m_centralWidget->setLayout(m_layout);
    setCentralWidget(m_centralWidget);
    connect(m_button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    // Configure window
    setWindowTitle("My Qt App");
    resize(800, 600);

    // Add widgets to layout
    m_layout->addWidget(m_button);
}
void MainWindow::onButtonClicked() {
    if (!m_lernsetwindow) {
        m_lernsetwindow = std::make_unique<LernsetWindow>(m_centralWidget);
        m_layout->addWidget(m_lernsetwindow.get());
    }
    m_lernsetwindow->show();  // Or raise() if already added
}

MainWindow::~MainWindow() = default;

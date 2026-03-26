#include "lernsetwindow.h"

LernsetWindow::LernsetWindow(QWidget *parent)
    : QWidget(parent)
{
    m_cardLabel = new QLabel("Click 'Flip' or use arrows", this);
    m_cardLabel->setAlignment(Qt::AlignCenter);
    m_cardLabel->setStyleSheet("QLabel { font-size: 24px; font-weight: bold; padding: 20px; border: 2px solid gray; border-radius: 10px; background: white; }");

    m_prevButton = new QPushButton("Previous", this);
    m_nextButton = new QPushButton("Next", this);
    m_flipButton = new QPushButton("Flip", this);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_cardLabel);
    layout->addWidget(m_flipButton);
    auto *navLayout = new QHBoxLayout;
    navLayout->addWidget(m_prevButton);
    navLayout->addStretch();
    navLayout->addWidget(m_nextButton);
    layout->addLayout(navLayout);

    connect(m_prevButton, &QPushButton::clicked, this, &LernsetWindow::prevCard);
    connect(m_nextButton, &QPushButton::clicked, this, &LernsetWindow::nextCard);
    connect(m_flipButton, &QPushButton::clicked, this, &LernsetWindow::flipCard);

    nextCard();  // Show first card
}

void LernsetWindow::nextCard()
{
    m_currentIndex = (m_currentIndex + 1) % m_fronts.size();
    m_isFront = true;
    m_cardLabel->setText(m_fronts[m_currentIndex]);
}

void LernsetWindow::prevCard()
{
    m_currentIndex = (m_currentIndex - 1 + m_fronts.size()) % m_fronts.size();
    m_isFront = true;
    m_cardLabel->setText(m_fronts[m_currentIndex]);
}

void LernsetWindow::flipCard()
{
    if (m_isFront) {
        m_cardLabel->setText(m_backs[m_currentIndex]);
        m_flipButton->setText("Unflip");
    } else {
        m_cardLabel->setText(m_fronts[m_currentIndex]);
        m_flipButton->setText("Flip");
    }
    m_isFront = !m_isFront;
}


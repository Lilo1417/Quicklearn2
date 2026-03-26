#ifndef LERNSETWINDOW_H
#define LERNSETWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class LernsetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LernsetWindow(QWidget *parent = nullptr);

public slots:
    void nextCard();
    void prevCard();
    void flipCard();

private:
    QLabel *m_cardLabel;
    QPushButton *m_prevButton;
    QPushButton *m_nextButton;
    QPushButton *m_flipButton;

    QStringList m_fronts = {"What is Qt?", "Capital of Switzerland?", "2 + 2 = ?"};
    QStringList m_backs = {"C++ GUI framework", "Bern", "4"};
    int m_currentIndex = 0;
    bool m_isFront = true;
};

#endif // LERNSETWINDOW_H


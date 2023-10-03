#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "game.h"

class QPushButton;
class QSpinBox;
class QGraphicsScene;
class QGraphicsView;
class QScrollBar;

class mainwidget : public QWidget
{
    Q_OBJECT
    QPushButton *btnGame;
    QSpinBox *spnDiskNum;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QScrollBar *scrollBar;
    void setupForm();
    QList<Log> *log;
public:
    mainwidget(QWidget *parent = nullptr);
    ~mainwidget();
    void drawPole(int rel, Stack *Pole);
    void resizeEvent(QResizeEvent * event) override;

public slots:
    void solve();
    void draw();
};

#endif // MAINWIDGET_H

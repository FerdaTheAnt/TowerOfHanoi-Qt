#include "mainwidget.h"
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScrollBar>
#include <QMessageBox>

mainwidget::mainwidget(QWidget *parent)
    : QWidget(parent)
{
    setupForm();
}

void mainwidget::setupForm()
{
    btnGame = new QPushButton(tr("&Solve"));
    spnDiskNum = new QSpinBox();
    spnDiskNum->setRange(1, 25);
    scene = new QGraphicsScene();
    view = new QGraphicsView();
    scrollBar = new QScrollBar(Qt::Horizontal);
    view->setScene(scene);
    log = new QList<Log>;
    QHBoxLayout *lBot = new QHBoxLayout;
    QVBoxLayout *lMain = new QVBoxLayout;
    lBot->addWidget(btnGame);
    lBot->addWidget(spnDiskNum);
    lMain->addWidget(view);
    lMain->addWidget(scrollBar);
    lMain->addLayout(lBot);
    this->setLayout(lMain);
    connect(btnGame, SIGNAL(clicked()), this, SLOT(solve()));
    connect(scrollBar, SIGNAL(valueChanged(int)), this, SLOT(draw()));
}

void mainwidget::solve()
{
    log->clear();
    int n = this->spnDiskNum->value();
    Stack * PoleA = new Stack(n);
    Stack * PoleB = new Stack(n);
    Stack * PoleC = new Stack(n);
    game(PoleA, PoleB, PoleC, n, log);
    scrollBar->setMaximum(log->count()-1);
    draw();
    delete PoleA;
    delete PoleB;
    delete PoleC;
}

void mainwidget::drawPole(int rel, Stack *Pole)
{
    int w = view->width();
    int h = view->height();
    int xpos = (rel+2)*w/4;
    int n = Pole->getCapacity();
    int dh = h/(n+10);
    int dw = 0;
    if(n!=0){
        dw = w/(4*n);
    }
    for(int i = 0; i<=Pole->getSp();i++){
        int cur = Pole->read(i);
        QGraphicsRectItem *disk = new QGraphicsRectItem();
        disk->setRect(xpos-cur*dw/2, h/2-i*dh, dw*cur, dh*9/10);
        disk->setPen(QColor::fromHsv(120, 200, 200));
        disk->setBrush(QColor::fromHsv(120, 120, 200));
        view->scene()->addItem(disk);
    }
}

void mainwidget::draw()
{
    view->scene()->clear();
    if(!log->isEmpty()){
        Log r = log->at(scrollBar->value());
        drawPole(-1, &r.A);
        drawPole(0, &r.B);
        drawPole(1, &r.C);
    }
}

void mainwidget::resizeEvent(QResizeEvent *event)
{
    draw();
    QWidget::resizeEvent(event);
}

mainwidget::~mainwidget()
{
    delete log;
}


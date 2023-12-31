﻿#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Game.h"

extern Game* game;
Enemy::Enemy(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);
    //setRotation(180);
    // connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move bullet down
    setPos(x(), y()+5);
    if (pos().y() > scene()->height())
    {
        // decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet deleted";
    }
}

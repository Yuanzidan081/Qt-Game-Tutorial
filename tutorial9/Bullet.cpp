﻿#include "Bullet.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h> // qSin, qCos, qTan

Bullet::Bullet(QGraphicsItem *parent)
{

    QPixmap image(":images/arrow.png");
    image = image.transformed(QTransform().rotate(180));

    //set graphics
    setPixmap(image);

    //connect a timer to move()
    QTimer* move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}

void Bullet::move()
{
    int STEP_SIZE = 30;
    double theta = rotation();//degrees
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);


}

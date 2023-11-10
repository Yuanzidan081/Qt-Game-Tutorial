#include "Tower.h"
#include "Bullet.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include <QTimer>
#include "Game.h"

extern Game* game;
// list of points: (1,0), (2,0), (3,1), (3,2), (2,3), (1,3), (0,2), (0,1)
Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set the garphics
    setPixmap(QPixmap(":/images/Tower.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
           << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 50;
    for (int i = 0, n = points.size(); i < n; ++i )
    {
        points[i] *= SCALE_FACTOR;
    }
    // create a polygon from these points
    QPolygonF polygon(points);

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(polygon, this);

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x() + pixmap().width()/2, y() + pixmap().height()/2);
    QLineF in(poly_center, tower_center);
    attack_area->setPos(x() + in.dx(), y() + in.dy());

    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(attack_target()));
    timer->start(1000);

    // set attack_dest
    attack_dest = QPointF(800, 0);

}

void Tower::attack_target()
{
    Bullet* bullet = new Bullet();
    bullet->setPos(x()+25, y()+25);

    QLineF in(QPointF(x()+25, y()+25), attack_dest);
    double angle = -1 * in.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

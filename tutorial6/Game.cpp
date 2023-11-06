#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"


Game::Game(QWidget *parent)
{
    // Create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800×600 instead of infinity by infinity

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // Create the player
    player = new Player();
    player->setRect(0, 0, 100, 100); // change the rect from 0×0 to 100×100 pixels
    player->setPos(width()/2, height() - player->rect().height());
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // Add the item to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    //show the view
    show();
}

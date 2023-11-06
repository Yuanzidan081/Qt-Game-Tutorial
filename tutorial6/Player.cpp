#include <Player.h>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

void Player::keyPressEvent(QKeyEvent* event)
{
  //qDebug() << "MyRect knows that you pressed a key";
  if (event->key() == Qt::Key_Left){
      if (pos().x() > 0)
        setPos(x()-10,y());
  }
  else if (event->key() == Qt::Key_Right){
      if (pos().x() + rect().width() < scene()->width())
        setPos(x()+10,y());
  }
  /*
   The origin is in the upper left corner,
   the positive direction of the y-axis is down
   and the positive direction of the x-axis is to the right
  */

  /*
   * we don't want the player move up and move down
   */
  /*
  else if (event->key() == Qt::Key_Up){
      setPos(x(),y()-10);
  }
  else if (event->key() == Qt::Key_Down){
      setPos(x(),y()+10);
  }
   */
  else if (event->key() == Qt::Key_Space){
      // Create a bullet
      Bullet* bullet = new Bullet();
      //qDebug() << "bullet created";
      bullet->setPos(x(),y());
      scene()->addItem(bullet);

  }
}

void Player::spawn()
{
    //create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

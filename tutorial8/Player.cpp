#include <Player.h>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Bullet.mp3"));

    // set graphics
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
  //qDebug() << "MyRect knows that you pressed a key";
  if (event->key() == Qt::Key_Left){
      if (pos().x() > 0)
        setPos(x()-10,y());
  }
  else if (event->key() == Qt::Key_Right){
      if (pos().x() + 100 < scene()->width())
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
      bullet->setPos(x() + 45,y());
      scene()->addItem(bullet);

      // play bulletsound
      if (bulletsound->state() == QMediaPlayer::PlayingState)
      {
          bulletsound->setPosition(0);
      }
      else if (bulletsound->state() == QMediaPlayer::StoppedState)
      {
          bulletsound->play();
      }

  }
}

void Player::spawn()
{
    //create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

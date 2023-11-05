#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

/*
Tutorial Topics:
- QGraphicScene's sceneRect
- QGraphicView's sceneRect
- QGraphicView coordinates vs QGraphicScene coordinates vs QGraphicitem coordinates
*/

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // Create a scene
  QGraphicsScene *scene = new QGraphicsScene();

  // Create an item to put into the scene
  MyRect *player = new MyRect();

  player->setRect(0, 0, 100, 100);

  // Add the item to the scene
  scene->addItem(player);

  // make rect focusable
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

  // Add a view
  // You can also write the code as following
  /*
   * QGraphicsView* View = new QGraphicsView();
   * View->setScene(scene);
   */
  QGraphicsView *View = new QGraphicsView(scene);

  View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  View->show();

  /*
   * These two lines of code make the origin of QGraphicsScene and QGraphicsView coincide
   * More information about coordinate of QGraphicsScene and QGraphicsView, see tutorial4-coordinates.png
   * After add these two lines of code, the effect can be seen in tutorial4-coordinates-adjust.png
   * and tutorial4-effect1.png
   */
  View->setFixedSize(800,600);
  scene->setSceneRect(0,0,800,600);
  /*
   * Rectangle in the upper left corner in tutorial4-effect1.png, add the following code
   * to set the position of the rectangle to be centred at the bottom, and the effect can
   * be seen in tutorial4-effect2.png
   */
  player->setPos(View->width()/2, View->height() - player->rect().height());
  return a.exec();
}

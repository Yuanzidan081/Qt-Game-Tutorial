#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

/*
Tutorial Topics:
- QTimer
- signals and slots (connect function)
- QObject and Q_OBJECT macro
*/

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // Create a scene
  QGraphicsScene *scene = new QGraphicsScene();

  // Create an item to put into the scene
  MyRect *rect = new MyRect();

  rect->setRect(0, 0, 100, 100);

  // Add the item to the scene
  scene->addItem(rect);

  // make rect focusable
  rect->setFlag(QGraphicsItem::ItemIsFocusable);
  rect->setFocus();

  // Add a view
  // You can also write the code as following
  /*
     QGraphicsView* View = new QGraphicsView();
     View->setScene(scene);
  */
  QGraphicsView *View = new QGraphicsView(scene);

  View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  View->show();
  return a.exec();
}

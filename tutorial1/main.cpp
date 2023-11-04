#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

/*
Prereqs:
- basic knowledge of C++ (pointers and memory management)
- very basic knowledge of Qt (Widgets)
Tutorial Topics:
- QGraphicsScene
- QGraphicsItem (QGraphicsRectItem)
- QGraphicsView
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();

    rect->setRect(0,0,100,100);

    // Add the item to the scene
    scene->addItem(rect);

    // Add a view
    // You can also write the code as following
    /*
       QGraphicsView* View = new QGraphicsView();
       View->setScene(scene);
    */
    QGraphicsView* View = new QGraphicsView(scene);


    View->show();
    return a.exec();
}

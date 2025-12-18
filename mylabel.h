#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPoint>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QFont>

class MyLabel : public QLabel
{
    Q_OBJECT
    private:
        QString _color; // La valeur de la couleur en hexa

        QPoint dragStartPosition; // Position de depart du drag

    public:
        MyLabel(QWidget * parent = 0);

        /// LOGIQUE DE STOCKAGE COULEUR
        void clear(); // Remet à zero le label (aucunes couleurs)
        QString color(); // Retourne la couleur actuelle dans _color
        void setColor(int nRed, int nGreen, int nBlue); // Remplace la couleur actuelle
        void setColor(QColor nColor); // Remplace la couleur actuelle (surcharge)
        void colorAdjust(); // Modifie le background et le texte du label
        ///

        /// FONCTIONS DU CLICK AND DRAW
        void mousePressEvent(QMouseEvent *event); // Si la souris click
        void mouseDoubleClickEvent(QMouseEvent * event); // Si la souris double click
        void mouseMoveEvent(QMouseEvent * event); // si la souris bouge
        void dragEnterEvent(QDragEnterEvent * event); // debut du glisser deposer
        void dropEvent(QDropEvent *event); // deposer
        ///

    signals:
        void clicked(); // Vers changerLabelParDefault
        void doubleClicked();// Vers conserver_couleur ou utiliser_couleur
        void changed(); // Vers modifParDrop
};

#endif // MYLABEL_H

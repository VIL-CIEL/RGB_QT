#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
    private:
        QString _color; // La valeur de la couleur en hexa

    public:
        MyLabel(QWidget * parent = 0);

        void clear(); // Remet à zero le label (aucunes couleurs)
        QString color(); // Retourne la couleur actuelle dans _color
        void setColor(int nRed, int nGreen, int nBlue); // Remplace la couleur actuelle
        void setColor(QColor nColor); // Remplace la couleur actuelle (surcharge)
        void colorAdjust(); // Modifie le background et le texte du label
};

#endif // MYLABEL_H

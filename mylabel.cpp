#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent)
{
}

void MyLabel::clear()
{
    QColor ClearColor(Qt::white);
    setColor(ClearColor);
    this->setText("");
}

QString MyLabel::color()
{
    return _color;
}

void MyLabel::setColor(int nRed, int nGreen, int nBlue)
{
    QColor nColor(nRed, nGreen, nBlue);
    _color = nColor.name();
    colorAdjust();
}

void MyLabel::setColor(QColor nColor)
{
    _color = nColor.name();
    colorAdjust();
}

void MyLabel::colorAdjust()
{
    // Recupère la couleur actuelle
    QPalette palette;
    QColor currentColor(_color);
    //

    // Attribue la couleur au fond du label couleur
    this->setAutoFillBackground(true);
    palette.setColor(QPalette::Window, currentColor);
    this->setPalette(palette);
    //

    this->setText(currentColor.name()); // Attribue le code hexa au texte du label couleur

}

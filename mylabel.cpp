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

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragStartPosition = event->pos();
        emit clicked();
    }
}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) emit doubleClicked();
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (_color.isEmpty()) return;
    if (!(event->buttons() & Qt::LeftButton))return;
    if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance()) return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    QPixmap pixmap(this->width(),this->height());
    QPainter painter;
    painter.begin(&pixmap);
    painter.fillRect(pixmap.rect(), QColor(_color));
    painter.setPen(QPen(Qt::black, 4));
    painter.setFont(QFont("Courrier New", 12, QFont::Bold));
    painter.drawText(pixmap.rect(), Qt::AlignCenter, _color);
    painter.end();
    drag->setPixmap(pixmap);

    mimeData->setText(_color);
    drag->setMimeData(mimeData);
    drag->exec(Qt::CopyAction);
}

void MyLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain")) event->acceptProposedAction();
}

void MyLabel::dropEvent(QDropEvent *event)
{
    this->setColor(QColor(event->mimeData()->text()));
    emit changed();
    event->acceptProposedAction();
}

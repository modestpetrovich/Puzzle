#include "picture.h"
#include "pieces.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>

Picture::Picture(int imageSize, QWidget *parent)
    : QWidget(parent), m_ImageSize(imageSize)
{
    setAcceptDrops(true);
    setMinimumSize(m_ImageSize, m_ImageSize);
    setMaximumSize(m_ImageSize, m_ImageSize);
}

void Picture::dragLeaveEvent(QDragLeaveEvent *event)
{
    QRect updateRect = highlightedRect;
    highlightedRect = QRect();
    update(updateRect);
    event->accept();
}

int Picture::findPiece(const QRect &pieceRect) const
{
    for (int i = 0, size = pieces.size(); i < size; ++i) {
        if (pieces.at(i).rect == pieceRect)
            return i;
    }
    return -1;
}

void Picture::mousePressEvent(QMouseEvent *event)
{
    QRect square = targetSquare(event->pos());
    const int found = findPiece(square);

    if (found == -1)
        return;

    Piece piece = pieces.takeAt(found);

    if (piece.location == square.topLeft() / pieceSize())
        inPlace--;

    update(square);

    QByteArray itemData;

}

void Picture::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), Qt::white);

    if (highlightedRect.isValid()) {
        painter.setBrush(QColor("#ffcccc"));
        painter.setPen(Qt::NoPen);
        painter.drawRect(highlightedRect.adjusted(0, 0, 1, 1));
    }

    for (const Piece &piece : pieces)
        painter.drawPixmap(piece.rect, piece.pixmap);
}

const QRect Picture::targetSquare(const QPoint &position) const
{
    return QRect(position / pieceSize() * pieceSize(),
                 QSize(pieceSize(), pieceSize()));
}

int Picture::pieceSize() const
{
    return m_ImageSize / 10;
}

int Picture::imageSize() const
{
    return m_ImageSize;
}

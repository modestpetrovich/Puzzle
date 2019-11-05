#include "puzzlewidget.h"
#include "pieceslist.h"

PuzzleWidget::PuzzleWidget(int imageSize, QWidget *parent)
    : QWidget(parent), ImageSize(imageSize)
{
    setAcceptDrops(true);
    setMinimumSize(ImageSize, ImageSize);
    setMaximumSize(ImageSize, ImageSize);
}
void PuzzleWidget::clear()
{
    pieces.clear();
    highlightedRect = QRect();
    inPlace = 0;
    update();
}
const QRect PuzzleWidget::targetSquare(const QPoint &position) const
{
    return QRect(position / pieceSize() * pieceSize(),
                 QSize(pieceSize(), pieceSize()));
}

int PuzzleWidget::pieceSize() const
{
    return ImageSize / 10;
}

int PuzzleWidget::imageSize() const
{
    return _ImageSize;
}

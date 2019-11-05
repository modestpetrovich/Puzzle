#ifndef PIECESLIST_H
#define PIECESLIST_H

#include <QListWidget>

class PiecesList : public QListWidget
{
    Q_OBJECT

public:
    PiecesList(int pieceSize, QWidget *parent = nullptr);
    void addPiece(const QPixmap &pixmap, const QPoint &location);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void startDrag(Qt::DropActions supportedActions);

    int PieceSize;
};

#endif // PIECESLIST_H

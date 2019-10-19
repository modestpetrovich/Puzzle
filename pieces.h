#ifndef PIECESLIST_H
#define PIECESLIST_H

#include <QListWidget>

class Pieces : public QListWidget
{
    Q_OBJECT

public:
    explicit Pieces(int pieceSize, QWidget *parent = nullptr);
    void addPiece(const QPixmap &pixmap, const QPoint &location);

    static QString puzzleMimeType() { return QStringLiteral("image/x-puzzle-piece"); }

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    //void dropEvent(QDropEvent *event) override;
    //void startDrag(Qt::DropActions supportedActions) override;
protected:
    int m_PieceSize;
};

#endif // PIECES_H

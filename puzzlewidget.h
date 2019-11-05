#ifndef PUZZLEWIDGET_H
#define PUZZLEWIDGET_H

#include <QPoint>
#include <QPixmap>
#include <QVector>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
class QMouseEvent;
QT_END_NAMESPACE

class PuzzleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PuzzleWidget(int imageSize, QWidget *parent = nullptr);
    void clear();
    int pieceSize() const;
    int imageSize() const;

signals:
    void puzzleCompleted();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    struct Piece {
        QPixmap pixmap;
        QRect rect;
        QPoint location;
    };

    int findPiece(const QRect &pieceRect) const;
    const QRect targetSquare(const QPoint &position) const;
    QVector<Piece> pieces;
    QRect highlightedRect;
    int inPlace;
    int m_ImageSize;
};

#endif // PUZZLEWIDGET_H

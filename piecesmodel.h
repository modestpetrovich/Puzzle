#ifndef PIECESLIST_H
#define PIECESLIST_H

#include <QAbstractListModel>
#include <QList>
#include <QPixmap>
#include <QPoint>
#include <QStringList>

class QMimeData;

class PiecesModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PiecesModel(int pieceSize, QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;

    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
                      int row, int column, const QModelIndex &parent) override;
    QMimeData *mimeData(const QModelIndexList &indexes) const override;
    QStringList mimeTypes() const override;
    int rowCount(const QModelIndex &parent) const override;
    Qt::DropActions supportedDropActions() const override;

    void addPiece(const QPixmap &pixmap, const QPoint &location);
    void addPieces(const QPixmap& pixmap);

private:
    QList<QPoint> locations;
    QList<QPixmap> pixmaps;

    int m_PieceSize;
};

#endif // PIECESLIST_H


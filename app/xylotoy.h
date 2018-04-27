#ifndef XYLOTOY_H
#define XYLOTOY_H

#include <QObject>
#include "lib/misulib/comm/isender.h"
#include "lib/misulib/comm/libofqf/qoscserver.h"

class Xylotoy : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject *> playFields MEMBER _playFields NOTIFY playFieldsChanged)
    Q_PROPERTY(int nPlayFields READ nPlayFields NOTIFY playFieldsChanged)

public:
    explicit Xylotoy(QObject *parent = nullptr);

    int nPlayFields();

signals:
    void playFieldsChanged();

public slots:
    void onOscData(QString path, QList<QVariant> data);

private:
    QList<QObject *>    _playFields;
    QList<int>          _pitches;
    ISender *           _out;
    QOscServer *        _in;

};

#endif // XYLOTOY_H

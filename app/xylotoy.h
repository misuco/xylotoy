#ifndef XYLOTOY_H
#define XYLOTOY_H

#include <QObject>
#include "lib/misulib/widgets/core/playarea.h"
#include "lib/misulib/comm/isender.h"
#include "lib/misulib/comm/libofqf/qoscserver.h"

class Xylotoy : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* playArea MEMBER _playArea CONSTANT)
    Q_PROPERTY(QObject* touchHistory MEMBER _touchHistory CONSTANT)

public:
    explicit Xylotoy(QObject *parent = nullptr);

public slots:
    void onOscData(QString path, QList<QVariant> data, QHostAddress src_adr, quint16 src_port);

private:
    MasterSender *  _out;
    TouchHistory *  _touchHistory;
    PlayArea *      _playArea;
    QOscServer *    _in;
    QList<bool>     _scale;
    int             _receivedScaleId;

};

#endif // XYLOTOY_H

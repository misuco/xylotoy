#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <QObject>
#include <QColor>
#include "lib/misulib/models/freqtriple.h"
#include "lib/misulib/comm/isender.h"

class PlayField : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor color MEMBER _color NOTIFY colorChanged)

public:
    explicit PlayField(int pitch, ISender *out, QObject *parent = nullptr);

    Q_INVOKABLE void onPressed();
    Q_INVOKABLE void onReleased();

    void setOct(int o);

signals:
    void colorChanged();

private:
    FreqTriple *    _freq;
    QColor          _color;
    ISender *       _out;
    int             _currentVoiceId;
    static int      _nextVoiceId;
};

#endif // PLAYFIELD_H

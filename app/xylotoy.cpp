#include "xylotoy.h"
#include "lib/misulib/comm/sendermobilesynth.h"

Xylotoy::Xylotoy(QObject *parent) : QObject(parent)
{
    _out = new MasterSender();
    _out->addSender(new SenderMobileSynth());

    _in = new QOscServer(3150,this);

    connect(_in,SIGNAL(oscData(QString,QList<QVariant>)),this,SLOT(onOscData(QString,QList<QVariant>)));

    _playArea = new PlayArea(_out, this);
    QList<bool> scale;
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    _playArea->onSetScale(0,scale);
}

void Xylotoy::onOscData(QString path, QList<QVariant> data)
{
    qDebug() << path << " " << data;
}

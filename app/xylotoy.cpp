#include "xylotoy.h"
#include "lib/misulib/comm/sendermobilesynth.h"

Xylotoy::Xylotoy(QObject *parent) : QObject(parent),
    _out(new MasterSender(this)),
    _touchHistory(new TouchHistory(this)),
    _playArea(new PlayArea(_out, _touchHistory, this)),
    _in(new QOscServer(3150,this)),
    _receivedScaleId(0)
{
    _out->addSenderThread(new SenderMobileSynth());
    connect(_in,SIGNAL(oscData(QString,QList<QVariant>,QHostAddress,quint16)),this,SLOT(onOscData(QString,QList<QVariant>,QHostAddress,quint16)));

    _scale.append(false);
    _scale.append(true);
    _scale.append(false);
    _scale.append(true);
    _scale.append(true);
    _scale.append(false);
    _scale.append(true);
    _scale.append(false);
    _scale.append(true);
    _scale.append(false);
    _scale.append(true);
    _playArea->onSetScale(0,_scale);
}

void Xylotoy::onOscData(QString path, QList<QVariant> data, QHostAddress src_adr, quint16 src_port)
{
    qDebug() << src_adr << " " << src_port << " " << path << " " << data;

    // is it a valid heartbeat?
    if(path=="/hb" && data.size()>2) {

        // has this scale not yet been receiver?
        if(data.at(1).toInt()>_receivedScaleId) {

            // reset current scale
            for(int i=0;i<_scale.size();i++) {
                _scale[i]=false;
            }

            // set current scale according to received scale
            for(int i=3;i<data.size();i++) {
                _scale[data.at(i).toInt()]=true;
            }
            _playArea->onSetScale(data.at(2).toInt(),_scale);
        }
    }
}

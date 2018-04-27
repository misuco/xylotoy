#include "xylotoy.h"
#include "playfield.h"
#include "lib/misulib/comm/sendermobilesynth.h"

Xylotoy::Xylotoy(QObject *parent) : QObject(parent)
{
    _out = new SenderMobileSynth();
    _in = new QOscServer(3150,this);

    connect(_in,SIGNAL(oscData(QString,QList<QVariant>)),this,SLOT(onOscData(QString,QList<QVariant>)));

    for(int i=0;i<12;i++) {
        int rootNote=i;
        _pitches.append(rootNote);
    }

    _playFields.append(new PlayField(_pitches.at(0),_out,this));
    _playFields.append(new PlayField(_pitches.at(2),_out,this));
    _playFields.append(new PlayField(_pitches.at(4),_out,this));
    _playFields.append(new PlayField(_pitches.at(5),_out,this));
    _playFields.append(new PlayField(_pitches.at(7),_out,this));
    _playFields.append(new PlayField(_pitches.at(9),_out,this));
    _playFields.append(new PlayField(_pitches.at(11),_out,this));
    PlayField * p =new PlayField(_pitches.at(0),_out,this);
    p->setOct(7);
    _playFields.append(p);

    emit playFieldsChanged();
}

int Xylotoy::nPlayFields()
{
    return _playFields.size();
}

void Xylotoy::onOscData(QString path, QList<QVariant> data)
{

}

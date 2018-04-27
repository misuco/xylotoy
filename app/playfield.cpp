#include <QDebug>
#include "playfield.h"

int PlayField::_nextVoiceId = 1;

PlayField::PlayField(int pitch, ISender * out, QObject *parent) : QObject(parent),
  _out(out),
  _currentVoiceId(0)
{
    _freq=new FreqTriple(pitch,this);
    _freq->setOct(6);
    _color = QColor::fromHsvF(_freq->getHue(),0.8,0.4);
}

void PlayField::onPressed()
{
    if(_currentVoiceId==0) {
        _currentVoiceId = _nextVoiceId++;
        _out->noteOn(_currentVoiceId,_freq->getFreq(),_freq->getMidinote(),_freq->getPitch(),127);
        _color = QColor::fromHsvF(_freq->getHue(),0.8,0.8);
        emit colorChanged();
    }
}

void PlayField::onReleased()
{
    _out->noteOff(_currentVoiceId);
    _currentVoiceId=0;
    _color = QColor::fromHsvF(_freq->getHue(),0.8,0.4);
    emit colorChanged();
}

void PlayField::setOct(int o)
{
    _freq->setOct(o);
}

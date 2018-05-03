QT += quick multimedia
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += lib/mobilesynth

SOURCES += main.cpp \
    lib/mobilesynth/synth/controller.cpp \
    lib/mobilesynth/synth/envelope.cpp \
    lib/mobilesynth/synth/filter.cpp \
    lib/mobilesynth/synth/key_stack.cpp \
    lib/mobilesynth/synth/lag_processor.cpp \
    lib/mobilesynth/synth/modulation.cpp \
    lib/mobilesynth/synth/oscillator.cpp \
    lib/mobilesynth/synth/parameter.cpp \
    lib/mobilesynth/mobilesynthqt52.cpp \
    app/xylotoy.cpp \
    lib/misulib/comm/sendermobilesynth.cpp \
    lib/misulib/comm/libofqf/qoscserver.cpp \
    lib/misulib/comm/libofqf/qosctypes.cpp \
    lib/misulib/models/freqtriple.cpp \
    lib/misulib/widgets/core/playarea.cpp \
    lib/misulib/models/playfield.cpp \
    lib/misulib/comm/mastersender.cpp \
    lib/misulib/widgets/core/touchhistory.cpp \
    lib/misulib/models/touchhistoryevent.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    lib/mobilesynth/synth/controller.h \
    lib/mobilesynth/synth/envelope.h \
    lib/mobilesynth/synth/filter.h \
    lib/mobilesynth/synth/key_stack.h \
    lib/mobilesynth/synth/lag_processor.h \
    lib/mobilesynth/synth/modulation.h \
    lib/mobilesynth/synth/oscillator.h \
    lib/mobilesynth/synth/parameter.h \
    lib/mobilesynth/synth/test_util.h \
    lib/mobilesynth/AudioOutput.h \
    lib/mobilesynth/mobilesynthqt52.h \
    lib/mobilesynth/mobilesynthViewControllerRc1.h \
    lib/mobilesynth/mobilesynthviewcontrollerrc1.hpp \
    app/xylotoy.h \
    lib/misulib/comm/isender.h \
    lib/misulib/comm/sendermobilesynth.h \
    lib/misulib/comm/libofqf/qoscserver.h \
    lib/misulib/comm/libofqf/qoscserverinterface.h \
    lib/misulib/comm/libofqf/qosctypes.h \
    lib/misulib/models/freqtriple.h \
    lib/misulib/widgets/core/playarea.h \
    lib/misulib/models/playfield.h \
    lib/misulib/comm/mastersender.h \
    lib/misulib/widgets/core/touchhistory.h \
    lib/misulib/models/touchhistoryevent.h

OBJECTIVE_SOURCES += \
    lib/mobilesynth/mobilesynthViewControllerRc1.mm \
    lib/mobilesynth/AudioOutput.m \

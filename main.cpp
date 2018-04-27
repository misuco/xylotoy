#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "app/xylotoy.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QObject * xylotoy=new Xylotoy();

    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("app", xylotoy);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    int returnCode = app.exec();
    return returnCode;

}

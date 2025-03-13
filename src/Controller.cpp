#include "Controller.h"
#include <QDebug>
#include <QQmlContext>

Controller::Controller(QQmlApplicationEngine *engine, QObject *parent)
    : QObject(parent), m_engine(engine)
{
    // Expose the Controller instance to QML first
    m_engine->rootContext()->setContextProperty("controller", this);

    // Load the QML file after setting the context property
    m_engine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    // Ensure the QML file loads correctly
    if (m_engine->rootObjects().isEmpty()) {
        qCritical() << "Failed to load QML file.";
        return;
    }

    // Get the root object of the QML application
    QObject *rootObject = m_engine->rootObjects().first();

    // Connect the QML signal "buttonPressed" to the C++ slot "onButtonClicked"
    if (rootObject) {
        connect(rootObject, SIGNAL(buttonPressed()), this, SLOT(onButtonClicked()));
    } else {
        qCritical() << "Root object is null.";
    }
}


Controller::~Controller()
{
    // Destructor definition (even if empty)
    // This allows the MOC to handle the class correctly.
}

QString Controller::message() const
{
    return m_message;
}

void Controller::setMessage(const QString &message)
{
    if (m_message != message) {
        m_message = message;

        qDebug() << "Controller::setMessage - emit messageChanged signal";
        emit messageChanged();  // Notify QML about the change
    }
}

void Controller::onButtonClicked()
{
    qDebug() << "Button clicked! Signal received in Controller.";
    setMessage("Button clicked!");  // Update the message property
}

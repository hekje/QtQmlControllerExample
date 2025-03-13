#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

class Controller : public QObject
{
    Q_OBJECT  // This macro enables meta-object features like signals and slots
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Controller(QQmlApplicationEngine *engine, QObject *parent = nullptr);
    ~Controller();  // Destructor declaration

    QString message() const;
    void setMessage(const QString &message);

signals:
    void messageChanged();

public slots:
    void onButtonClicked();  // Slot to handle button click

private:
    QQmlApplicationEngine *m_engine; // Engine reference
    QString m_message;
};

#endif // CONTROLLER_H

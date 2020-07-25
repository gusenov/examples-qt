#ifndef QML_LIVE_H
#define QML_LIVE_H

#include "livenodeengine.h"
#include "remotereceiver.h"

class LiveNodeEngineRunner {
public:
    static LiveNodeEngineRunner& GetInstance() {
        static LiveNodeEngineRunner instance;
        return instance;
    }

    void Run(QQmlApplicationEngine& engine, QUrl const& qmlFile) {
        // Let QmlLive know your runtime
        m_node.setQmlEngine(&engine);

        // Allow it to display QML components with non-QQuickWindow root object
        m_fallbackView = new QQuickView(&engine, nullptr);
        m_node.setFallbackView(m_fallbackView);

        // Tell it where file updates should be stored relative to
        m_node.setWorkspace(SRCDIR,
                          LiveNodeEngine::AllowUpdates | LiveNodeEngine::UpdatesAsOverlay);

        // Listen to IPC call from remote QmlLive Bench
        m_receiver.registerNode(&m_node);
        m_receiver.listen(10234);
        // Открыть порт 10234 и ждать подключения от QML Live Bench.
        // Если подключения не будет, то приложение будет выполняться в обычном порядке.

        m_window = qobject_cast<QQuickWindow *>(engine.rootObjects().first());

        // Advanced use: let it know the initially loaded QML component (do this
        // only after registering to receiver!)
        m_node.usePreloadedDocument(qmlFile.toString(), m_window, m_warnings);
    }

    LiveNodeEngineRunner(LiveNodeEngineRunner const&) = delete;
    LiveNodeEngineRunner const& operator=(LiveNodeEngineRunner const &) = delete;

    LiveNodeEngineRunner(LiveNodeEngineRunner&&) = delete;
    LiveNodeEngineRunner& operator=(LiveNodeEngineRunner&&) = delete;

private:
    LiveNodeEngine m_node;
    QQuickView *m_fallbackView = nullptr;
    RemoteReceiver m_receiver;
    QQuickWindow *m_window = nullptr;
    QList<QQmlError> m_warnings;

    LiveNodeEngineRunner() = default;

    ~LiveNodeEngineRunner() {
    }
};

#endif  // QML_LIVE_H

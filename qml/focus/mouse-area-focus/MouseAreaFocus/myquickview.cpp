#include "myquickview.h"
#include <QDebug>

MyQuickView::MyQuickView()
{
    // qDebug() << this << "isWindowType =" << this->isWindowType();
    // QQuickView(0x7fef0a588d60, visibility=QWindow::Hidden, flags=QFlags<Qt::WindowType>(Window), geometry=0,0 0x0)
    //     isWindowType = true

    auto win = dynamic_cast<QWindow*>(this);
    win->setFlags(win->flags() | Qt::WindowStaysOnTopHint);
    // https://amin-ahmadi.com/2016/06/20/how-to-make-your-window-stay-always-on-top/

    // https://doc.qt.io/qt-5/qwindow.html#focusObjectChanged
    connect(win,
            QOverload<QObject *>::of(&QWindow::focusObjectChanged),
            [](QObject *object)
    {
        qDebug() << "QWindow::focusObjectChanged = " << object;
    });
}

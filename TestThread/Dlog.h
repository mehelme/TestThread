#ifndef DLOG_H
#define DLOG_H

#include <QDebug>
#include <QThread>

#define DLOGPF qDebug() << __PRETTY_FUNCTION__ << QThread::currentThread()


#endif // DLOG_H

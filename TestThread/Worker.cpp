#include <QTimer>
#include <QApplication>
#include <QDateTime>
#include "Worker.h"
#include "Dlog.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
	DLOGPF;
}

Worker::~Worker()
{
	DLOGPF;
}

void Worker::init()
{
	DLOGPF;
	t = new QTimer(this);
	t->setInterval(1000);
	connect(t, &QTimer::timeout, [=] {
		emit jobProgress(jobCount--);
		if (jobCount == 0)
			stopJob();
	});
	emit initialized();
}

void Worker::futureStart(QFutureInterface<void> &future)
{
	DLOGPF;
	int count = 10;
	for (int i = 0; i != count; ++i) {
		future.setProgressValue(100.0*i/count);
		QThread::sleep(1);
		if (future.isCanceled())
			break;
	}
}

void Worker::start(int count)
{
	DLOGPF;
	jobCount = count;
	t->start();
}

void Worker::stop()
{
	DLOGPF;
    stopJob();
}

void Worker::startT(int t)
{
    DLOGPF << t;
}

void Worker::stopJob()
{
	if (!t->isActive()) return;
	DLOGPF;
	t->stop();
	emit jobFinished();
}


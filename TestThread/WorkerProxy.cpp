#include <QThread>
#include "WorkerProxy.h"
#include "Dlog.h"

WorkerProxy::WorkerProxy(QObject *parent) : Worker(parent)
{
	DLOGPF;

	fWorkerThread = new QThread(this);
	fWorker = new Worker();
	fWorker->moveToThread(fWorkerThread);

	// Команды к потоку
	connect(this, &WorkerProxy::p_init, fWorker, &Worker::init);
	connect(this, &WorkerProxy::p_start, fWorker, &Worker::start);
	connect(this, &WorkerProxy::p_stop, fWorker, &Worker::stop);

	// Сигналы от потока
	connect(fWorker, &Worker::initialized, this, &WorkerProxy::initialized);
	connect(fWorker, &Worker::started, this, &WorkerProxy::started);
	connect(fWorker, &Worker::jobProgress, this, &WorkerProxy::jobProgress);
	connect(fWorker, &Worker::jobFinished, this, &WorkerProxy::jobFinished);

	// Удаление класса, живущего в потоке
	connect(fWorkerThread, &QThread::finished, fWorker, &QObject::deleteLater);
	fWorkerThread->start();
	emit p_init();
}

WorkerProxy::~WorkerProxy()
{
	DLOGPF;
	fWorkerThread->quit();
	fWorkerThread->wait();
}

void WorkerProxy::start(int count)
{
	DLOGPF;
	emit p_start(count);
}

void WorkerProxy::stop()
{
	DLOGPF;
	emit p_stop();
}


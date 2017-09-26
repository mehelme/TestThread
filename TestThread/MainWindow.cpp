#include <QtConcurrent>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "WorkerProxy.h"
#include "Dlog.h"
#include "runextensions.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    if (!fWorkerProxy) {
        fWorkerProxy = new WorkerProxy(this);
        connect(fWorkerProxy, &WorkerProxy::initialized, [] { qDebug() << "INITIALIZED" ; });
        connect(fWorkerProxy, &WorkerProxy::started, [] { qDebug() << "JOB STARTED" ; });
        connect(fWorkerProxy, &WorkerProxy::jobProgress, [](int i) { qDebug() << "JOB PROGRESS" << i; });
        connect(fWorkerProxy, &WorkerProxy::jobFinished, [] { qDebug() << "JOB FINISHED" ; });
    }
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pbStart_clicked()
{
	DLOGPF;
	fWorkerProxy->start(10);
}

void MainWindow::on_pbStop_clicked()
{
	DLOGPF;
	fWorkerProxy->stop();
}

void MainWindow::on_pbStartFuture_clicked()
{
	DLOGPF;
	Worker *w = new Worker();
	if (!fW) {
		fW = new QFutureWatcher<void>();
		connect(fW, &QFutureWatcher<void>::finished, [w] { qDebug() << "FW FINISHED"; w->deleteLater(); });
		connect(fW, &QFutureWatcher<void>::canceled, [] { qDebug() << "FW CANCELED"; });
		connect(fW, &QFutureWatcher<void>::progressValueChanged, [](int i) { qDebug() << "FW PROGRESS" << i << "%"; });
	}
	connect(w, &WorkerProxy::jobProgress, [](int i) { qDebug() << "JOB PROGRESS" << i; });
	fW->setFuture(QtConcurrent::run(&Worker::futureStart));
}

void MainWindow::on_pbStopFuture_clicked()
{
	if (!fW) return;
	fW->cancel();
}

void MainWindow::on_pbStartT_clicked()
{
    DLOGPF;
    fWorkerProxy->startT(qrand());
}

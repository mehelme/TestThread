#pragma once

#include "Worker.h"

// Класс RunnerManThreadProxy живет в основном потоке, а RunnerMan в другом
// RunnerManThreadProxy наследник RunnerMan только для убобства (не переписывать сигналы)

class WorkerProxy : public Worker
{
	Q_OBJECT
public:
	explicit WorkerProxy(QObject *parent = 0);

	~WorkerProxy();

public slots:

	void start(int count) override;
	void stop() override;

signals:

	// Сигналы с префиксом p_ - приватные, используются самим классом для отправки команд к потоку
	void p_init();
	void p_start(int count);
	void p_stop();

private:

	QThread* fWorkerThread;
	Worker* fWorker;
};

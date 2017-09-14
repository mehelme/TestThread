#pragma once

#include <QObject>
#include <QFuture>
#include <QFutureWatcher>

class QTimer;
class WorkerProxy;

// Класс, живущий в другом потоке и выполняющий некие действия

class Worker : public QObject
{
	Q_OBJECT
public:

	explicit Worker(QObject *parent = 0);

	~Worker();

signals:

	void initialized(); // Сигнал выполнения инициализации в другом потоке: создание объектов этого потока

	void started(); // Работа начата

	void jobProgress(int i);  // Прогресс работы

	void jobFinished(); // Работа завершена

public slots:

	// Инициализация
	void init();

	// Для вызова QtConcurent
	static void futureStart(QFutureInterface<void> &future);

	// Выполнить работу
	virtual void start(int count);

	// Остановить работу
	virtual void stop();

private:

	// Пример работы
	QTimer* t;
	int jobCount;
	void stopJob();
};

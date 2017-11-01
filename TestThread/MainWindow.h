#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFutureWatcher>

class WorkerProxy;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pbStart_clicked();

	void on_pbStop_clicked();

	void on_pbStartFuture_clicked();

	void on_pbStopFuture_clicked();

    void on_pbStartT_clicked();

    void on_pbDlog_clicked();

private:
	Ui::MainWindow *ui;

	WorkerProxy* fWorkerProxy = nullptr;
	QFutureWatcher<void>* fW = nullptr;
};

#endif // MAINWINDOW_H

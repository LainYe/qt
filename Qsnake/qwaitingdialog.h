
#ifndef QWAITTINGDIALOG_H
#define QWAITTINGDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QThread>
#include <QTimer>

class QWaitingDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QWaitingDialog(QWidget *parent = nullptr);

    void Run(int nStartValue);

signals:

public slots:
    void on_timer_timeout();

private:
    QLabel*             m_pLabel;
    QTimer*             m_pTimer;
    int                 m_nStartValue;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent* event);
};


#endif // QWAITTINGDIALOG_H

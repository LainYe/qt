#include "qwaitingdialog.h"
#include <QPainter>
#include <QVBoxLayout>

QWaitingDialog::QWaitingDialog(QWidget *parent) : QDialog(parent)
    , m_nStartValue(0)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

    // 全透明
    setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout* pVBoxLayout = new QVBoxLayout(this);

    m_pLabel = new QLabel();
    pVBoxLayout->addWidget(m_pLabel);

    m_pLabel->setText("");
    m_pLabel->setAlignment(Qt::AlignCenter);

    QString strStyle = "QLabel{"
                       "font-family: \"Microsoft YaHei\";"
                       "font-size: 128px;"
                       "color: rgb(50, 50, 50, 180);"
                       "}";

    m_pLabel->setStyleSheet(strStyle);

    m_pTimer = new QTimer(this);
    connect(m_pTimer, &QTimer::timeout, this, &QWaitingDialog::on_timer_timeout);
    m_pTimer->setInterval(1000);
}

void QWaitingDialog::Run(int nStartValue)
{
    m_pTimer->stop();

    m_nStartValue = nStartValue;

    QWidget* parent = parentWidget();
    move(parent->pos());
    resize(parent->rect().width(), parent->rect().height());

    on_timer_timeout();
    m_pTimer->start();

    show();
}

void QWaitingDialog::on_timer_timeout()
{
    if (m_nStartValue == 0)
    {
        m_pTimer->stop();
        close();
        return;
    }

    m_pLabel->setText(QString::number(m_nStartValue));

    m_nStartValue--;
}



void QWaitingDialog::paintEvent(QPaintEvent* event)
{
    // 避免鼠标穿透
    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(240, 240, 240, 1));   // 配合全透明属性一起使用
}

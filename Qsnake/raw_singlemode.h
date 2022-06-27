#ifndef RAW_SINGLEMODE_H
#define RAW_SINGLEMODE_H

#include <QWidget>
#include <QObject>
#include <board.h>
#include <QKeyEvent>

namespace Ui {
class SingleMode;
}

class QPaintEvent;

class SingleMode : public QWidget
{
    Q_OBJECT

public:
    explicit SingleMode(QWidget *parent = nullptr);
    ~SingleMode();
    bool pause;//鏄惁鏆傚仠鐘舵€    bool flag;//鐢ㄦ潵淇濊瘉1涓椂闂撮棿闅斿彧澶勭悊涓€涓湁鏁堥敭鐩樹簨浠    QTimer *timer;//璁℃椂鍣    QTimer *timer2;//鐢ㄤ簬鐢熸垚椋熺墿
    Board *board;//鍦板浘
    QWidget *father;

    void paintEvent(QPaintEvent *);//閲嶅啓缁樺浘鍑芥暟
    void keyPressEvent(QKeyEvent *);//閲嶅啓閿洏浜嬩欢鍑芥暟
    int saveFile(std::string);//瀛樻。鍑芥暟,鍥犱负閲嶅悕鏀惧純瀛樻。杩斿洖1

public slots:
    void timerEvent();//璁℃椂鍣ㄥ埌鏃剁殑妲藉嚱鏁
private:
    Ui::SingleMode *ui;
};

#endif // RAW_SINGLEMODE_H

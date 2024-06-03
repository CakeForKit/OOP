#pragma once

#include <QPushButton>
#include <QObject>

enum TypeBtn
{
    UP_BTN = 1,
    DOWN_BTN = -1,
    INLIFT_BRN = 0,
};

class ButtonLift: public QPushButton
{
    Q_OBJECT

    enum StatusButtonLift
    {
        PRESSED,
        NOTPRESSED
    };

public:
    ButtonLift(int buttonFloor, TypeBtn _type, QPushButton *parant = nullptr);
    ~ButtonLift() noexcept = default;

signals:
    void PressSignal(int _floor, TypeBtn _type);

public slots:
    void EndActionButtonSlot(int _floor, TypeBtn _type);

private slots:
    void pressedButtonSlot();

private:
    StatusButtonLift status;
    TypeBtn direction;
    int floor;
};
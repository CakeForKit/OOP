#include "ButtonLift.h"

ButtonLift::ButtonLift(int buttonFloor, TypeBtn _type, QPushButton *parant) 
: QPushButton(parant), status(NOTPRESSED), direction(_type), floor(buttonFloor)
{
    connect(this, &ButtonLift::clicked, this, &ButtonLift::pressedButtonSlot);

    QString label;
    if (direction == UP_BTN) {
        label = "UP";
    } else if (direction == DOWN_BTN) {
        label = "DOWN";
    } else {
        label = "";
    }
    this->setText(QString::number(floor) + QString(" (") + label + QString(")"));
}

void ButtonLift::pressedButtonSlot()
{
    if (status == NOTPRESSED)
    {
        status = PRESSED;
        this->setDisabled(true);
        emit PressSignal(floor, direction);
    }
}

void ButtonLift::EndActionButtonSlot(int _floor, TypeBtn _type)
{
    if (status == PRESSED && _type == direction && _floor == floor)
    {
        status = NOTPRESSED;
        this->setDisabled(false);
    }
}
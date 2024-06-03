#pragma once
#include "CabinLift.h"
#include "ControllerLift.h"
#include <QObject>

class Lift: public QObject
{
    Q_OBJECT
public:
    Lift(QObject *parent = nullptr);
    ~Lift() noexcept = default; // если убрать noexcept будет ошибка совместимости с базовым классом

    QWidget *getWidgetController();

private:
    ControllerLift controller;
    CabinLift cabin;
};


#include "Lift.h"

Lift::Lift(QObject *parent) : QObject(parent) 
{
    connect(&cabin, &CabinLift::ReachedFloorCabinSignal, &controller, &ControllerLift::GotTargetSlot);
    connect(&cabin, &CabinLift::DoorsClosedSignal, &controller, &ControllerLift::SearchTargetSlot);
    connect(&controller, &ControllerLift::MoveControllerSignal, &cabin, &CabinLift::GotCommandMove);
    connect(&controller, &ControllerLift::StopOnFloorSignal, &cabin, &CabinLift::StopToOpenCabinSlot);
    connect(&controller, &ControllerLift::StopCabinSignal, &cabin, &CabinLift::StandCabinSlot);
    
}

QWidget *Lift::getWidgetController()
{
    return &controller;
}
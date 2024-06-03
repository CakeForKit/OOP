#include "Lift.h"

Lift::Lift(QObject *parent) : QObject(parent) 
{
    connect(&cabin, &CabinLift::ReachedFloorCabinSignal, &controller, &ControllerLift::FloorReachedSlot);
    connect(&controller, &ControllerLift::MoveSignal, &cabin, &CabinLift::MoveCabinSlot);
    connect(&controller, &ControllerLift::StopSignal, &cabin, &CabinLift::StopCabinSlot);
    
}

QWidget *Lift::getWidgetController()
{
    return &controller;
}
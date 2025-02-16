#include "CabinLift.h"

#define DEBUG false

CabinLift::CabinLift(QObject *parent, int _movetime)
: QObject(parent), movetime(_movetime), doors()
{
    assert(movetime > 0);

    status = STAND;
    currentFloor = 1;
    targetFloor = 1;
    direction = STOP;

    connect(this, &CabinLift::MoveSignal, this, &CabinLift::MoveCabinSlot);
    connect(&timer, &QTimer::timeout, this, &CabinLift::MoveCabinSlot);
    connect(this, &CabinLift::OpenDoorsSignal, &doors, &DoorsLift::OpeningSlot);
    connect(&doors, &DoorsLift::ClosedSignal, this, &CabinLift::CloseDoorsCabinSlot);
}

void CabinLift::GotCommandMove(int _currentFloor, int _targetFloor, Direction _direction)
{
    if (DEBUG)
        std::cout << "\tCabinLift::GotCommandMove" << 
            " cur - " << _currentFloor << " trgt - " << _targetFloor << std::endl;

    currentFloor = _currentFloor;
    targetFloor = _targetFloor;
    direction = _direction;

    if (status == STAND)
    {
        status = GOTCOMMAND;
        emit MoveSignal();
    }
}

void CabinLift::MoveCabinSlot()
{
    if (DEBUG)
        std::cout << "\tCabinLift::MoveCabinSlot" << 
            " cur - " << currentFloor << " trgt - " << targetFloor << std::endl;

    if (status == MOVING || status == GOTCOMMAND)
    {
        if (status == MOVING)
            currentFloor += direction;  // Исправление теперь нет фантомногое прибавления этажа
        status = MOVING;
        timer.start(movetime);
        
        std::cout << "Лифт на " << currentFloor << " этаже." << std::endl;
        emit ReachedFloorCabinSignal(currentFloor, targetFloor);
    }
}

void CabinLift::StopToOpenCabinSlot(int floor)
{
    if (DEBUG)
        std::cout << "\tCabinLift::StopToOpenCabinSlot" << std::endl;

    if (status == MOVING || status == STAND)
    {
        timer.stop();
        status = STANDOPEN;
        (void) floor;
        // std::cout << "Лифт остановился на " << floor << " этаже." << std::endl;

        emit OpenDoorsSignal();
    }
    
}

void CabinLift::CloseDoorsCabinSlot()
{
    if (DEBUG)
        std::cout << "\tCabinLift::CloseDoorsCabinSlot" << std::endl;

    if (status == STANDOPEN)
    {
        status = STAND;
        timer.stop();
        emit DoorsClosedSignal();
    }
}

void CabinLift::StandCabinSlot(int floor)
{
    if (DEBUG)
        std::cout << "\tCabinLift::StandCabinSlot" << std::endl;

    if (status == STANDOPEN || status == STAND)    // TODO проверить
    {
        status = STAND;
        timer.stop();
        std::cout << "Лифт стоит на " << floor << " этаже." << std::endl;
    }
}


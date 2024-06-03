#include "CabinLift.h"

CabinLift::CabinLift(int _movetime = 1000, int _stoptime = 200, QObject *parent = 0)
: movetime(_movetime), stoptime(_stoptime)
{
    assert(movetime > 0 and stoptime > 0);
    status = STAND;
    // TODO Создать двери
}

void CabinLift::MoveCabinSlot(int currentFloor, Direction direction)
{
    status = MOVING;
    timer.start(movetime);
    currentFloor += direction;
    std::cout << "Лифт на " << currentFloor << " этаже." << std::endl;
    emit ReachedFloorCabinSignal(currentFloor, direction);
}

void CabinLift::StopCabinSlot(int floor)
{
    status = STAND;
    std::cout << "Лифт остановился на " << floor << " этаже." << std::endl;

    // TODO двери открываются, закрываются
}

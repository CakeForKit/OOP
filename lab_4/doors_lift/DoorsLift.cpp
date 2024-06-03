#include "DoorsLift.h"
#include <iostream>

#define DEBUG true

DoorsLift::DoorsLift(int _openingTime, int _openedTime, int _closingTime)
: openingTime(_openingTime), openedTime(_openedTime), closingTime(_closingTime)
{
    status = CLOSED;
    connect(&openingTimer, &QTimer::timeout, this, &DoorsLift::OpenSlot);
    connect(&openedTimer, &QTimer::timeout, this, &DoorsLift::ClosingSlot);
    connect(&closingTimer, &QTimer::timeout, this, &DoorsLift::CloseSlot);
}

void DoorsLift::OpeningSlot()
{
    if (DEBUG)
        std::cout << "\tDoorsLift::OpeningSlot" << std::endl;

    if (status == CLOSED || status == CLOSING)
    {
        std::cout << "Двери открываются" << std::endl;
        status = OPENING;
        openingTimer.start(openingTime);
    }
}

void DoorsLift::OpenSlot() 
{
    if (DEBUG)
        std::cout << "\tDoorsLift::OpenSlot" << std::endl;

    if (status == OPENING)
    {
        openingTimer.stop();
        std::cout << "Двери открыты"  << std::endl;
        status = OPEN;
        openedTimer.start(openedTime);
    }
}

void DoorsLift::ClosingSlot() 
{
    if (DEBUG)
        std::cout << "\tDoorsLift::ClosingSlot" << std::endl;

    if (status == OPEN)
    {
        openedTimer.stop();
        status = CLOSING;
        std::cout << "Двери закрываются" << std::endl;
        closingTimer.start(closingTime);
    }
}

void DoorsLift::CloseSlot() 
{
    if (DEBUG)
        std::cout << "\tDoorsLift::CloseSlot" << std::endl;

    if (status == CLOSING)
    {
        closingTimer.stop();
        status = CLOSED;
        std::cout << "Двери закрыты" << std::endl;
        emit ClosedSignal();
    }
}

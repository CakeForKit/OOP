#include "ControllerLift.h"

ControllerLift::ControllerLift(int _minFloor, int _maxFloor, QWidget *parant = nullptr)
: QWidget(parant), minFloor(_minFloor), maxFloor(_maxFloor)
{
    assert(minFloor <= maxFloor);

    connect(this, &ControllerLift::FloorReachedSignal, this, &ControllerLift::FloorReachedSlot;)

    layout = std::unique_ptr<QGridLayout>(new QGridLayout);
    this->setLayout(layout.get());

    status = FREE;
    direction = STOP;
    currentFloor = 1;
    targetFloor = 1;
    callsFloorsUp = std::vector<bool>(maxFloor - minFloor, false);
    callsFloorsUp = std::vector<bool>(maxFloor - minFloor, false);
    callsFloorsUp = std::vector<bool>(maxFloor - minFloor, false);

    for (int i = minFloor; i <= maxFloor; i++)
    {
        std::shared_ptr<ButtonLift> button(new ButtonLift(i, UP_BTN));



        upButtons.push_back(button);
        layout->addWidget(button.get(), maxFloor - minFloor - i, 1);
    }

}

void ControllerLift::buttonPushedSlot(int _floor, TypeBtn _typeBtn)
{
    if (!isFloorExist(_floor))
        return;

    if (_typeBtn == UP_BTN)
        callsFloorsUp[_floor - minFloor] = true;
    else if (_typeBtn == DOWN_BTN)
        callsFloorsDown[_floor - minFloor] = true;
    else
        callsFloorsInLift[_floor - minFloor] = true;

    updateTarget(_floor, _typeBtn);  // выбор нового тергета с учетом новой нажатой кнопки

    if (currentFloor == targetFloor)
        emit FloorReachedSignal(currentFloor, direction);
    else
    {
        direction = currentFloor > targetFloor ? DOWN : UP;

        emit MoveSignal(currentFloor, direction);
    }
}

void ControllerLift::FloorReachedSlot(int _floor, Direction _direction)
{
    currentFloor = _floor;

    if (currentFloor != targetFloor)
        emit MoveSignal(currentFloor, direction);
    else
    {
        emit StopSignal(currentFloor);
        // ищем следующуу цель
    }
        
}

void ControllerLift::searchNewTarget()
{
    // ищем наиболее близкую цель среди inLift запросов
    int indexnewTarget = -1;
    int indexCurrentFloor = indexByFloor(currentFloor);
    for (int i = 0; i < countFloors(); ++i)
    {
        if (callsFloorsInLift[i] && indexnewTarget == -1 || 
                abs(i - indexCurrentFloor) < abs(indexnewTarget - indexCurrentFloor)))
            indexnewTarget = i;
    }

}

void ControllerLift::updateTarget(int _floor, TypeBtn _typeBtn)
{
    if (status == FREE) 
    {
        targetFloor = _floor;

        if (_typeBtn == INLIFT_BRN)
            status = BUSY;
        else
            status = INSEARCH;
    }
    else if (status == INSEARCH)    // TODO вызовется сначала down потом up на этаже, лифт наче=нет метаться?
    {
        if (_typeBtn == INLIFT_BRN)
        {
            status = BUSY;
            targetFloor = _floor;
        }
        else if (_typeBtn == DOWN_BTN)  // берем самую дальнюю цель, чтобы потом подобрать длижние
        {
            bool find = false;
            for (size_t i = countFloors(); !find && i >= 0; --i)
                if (callsFloorsDown[i])
                {
                    targetFloor = i + minFloor;
                    find = true;
                }
        }
        else
        {
            bool find = false;
            for (size_t i = 0; !find && i < countFloors(); ++i)
                if (callsFloorsUp[i])
                {
                    targetFloor = i + minFloor;
                    find = true;
                }
        }
    }
    else if (status == BUSY)
    {
        // вызов кнопок вне лифта даже не рассматривается
        if (_typeBtn == INLIFT_BRN)
        {
            if (direction == UP)
            {
                bool find = false;
                for (size_t i = indexByFloor(currentFloor); !find && i < countFloors(); ++i)
                    if (callsFloorsInLift[i])
                    {
                        targetFloor = floorByIndex(i);
                        find = true;
                    }
            }
            else
            {
                bool find = false;
                for (size_t i = indexByFloor(currentFloor); !find && i >= 0; --i)
                    if (callsFloorsInLift[i])
                    {
                        targetFloor = floorByIndex(i);
                        find = true;
                    }
            }
        }
    }
}

bool ControllerLift::isFloorExist(int _floor)
{
    return minFloor <= _floor and _floor <= maxFloor;
}

inline int ControllerLift::floorByIndex(size_t ind) noexcept
{
    return ind + minFloor;
}

inline size_t ControllerLift::indexByFloor(int floor) noexcept
{
    return floor + minFloor;
}

inline size_t ControllerLift::countFloors() noexcept
{
    return maxFloor - minFloor;
}
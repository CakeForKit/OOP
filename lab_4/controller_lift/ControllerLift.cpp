#include "ControllerLift.h"

#define DEBUG true

ControllerLift::ControllerLift(int _minFloor, int _maxFloor, QWidget *parant)
: QWidget(parant), minFloor(_minFloor), maxFloor(_maxFloor)
{
    assert(minFloor <= maxFloor);

    connect(this, &ControllerLift::GotTargetSignal, this, &ControllerLift::GotTargetSlot);
    connect(this, &ControllerLift::NeedNewTargetSignal, this, &ControllerLift::SearchTargetSlot);
    connect(this, &ControllerLift::NoTargetSignal, this, &ControllerLift::FreeSlot);

    layout = std::unique_ptr<QGridLayout>(new QGridLayout);
    this->setLayout(layout.get());

    status = FREE;
    direction = STOP;
    currentFloor = 1;
    targetFloor = 1;
    callsFloorsUp = std::vector<std::pair<bool, TypeBtn>>(maxFloor - minFloor, std::make_pair(false, INLIFT_BRN));
    callsFloorsDown = std::vector<std::pair<bool, TypeBtn>>(maxFloor - minFloor, std::make_pair(false, INLIFT_BRN));
    callsFloorsInLift = std::vector<std::pair<bool, TypeBtn>>(maxFloor - minFloor, std::make_pair(false, INLIFT_BRN));

    for (int i = minFloor; i <= maxFloor; ++i)
    {
        std::shared_ptr<ButtonLift> button(new ButtonLift(i, UP_BTN));
        connect(button.get(), &ButtonLift::PressSignal, this, &ControllerLift::ButtonPushedSlot);
        connect(this, &ControllerLift::EndActionButtonSignal, button.get(), &ButtonLift::EndActionButtonSlot);

        upButtons.push_back(button);
        layout->addWidget(button.get(), maxFloor - minFloor - i, 1);
    }
    for (int i = minFloor; i <= maxFloor; ++i)
    {
        std::shared_ptr<ButtonLift> button(new ButtonLift(i, DOWN_BTN));
        connect(button.get(), &ButtonLift::PressSignal, this, &ControllerLift::ButtonPushedSlot);
        connect(this, &ControllerLift::EndActionButtonSignal, button.get(), &ButtonLift::EndActionButtonSlot);

        downButtons.push_back(button);
        layout->addWidget(button.get(), maxFloor - minFloor - i, 0);
    }
    for (int i = minFloor; i <= maxFloor; ++i)
    {
        std::shared_ptr<ButtonLift> button(new ButtonLift(i, INLIFT_BRN));
        connect(button.get(), &ButtonLift::PressSignal, this, &ControllerLift::ButtonPushedSlot);
        connect(this, &ControllerLift::EndActionButtonSignal, button.get(), &ButtonLift::EndActionButtonSlot);

        inLiftButtons.push_back(button);
        layout->addWidget(button.get(), maxFloor - minFloor - i, 2);
    }

}

void ControllerLift::ButtonPushedSlot(int _floor, TypeBtn _typeBtn)
{
    if (DEBUG)
        std::cout << "\tControllerLift::ButtonPushedSlot" << std::endl;

    if (!isFloorExist(_floor))
        return;
    
    status = PUSHED_BTN;

    if (_typeBtn == UP_BTN)
    {
        callsFloorsUp[indexByFloor(_floor)].first = true;
        callsFloorsUp[indexByFloor(_floor)].second = UP_BTN;
    }
    else if (_typeBtn == DOWN_BTN)
    {
        callsFloorsDown[indexByFloor(_floor)].first = true;
        callsFloorsDown[indexByFloor(_floor)].second = DOWN_BTN;
    }
    else
    {
        callsFloorsInLift[indexByFloor(_floor)].first = true;
        callsFloorsInLift[indexByFloor(_floor)].second = INLIFT_BRN;
    }

    emit NeedNewTargetSignal();
}

void ControllerLift::GotTargetSlot(int _currentFloor, int _targetFloor)
{
    if (DEBUG)
        std::cout << "\tControllerLift::GotTargetSlot" << 
            " cur - " << _currentFloor << " trgt - " << _targetFloor <<  std::endl;

    if (!(status == BUSY || status == INSEARCH))
        return;

    status = BUSY;
    currentFloor = _currentFloor;
    targetFloor = _targetFloor;

    if (currentFloor == targetFloor)
    {
        endActionButtons(currentFloor);
        emit StopOnFloorSignal(currentFloor);
        // emit NeedNewTargetSignal();
    }
    else
    {
        direction = currentFloor > targetFloor ? DOWN : UP;
        emit MoveControllerSignal(currentFloor, targetFloor, direction);
    }
}

void ControllerLift::SearchTargetSlot()
{
    if (DEBUG)
        std::cout << "\tControllerLift::SearchTargetSlot" << std::endl;
        
    if (!(status == PUSHED_BTN || status == BUSY))
        return;

    status = INSEARCH;

    // ищем наиболее близкую цель среди inLift запросов
    int indexnewTarget = -1;
    int indexCurrentFloor = indexByFloor(currentFloor);
    for (int i = 0; i < static_cast<int>(countFloors()); ++i)
    {
        if (callsFloorsInLift[i].first && (indexnewTarget == -1 || 
                abs(i - indexCurrentFloor) < abs(indexnewTarget - indexCurrentFloor)))
            indexnewTarget = i;
    }

    bool find = false;
    if (indexnewTarget >= 0)
    {
        targetFloor = floorByIndex(indexnewTarget);
        find = true;

        if (DEBUG)
            std::cout << "\t\t INLIFT targetFloor = " << targetFloor << std::endl;
    }
    else
    {
        // берем самую дальнюю цель, чтобы потом подобрать длижние
        for (int i = static_cast<int>(countFloors()) - 1; !find && i >= 0; --i)
            if (callsFloorsDown[i].first)
            {
                targetFloor = i + minFloor;
                find = true;
            }
        if (DEBUG && find)
            std::cout << "\t\t DOWN targetFloor = " << targetFloor << std::endl;
        for (size_t i = 0; !find && i < countFloors(); ++i)
            if (callsFloorsUp[i].first)
            {
                targetFloor = i + minFloor;
                find = true;
            }
        if (DEBUG && find)
            std::cout << "\t\t UP targetFloor = " << targetFloor << std::endl;
    }

    if (find)
        emit GotTargetSignal(currentFloor, targetFloor);
    else
        emit NoTargetSignal();
}

void ControllerLift::FreeSlot()
{
    if (DEBUG)
        std::cout << "\tControllerLift::FreeSlot" << std::endl;
        
    if (status == INSEARCH)
    {
        status = FREE;
        direction = STOP;
        emit StopCabinSignal(currentFloor);
    }
}

void ControllerLift::endActionButtons(int floor)
{
    size_t indexFloor = indexByFloor(floor);
    if (callsFloorsInLift[indexFloor].first)
    {
        callsFloorsInLift[indexFloor].first = false;
        emit EndActionButtonSignal(floor, INLIFT_BRN);
    }
    if (callsFloorsUp[indexFloor].first)
    {
        callsFloorsUp[indexFloor].first = false;
        emit EndActionButtonSignal(floor, UP_BTN);
    }
    if (callsFloorsDown[indexFloor].first)
    {
        callsFloorsDown[indexFloor].first = false;
        emit EndActionButtonSignal(floor, DOWN_BTN);
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
    return floor - minFloor;
}

inline size_t ControllerLift::countFloors() noexcept
{
    return maxFloor - minFloor;
}
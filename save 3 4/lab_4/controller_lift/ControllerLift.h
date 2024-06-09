#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include <memory>
#include <utility>

#include "ButtonLift.h"
#include "CabinLift.h"

class ControllerLift: public QWidget
{
    Q_OBJECT

    enum StatusControllerLift
    {
        FREE,
        BUSY,
        INSEARCH,
        PUSHED_BTN
    };

public:
    ControllerLift(int _minFloor = -1, int _maxFloor = 10, QWidget *parant = nullptr);
    ~ControllerLift() noexcept = default;

signals:
    void MoveControllerSignal(int _currectFloor, int _targetFloor, Direction _direction);
    void StopOnFloorSignal(int _currectFloor);
    void EndActionButtonSignal(int _currectFloor, TypeBtn _typeBtn);;
    void NeedNewTargetSignal();
    void GotTargetSignal(int currentFloor, int _targetFloor);
    void NoTargetSignal();
    void StopCabinSignal(int _currectFloor);
    
public slots:
    void ButtonPushedSlot(int _floor, TypeBtn _typeBtn);
    void GotTargetSlot(int _currentFloor, int _targetFloor);
    void SearchTargetSlot();
    void FreeSlot();

private:
    StatusControllerLift status;
    Direction direction;
    int currentFloor;
    int targetFloor;

    std::vector<std::shared_ptr<ButtonLift>> upButtons;
    std::vector<std::shared_ptr<ButtonLift>> downButtons;
    std::vector<std::shared_ptr<ButtonLift>> inLiftButtons;
    std::unique_ptr<QGridLayout> layout;

    std::vector<std::pair<bool, TypeBtn>> callsFloorsUp;
    std::vector<std::pair<bool, TypeBtn>> callsFloorsDown;
    std::vector<std::pair<bool, TypeBtn>> callsFloorsInLift;

    void endActionButtons(int floor);
    bool isFloorExist(int floor);
    inline int floorByIndex(size_t ind) noexcept;
    inline size_t indexByFloor(int floor) noexcept;
    inline size_t countFloors() noexcept;

    int minFloor;
    int maxFloor;
};

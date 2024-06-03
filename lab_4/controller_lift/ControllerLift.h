#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include <memory>

#include "ButtonLift.h"

enum Direction
{
    UP = 1,
    DOWN = -1,
    STOP = 0
};

class ControllerLift: public QWidget
{
    Q_OBJECT

    enum StatusControllerLift
    {
        FREE,
        BUSY,
        INSEARCH
    };

public:
    ControllerLift(int _minFloor = -1, int _maxFloor = 10, QWidget *parant = nullptr);
    ~ControllerLift() noexcept = default;

signals:
    void MoveSignal(int _currectFloor, Direction _direction);
    void StopSignal(int _currentFloor);
    void GetTargetSignal();
    void FloorReachedSignal(int _floor, Direction _direction); // на каком этаже это произошло и куда направлялись до этого

public slots:
    void buttonPushedSlot(int _floor, TypeBtn _typeBtn);
    void GetTargetSlot();
    void FloorReachedSlot(int _floor, Direction _direction);

private:
    StatusControllerLift status;
    Direction direction;
    int currentFloor;
    int targetFloor;

    std::vector<std::shared_ptr<ButtonLift>> upButtons;
    std::vector<std::shared_ptr<ButtonLift>> downButtons;
    std::vector<std::shared_ptr<ButtonLift>> inLiftButtons;
    std::unique_ptr<QGridLayout> layout;

    std::vector<bool> callsFloorsUp;
    std::vector<bool> callsFloorsDown;
    std::vector<bool> callsFloorsInLift;

    void searchNewTarget();
    void updateTarget(int _floor, TypeBtn _typeBtn);
    bool isFloorExist(int _floor);
    inline int floorByIndex(size_t ind) noexcept;
    inline size_t indexByFloor(int floor) noexcept;
    inline size_t countFloors() noexcept;

    int minFloor;
    int maxFloor;
};

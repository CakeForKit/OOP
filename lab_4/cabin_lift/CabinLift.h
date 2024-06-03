#pragma once
// #include "ControllerLift.h"
#include <QObject>
#include <QTimer>
#include <iostream>

#include "DoorsLift.h"

enum Direction
{
    UP = 1,
    DOWN = -1,
    STOP = 0
};

class CabinLift : public QObject {
    Q_OBJECT

    enum StatusCabinLift {
        STAND,
        STANDOPEN,
        MOVING,
        GOTCOMMAND
    };

    public:
        CabinLift(QObject *parent = nullptr, int movetime = 3000);
        ~CabinLift() = default;
    
    public slots:
        void GotCommandMove(int currentFloor, int _targetFloor, Direction direction);
        void StopToOpenCabinSlot(int floor);
        void CloseDoorsCabinSlot();
        void StandCabinSlot(int floor);

    private slots:
        void MoveCabinSlot();

    private:
        StatusCabinLift status;
        int currentFloor;
        int targetFloor;
        Direction direction;

        QTimer timer;
        int movetime;

        DoorsLift doors;
    
    signals:
        void ReachedFloorCabinSignal(int currentFloor, int _targetFloor);
        void OpenDoorsSignal();
        void DoorsClosedSignal();
        void MoveSignal();
};
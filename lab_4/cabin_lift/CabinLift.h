#pragma once
#include "ControllerLift.h"
#include <QObject>
#include <QTimer>
#include <iostream>

#define MOVETIME 2000

class CabinLift : public QObject {
    Q_OBJECT

    enum StatusCabinLift {
        STAND,
        MOVING
    };

    public:
        CabinLift(int movetime = 1000, int stoptime = 200, QObject *parent = 0);
        ~CabinLift() = default;
    
    public slots:
        void MoveCabinSlot(int currentFloor, Direction direction);
        void StopCabinSlot(int floor);

    private:
        StatusCabinLift status;
        // LiftDoors doors;

        QTimer timer;
        int movetime;
        int stoptime;
    
    signals:
        void ReachedFloorCabinSignal(int floor, Direction direction);
        void OpenDoorsSignal(int floor);
};
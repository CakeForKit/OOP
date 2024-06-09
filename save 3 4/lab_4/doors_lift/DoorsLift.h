#pragma once
#include <QObject>
#include <QTimer>

class DoorsLift : public QObject {
    Q_OBJECT

    enum LiftDoorsStatus {
        CLOSED,
        CLOSING,
        OPENING,
        OPEN
    };

    public:
        DoorsLift(int _openingTime = 3000, int _openedTime = 3000, int _closingTime = 3000);
        ~DoorsLift() = default;
    
    public slots:
        void OpeningSlot();
    
    private slots:
        void OpenSlot();
        void ClosingSlot();
        void CloseSlot();
    
    signals:
        void ClosedSignal();

    private:
        LiftDoorsStatus status;
        int openingTime;
        int openedTime;
        int closingTime;

        QTimer openingTimer;
        QTimer closingTimer;
        QTimer openedTimer;
};


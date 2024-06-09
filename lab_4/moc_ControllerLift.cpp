/****************************************************************************
** Meta object code from reading C++ file 'ControllerLift.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "controller_lift/ControllerLift.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControllerLift.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControllerLift_t {
    QByteArrayData data[22];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControllerLift_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControllerLift_t qt_meta_stringdata_ControllerLift = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ControllerLift"
QT_MOC_LITERAL(1, 15, 20), // "MoveControllerSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "_currectFloor"
QT_MOC_LITERAL(4, 51, 12), // "_targetFloor"
QT_MOC_LITERAL(5, 64, 9), // "Direction"
QT_MOC_LITERAL(6, 74, 10), // "_direction"
QT_MOC_LITERAL(7, 85, 17), // "StopOnFloorSignal"
QT_MOC_LITERAL(8, 103, 21), // "EndActionButtonSignal"
QT_MOC_LITERAL(9, 125, 7), // "TypeBtn"
QT_MOC_LITERAL(10, 133, 8), // "_typeBtn"
QT_MOC_LITERAL(11, 142, 19), // "NeedNewTargetSignal"
QT_MOC_LITERAL(12, 162, 15), // "GotTargetSignal"
QT_MOC_LITERAL(13, 178, 12), // "currentFloor"
QT_MOC_LITERAL(14, 191, 14), // "NoTargetSignal"
QT_MOC_LITERAL(15, 206, 15), // "StopCabinSignal"
QT_MOC_LITERAL(16, 222, 16), // "ButtonPushedSlot"
QT_MOC_LITERAL(17, 239, 6), // "_floor"
QT_MOC_LITERAL(18, 246, 13), // "GotTargetSlot"
QT_MOC_LITERAL(19, 260, 13), // "_currentFloor"
QT_MOC_LITERAL(20, 274, 16), // "SearchTargetSlot"
QT_MOC_LITERAL(21, 291, 8) // "FreeSlot"

    },
    "ControllerLift\0MoveControllerSignal\0"
    "\0_currectFloor\0_targetFloor\0Direction\0"
    "_direction\0StopOnFloorSignal\0"
    "EndActionButtonSignal\0TypeBtn\0_typeBtn\0"
    "NeedNewTargetSignal\0GotTargetSignal\0"
    "currentFloor\0NoTargetSignal\0StopCabinSignal\0"
    "ButtonPushedSlot\0_floor\0GotTargetSlot\0"
    "_currentFloor\0SearchTargetSlot\0FreeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControllerLift[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,
       7,    1,   76,    2, 0x06 /* Public */,
       8,    2,   79,    2, 0x06 /* Public */,
      11,    0,   84,    2, 0x06 /* Public */,
      12,    2,   85,    2, 0x06 /* Public */,
      14,    0,   90,    2, 0x06 /* Public */,
      15,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    2,   94,    2, 0x0a /* Public */,
      18,    2,   99,    2, 0x0a /* Public */,
      20,    0,  104,    2, 0x0a /* Public */,
      21,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    3,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,   17,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ControllerLift::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControllerLift *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MoveControllerSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Direction(*)>(_a[3]))); break;
        case 1: _t->StopOnFloorSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->EndActionButtonSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< TypeBtn(*)>(_a[2]))); break;
        case 3: _t->NeedNewTargetSignal(); break;
        case 4: _t->GotTargetSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->NoTargetSignal(); break;
        case 6: _t->StopCabinSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ButtonPushedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< TypeBtn(*)>(_a[2]))); break;
        case 8: _t->GotTargetSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->SearchTargetSlot(); break;
        case 10: _t->FreeSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ControllerLift::*)(int , int , Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::MoveControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ControllerLift::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::StopOnFloorSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ControllerLift::*)(int , TypeBtn );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::EndActionButtonSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ControllerLift::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::NeedNewTargetSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ControllerLift::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::GotTargetSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ControllerLift::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::NoTargetSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ControllerLift::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerLift::StopCabinSignal)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControllerLift::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ControllerLift.data,
    qt_meta_data_ControllerLift,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ControllerLift::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllerLift::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControllerLift.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ControllerLift::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ControllerLift::MoveControllerSignal(int _t1, int _t2, Direction _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControllerLift::StopOnFloorSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControllerLift::EndActionButtonSignal(int _t1, TypeBtn _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ControllerLift::NeedNewTargetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ControllerLift::GotTargetSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ControllerLift::NoTargetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ControllerLift::StopCabinSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

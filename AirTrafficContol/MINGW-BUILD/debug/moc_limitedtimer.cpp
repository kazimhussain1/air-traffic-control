/****************************************************************************
** Meta object code from reading C++ file 'limitedtimer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CustomWidgets/limitedtimer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'limitedtimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LimitedTimer_t {
    QByteArrayData data[10];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LimitedTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LimitedTimer_t qt_meta_stringdata_LimitedTimer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LimitedTimer"
QT_MOC_LITERAL(1, 13, 4), // "tick"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "int&"
QT_MOC_LITERAL(4, 24, 12), // "std::string&"
QT_MOC_LITERAL(5, 37, 5), // "bool&"
QT_MOC_LITERAL(6, 43, 7), // "QLabel*"
QT_MOC_LITERAL(7, 51, 19), // "QPropertyAnimation*"
QT_MOC_LITERAL(8, 71, 14), // "timeoutConnect"
QT_MOC_LITERAL(9, 86, 14) // "finishedUpdate"

    },
    "LimitedTimer\0tick\0\0int&\0std::string&\0"
    "bool&\0QLabel*\0QPropertyAnimation*\0"
    "timeoutConnect\0finishedUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LimitedTimer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   42,    2, 0x0a /* Public */,
       9,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 5, 0x80000000 | 6, 0x80000000 | 7,    2,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LimitedTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LimitedTimer *_t = static_cast<LimitedTimer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QLabel*(*)>(_a[5])),(*reinterpret_cast< QPropertyAnimation*(*)>(_a[6]))); break;
        case 1: _t->timeoutConnect(); break;
        case 2: _t->finishedUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPropertyAnimation* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LimitedTimer::*)(int & , int & , std::string & , bool & , QLabel * , QPropertyAnimation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LimitedTimer::tick)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LimitedTimer::staticMetaObject = {
    { &QTimer::staticMetaObject, qt_meta_stringdata_LimitedTimer.data,
      qt_meta_data_LimitedTimer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LimitedTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LimitedTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LimitedTimer.stringdata0))
        return static_cast<void*>(this);
    return QTimer::qt_metacast(_clname);
}

int LimitedTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LimitedTimer::tick(int & _t1, int & _t2, std::string & _t3, bool & _t4, QLabel * _t5, QPropertyAnimation * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

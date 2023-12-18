/****************************************************************************
** Meta object code from reading C++ file 'Controller.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Controller.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSControllerENDCLASS = QtMocHelpers::stringData(
    "Controller",
    "onSignIn",
    "",
    "QString&",
    "username",
    "password",
    "onSignUp",
    "onSignOut",
    "onTableAddContact",
    "name",
    "phone",
    "email",
    "tab",
    "onTableSearchClicked",
    "onSearchAccepted",
    "searchName",
    "searchOption"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[9];
    char stringdata7[10];
    char stringdata8[18];
    char stringdata9[5];
    char stringdata10[6];
    char stringdata11[6];
    char stringdata12[4];
    char stringdata13[21];
    char stringdata14[17];
    char stringdata15[11];
    char stringdata16[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSControllerENDCLASS_t qt_meta_stringdata_CLASSControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Controller"
        QT_MOC_LITERAL(11, 8),  // "onSignIn"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 8),  // "QString&"
        QT_MOC_LITERAL(30, 8),  // "username"
        QT_MOC_LITERAL(39, 8),  // "password"
        QT_MOC_LITERAL(48, 8),  // "onSignUp"
        QT_MOC_LITERAL(57, 9),  // "onSignOut"
        QT_MOC_LITERAL(67, 17),  // "onTableAddContact"
        QT_MOC_LITERAL(85, 4),  // "name"
        QT_MOC_LITERAL(90, 5),  // "phone"
        QT_MOC_LITERAL(96, 5),  // "email"
        QT_MOC_LITERAL(102, 3),  // "tab"
        QT_MOC_LITERAL(106, 20),  // "onTableSearchClicked"
        QT_MOC_LITERAL(127, 16),  // "onSearchAccepted"
        QT_MOC_LITERAL(144, 10),  // "searchName"
        QT_MOC_LITERAL(155, 12)   // "searchOption"
    },
    "Controller",
    "onSignIn",
    "",
    "QString&",
    "username",
    "password",
    "onSignUp",
    "onSignOut",
    "onTableAddContact",
    "name",
    "phone",
    "email",
    "tab",
    "onTableSearchClicked",
    "onSearchAccepted",
    "searchName",
    "searchOption"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x08,    1 /* Private */,
       6,    2,   55,    2, 0x08,    4 /* Private */,
       7,    0,   60,    2, 0x08,    7 /* Private */,
       8,    4,   61,    2, 0x08,    8 /* Private */,
      13,    0,   70,    2, 0x08,   13 /* Private */,
      14,    3,   71,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   15,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QApplication::staticMetaObject>(),
    qt_meta_stringdata_CLASSControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Controller, std::true_type>,
        // method 'onSignIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'onSignUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'onSignOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTableAddContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onTableSearchClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSearchAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSignIn((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[2]))); break;
        case 1: _t->onSignUp((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[2]))); break;
        case 2: _t->onSignOut(); break;
        case 3: _t->onTableAddContact((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 4: _t->onTableSearchClicked(); break;
        case 5: _t->onSearchAccepted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QApplication::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

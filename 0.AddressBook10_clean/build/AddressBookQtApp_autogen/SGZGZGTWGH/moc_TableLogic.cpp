/****************************************************************************
** Meta object code from reading C++ file 'TableLogic.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Logic/TableLogic.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TableLogic.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTableLogicENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTableLogicENDCLASS = QtMocHelpers::stringData(
    "TableLogic",
    "sigContactAdded",
    "",
    "name",
    "phone",
    "email",
    "tab",
    "sigSearchClicked",
    "sigSignOutClicked",
    "onAddContactClicked2",
    "onSearchClicked",
    "onSignOutClicked",
    "onAddAccepted",
    "onSearchAccepted",
    "searchName",
    "searchOption"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTableLogicENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[6];
    char stringdata6[4];
    char stringdata7[17];
    char stringdata8[18];
    char stringdata9[21];
    char stringdata10[16];
    char stringdata11[17];
    char stringdata12[14];
    char stringdata13[17];
    char stringdata14[11];
    char stringdata15[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTableLogicENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTableLogicENDCLASS_t qt_meta_stringdata_CLASSTableLogicENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "TableLogic"
        QT_MOC_LITERAL(11, 15),  // "sigContactAdded"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 4),  // "name"
        QT_MOC_LITERAL(33, 5),  // "phone"
        QT_MOC_LITERAL(39, 5),  // "email"
        QT_MOC_LITERAL(45, 3),  // "tab"
        QT_MOC_LITERAL(49, 16),  // "sigSearchClicked"
        QT_MOC_LITERAL(66, 17),  // "sigSignOutClicked"
        QT_MOC_LITERAL(84, 20),  // "onAddContactClicked2"
        QT_MOC_LITERAL(105, 15),  // "onSearchClicked"
        QT_MOC_LITERAL(121, 16),  // "onSignOutClicked"
        QT_MOC_LITERAL(138, 13),  // "onAddAccepted"
        QT_MOC_LITERAL(152, 16),  // "onSearchAccepted"
        QT_MOC_LITERAL(169, 10),  // "searchName"
        QT_MOC_LITERAL(180, 12)   // "searchOption"
    },
    "TableLogic",
    "sigContactAdded",
    "",
    "name",
    "phone",
    "email",
    "tab",
    "sigSearchClicked",
    "sigSignOutClicked",
    "onAddContactClicked2",
    "onSearchClicked",
    "onSignOutClicked",
    "onAddAccepted",
    "onSearchAccepted",
    "searchName",
    "searchOption"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTableLogicENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   62,    2, 0x06,    1 /* Public */,
       7,    0,   71,    2, 0x06,    6 /* Public */,
       8,    0,   72,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   73,    2, 0x0a,    8 /* Public */,
      10,    0,   74,    2, 0x0a,    9 /* Public */,
      11,    0,   75,    2, 0x0a,   10 /* Public */,
      12,    4,   76,    2, 0x08,   11 /* Private */,
      13,    3,   85,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject TableLogic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTableLogicENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTableLogicENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTableLogicENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TableLogic, std::true_type>,
        // method 'sigContactAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sigSearchClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigSignOutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddContactClicked2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSearchClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSignOutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSearchAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void TableLogic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TableLogic *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigContactAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 1: _t->sigSearchClicked(); break;
        case 2: _t->sigSignOutClicked(); break;
        case 3: _t->onAddContactClicked2(); break;
        case 4: _t->onSearchClicked(); break;
        case 5: _t->onSignOutClicked(); break;
        case 6: _t->onAddAccepted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 7: _t->onSearchAccepted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TableLogic::*)(const QString & , const QString & , const QString & , const QString & );
            if (_t _q_method = &TableLogic::sigContactAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TableLogic::*)();
            if (_t _q_method = &TableLogic::sigSearchClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TableLogic::*)();
            if (_t _q_method = &TableLogic::sigSignOutClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *TableLogic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableLogic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTableLogicENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TableLogic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TableLogic::sigContactAdded(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TableLogic::sigSearchClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TableLogic::sigSignOutClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

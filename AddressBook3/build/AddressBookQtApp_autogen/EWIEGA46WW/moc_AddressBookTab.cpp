/****************************************************************************
** Meta object code from reading C++ file 'AddressBookTab.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AddressBookTab.hpp"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressBookTab.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAddressBookTabENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAddressBookTabENDCLASS = QtMocHelpers::stringData(
    "AddressBookTab",
    "sendDetails",
    "",
    "name",
    "phone",
    "email",
    "sendFilePath",
    "filePath",
    "addEntry",
    "openEntry"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAddressBookTabENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[15];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[6];
    char stringdata6[13];
    char stringdata7[9];
    char stringdata8[9];
    char stringdata9[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAddressBookTabENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAddressBookTabENDCLASS_t qt_meta_stringdata_CLASSAddressBookTabENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "AddressBookTab"
        QT_MOC_LITERAL(15, 11),  // "sendDetails"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 4),  // "name"
        QT_MOC_LITERAL(33, 5),  // "phone"
        QT_MOC_LITERAL(39, 5),  // "email"
        QT_MOC_LITERAL(45, 12),  // "sendFilePath"
        QT_MOC_LITERAL(58, 8),  // "filePath"
        QT_MOC_LITERAL(67, 8),  // "addEntry"
        QT_MOC_LITERAL(76, 9)   // "openEntry"
    },
    "AddressBookTab",
    "sendDetails",
    "",
    "name",
    "phone",
    "email",
    "sendFilePath",
    "filePath",
    "addEntry",
    "openEntry"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAddressBookTabENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   38,    2, 0x06,    1 /* Public */,
       6,    1,   45,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   48,    2, 0x0a,    7 /* Public */,
       9,    0,   49,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddressBookTab::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAddressBookTabENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAddressBookTabENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAddressBookTabENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddressBookTab, std::true_type>,
        // method 'sendDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sendFilePath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddressBookTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddressBookTab *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->sendFilePath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->addEntry(); break;
        case 3: _t->openEntry(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddressBookTab::*)(const QString & , const QString & , const QString & );
            if (_t _q_method = &AddressBookTab::sendDetails; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddressBookTab::*)(const QString & );
            if (_t _q_method = &AddressBookTab::sendFilePath; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *AddressBookTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddressBookTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAddressBookTabENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddressBookTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddressBookTab::sendDetails(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddressBookTab::sendFilePath(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP

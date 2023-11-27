/****************************************************************************
** Meta object code from reading C++ file 'AddressBookLogic.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Logic/AddressBookLogic.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressBookLogic.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAddressBookLogicENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAddressBookLogicENDCLASS = QtMocHelpers::stringData(
    "AddressBookLogic",
    "contactAdded",
    "",
    "name",
    "phone",
    "email",
    "contactEdited",
    "tabIndex",
    "rowIndex",
    "addContact",
    "editContact",
    "QTableWidgetItem*",
    "item",
    "openAddressBook",
    "searchContacts",
    "saveAddressBook",
    "addContactToDatabase"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAddressBookLogicENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[17];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[6];
    char stringdata6[14];
    char stringdata7[9];
    char stringdata8[9];
    char stringdata9[11];
    char stringdata10[12];
    char stringdata11[18];
    char stringdata12[5];
    char stringdata13[16];
    char stringdata14[15];
    char stringdata15[16];
    char stringdata16[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAddressBookLogicENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAddressBookLogicENDCLASS_t qt_meta_stringdata_CLASSAddressBookLogicENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "AddressBookLogic"
        QT_MOC_LITERAL(17, 12),  // "contactAdded"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 4),  // "name"
        QT_MOC_LITERAL(36, 5),  // "phone"
        QT_MOC_LITERAL(42, 5),  // "email"
        QT_MOC_LITERAL(48, 13),  // "contactEdited"
        QT_MOC_LITERAL(62, 8),  // "tabIndex"
        QT_MOC_LITERAL(71, 8),  // "rowIndex"
        QT_MOC_LITERAL(80, 10),  // "addContact"
        QT_MOC_LITERAL(91, 11),  // "editContact"
        QT_MOC_LITERAL(103, 17),  // "QTableWidgetItem*"
        QT_MOC_LITERAL(121, 4),  // "item"
        QT_MOC_LITERAL(126, 15),  // "openAddressBook"
        QT_MOC_LITERAL(142, 14),  // "searchContacts"
        QT_MOC_LITERAL(157, 15),  // "saveAddressBook"
        QT_MOC_LITERAL(173, 20)   // "addContactToDatabase"
    },
    "AddressBookLogic",
    "contactAdded",
    "",
    "name",
    "phone",
    "email",
    "contactEdited",
    "tabIndex",
    "rowIndex",
    "addContact",
    "editContact",
    "QTableWidgetItem*",
    "item",
    "openAddressBook",
    "searchContacts",
    "saveAddressBook",
    "addContactToDatabase"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAddressBookLogicENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x06,    1 /* Public */,
       6,    5,   69,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   80,    2, 0x0a,   11 /* Public */,
      10,    1,   81,    2, 0x0a,   12 /* Public */,
      13,    0,   84,    2, 0x0a,   14 /* Public */,
      14,    0,   85,    2, 0x0a,   15 /* Public */,
      15,    0,   86,    2, 0x0a,   16 /* Public */,
      16,    3,   87,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddressBookLogic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAddressBookLogicENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAddressBookLogicENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAddressBookLogicENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddressBookLogic, std::true_type>,
        // method 'contactAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'contactEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        // method 'openAddressBook'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchContacts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveAddressBook'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addContactToDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void AddressBookLogic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddressBookLogic *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->contactAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->contactEdited((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 2: _t->addContact(); break;
        case 3: _t->editContact((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 4: _t->openAddressBook(); break;
        case 5: _t->searchContacts(); break;
        case 6: _t->saveAddressBook(); break;
        case 7: _t->addContactToDatabase((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddressBookLogic::*)(const QString & , const QString & , const QString & );
            if (_t _q_method = &AddressBookLogic::contactAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddressBookLogic::*)(int , int , const QString & , const QString & , const QString & );
            if (_t _q_method = &AddressBookLogic::contactEdited; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *AddressBookLogic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddressBookLogic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAddressBookLogicENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AddressBookLogic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddressBookLogic::contactAdded(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddressBookLogic::contactEdited(int _t1, int _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP

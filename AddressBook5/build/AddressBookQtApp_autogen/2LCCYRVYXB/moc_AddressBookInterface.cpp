/****************************************************************************
** Meta object code from reading C++ file 'AddressBookInterface.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI/AddressBookInterface.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressBookInterface.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS = QtMocHelpers::stringData(
    "AddressBookInterface",
    "addTabClicked",
    "",
    "addContactClicked",
    "editContact",
    "QTableWidgetItem*",
    "item",
    "openAddressBook",
    "searchContacts",
    "saveAddressBook",
    "showDatabaseContents"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[21];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[12];
    char stringdata5[18];
    char stringdata6[5];
    char stringdata7[16];
    char stringdata8[15];
    char stringdata9[16];
    char stringdata10[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "AddressBookInterface"
        QT_MOC_LITERAL(21, 13),  // "addTabClicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 17),  // "addContactClicked"
        QT_MOC_LITERAL(54, 11),  // "editContact"
        QT_MOC_LITERAL(66, 17),  // "QTableWidgetItem*"
        QT_MOC_LITERAL(84, 4),  // "item"
        QT_MOC_LITERAL(89, 15),  // "openAddressBook"
        QT_MOC_LITERAL(105, 14),  // "searchContacts"
        QT_MOC_LITERAL(120, 15),  // "saveAddressBook"
        QT_MOC_LITERAL(136, 20)   // "showDatabaseContents"
    },
    "AddressBookInterface",
    "addTabClicked",
    "",
    "addContactClicked",
    "editContact",
    "QTableWidgetItem*",
    "item",
    "openAddressBook",
    "searchContacts",
    "saveAddressBook",
    "showDatabaseContents"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAddressBookInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    1,   58,    2, 0x0a,    3 /* Public */,
       7,    0,   61,    2, 0x0a,    5 /* Public */,
       8,    0,   62,    2, 0x0a,    6 /* Public */,
       9,    0,   63,    2, 0x0a,    7 /* Public */,
      10,    0,   64,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddressBookInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAddressBookInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddressBookInterface, std::true_type>,
        // method 'addTabClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addContactClicked'
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
        // method 'showDatabaseContents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddressBookInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddressBookInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addTabClicked(); break;
        case 1: _t->addContactClicked(); break;
        case 2: _t->editContact((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 3: _t->openAddressBook(); break;
        case 4: _t->searchContacts(); break;
        case 5: _t->saveAddressBook(); break;
        case 6: _t->showDatabaseContents(); break;
        default: ;
        }
    }
}

const QMetaObject *AddressBookInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddressBookInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddressBookInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP

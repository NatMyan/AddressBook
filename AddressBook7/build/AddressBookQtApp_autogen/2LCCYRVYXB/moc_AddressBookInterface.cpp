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
    "tabAdded",
    "",
    "tabName",
    "sigSignOutClicked",
    "addTabClicked",
    "addContactClicked",
    "signOutClicked",
    "editContact",
    "QTableWidgetItem*",
    "item",
    "searchContacts",
    "showDatabaseContents"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[21];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[18];
    char stringdata5[14];
    char stringdata6[18];
    char stringdata7[15];
    char stringdata8[12];
    char stringdata9[18];
    char stringdata10[5];
    char stringdata11[15];
    char stringdata12[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS_t qt_meta_stringdata_CLASSAddressBookInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "AddressBookInterface"
        QT_MOC_LITERAL(21, 8),  // "tabAdded"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 7),  // "tabName"
        QT_MOC_LITERAL(39, 17),  // "sigSignOutClicked"
        QT_MOC_LITERAL(57, 13),  // "addTabClicked"
        QT_MOC_LITERAL(71, 17),  // "addContactClicked"
        QT_MOC_LITERAL(89, 14),  // "signOutClicked"
        QT_MOC_LITERAL(104, 11),  // "editContact"
        QT_MOC_LITERAL(116, 17),  // "QTableWidgetItem*"
        QT_MOC_LITERAL(134, 4),  // "item"
        QT_MOC_LITERAL(139, 14),  // "searchContacts"
        QT_MOC_LITERAL(154, 20)   // "showDatabaseContents"
    },
    "AddressBookInterface",
    "tabAdded",
    "",
    "tabName",
    "sigSignOutClicked",
    "addTabClicked",
    "addContactClicked",
    "signOutClicked",
    "editContact",
    "QTableWidgetItem*",
    "item",
    "searchContacts",
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    0,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   66,    2, 0x0a,    4 /* Public */,
       6,    0,   67,    2, 0x0a,    5 /* Public */,
       7,    0,   68,    2, 0x0a,    6 /* Public */,
       8,    1,   69,    2, 0x0a,    7 /* Public */,
      11,    0,   72,    2, 0x0a,    9 /* Public */,
      12,    0,   73,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
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
        // method 'tabAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sigSignOutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTabClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addContactClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signOutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        // method 'searchContacts'
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
        case 0: _t->tabAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sigSignOutClicked(); break;
        case 2: _t->addTabClicked(); break;
        case 3: _t->addContactClicked(); break;
        case 4: _t->signOutClicked(); break;
        case 5: _t->editContact((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 6: _t->searchContacts(); break;
        case 7: _t->showDatabaseContents(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddressBookInterface::*)(const QString & );
            if (_t _q_method = &AddressBookInterface::tabAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddressBookInterface::*)();
            if (_t _q_method = &AddressBookInterface::sigSignOutClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
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
void AddressBookInterface::tabAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddressBookInterface::sigSignOutClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

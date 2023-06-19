/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../scrabblev2/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[38];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[5];
    char stringdata5[18];
    char stringdata6[7];
    char stringdata7[6];
    char stringdata8[24];
    char stringdata9[22];
    char stringdata10[22];
    char stringdata11[15];
    char stringdata12[2];
    char stringdata13[16];
    char stringdata14[4];
    char stringdata15[18];
    char stringdata16[21];
    char stringdata17[2];
    char stringdata18[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "tileSelectedSlot"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 5),  // "Tile*"
        QT_MOC_LITERAL(35, 4),  // "tile"
        QT_MOC_LITERAL(40, 17),  // "spaceSelectedSlot"
        QT_MOC_LITERAL(58, 6),  // "Space*"
        QT_MOC_LITERAL(65, 5),  // "space"
        QT_MOC_LITERAL(71, 23),  // "on_submitButton_clicked"
        QT_MOC_LITERAL(95, 21),  // "on_passButton_clicked"
        QT_MOC_LITERAL(117, 21),  // "on_drawButton_clicked"
        QT_MOC_LITERAL(139, 14),  // "numPlayersSlot"
        QT_MOC_LITERAL(154, 1),  // "n"
        QT_MOC_LITERAL(156, 15),  // "blankSubmitSlot"
        QT_MOC_LITERAL(172, 3),  // "let"
        QT_MOC_LITERAL(176, 17),  // "createPlayersSlot"
        QT_MOC_LITERAL(194, 20),  // "std::vector<Player*>"
        QT_MOC_LITERAL(215, 1),  // "p"
        QT_MOC_LITERAL(217, 23)   // "on_resignButton_clicked"
    },
    "MainWindow",
    "tileSelectedSlot",
    "",
    "Tile*",
    "tile",
    "spaceSelectedSlot",
    "Space*",
    "space",
    "on_submitButton_clicked",
    "on_passButton_clicked",
    "on_drawButton_clicked",
    "numPlayersSlot",
    "n",
    "blankSubmitSlot",
    "let",
    "createPlayersSlot",
    "std::vector<Player*>",
    "p",
    "on_resignButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       5,    1,   71,    2, 0x08,    3 /* Private */,
       8,    0,   74,    2, 0x08,    5 /* Private */,
       9,    0,   75,    2, 0x08,    6 /* Private */,
      10,    0,   76,    2, 0x08,    7 /* Private */,
      11,    1,   77,    2, 0x08,    8 /* Private */,
      13,    1,   80,    2, 0x08,   10 /* Private */,
      15,    1,   83,    2, 0x08,   12 /* Private */,
      18,    0,   86,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Char,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'tileSelectedSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Tile *, std::false_type>,
        // method 'spaceSelectedSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Space *, std::false_type>,
        // method 'on_submitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_passButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_drawButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'numPlayersSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'blankSubmitSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char, std::false_type>,
        // method 'createPlayersSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<Player*>, std::false_type>,
        // method 'on_resignButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tileSelectedSlot((*reinterpret_cast< std::add_pointer_t<Tile*>>(_a[1]))); break;
        case 1: _t->spaceSelectedSlot((*reinterpret_cast< std::add_pointer_t<Space*>>(_a[1]))); break;
        case 2: _t->on_submitButton_clicked(); break;
        case 3: _t->on_passButton_clicked(); break;
        case 4: _t->on_drawButton_clicked(); break;
        case 5: _t->numPlayersSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->blankSubmitSlot((*reinterpret_cast< std::add_pointer_t<char>>(_a[1]))); break;
        case 7: _t->createPlayersSlot((*reinterpret_cast< std::add_pointer_t<std::vector<Player*>>>(_a[1]))); break;
        case 8: _t->on_resignButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Tile* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Space* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

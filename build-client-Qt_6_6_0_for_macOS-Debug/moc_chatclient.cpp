/****************************************************************************
** Meta object code from reading C++ file 'chatclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/chatclient.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
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
struct qt_meta_stringdata_CLASSChatClientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSChatClientENDCLASS = QtMocHelpers::stringData(
    "ChatClient",
    "logOut",
    "",
    "username",
    "requestGetAllUsers",
    "sendPrivateMessage",
    "message",
    "getPrivateHistory",
    "requestCreateGroup",
    "nameGroup",
    "members",
    "sendGroupMessage",
    "getGroupHistory",
    "requestManageGroup",
    "requestUpdateGroup",
    "requestLeaveGroup",
    "requestAddFriend",
    "type",
    "get_active_users",
    "data",
    "get_all_users",
    "userList",
    "set_receiver",
    "clickedUsername",
    "get_messages",
    "from",
    "messages",
    "on_pushButton_sendMsg_clicked",
    "on_pushButton_createGroup_clicked",
    "request_create_group",
    "get_my_groups",
    "groups",
    "request_manage_group",
    "groupName",
    "open_manage_group",
    "request_leave_group",
    "request_update_group",
    "send_request_add_friend",
    "on_pushButton_logout_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSChatClientENDCLASS_t {
    uint offsetsAndSizes[78];
    char stringdata0[11];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[19];
    char stringdata5[19];
    char stringdata6[8];
    char stringdata7[18];
    char stringdata8[19];
    char stringdata9[10];
    char stringdata10[8];
    char stringdata11[17];
    char stringdata12[16];
    char stringdata13[19];
    char stringdata14[19];
    char stringdata15[18];
    char stringdata16[17];
    char stringdata17[5];
    char stringdata18[17];
    char stringdata19[5];
    char stringdata20[14];
    char stringdata21[9];
    char stringdata22[13];
    char stringdata23[16];
    char stringdata24[13];
    char stringdata25[5];
    char stringdata26[9];
    char stringdata27[30];
    char stringdata28[34];
    char stringdata29[21];
    char stringdata30[14];
    char stringdata31[7];
    char stringdata32[21];
    char stringdata33[10];
    char stringdata34[18];
    char stringdata35[20];
    char stringdata36[21];
    char stringdata37[24];
    char stringdata38[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSChatClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSChatClientENDCLASS_t qt_meta_stringdata_CLASSChatClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "ChatClient"
        QT_MOC_LITERAL(11, 6),  // "logOut"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 8),  // "username"
        QT_MOC_LITERAL(28, 18),  // "requestGetAllUsers"
        QT_MOC_LITERAL(47, 18),  // "sendPrivateMessage"
        QT_MOC_LITERAL(66, 7),  // "message"
        QT_MOC_LITERAL(74, 17),  // "getPrivateHistory"
        QT_MOC_LITERAL(92, 18),  // "requestCreateGroup"
        QT_MOC_LITERAL(111, 9),  // "nameGroup"
        QT_MOC_LITERAL(121, 7),  // "members"
        QT_MOC_LITERAL(129, 16),  // "sendGroupMessage"
        QT_MOC_LITERAL(146, 15),  // "getGroupHistory"
        QT_MOC_LITERAL(162, 18),  // "requestManageGroup"
        QT_MOC_LITERAL(181, 18),  // "requestUpdateGroup"
        QT_MOC_LITERAL(200, 17),  // "requestLeaveGroup"
        QT_MOC_LITERAL(218, 16),  // "requestAddFriend"
        QT_MOC_LITERAL(235, 4),  // "type"
        QT_MOC_LITERAL(240, 16),  // "get_active_users"
        QT_MOC_LITERAL(257, 4),  // "data"
        QT_MOC_LITERAL(262, 13),  // "get_all_users"
        QT_MOC_LITERAL(276, 8),  // "userList"
        QT_MOC_LITERAL(285, 12),  // "set_receiver"
        QT_MOC_LITERAL(298, 15),  // "clickedUsername"
        QT_MOC_LITERAL(314, 12),  // "get_messages"
        QT_MOC_LITERAL(327, 4),  // "from"
        QT_MOC_LITERAL(332, 8),  // "messages"
        QT_MOC_LITERAL(341, 29),  // "on_pushButton_sendMsg_clicked"
        QT_MOC_LITERAL(371, 33),  // "on_pushButton_createGroup_cli..."
        QT_MOC_LITERAL(405, 20),  // "request_create_group"
        QT_MOC_LITERAL(426, 13),  // "get_my_groups"
        QT_MOC_LITERAL(440, 6),  // "groups"
        QT_MOC_LITERAL(447, 20),  // "request_manage_group"
        QT_MOC_LITERAL(468, 9),  // "groupName"
        QT_MOC_LITERAL(478, 17),  // "open_manage_group"
        QT_MOC_LITERAL(496, 19),  // "request_leave_group"
        QT_MOC_LITERAL(516, 20),  // "request_update_group"
        QT_MOC_LITERAL(537, 23),  // "send_request_add_friend"
        QT_MOC_LITERAL(561, 28)   // "on_pushButton_logout_clicked"
    },
    "ChatClient",
    "logOut",
    "",
    "username",
    "requestGetAllUsers",
    "sendPrivateMessage",
    "message",
    "getPrivateHistory",
    "requestCreateGroup",
    "nameGroup",
    "members",
    "sendGroupMessage",
    "getGroupHistory",
    "requestManageGroup",
    "requestUpdateGroup",
    "requestLeaveGroup",
    "requestAddFriend",
    "type",
    "get_active_users",
    "data",
    "get_all_users",
    "userList",
    "set_receiver",
    "clickedUsername",
    "get_messages",
    "from",
    "messages",
    "on_pushButton_sendMsg_clicked",
    "on_pushButton_createGroup_clicked",
    "request_create_group",
    "get_my_groups",
    "groups",
    "request_manage_group",
    "groupName",
    "open_manage_group",
    "request_leave_group",
    "request_update_group",
    "send_request_add_friend",
    "on_pushButton_logout_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSChatClientENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  164,    2, 0x06,    1 /* Public */,
       4,    0,  167,    2, 0x06,    3 /* Public */,
       5,    1,  168,    2, 0x06,    4 /* Public */,
       7,    0,  171,    2, 0x06,    6 /* Public */,
       8,    2,  172,    2, 0x06,    7 /* Public */,
      11,    1,  177,    2, 0x06,   10 /* Public */,
      12,    0,  180,    2, 0x06,   12 /* Public */,
      13,    1,  181,    2, 0x06,   13 /* Public */,
      14,    2,  184,    2, 0x06,   15 /* Public */,
      15,    1,  189,    2, 0x06,   18 /* Public */,
      16,    2,  192,    2, 0x06,   20 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  197,    2, 0x08,   23 /* Private */,
      20,    1,  200,    2, 0x08,   25 /* Private */,
      22,    2,  203,    2, 0x08,   27 /* Private */,
      24,    2,  208,    2, 0x08,   30 /* Private */,
      27,    0,  213,    2, 0x08,   33 /* Private */,
      28,    0,  214,    2, 0x08,   34 /* Private */,
      29,    2,  215,    2, 0x08,   35 /* Private */,
      30,    1,  220,    2, 0x08,   38 /* Private */,
      32,    1,  223,    2, 0x08,   40 /* Private */,
      34,    2,  226,    2, 0x08,   42 /* Private */,
      35,    1,  231,    2, 0x08,   45 /* Private */,
      36,    2,  234,    2, 0x08,   47 /* Private */,
      37,    2,  239,    2, 0x08,   50 /* Private */,
      38,    0,  244,    2, 0x08,   53 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    9,   10,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   23,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    9,   10,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   33,   10,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   33,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   17,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ChatClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSChatClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSChatClientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSChatClientENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChatClient, std::true_type>,
        // method 'logOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'requestGetAllUsers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendPrivateMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getPrivateHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestCreateGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'sendGroupMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getGroupHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestManageGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestUpdateGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'requestLeaveGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestAddFriend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_active_users'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_all_users'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'set_receiver'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_messages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_sendMsg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_createGroup_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_create_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'get_my_groups'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'request_manage_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'open_manage_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'request_leave_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'request_update_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'send_request_add_friend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_logout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ChatClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logOut((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->requestGetAllUsers(); break;
        case 2: _t->sendPrivateMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->getPrivateHistory(); break;
        case 4: _t->requestCreateGroup((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 5: _t->sendGroupMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->getGroupHistory(); break;
        case 7: _t->requestManageGroup((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->requestUpdateGroup((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 9: _t->requestLeaveGroup((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->requestAddFriend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->get_active_users((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->get_all_users((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->set_receiver((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 14: _t->get_messages((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->on_pushButton_sendMsg_clicked(); break;
        case 16: _t->on_pushButton_createGroup_clicked(); break;
        case 17: _t->request_create_group((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 18: _t->get_my_groups((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->request_manage_group((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->open_manage_group((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 21: _t->request_leave_group((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->request_update_group((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 23: _t->send_request_add_friend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->on_pushButton_logout_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatClient::*)(QString );
            if (_t _q_method = &ChatClient::logOut; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)();
            if (_t _q_method = &ChatClient::requestGetAllUsers; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(QString );
            if (_t _q_method = &ChatClient::sendPrivateMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)();
            if (_t _q_method = &ChatClient::getPrivateHistory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(QString , QStringList );
            if (_t _q_method = &ChatClient::requestCreateGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(QString );
            if (_t _q_method = &ChatClient::sendGroupMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)();
            if (_t _q_method = &ChatClient::getGroupHistory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString );
            if (_t _q_method = &ChatClient::requestManageGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString , QStringList );
            if (_t _q_method = &ChatClient::requestUpdateGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString );
            if (_t _q_method = &ChatClient::requestLeaveGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , QString );
            if (_t _q_method = &ChatClient::requestAddFriend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject *ChatClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSChatClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChatClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void ChatClient::logOut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatClient::requestGetAllUsers()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChatClient::sendPrivateMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatClient::getPrivateHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ChatClient::requestCreateGroup(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChatClient::sendGroupMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ChatClient::getGroupHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ChatClient::requestManageGroup(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ChatClient::requestUpdateGroup(const QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ChatClient::requestLeaveGroup(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ChatClient::requestAddFriend(const QString & _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP

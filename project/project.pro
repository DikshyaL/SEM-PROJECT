QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += sql
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calcdialog.cpp \
    listdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    piedialog.cpp \
    profiledialog.cpp \
    regdialog.cpp \
    secdialog.cpp

HEADERS += \
    calcdialog.h \
    listdialog.h \
    mainwindow.h \
    piedialog.h \
    profiledialog.h \
    regdialog.h \
    secdialog.h

FORMS += \
    calcdialog.ui \
    listdialog.ui \
    mainwindow.ui \
    piedialog.ui \
    profiledialog.ui \
    regdialog.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../Pictures/Screenshots/bus.qrc \
    ../../Pictures/Screenshots/calc.qrc \
    ../../Pictures/Screenshots/dash.qrc \
    ../../Pictures/Screenshots/dashh.qrc \
    ../../Pictures/Screenshots/duftiii.qrc \
    ../../Pictures/Screenshots/group.qrc \
    ../../Pictures/Screenshots/home.qrc \
    ../../Pictures/Screenshots/hya.qrc \
    ../../Pictures/Screenshots/hyuuu.qrc \
    ../../Pictures/Screenshots/logo.qrc \
    ../../Pictures/Screenshots/logo2.qrc \
    ../../Pictures/Screenshots/logooo.qrc \
    ../../Pictures/Screenshots/loooo.qrc \
    ../../Pictures/Screenshots/pic.qrc \
    ../../Pictures/Screenshots/pie.qrc \
    ../../Pictures/Screenshots/profile.qrc \
    ../../Pictures/Screenshots/profile2.qrc \
    ../../Pictures/Screenshots/prooo.qrc \
    ../../Pictures/Screenshots/qttt.qrc \
    ../../Pictures/Screenshots/ramen.qrc \
    ../../Pictures/Screenshots/things.qrc

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    employee.cpp \
    date.cpp \
    display.cpp \
    loginmanagement.cpp \
    management.cpp \
    manager.cpp \
    nailtechnician.cpp


HEADERS += \
    employee.h \
    date.h \
    display.h \
    loginmanagement.h \
    management.h \
    manager.h \
    nailtechnician.h

DISTFILES += \
    login.txt


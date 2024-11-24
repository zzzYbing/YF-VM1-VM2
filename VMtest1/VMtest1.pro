QT       += core gui axcontainer network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_control.cpp \
    dlg_display.cpp \
    dlg_native.cpp \
    dlg_vision.cpp \
    m_set.cpp \
    main.cpp \
    mainwindow.cpp \
    includevm\vmfrontendcontrolwinform.cpp \
    includevm\vmglobaltoolwinform.cpp \
    includevm\vmmainviewcontrolwinform.cpp \
    includevm\vmparamscontrolwinform.cpp \
    includevm\vmparamsrendercontrolwinform.cpp \
    includevm\vmprocedurecontrolwinform.cpp \
    includevm\vmrealtimeacqcontrolwinform.cpp \
    includevm\vmrendercontrolwinform.cpp \
    includevm\vmsinglemodulesetcontrolwinform.cpp \
    setcl.cpp \
    setsol.cpp \
    solution.cpp

HEADERS += \
    dlg_control.h \
    dlg_display.h \
    dlg_native.h \
    dlg_vision.h \
    includevm\VmControlBaseInfo.h \
    m_set.h \
    mainwindow.h \
    includevm\vmfrontendcontrolwinform.h \
    includevm\vmglobaltoolwinform.h \
    includevm\vmmainviewcontrolwinform.h \
    includevm\vmparamscontrolwinform.h \
    includevm\vmparamsrendercontrolwinform.h \
    includevm\vmprocedurecontrolwinform.h \
    includevm\vmrealtimeacqcontrolwinform.h \
    includevm\vmrendercontrolwinform.h \
    includevm\vmsinglemodulesetcontrolwinform.h \
    setcl.h \
    setsol.h \
    solution.h

FORMS += \
    dlg_control.ui \
    dlg_display.ui \
    dlg_native.ui \
    dlg_vision.ui \
    m_set.ui \
    mainwindow.ui \
    setcl.ui \
    setsol.ui \
    solution.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 替换为自己的VisionMaster4.3.0安装路径
win32: LIBS += -L'D:/VisionMaster4.3.0/Development/V4.x/Libraries/win64/C/' -liMVS-6000PlatformSDK

INCLUDEPATH += 'D:/VisionMaster4.3.0/Development/V4.x/Includes'
DEPENDPATH += 'D:/VisionMaster4.3.0/Development/V4.x/Includes'

RESOURCES += \
    Icon.qrc

RC_ICONS = favicon.ico


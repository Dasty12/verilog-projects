QT -= gui
QT += printsupport
CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += c:\msys64\usr\share\verilator\include
INCLUDEPATH += c:\msys64\usr\share\verilator\include\vltstd
INCLUDEPATH += C:\Users\david.jensi\Desktop\taaaaaaaaaaa\QCustomPlot


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#LIBS += ..\*.o

SOURCES += \
        ggg.cpp \
        main.cpp \
        c:\msys64\usr\share\verilator\include\verilated.cpp \
        c:\SPB_Data\projects\verilator_qt\obj_dir\Vtest.cpp \
        c:\SPB_Data\projects\verilator_qt\obj_dir\Vtest__Syms.cpp \
        c:\SPB_Data\projects\verilator_qt\obj_dir\Vtest___024root__Slow.cpp \
        c:\SPB_Data\projects\verilator_qt\obj_dir\Vtest___024root__DepSet_hc07518e4__0.cpp \
        c:\SPB_Data\projects\verilator_qt\obj_dir\Vtest___024root__DepSet_hc07518e4__0__Slow.cpp
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ggg.h

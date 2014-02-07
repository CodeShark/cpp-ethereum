#-------------------------------------------------
#
# Project created by QtCreator 2014-01-22T11:47:38
#
#-------------------------------------------------

QT       += core gui widgets network


TARGET = alephzero
TEMPLATE = app

CONFIG(debug, debug|release): DEFINES += ETH_DEBUG

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ../ /usr/x86_64-w64-mingw32/include
QMAKE_LIBDIR += ../libethereum/lib ../../cryptopp562 /usr/x86_64-w64-mingw32/lib /usr/x86_64-w64-mingw32/plugins/platforms
LIBS += -lethereum -lcryptopp -lminiupnpc -lleveldb -lgmp -lboost_filesystem-mt-s -lboost_system-mt-s -lboost_chrono-mt-s -lboost_thread_win32-mt-s -lmswsock -lshlwapi -liphlpapi
#INCLUDEPATH = ../../secp256k1/include ../

SOURCES += main.cpp \
    MainWin.cpp

HEADERS  += \
    MainWin.h

FORMS    += Main.ui




QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

TARGET = tst_Message
DESTDIR = $$PWD/../../bin

INCLUDEPATH += $$PWD/../../PetAPI/include
DEPENDPATH += $$PWD/../../PetAPI/include

CONFIG(debug, debug|release) {
	contains(QMAKE_HOST.arch, x86_64) {
		LIBS += -L$$PWD/../../bin -llibPetAPI_x64d
	} else {
		LIBS += -L$$PWD/../../bin -llibPetAPI_x86d
	}
} else:CONFIG(release, debug|release) {
	contains(QMAKE_HOST.arch, x86_64) {
		LIBS += -L$$PWD/../../bin -llibPetAPI_x64
	} else {
		LIBS += -L$$PWD/../../bin -llibPetAPI_x86
	}
}

SOURCES +=  $$PWD/src/tst_Message.cpp

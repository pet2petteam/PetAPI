#-------------------------------------------------
#
# Project created by QtCreator 2019-02-20T18:01:08
#
#-------------------------------------------------

TEMPLATE = lib

DEFINES += PETAPI_EXPORT

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = $$PWD/../bin

CONFIG(debug, debug|release) {
	contains(QMAKE_HOST.arch, x86_64) {
		TARGET = PetAPI_x64d
	} else {
		TARGET = PetAPI_x86d
	}
} else:CONFIG(release, debug|release) {
	contains(QMAKE_HOST.arch, x86_64) {
		TARGET = PetAPI_x64
	} else {
		TARGET = PetAPI_x86
	}
}

INCLUDEPATH += $$PWD/include

SOURCES += $$PWD/src/Container/ByteBuffer.cpp
SOURCES += $$PWD/src/DataStruct/Message.cpp
SOURCES += $$PWD/src/DataStruct/DateTime.cpp
SOURCES += $$PWD/src/DataStruct/File.cpp

HEADERS += $$PWD/include/Container/ByteBuffer.h
HEADERS += $$PWD/include/DataStruct/Message.h
HEADERS += $$PWD/include/DataStruct/DateTime.h
HEADERS += $$PWD/include/DataStruct/File.h
HEADERS += $$PWD/include/PetAPI_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

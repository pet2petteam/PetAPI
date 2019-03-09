#include <QtTest>
#include <QTime>

#include <DataStruct/DateTime.h>
#include <Container/ByteBuffer.h>

using namespace PetAPI;

class tst_Time : public QObject {
	
	Q_OBJECT
	
public:
	
	tst_Time() = default;
	~tst_Time() = default;
	
private slots:
	
	void tst_currentTime();
	void tst_fromToByteBuffer();
	
};

void tst_Time::tst_currentTime() {
	Time time = Time::currentTime();
	QTime qtime = QTime::currentTime();
	
	QVERIFY(time.hour == qtime.hour());
	QVERIFY(time.minute == qtime.minute());
	QVERIFY(time.second == qtime.second());
}

void tst_Time::tst_fromToByteBuffer() {
	Time time_1 = Time::currentTime();
	ByteBuffer timeBuffer = time_1.toByteBuffer();
	Time time_2 = Time::fromByteBuffer(timeBuffer);
	
	QVERIFY(time_1 == time_2);
}

QTEST_APPLESS_MAIN(tst_Time)
#include "tst_Time.moc"

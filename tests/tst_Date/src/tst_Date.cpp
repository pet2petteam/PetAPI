#include <QtTest>
#include <QDate>

#include <Container/ByteBuffer.h>
#include <DataStruct/DateTime.h>

using namespace PetAPI;

class tst_Date : public QObject {
	
	Q_OBJECT
	
public:
	
	tst_Date() = default;
	~tst_Date() = default;
	
private slots:
	
	void tst_currentDate();
	void tst_fromToByteBuffer();
	
};

void tst_Date::tst_currentDate() {
	Date date = Date::currentDate();
	QDate qdate = QDate::currentDate();
	
	QVERIFY(qdate.year() == date.year);
	QVERIFY(qdate.month() == date.month);
	QVERIFY(qdate.day() == date.day);
}

void tst_Date::tst_fromToByteBuffer() {
	Date date_1 = Date::currentDate();
	ByteBuffer dateBuffer = date_1.toByteBuffer();
	Date date_2 = Date::fromByteBuffer(dateBuffer);
	
	QVERIFY(date_1 == date_2);
}

QTEST_APPLESS_MAIN(tst_Date)
#include "tst_Date.moc"

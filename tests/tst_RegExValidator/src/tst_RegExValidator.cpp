#include <QtTest>
#include <QTime>

#include <Utils/RegExValidator.h>

using namespace PetAPI;

class tst_RegExValidator : public QObject {
	
	Q_OBJECT
	
public:
	
	tst_RegExValidator() = default;
	~tst_RegExValidator() = default;
	
private slots:
	
	void tst_validator();
	
};

void tst_RegExValidator::tst_validator() {
	QVERIFY(Utils::RegExValidator::isDataValid("andrejj7771", Utils::LOGIN_DEF_VALIDATION_PATTERN) == true);
	QVERIFY(Utils::RegExValidator::isDataValid("andrey1996", Utils::LOGIN_DEF_VALIDATION_PATTERN) == true);
	QVERIFY(Utils::RegExValidator::isDataValid("Nikulin_314", Utils::LOGIN_DEF_VALIDATION_PATTERN) == true);
	QVERIFY(Utils::RegExValidator::isDataValid("user@example.com", Utils::EMAIL_DEF_VALIDATION_PATTERN) == true);
	QVERIFY(Utils::RegExValidator::isDataValid("andrejj7771@something.ru", Utils::EMAIL_DEF_VALIDATION_PATTERN) == true);
	QVERIFY(Utils::RegExValidator::isDataValid("itisnottrue_", Utils::LOGIN_DEF_VALIDATION_PATTERN) == false);
	QVERIFY(Utils::RegExValidator::isDataValid("the_great_person", Utils::PASSWORD_DEF_VALIDATION_PATTERN) == false);
	QVERIFY(Utils::RegExValidator::isDataValid("user@example", Utils::EMAIL_DEF_VALIDATION_PATTERN) == false);
	QVERIFY(Utils::RegExValidator::isDataValid("userexample.ru", Utils::EMAIL_DEF_VALIDATION_PATTERN) == false);
	
}

QTEST_APPLESS_MAIN(tst_RegExValidator)
#include "tst_RegExValidator.moc"

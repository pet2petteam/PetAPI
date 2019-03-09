#include <QtTest>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <string>

#include <DataStruct/Message.h>
#include <Container/ByteBuffer.h>

using namespace PetAPI;

const std::string tst_messageText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                                    "sed do eiusmod tempor incididunt ut labore et dolore magna "
                                    "aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
                                    "ullamco laboris nisi ut aliquip ex ea commodo consequat. "
                                    "Duis aute irure dolor in reprehenderit in voluptate velit "
                                    "esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
                                    "occaecat cupidatat non proident, sunt in culpa qui officia "
                                    "deserunt mollit anim id est laborum.";

class tst_Message : public QObject {
	
	Q_OBJECT
	
	Message m_testMessage;
	
public:
	
	tst_Message() = default;
	~tst_Message() = default;
	
private slots:
	
	void tst_messageStructWOFiles();	//Without files
	void tst_messageStructWFiles();		//With files
	
};

void tst_Message::tst_messageStructWOFiles() {
	m_testMessage.clear();
	
	m_testMessage.setText(tst_messageText);
	const ByteBuffer & buff = m_testMessage.toByteBuffer();
	Message mess = Message::fromByteBuffer(buff);
	QVERIFY(m_testMessage.getText() == mess.getText());
}

void tst_Message::tst_messageStructWFiles() {
	m_testMessage.clear();
	m_testMessage.setText(tst_messageText);
	std::vector<QString> names;
	names.push_back("tst_text.txt");
	names.push_back("tst_img.jpg");
	
	for (size_t i = 0; i < names.size(); ++i) {
		QFile f("../tests/tst_Message/tst_files/" + names.at(i));
		QVERIFY(f.open(QFile::ReadOnly));
		const QByteArray & fArray = f.readAll();
		ByteBuffer array(fArray.toStdString());
		m_testMessage.appendFile(names.at(i).toStdString(), array);
		f.close();
	}
	
	const ByteBuffer & buffer = m_testMessage.toByteBuffer();
	Message mess = Message::fromByteBuffer(buffer);
	QVERIFY(m_testMessage.getText() == mess.getText());
	QVERIFY(m_testMessage.getNumFiles() == mess.getNumFiles());
	for (size_t i = 0; i < mess.getNumFiles(); ++i) {
		QVERIFY(mess.getFile(i).fileSize == m_testMessage.getFile(i).fileSize);
		QVERIFY(mess.getFile(i).fileName == m_testMessage.getFile(i).fileName);
		QVERIFY(mess.getFile(i).fileData == m_testMessage.getFile(i).fileData);
	}
}

QTEST_APPLESS_MAIN(tst_Message)
#include "tst_Message.moc"

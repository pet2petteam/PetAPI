#include <QtTest>

#include <Container/ByteBuffer.h>

using namespace PetAPI;

class tst_ByteBuffer : public QObject {
	
	Q_OBJECT
	
	ByteBuffer m_testBuffer;
	
public:
	
	tst_ByteBuffer() = default;
	~tst_ByteBuffer() = default;
	
private slots:
	
	void init();
	
	void test_AppendParse_uChar();
	void test_AppendParse_charLessZero();
	void test_AppendParse_int();
	void test_AppendParse_string();
	void test_AppendParse_buffer();
	
	void test_checkEquality();
};

void tst_ByteBuffer::init() { m_testBuffer.clear(); }

void tst_ByteBuffer::test_AppendParse_uChar() {
	unsigned char test_ucharVar_1 = 143;
	unsigned char test_ucharVar_2 = 255;
	unsigned char test_ucharVar_3 = 'a';
	unsigned char test_ucharVar_4 = 'z';
	unsigned char test_ucharVar_5 = '/';
	unsigned char test_ucharVar_6 = ':';
	
	m_testBuffer.appendVariable<unsigned char>(test_ucharVar_1);
	m_testBuffer.appendVariable<unsigned char>(test_ucharVar_2);
	m_testBuffer.appendVariable<unsigned char>(test_ucharVar_3);
	m_testBuffer.appendVariable<unsigned char>(test_ucharVar_4);
	m_testBuffer.appendVariable<unsigned char>(test_ucharVar_5);
	m_testBuffer.appendVariable<unsigned char>(test_ucharVar_6);
	
	QVERIFY(m_testBuffer.size() == 6);
	
	unsigned char test_ucharVar_1_res = 0;
	unsigned char test_ucharVar_2_res = 0;
	unsigned char test_ucharVar_3_res = 0;
	unsigned char test_ucharVar_4_res = 0;
	unsigned char test_ucharVar_5_res = 0;
	unsigned char test_ucharVar_6_res = 0;
	
	m_testBuffer.parseVariable<unsigned char>(0, test_ucharVar_1_res);
	QVERIFY(test_ucharVar_1 == test_ucharVar_1_res);
	m_testBuffer.parseVariable<unsigned char>(1, test_ucharVar_2_res);
	QVERIFY(test_ucharVar_2 == test_ucharVar_2_res);
	m_testBuffer.parseVariable<unsigned char>(2, test_ucharVar_3_res);
	QVERIFY(test_ucharVar_3 == test_ucharVar_3_res);
	m_testBuffer.parseVariable<unsigned char>(3, test_ucharVar_4_res);
	QVERIFY(test_ucharVar_4 == test_ucharVar_4_res);
	m_testBuffer.parseVariable<unsigned char>(4, test_ucharVar_5_res);
	QVERIFY(test_ucharVar_5 == test_ucharVar_5_res);
	m_testBuffer.parseVariable<unsigned char>(5, test_ucharVar_6_res);
	QVERIFY(test_ucharVar_6 == test_ucharVar_6_res);
}

void tst_ByteBuffer::test_AppendParse_charLessZero() {
	char test_ucharVar_1 = -127;
	char test_ucharVar_2 = -55;
	
	m_testBuffer.appendVariable<char>(test_ucharVar_1);
	m_testBuffer.appendVariable<char>(test_ucharVar_2);
	
	QVERIFY(m_testBuffer.size() == 2);
	
	char test_ucharVar_1_res = 0;
	char test_ucharVar_2_res = 0;
	
	m_testBuffer.parseVariable<char>(0, test_ucharVar_1_res);
	m_testBuffer.parseVariable<char>(1, test_ucharVar_2_res);
	
	QVERIFY(test_ucharVar_1 == test_ucharVar_1_res &&
			test_ucharVar_2 == test_ucharVar_2_res);
}

void tst_ByteBuffer::test_AppendParse_int() {
	int test_intVar_1 = 6236;
	int test_intVar_2 = -6247;
	int test_intVar_3 = 2647734;
	int test_intVar_4 = -345238;
	int test_intVar_5 = 352346;
	int test_intVar_6 = 10000;
	int test_intVar_7 = -10000;
	int test_intVar_8 = 235783;
	int test_intVar_9 = 524623;
	int test_intVar_10 = 3462345;
	int test_intVar_11 = 46234235;
	int test_intVar_12 = -52236353;
	
	QVERIFY2(m_testBuffer.size() == 0, "Wrong Size. Have to be 0");
	m_testBuffer.appendVariable<int>(test_intVar_1);
	QVERIFY2(m_testBuffer.size() == 4, "Wrong Size. Have to be 4");
	m_testBuffer.appendVariable<int>(test_intVar_2);
	QVERIFY2(m_testBuffer.size() == 8, "Wrong Size. Have to be 8");
	m_testBuffer.appendVariable<int>(test_intVar_3);
	QVERIFY2(m_testBuffer.size() == 12, "Wrong Size. Have to be 12");
	m_testBuffer.appendVariable<int>(test_intVar_4);
	QVERIFY2(m_testBuffer.size() == 16, "Wrong Size. Have to be 16");
	m_testBuffer.appendVariable<int>(test_intVar_5);
	QVERIFY2(m_testBuffer.size() == 20, "Wrong Size. Have to be 20");
	m_testBuffer.appendVariable<int>(test_intVar_6);
	QVERIFY2(m_testBuffer.size() == 24, "Wrong Size. Have to be 24");
	m_testBuffer.appendVariable<int>(test_intVar_7);
	QVERIFY2(m_testBuffer.size() == 28, "Wrong Size. Have to be 28");
	m_testBuffer.appendVariable<int>(test_intVar_8);
	QVERIFY2(m_testBuffer.size() == 32, "Wrong Size. Have to be 32");
	m_testBuffer.appendVariable<int>(test_intVar_9);
	QVERIFY2(m_testBuffer.size() == 36, "Wrong Size. Have to be 36");
	m_testBuffer.appendVariable<int>(test_intVar_10);
	QVERIFY2(m_testBuffer.size() == 40, "Wrong Size. Have to be 40");
	m_testBuffer.appendVariable<int>(test_intVar_11);
	QVERIFY2(m_testBuffer.size() == 44, "Wrong Size. Have to be 44");
	m_testBuffer.appendVariable<int>(test_intVar_12);
	QVERIFY2(m_testBuffer.size() == 48, "Wrong Size. Have to be 44");
	
	int test_intVar_1_res = 0;
	int test_intVar_2_res = 0;
	int test_intVar_3_res = 0;
	int test_intVar_4_res = 0;
	int test_intVar_5_res = 0;
	int test_intVar_6_res = 0;
	int test_intVar_7_res = 0;
	int test_intVar_8_res = 0;
	int test_intVar_9_res = 0;
	int test_intVar_10_res = 0;
	int test_intVar_11_res = 0;
	int test_intVar_12_res = 0;
	
	m_testBuffer.parseVariable<int>(0, test_intVar_1_res);
	QVERIFY(test_intVar_1 == test_intVar_1_res);
	m_testBuffer.parseVariable<int>(4, test_intVar_2_res);
	QVERIFY(test_intVar_2 == test_intVar_2_res);
	m_testBuffer.parseVariable<int>(8, test_intVar_3_res);
	QVERIFY(test_intVar_3 == test_intVar_3_res);
	m_testBuffer.parseVariable<int>(12, test_intVar_4_res);
	QVERIFY(test_intVar_4 == test_intVar_4_res);
	m_testBuffer.parseVariable<int>(16, test_intVar_5_res);
	QVERIFY(test_intVar_5 == test_intVar_5_res);
	m_testBuffer.parseVariable<int>(20, test_intVar_6_res);
	QVERIFY(test_intVar_6 == test_intVar_6_res);
	m_testBuffer.parseVariable<int>(24, test_intVar_7_res);
	QVERIFY(test_intVar_7 == test_intVar_7_res);
	m_testBuffer.parseVariable<int>(28, test_intVar_8_res);
	QVERIFY(test_intVar_8 == test_intVar_8_res);
	m_testBuffer.parseVariable<int>(32, test_intVar_9_res);
	QVERIFY(test_intVar_9 == test_intVar_9_res);
	m_testBuffer.parseVariable<int>(36, test_intVar_10_res);
	QVERIFY(test_intVar_10 == test_intVar_10_res);
	m_testBuffer.parseVariable<int>(40, test_intVar_11_res);
	QVERIFY(test_intVar_11 == test_intVar_11_res);
	m_testBuffer.parseVariable<int>(44, test_intVar_12_res);
	QVERIFY(test_intVar_12 == test_intVar_12_res);
}

void tst_ByteBuffer::test_AppendParse_string() {
	const std::string & test_stringVar_1 = "hello ";
	const std::string & test_stringVar_2 = "my name is ";
	const std::string & test_stringVar_3 = "andrejj7771.";
	const std::string & test_stringVar_4 = "\n";
	const std::string & test_stringVar_5 = "i am";
	const std::string & test_stringVar_6 = "the worst";
	const std::string & test_stringVar_7 = "programmer";
	const std::string & test_stringVar_8 = "ever.\n";
	const std::string & test_stringVar_1_rus = "Эта строка является";
	const std::string & test_stringVar_2_rus = "проверкой аппедда";
	const std::string & test_stringVar_3_rus = "русских";
	const std::string & test_stringVar_4_rus = "символов в буффер\n";
	
	size_t size = 0;
	m_testBuffer.append(test_stringVar_1);
	size += test_stringVar_1.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_2);
	size += test_stringVar_2.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_3);
	size += test_stringVar_3.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_4);
	size += test_stringVar_4.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_5);
	size += test_stringVar_5.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_6);
	size += test_stringVar_6.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_7);
	size += test_stringVar_7.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_8);
	size += test_stringVar_8.size();
	QVERIFY(m_testBuffer.size() == size);
	
	std::string testVar_res = test_stringVar_1 +
								test_stringVar_2 +
								test_stringVar_3 +
								test_stringVar_4 +
								test_stringVar_5 +
								test_stringVar_6 +
								test_stringVar_7 +
								test_stringVar_8;
	std::string test_res = "";
	m_testBuffer.slice(test_res, 0, size);
	QVERIFY(testVar_res == test_res);
	
	size = 0;
	m_testBuffer.clear();
	
	m_testBuffer.append(test_stringVar_1_rus);
	size += test_stringVar_1_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_2_rus);
	size += test_stringVar_2_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_3_rus);
	size += test_stringVar_3_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_stringVar_4_rus);
	size += test_stringVar_4_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	testVar_res = test_stringVar_1_rus +
	              test_stringVar_2_rus +
				  test_stringVar_3_rus +
				  test_stringVar_4_rus;
	test_res = "";
	m_testBuffer.slice(test_res, 0, size);
	QVERIFY(testVar_res == test_res);
	
}

void tst_ByteBuffer::test_AppendParse_buffer() {
	ByteBuffer test_bufferVar_1("hello ");
	ByteBuffer test_bufferVar_2("my name is ");
	ByteBuffer test_bufferVar_3("andrejj7771.");
	ByteBuffer test_bufferVar_4("\n");
	ByteBuffer test_bufferVar_5("i am");
	ByteBuffer test_bufferVar_6("the worst");
	ByteBuffer test_bufferVar_7("programmer");
	ByteBuffer test_bufferVar_8("ever.\n");
	ByteBuffer test_bufferVar_1_rus("Эта строка является");
	ByteBuffer test_bufferVar_2_rus("проверкой аппедда");
	ByteBuffer test_bufferVar_3_rus("русских");
	ByteBuffer test_bufferVar_4_rus("символов в буффер\n");
	
	size_t size = 0;
	m_testBuffer.append(test_bufferVar_1);
	size += test_bufferVar_1.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_2);
	size += test_bufferVar_2.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_3);
	size += test_bufferVar_3.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_4);
	size += test_bufferVar_4.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_5);
	size += test_bufferVar_5.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_6);
	size += test_bufferVar_6.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_7);
	size += test_bufferVar_7.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_8);
	size += test_bufferVar_8.size();
	QVERIFY(m_testBuffer.size() == size);
	
	ByteBuffer testVar_res = test_bufferVar_1 +
								test_bufferVar_2 +
								test_bufferVar_3 +
								test_bufferVar_4 +
								test_bufferVar_5 +
								test_bufferVar_6 +
								test_bufferVar_7 +
								test_bufferVar_8;
	std::string test_res = "";
	m_testBuffer.slice(test_res, 0, size);
	QVERIFY(testVar_res == test_res);
	
	size = 0;
	m_testBuffer.clear();
	
	m_testBuffer.append(test_bufferVar_1_rus);
	size += test_bufferVar_1_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_2_rus);
	size += test_bufferVar_2_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_3_rus);
	size += test_bufferVar_3_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	m_testBuffer.append(test_bufferVar_4_rus);
	size += test_bufferVar_4_rus.size();
	QVERIFY(m_testBuffer.size() == size);
	
	testVar_res = test_bufferVar_1_rus +
	              test_bufferVar_2_rus +
				  test_bufferVar_3_rus +
				  test_bufferVar_4_rus;
	test_res = "";
	m_testBuffer.slice(test_res, 0, size);
	QVERIFY(testVar_res == test_res);
}

void tst_ByteBuffer::test_checkEquality() {
	ByteBuffer tBuffer("This is a test string for equality checking.");
	
	std::string string_true = "This is a test string for equality checking.";
	std::string string_false = "This is a test string for equalitychecking.";
	ByteBuffer buffer_true("This is a test string for equality checking.");
	ByteBuffer buffer_false("This is a test string for equalitychecking.");
	
	bool test1_true = tBuffer == string_true;
	QVERIFY(test1_true);
	
	bool test1_false = tBuffer == string_false;
	QVERIFY(!test1_false);

	bool test2_true = tBuffer == buffer_true;
	QVERIFY(test2_true);
	
	bool test2_false = tBuffer == buffer_false;
	QVERIFY(!test2_false);
	
}

QTEST_APPLESS_MAIN(tst_ByteBuffer)
#include "tst_ByteBuffer.moc"

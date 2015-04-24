#include "../library/file-read-write.h"
#include "file-read-write-test.h"

bool CKDMReadWriteTest::testAll(){
	try{
		testOpen();
		testRead();
		testReadRange();
		testWriteOpen();
		testWriteAppend();
		testWriteTruncate();
		testWriteChangeMode();
		testWriteModify();
	}
	catch (std::logic_error &e){

		displayError(e.what());
		return false;
	}

	displaySuccess(TEST_FILE_NAME);

	return true;
}

bool CKDMReadWriteTest::testOpen(){
	CKDMFileRead testInstance(TEST_CASE_SRC);

	if (testInstance.isOpen() == false){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMReadWriteTest::testRead(){
	CKDMFileRead testInstance(TEST_CASE_SRC);
	
	std::cout << "Testing " << TEST_FUNCTION_NAME<< " start\n=======" << std::endl;
	std::cout.write(testInstance(), testInstance.getFileSize());
	std::cout << "\n=======" << std::endl;
	
	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMReadWriteTest::testReadRange(){
	CKDMFileRead testInstance(TEST_CASE_SRC);
	
	char testDataSrc[4] = { 'g', 'o', 'o', 'd' };
	char testDataDest[4];
		
	if (strncmp(testDataSrc, testInstance(testDataDest, 27, 4), 4) != 0){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMReadWriteTest::testWriteOpen(){
	CKDMFileWrite testInstance(TEST_CASE_DEST, CKDMFileWrite::WRITE_TRUNCATE);

	if (testInstance.isOpen() == false){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMReadWriteTest::testWriteAppend(){
	//기본 생성자는 APPEND
	CKDMFileWrite* testInstance;
	testInstance = new CKDMFileWrite(TEST_CASE_DEST);

	(*testInstance)("abc", 3);
	testInstance->writeData("def", 3);

	delete testInstance;

	//다시 생성해서 append 테스트
	testInstance = new CKDMFileWrite(TEST_CASE_DEST);

	(*testInstance)("abc", 3);
	testInstance->writeData("def", 3);

	delete testInstance;

	CKDMFileRead testInstance_read(TEST_CASE_DEST);
	if (strncmp("abcdefabcdef", testInstance_read(), 12) != 0){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}
	
	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
bool CKDMReadWriteTest::testWriteTruncate(){
	CKDMFileWrite* testInstance;
	testInstance = new CKDMFileWrite(TEST_CASE_DEST, CKDMFileWrite::WRITE_TRUNCATE);

	(*testInstance)("abc", 3);
	testInstance->writeData("def", 3);

	delete testInstance;

	//다시 생성해서 truncate 테스트
	testInstance = new CKDMFileWrite(TEST_CASE_DEST, CKDMFileWrite::WRITE_TRUNCATE);

	(*testInstance)("zxc", 3);

	delete testInstance;

	CKDMFileRead testInstance_read(TEST_CASE_DEST);
	if (strncmp("zxc", testInstance_read(), 3) != 0){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
bool CKDMReadWriteTest::testWriteChangeMode(){
	//먼저 test case 만들기
	CKDMFileWrite* testInstance;
	testInstance = new CKDMFileWrite(TEST_CASE_DEST, CKDMFileWrite::WRITE_TRUNCATE);
	(*testInstance)("abcdefabcdef", 12);
	delete testInstance;
	
	//APPEND로 열었다가 TRUNCATE로 바꿔서 지워지는지 확인
	testInstance = new CKDMFileWrite(TEST_CASE_DEST);
	testInstance->changeMode(CKDMFileWrite::WRITE_TRUNCATE);
	(*testInstance)("abc", 3);

	delete testInstance;

	CKDMFileRead* testInstace_read = new CKDMFileRead(TEST_CASE_DEST);
	if (strncmp("abc", (*testInstace_read)(), 3) != 0){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	delete testInstace_read;

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMReadWriteTest::testWriteModify(){
	//먼저 test case 만들기
	CKDMFileWrite* testInstance;
	testInstance = new CKDMFileWrite(TEST_CASE_DEST, CKDMFileWrite::WRITE_TRUNCATE);
	(*testInstance)("abcdefabcdef", 12);
	delete testInstance;

	//수정해보기
	testInstance = new CKDMFileWrite(TEST_CASE_DEST);
	testInstance->modifyData("!haruka!", 3, 8);

	delete testInstance;

	CKDMFileRead* testInstace_read = new CKDMFileRead(TEST_CASE_DEST);
	if (strncmp("abc!haruka!f", (*testInstace_read)(), 12) != 0){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	delete testInstace_read;

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
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
	
	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
bool CKDMReadWriteTest::testWriteChangeMode(){

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
bool CKDMReadWriteTest::testWriteModify(){

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
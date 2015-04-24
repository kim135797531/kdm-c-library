#ifndef KDM_SRC_AUTOTEST_FILE_READ_WRITE_TEST_H
#define KDM_SRC_AUTOTEST_FILE_READ_WRITE_TEST_H

#include <iostream>
#include <fstream>
#include "autotest-util.h"

#define TEST_CASE_SRC "../src/autotest/file-read-write-test-input.txt"
#define TEST_CASE_DEST "../src/autotest/file-read-write-test-output.txt"

#define TEST_CASE_INPUT "\
CKDMFileRead is verrrrrrry good library!\n\
Elsanna chan daisuki!!!!\n\
한글도 됨!!!\n\
日本語も使用可能!!!!!!"

class CKDMReadWriteTest : public CKDMAutotestBase{
public:
	CKDMReadWriteTest(){
		//테스트 파일 생성
		std::ofstream testCase(TEST_CASE_SRC, std::ios_base::binary);
		testCase << TEST_CASE_INPUT;
		testCase.close();
	}
	~CKDMReadWriteTest(){
		//테스트 파일 삭제
		std::remove(TEST_CASE_SRC);
		std::remove(TEST_CASE_DEST);
	}
	bool testAll();
	bool testOpen();
	bool testRead();
	bool testReadRange();
	bool testWriteOpen();
	bool testWriteAppend();
	bool testWriteTruncate();
	bool testWriteChangeMode();
	bool testWriteModify();
private:
};

#endif KDM_SRC_AUTOTEST_FILE_READ_WRITE_TEST_H
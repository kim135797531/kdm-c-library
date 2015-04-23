#ifndef KDM_SRC_AUTOTEST_FILE_READ_WRITE_TEST_H
#define KDM_SRC_AUTOTEST_FILE_READ_WRITE_TEST_H

#include "autotest-util.h"

#define TEST_CASE_SRC "../src/autotest/file-read-write-test-input.txt"
#define TEST_CASE_DEST "../src/autotest/file-read-write-test-output.txt"

class CKDMReadWriteTest : public CKDMAutotestBase{
public:
	bool testAll();
	bool testOpen();
	bool testRead();
	bool testReadRange();
	bool testWrite();
private:
};

#endif KDM_SRC_AUTOTEST_BITWISE_FLAG_TEST_H
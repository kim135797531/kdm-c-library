#ifndef KDM_SRC_AUTOTEST_BITWISE_FLAG_TEST_H
#define KDM_SRC_AUTOTEST_BITWISE_FLAG_TEST_H

#include "autotest-util.h"

class CKDMBitwiseFlagTest : public CKDMAutotestBase{
public:
	bool testAll();
	bool testFlagSmallUnsignedChar();
	bool testFlagSmallInt();
	bool testFlagLargeInt();
private:
};

#endif KDM_SRC_AUTOTEST_BITWISE_FLAG_TEST_H
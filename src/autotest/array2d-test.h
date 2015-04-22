#ifndef KDM_AUTOTEST_ARRAY2D_TEST_H
#define KDM_AUTOTEST_ARRAY2D_TEST_H

#include "autotest-util.h"

class CKDMArray2DTest : public CKDMAutotestBase{
public:
	bool testAll();
	bool testSimple();
	bool testDoublePtr();
	bool testSinglePtr();
	bool testVectorPtr();
	bool testCopyConstructor();
private:
};

#endif KDM_AUTOTEST_ARRAY2D_TEST_H
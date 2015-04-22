#ifndef KDM_SRC_AUTOTEST_AUTOTEST_UTIL_H_
#define KDM_SRC_AUTOTEST_AUTOTEST_UTIL_H_

#include <iostream>

#define TEST_FUNCTION_NAME __FUNCTION__
#define TEST_FILE_NAME __FILE__

static void inline displayError(const char* p_rgcInfo){
	std::cout << "Test failed in " << p_rgcInfo << std::endl;
};

static void inline displaySuccess(const char* p_rgcInfo){
	std::cout << "Test passed in " << p_rgcInfo << std::endl;
};

class CKDMAutotestBase{
public:
	virtual bool testAll() = 0;
private:
};

#endif KDM_SRC_AUTOTEST_AUTOTEST_UTIL_H_
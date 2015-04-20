#ifndef KDM_AUTOTEST_AUTOTEST_UTIL_H_
#define KDM_AUTOTEST_AUTOTEST_UTIL_H_

#include <iostream>

#define TEST_FUNCTION_NAME __FUNCTION__
#define TEST_FILE_NAME __FILE__

void displayError(const char* p_rgcInfo){
	std::cout << "Test failed in " << p_rgcInfo << std::endl;
}

void displaySuccess(const char* p_rgcInfo){
	std::cout << "Test passed in " << p_rgcInfo << std::endl;
}

#endif KDM_AUTOTEST_AUTOTEST_UTIL_H_
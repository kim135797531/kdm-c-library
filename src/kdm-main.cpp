#include "kdm-main.h"
#include "autotest/array2d-test.h"
#include "autotest/bitwise-flag-test.h"

/*테스팅 목적 메인 함수*/

int main(void){
	CKDMArray2DTest array2DTest;
	CKDMBitwiseFlagTest bitwiseFlagTest;
	array2DTest.testAll();
	bitwiseFlagTest.testAll();
	return 0;
}
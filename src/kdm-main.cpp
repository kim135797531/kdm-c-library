#include <vector>
#include "kdm-main.h"
#include "autotest/array2d-test.h"
#include "autotest/bitwise-flag-test.h"
#include "autotest/file-read-write-test.h"

/*테스팅 목적 메인 함수*/

int main(void){
	std::vector<CKDMAutotestBase*> vTestList;
	vTestList.push_back(new CKDMArray2DTest());
	vTestList.push_back(new CKDMBitwiseFlagTest());
	CKDMReadWriteTest* a = new CKDMReadWriteTest();
	vTestList.push_back(a);

	for (unsigned int i = 0; i < vTestList.size(); i++){
		vTestList.at(i)->testAll();
		std::cout << std::endl;
	}

	delete a;

	for (unsigned int i = 0; i < vTestList.size(); i++){
		//delete vTestList.at(i);
		
	}

	return 0;
}
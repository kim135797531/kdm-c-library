#include "../library/bitwise-flag.h"
#include "autotest-util.h"
#include "bitwise-flag-test.h"

enum ETestFlagBit{
	FLAG_TEST_BIT_1 = (1 << 7), // 128
	FLAG_TEST_BIT_2 = (1 << 6), // 64
	FLAG_TEST_BIT_3 = (1 << 5) // 32
};

enum ETestFlagIndex{
	FLAG_TEST_INDEX_1 = 13, 
	FLAG_TEST_INDEX_2 = 14,
	FLAG_TEST_INDEX_3 = 15
};

/*
비트 마스크를 받을 것인가
-> 최대 크기 받기(기본값)
-> get set 함수 비트마스크 제공
//정수-개수에만 상관 있게 받을 것인가
-> 최대 크기 받기(기본값)
-> enum 받아 크기 확인
-> get set 함수 숫자 제공
-> get set 함수 enum 제공
//정수-해당 정수 크기만큼 받을 것인가 <- 최대값을 검사하자. 
*/

bool CKDMBitwiseFlagTest::testAll(){
	try{
		testSimple();
	}
	catch (std::logic_error &e){

		displayError(e.what());
		return false;
	}

	displaySuccess(TEST_FILE_NAME);

	return true;
}

bool CKDMBitwiseFlagTest::testSimple(){
	CKDMBitwiseFlag testInstance = CKDMBitwiseFlag();
	unsigned char test = FLAG_TEST_BIT_1 | FLAG_TEST_BIT_2;
	testInstance.set(test);

	if (testInstance.check(FLAG_TEST_BIT_1) &&
		testInstance.check(FLAG_TEST_BIT_2) == false){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	return true;
}
#include "../library/bitwise-flag.h"
#include "autotest-util.h"
#include "bitwise-flag-test.h"

enum ETestFlagBit{
	FLAG_TEST_BIT_1 = (1 << 7), // 128
	FLAG_TEST_BIT_2 = (1 << 6), // 64
	FLAG_TEST_BIT_3 = (1 << 5) // 32
};

enum ETestFlagIndex{
	FLAG_HARUKA = 0,
	FLAG_CHIHAYA = 7,
	FLAG_MIKI = 15
};

/*
//비트 마스크를 받을 것인가
-> get set 함수 비트마스크 제공

//정수-개수에만 상관 있게 받을 것인가
-> 최대 크기 받기(기본값)
-> get set 함수 숫자 제공

//정수-해당 정수 크기만큼 받을 것인가 <- enum 받아 최대값 확인
-> enum 받아 크기 확인
-> get set 함수 enum 제공
*/

bool CKDMBitwiseFlagTest::testAll(){
	try{
		testFlagSmallUnsignedChar();
		testFlagSmallInt();
	}
	catch (std::logic_error &e){
		displayError(e.what());
		return false;
	}

	displaySuccess(TEST_FILE_NAME);

	return true;
}

bool CKDMBitwiseFlagTest::testFlagSmallUnsignedChar(){
	CKDMBitwiseFlagSmall* testInstance = new CKDMBitwiseFlagSmall();

	unsigned char test = FLAG_TEST_BIT_1 | FLAG_TEST_BIT_2;
	testInstance->set(test);

	if (testInstance->check((unsigned char)FLAG_TEST_BIT_1) &&
		testInstance->check((unsigned char)FLAG_TEST_BIT_2) == false){ //세팅 안 됐으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->unset((unsigned char)FLAG_TEST_BIT_1);
	if (testInstance->check((unsigned char)FLAG_TEST_BIT_1) &&
		testInstance->check((unsigned char)FLAG_TEST_BIT_2) == true){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->clear();
	if (testInstance->isEmpty() == false){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	return true;
}

bool CKDMBitwiseFlagTest::testFlagSmallInt(){
	CKDMBitwiseFlag* testInstance = new CKDMBitwiseFlagSmall();

	testInstance->set(FLAG_HARUKA);
	testInstance->set(FLAG_CHIHAYA);

	if (testInstance->check(FLAG_HARUKA) &&
		testInstance->check(FLAG_CHIHAYA) == false){ //세팅 안 됐으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->unset(FLAG_HARUKA);
	if (testInstance->check(FLAG_HARUKA) &&
		testInstance->check(FLAG_CHIHAYA) == true){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->clear();
	if (testInstance->isEmpty() == false){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	return true;
}
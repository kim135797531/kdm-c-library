#include "../library/bitwise-flag.h"
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
	CKDMBitwiseFlag* testInstance = CKDMBitwiseFlagFactory::createFlag(CKDMBitwiseFlagFactory::FLAG_SMALL);
	
	unsigned char test = FLAG_TEST_BIT_1 | FLAG_TEST_BIT_2;
	testInstance->set(unsigned char(test), 0);

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

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMBitwiseFlagTest::testFlagSmallInt(){
	CKDMBitwiseFlag* testInstance = CKDMBitwiseFlagFactory::createFlag(CKDMBitwiseFlagFactory::FLAG_SMALL);

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

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
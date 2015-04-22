#include "../library/bitwise-flag.h"
#include "bitwise-flag-test.h"

#define	FLAG_TEST_BIT_1  (1 << 1) // 2
#define FLAG_TEST_BIT_7  (1 << 7) // 128

enum ETestFlagIndex{
	FLAG_HARUKA = 0,
	FLAG_CHIHAYA = 5,
	FLAG_TAKANE = 11,
	FLAG_MIKI = 77
};

bool CKDMBitwiseFlagTest::testAll(){
	try{
		testFlagSmallUnsignedChar();
		testFlagSmallInt();
		testFlagLargeInt();
	}
	catch (std::logic_error &e){
		displayError(e.what());
		return false;
	}

	displaySuccess(TEST_FILE_NAME);

	return true;
}

bool CKDMBitwiseFlagTest::testFlagSmallUnsignedChar(){
	CKDMBitwiseFlag* testInstance = new CKDMBitwiseFlag();
	
	unsigned char test = FLAG_TEST_BIT_1 | FLAG_TEST_BIT_7;
	testInstance->setByBit(test);

	if (testInstance->checkByBit(FLAG_TEST_BIT_1) &&
		testInstance->checkByBit(FLAG_TEST_BIT_7) == false){ //세팅 안 됐으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->unsetByBit(FLAG_TEST_BIT_1);
	if (testInstance->checkByBit(FLAG_TEST_BIT_1) &&
		testInstance->checkByBit(FLAG_TEST_BIT_7) == true){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->clear();
	if (testInstance->isEmpty() == false){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	delete testInstance;

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMBitwiseFlagTest::testFlagSmallInt(){
	CKDMBitwiseFlag* testInstance = new CKDMBitwiseFlag(6);

	testInstance->setByIndex(FLAG_HARUKA);
	testInstance->setByIndex(FLAG_CHIHAYA);

	if (testInstance->checkByIndex(FLAG_HARUKA) &&
		testInstance->checkByIndex(FLAG_CHIHAYA) == false){ //세팅 안 됐으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->unsetByIndex(FLAG_HARUKA);
	if (testInstance->checkByIndex(FLAG_HARUKA) &&
		testInstance->checkByIndex(FLAG_CHIHAYA) == true){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->clear();
	if (testInstance->isEmpty() == false){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	delete testInstance;

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}

bool CKDMBitwiseFlagTest::testFlagLargeInt(){
	CKDMBitwiseFlag* testInstance = new CKDMBitwiseFlag(100);

	testInstance->setByIndex(FLAG_HARUKA);
	testInstance->setByIndex(FLAG_CHIHAYA);
	testInstance->setByIndex(FLAG_TAKANE);
	testInstance->setByIndex(FLAG_MIKI);
	
	if (testInstance->checkByIndex(FLAG_HARUKA) &&
		testInstance->checkByIndex(FLAG_CHIHAYA) &&
		testInstance->checkByIndex(FLAG_TAKANE) &&
		testInstance->checkByIndex(FLAG_MIKI) == false){ //세팅 안 됐으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->unsetByIndex(FLAG_HARUKA);
	if (testInstance->checkByIndex(FLAG_HARUKA) &&
		testInstance->checkByIndex(FLAG_CHIHAYA) &&
		testInstance->checkByIndex(FLAG_TAKANE) &&
		testInstance->checkByIndex(FLAG_MIKI) == true){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance->clear();
	if (testInstance->isEmpty() == false){ //안 지워졌으면
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	delete testInstance;

	displaySuccess(TEST_FUNCTION_NAME);
	return true;
}
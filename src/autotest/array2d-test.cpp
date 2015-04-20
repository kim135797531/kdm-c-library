#include "../library/array2d.h"
#include "autotest-util.h"
#include "array2d-test.h"

bool CKDMArray2DTest::testAll(){
	try{
		testSimple();
		testDoublePtr();
		testSinglePtr();
		testVectorPtr();
	}
	catch(std::logic_error &e){
		
		displayError(e.what());
		return false;
	}

	displaySuccess(TEST_FILE_NAME);

	return true;
}

bool CKDMArray2DTest::testSimple(){
	CKDMArray2D<char> testInstance = CKDMArray2D<char>(2, 2);
	char cTestInput = 'a';
	testInstance(1, 1) = cTestInput;
	
	if (testInstance(1, 1) == NULL ||
		testInstance(1, 1) != cTestInput){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	return true;
}

bool CKDMArray2DTest::testDoublePtr(){
	char** c_rgTestArray = new char*[2];
	c_rgTestArray[0] = new char[2];
	c_rgTestArray[1] = new char[2];

	char cTestInput = 'a';
	c_rgTestArray[1][1] = cTestInput;

	CKDMArray2D<char> testInstance = CKDMArray2D<char>(2, 2, c_rgTestArray);
	
	if (testInstance(1, 1) == NULL ||
		testInstance(1, 1) != cTestInput){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	testInstance(0, 0) = cTestInput;

	if (testInstance(0, 0) == NULL ||
		testInstance(0, 0) != cTestInput){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	return true;
}

bool CKDMArray2DTest::testSinglePtr(){
	char c_rgTestArray[2][2];
	char cTestInput = 'a';
	c_rgTestArray[1][1] = cTestInput;

	CKDMArray2D<char> testInstance = CKDMArray2D<char>(2, 2, &c_rgTestArray[0][0]);

	if (testInstance(1, 1) == NULL ||
		testInstance(1, 1) != cTestInput){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}

	return true;
}

bool CKDMArray2DTest::testVectorPtr(){
	std::vector<char> c_rgTestArray;
	c_rgTestArray.resize(4);

	char cTestInput = 'a';
	c_rgTestArray.at(3) = cTestInput;

	CKDMArray2D<char> testInstance = CKDMArray2D<char>(2, 2, &c_rgTestArray);

	if (testInstance(1, 1) == NULL ||
		testInstance(1, 1) != cTestInput){
		throw std::logic_error(TEST_FUNCTION_NAME);
	}
	return true;
}
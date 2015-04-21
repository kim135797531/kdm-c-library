#ifndef KDM_SRC_LIBRARY_BITWISE_FLAG_H_
#define KDM_SRC_LIBRARY_BITWISE_FLAG_H_

#include <iostream>

#define BIT_OF_ONE_BYTE 8
#define MAX_FLAG_COUNT_IN_DESIGN 1000
#define ROW(index) ((index)/BIT_OF_ONE_BYTE)
#define COL(index) ((index)%BIT_OF_ONE_BYTE)

class CKDMBitwiseFlag{
public:
	CKDMBitwiseFlag()
	{
	}

	virtual ~CKDMBitwiseFlag(){
		
	}

	//0번부터 시작
	virtual bool check(void* p_pvIndex) const{
	}

	virtual void set(void* p_pvIndex){
	}

	virtual void reset(){
	}

private:
};

//1byte만 쓴다. Flag 8개 저장 가능
class CKDMBitwiseFlagSmall : public CKDMBitwiseFlag{

};

//배열을 쓴다. Flag 최대 1024개 저장 가능
class CKDMBitwiseFlagLarge : public CKDMBitwiseFlag{

};


#endif KDM_SRC_LIBRARY_BITWISE_FLAG_H_
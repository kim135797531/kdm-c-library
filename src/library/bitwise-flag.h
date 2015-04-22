#ifndef KDM_SRC_LIBRARY_BITWISE_FLAG_H_
#define KDM_SRC_LIBRARY_BITWISE_FLAG_H_

#include <iostream>

#define BITS_OF_ONE_BYTE 8
#define MAX_FLAG_COUNT_IN_DESIGN 1024
#define ROW(index) ((index)/BITS_OF_ONE_BYTE)
#define COL(index) ((index)%BITS_OF_ONE_BYTE)

class CKDMBitwiseFlag{
public:
	CKDMBitwiseFlag(unsigned char p_ucData = 0)
	{
	}

	virtual ~CKDMBitwiseFlag(){}

	virtual bool check(int p_iBitIndex) const = 0;
	virtual void set(int p_pvIndex) = 0;
	virtual void unset(int p_pvIndex) = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;

	bool isValidMaxCount(int p_nFlagMaxCount) const{
		if (p_nFlagMaxCount < 0){
			throw std::logic_error("Error: Range Underflow");
		}
		else if (p_nFlagMaxCount > MAX_FLAG_COUNT_IN_DESIGN){
			throw std::logic_error(
				"Error: CKDMBitwiseFlag Class supports the number of flags in 1~1024.\n\
				Too many flag denotes that your architecture design is maybe wrong. Sorry."
			);
		}
		return true;
	}
};

//1byte만 쓴다. Flag 0~7 저장 가능
class CKDMBitwiseFlagSmall : public CKDMBitwiseFlag{
public:
	CKDMBitwiseFlagSmall(unsigned char p_ucData = 0) :
	m_ucData(p_ucData)
	{
	}

	~CKDMBitwiseFlagSmall(){
	}

	bool check(int p_iBitIndex) const {
		if (!isValidMaxCount(p_iBitIndex))
			return false;

		return this->check(unsigned char(1 << p_iBitIndex));
	}

	bool check(unsigned char p_ucBitmask) const {
		return (this->m_ucData & p_ucBitmask) != 0;
	}

	void set(int p_iBitIndex){
		if (!isValidMaxCount(p_iBitIndex))
			return;

		this->set(unsigned char(1 << p_iBitIndex));
	}

	void set(unsigned char p_ucBitmask){
		this->m_ucData |= p_ucBitmask;
	}

	void unset(int p_iBitIndex){
		if (!isValidMaxCount(p_iBitIndex))
			return;

		this->unset(unsigned char(1 << p_iBitIndex));
	}

	void unset(unsigned char p_ucBitmask){
		this->m_ucData &= ~p_ucBitmask;
	}

	void clear(){
		m_ucData = 0;
	}

	bool isEmpty(){
		return m_ucData == 0;
	}

	bool isValidMaxCount(int p_nFlagMaxCount) const{
		try{
			CKDMBitwiseFlag::isValidMaxCount(p_nFlagMaxCount);
			if (p_nFlagMaxCount > this->m_nTotalFlagCount){
				throw std::logic_error("Error: Range Overflow");
			}
		}
		catch (std::logic_error &e){
			std::cerr << "Invalid Range : " << p_nFlagMaxCount << std::endl;
			std::cerr << e.what() << std::endl;
			return false;
		}

		return true;
	}

private:
	const int m_nTotalFlagCount = BITS_OF_ONE_BYTE;
	unsigned char m_ucData;
};

//배열을 쓴다. Flag 최대 1024개 저장 가능
class CKDMBitwiseFlagLarge : public CKDMBitwiseFlag{

};

#endif KDM_SRC_LIBRARY_BITWISE_FLAG_H_
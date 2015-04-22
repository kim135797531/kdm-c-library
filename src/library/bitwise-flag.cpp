#include <iostream>
#include "bitwise-flag.h"

CKDMBitwiseFlag::CKDMBitwiseFlag(int p_nTotalSize) :
m_nTotalFlagCount(p_nTotalSize),
m_nTotalDataArrayLength(1 + ROW(p_nTotalSize - 1))
{
	if (this->m_nTotalFlagCount > MAX_FLAG_COUNT_IN_DESIGN){
		std::cerr << "Warning: Too many flag denotes that your architecture design is maybe wrong." << std::endl;
	}
	this->m_ucData = new unsigned char[m_nTotalDataArrayLength];
	this->clear();
}


bool CKDMBitwiseFlag::checkByBit(unsigned char p_ucBitmask, int p_iBitIndex) const {
	//getPartData 결과에서 값 변경 안 할것이므로 캐스팅한다.
	unsigned char* ucCastedPartData = const_cast<CKDMBitwiseFlag&>(*this).getPartData(p_iBitIndex);
	return (*ucCastedPartData & p_ucBitmask) != 0;
}

void CKDMBitwiseFlag::setByBit(unsigned char p_ucBitmask, int p_iBitIndex){
	*this->getPartData(p_iBitIndex) |= p_ucBitmask;
}

void CKDMBitwiseFlag::unsetByBit(unsigned char p_ucBitmask, int p_iBitIndex){
	*this->getPartData(p_iBitIndex) &= ~p_ucBitmask;
}


bool CKDMBitwiseFlag::checkByIndex(int p_iBitIndex) const {
	return CKDMBitwiseFlag::checkByBit(unsigned char(1 << COL(p_iBitIndex)), p_iBitIndex);
}

void CKDMBitwiseFlag::setByIndex(int p_iBitIndex){
	CKDMBitwiseFlag::setByBit(unsigned char(1 << COL(p_iBitIndex)), p_iBitIndex);
}

void CKDMBitwiseFlag::unsetByIndex(int p_iBitIndex){
	CKDMBitwiseFlag::unsetByBit(unsigned char(1 << COL(p_iBitIndex)), p_iBitIndex);
}


void CKDMBitwiseFlag::clear(){
	memset(m_ucData, 0, sizeof(unsigned char)*m_nTotalDataArrayLength);
}

bool CKDMBitwiseFlag::isEmpty(){
	for (int i = 0; i < m_nTotalDataArrayLength; i++){
		if (m_ucData[i] != 0)
			return false;
	}
	return true;
}

bool CKDMBitwiseFlag::isValidMaxCount(int p_nFlagMaxCount) const {
	try{
		if (p_nFlagMaxCount < 0){
			throw std::logic_error("Error: Range Underflow");
		}
		else if (p_nFlagMaxCount > this->m_nTotalFlagCount){
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

unsigned char* CKDMBitwiseFlag::getPartData(int p_iBitIndex){
	return (isValidMaxCount(p_iBitIndex)) ? &m_ucData[ROW(p_iBitIndex)] : 0;
}
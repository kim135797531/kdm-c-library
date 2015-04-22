#include <iostream>
#include "bitwise-flag-impl.h"

bool CKDMBitwiseFlag::check(unsigned char p_ucBitmask, int p_iRow) const {
	//getPartData 결과에서 값 변경 안 할것이므로 캐스팅한다.
	unsigned char* ucCastedPartData = const_cast<CKDMBitwiseFlag&>(*this).getPartData(p_iRow);
	return (*ucCastedPartData & p_ucBitmask) != 0;
}

void CKDMBitwiseFlag::set(unsigned char p_ucBitmask, int p_iRow){
	*this->getPartData(p_iRow) |= p_ucBitmask;
}

void CKDMBitwiseFlag::unset(unsigned char p_ucBitmask, int p_iRow){
	*this->getPartData(p_iRow) &= ~p_ucBitmask;
}

bool CKDMBitwiseFlag::isValidMaxCount(int p_nFlagMaxCount) const {
	if (p_nFlagMaxCount < 0){
		throw std::logic_error("Error: Range Underflow");
	}
	return true;
}


bool CKDMBitwiseFlagSmall::check(int p_iBitIndex) const {
		return CKDMBitwiseFlag::check(unsigned char(1 << COL(p_iBitIndex)), ROW(p_iBitIndex));
	}

void CKDMBitwiseFlagSmall::set(int p_iBitIndex){
		CKDMBitwiseFlag::set(unsigned char(1 << COL(p_iBitIndex)), ROW(p_iBitIndex));
	}
			
void CKDMBitwiseFlagSmall::unset(int p_iBitIndex){
		CKDMBitwiseFlag::unset(unsigned char(1 << COL(p_iBitIndex)), ROW(p_iBitIndex));
	}                      

void CKDMBitwiseFlagSmall::clear(){
		*this->getPartData() = 0;
	}

bool CKDMBitwiseFlagSmall::isEmpty(){
		return *this->getPartData() == 0;
	}	

bool CKDMBitwiseFlagSmall::isValidMaxCount(int p_nFlagMaxCount) const{
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

unsigned char* CKDMBitwiseFlagSmall::getPartData(int p_iBitIndex){
		return (isValidMaxCount(p_iBitIndex)) ? &m_ucData : 0;
	}



CKDMBitwiseFlagLarge::CKDMBitwiseFlagLarge(int p_nTotalSize) :
		m_nTotalFlagCount(p_nTotalSize)
	{
		if (m_nTotalFlagCount > MAX_FLAG_COUNT_IN_DESIGN){
			std::cerr << "Warning: Too many flag denotes that your architecture design is maybe wrong." << std::endl;
		}
		m_ucData = new unsigned char[1+ROW(p_nTotalSize)];
	}


bool CKDMBitwiseFlagLarge::check(int p_iBitIndex) const {
		return CKDMBitwiseFlag::check(unsigned char(1 << COL(p_iBitIndex)), ROW(p_iBitIndex));
	}

void CKDMBitwiseFlagLarge::set(int p_iBitIndex){
		CKDMBitwiseFlag::set(unsigned char(1 << COL(p_iBitIndex)), ROW(p_iBitIndex));
	}

void CKDMBitwiseFlagLarge::unset(int p_iBitIndex){
		CKDMBitwiseFlag::unset(unsigned char(1 << COL(p_iBitIndex)), ROW(p_iBitIndex));
	}
	
void CKDMBitwiseFlagLarge::clear(){
		memset(m_ucData, 0, m_nTotalFlagCount);
	}

bool CKDMBitwiseFlagLarge::isEmpty(){
		return m_ucData == 0;
	}

bool CKDMBitwiseFlagLarge::isValidMaxCount(int p_nFlagMaxCount) const{
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


unsigned char* CKDMBitwiseFlagLarge::getPartData(int p_iBitIndex){
		return (isValidMaxCount(p_iBitIndex)) ? &m_ucData[ROW(p_iBitIndex)] : 0;
	}

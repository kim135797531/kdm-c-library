#ifndef KDM_SRC_LIBRARY_BITWISE_FLAG_H_
#define KDM_SRC_LIBRARY_BITWISE_FLAG_H_

#define ROW(index) ((index)/8)
#define COL(index) ((index)%8)

class CKDMBitwiseFlag{
public:
	CKDMBitwiseFlag(int p_nTotalSize = 8);
	~CKDMBitwiseFlag(){ delete[] m_ucData; }

	bool checkByBit(unsigned char p_ucBitmask, int p_iBitIndex = 0) const;
	void setByBit(unsigned char p_ucBitmask, int p_iBitIndex = 0);
	void unsetByBit(unsigned char p_ucBitmask, int p_iBitIndex = 0);

	bool checkByIndex(int p_iBitIndex) const;
	void setByIndex(int p_pvIndex);
	void unsetByIndex(int p_pvIndex);

	void clear();
	bool isEmpty();

	bool isValidMaxCount(int p_nFlagMaxCount) const;

private:
	unsigned char* getPartData(int p_iBitIndex = 0);

	static const int MAX_FLAG_COUNT_IN_DESIGN = 1024;
	const int m_nTotalFlagCount;
	const int m_nTotalDataArrayLength;
	unsigned char* m_ucData;
};

#endif KDM_SRC_LIBRARY_BITWISE_FLAG_H_
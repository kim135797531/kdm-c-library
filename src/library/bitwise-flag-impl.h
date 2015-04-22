#ifndef KDM_SRC_LIBRARY_BITWISE_FLAG_IMPL_H_
#define KDM_SRC_LIBRARY_BITWISE_FLAG_IMPL_H_

#define ROW(index) ((index)/8)
#define COL(index) ((index)%8)

class CKDMBitwiseFlag{
public:	
	CKDMBitwiseFlag(){}
	virtual ~CKDMBitwiseFlag(){}

	bool check(unsigned char p_ucBitmask, int p_iRow = 0) const;	
	void set(unsigned char p_ucBitmask, int p_iRow = 0);
	void unset(unsigned char p_ucBitmask, int p_iRow = 0);

	virtual bool check(int p_iBitIndex) const = 0;
	virtual void set(int p_pvIndex) = 0;
	virtual void unset(int p_pvIndex) = 0;

	virtual void clear() = 0;
	virtual bool isEmpty() = 0;

	bool isValidMaxCount(int p_nFlagMaxCount) const;

private:
	virtual unsigned char* getPartData(int p_iBitIndex = 0) = 0;
};

//1byte만 쓴다. Flag 0~7 저장 가능
class CKDMBitwiseFlagSmall : private CKDMBitwiseFlag{
private:
	friend class CKDMBitwiseFlagFactory;
	CKDMBitwiseFlagSmall(unsigned char p_ucData = 0) : m_ucData(p_ucData){}
public:	
	~CKDMBitwiseFlagSmall(){}

	bool check(int p_iBitIndex) const;
	void set(int p_iBitIndex);			
	void unset(int p_iBitIndex);

	void clear();
	bool isEmpty();

	bool isValidMaxCount(int p_nFlagMaxCount) const;

private:
	unsigned char* getPartData(int p_iBitIndex = 0);

	const int m_nTotalFlagCount = sizeof(unsigned char);
	unsigned char m_ucData;
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
//배열을 쓴다. Flag 최대 1024개 저장 가능
class CKDMBitwiseFlagLarge : private CKDMBitwiseFlag{
private:
	friend class CKDMBitwiseFlagFactory;
	CKDMBitwiseFlagLarge(int p_nTotalSize = 64);
public:
	~CKDMBitwiseFlagLarge(){delete[] m_ucData;}

	bool check(int p_iBitIndex) const;
	void set(int p_iBitIndex);
	void unset(int p_iBitIndex);
	
	void clear();
	bool isEmpty();

	bool isValidMaxCount(int p_nFlagMaxCount) const;

private:
	unsigned char* getPartData(int p_iBitIndex = 0);

	static const int MAX_FLAG_COUNT_IN_DESIGN = 1024;
	const int m_nTotalFlagCount;
	unsigned char* m_ucData;
};

#endif KDM_SRC_LIBRARY_BITWISE_FLAG_IMPL_H_
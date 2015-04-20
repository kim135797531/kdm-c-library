#ifndef KDM_SRC_ARRAY2D_H_
#define KDM_SRC_ARRAY2D_H_

#define _SCL_SECURE_NO_WARNINGS

#include <vector>

/*
짜증나는 2차원 배열을 쉽게쉽게 다루기 위한 클래스이다.
myArray(0,3); 등으로 쉽게 접근 가능하다.
인자로 넘기는게 너무 쉬워서 눈물이 날 지경이다 ㅜㅜ
그리고 실제 자료는 어차피 힙에 저장되기 때문에 그냥 지역 변수로 선언해도 된다.

경고: 생성자 오버로딩 때문에 C++11 이상에서만 사용가능!

2차원 배열을 다루고 싶을 때, 내부 구조로 가능한 것은
1. 2차원 배열
2. 더블 포인터
3. 1차원 배열
[4. 싱글 포인터]
가 있다. 여기선 싱글 포인터를 이용하여 구현하였다.
*/
template<typename T>
class CKDMArray2D{
public:
	//기본 생성자, 배열만 초기화
	CKDMArray2D(int p_nRow, int p_nCol) :
		m_nRow(p_nRow),
		m_nCol(p_nCol),
		m_nTotalSize(p_nRow*p_nCol)
	{
		this->m_tArray = new T[m_nTotalSize];
	}

	//더블 포인터로 넘어왔을 경우
	CKDMArray2D(int p_nRow, int p_nCol, T** p_tArray);
	//싱글 포인터 or 1차원 배열 or 강제 1차원 배열(&arr[0][0])로 넘어왔을 경우
	CKDMArray2D(int p_nRow, int p_nCol, T* p_tArray);
	//벡터로 넘어왔을 경우
	CKDMArray2D(int p_nRow, int p_nCol, std::vector<T>* p_tArray);

	//소멸자
	~CKDMArray2D(){
		delete m_tArray;
		m_tArray = 0;
	}

	T& operator()(int p_iRow, int p_iCol);
	const T& operator()(int p_iRow, int p_iCol) const;
	const bool isValidRange(int p_iRow, int p_iCol) const;

	const int getRow() const{ return m_nRow; }
	const int getCol() const{ return m_nCol; }
	const int getData(int p_iRow, int p_iCol) const{
		return m_tArray[
			p_iRow*(this->m_nCol) +
				p_iCol];
	}

private:
	const int m_nRow;
	const int m_nCol;
	const int m_nTotalSize;
	T* m_tArray;
};

//하단부에 넣어야 동작한다!
#include "array2d.hpp"

#endif KDM_SRC_ARRAY2D_H_
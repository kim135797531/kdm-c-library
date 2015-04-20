#ifdef KDM_SRC_ARRAY2D_H_

template<typename T>
CKDMArray2D<T>::CKDMArray2D(int p_nRow, int p_nCol, T** p_tArray) :
CKDMArray2D<T>::CKDMArray2D(p_nRow, p_nCol)
{
	for (int i = 0; i < this->m_nRow; i++){
		memcpy((this->m_tArray) + (i*p_nCol), p_tArray[i], p_nCol);
	}
}

template<typename T>
CKDMArray2D<T>::CKDMArray2D(int p_nRow, int p_nCol, T* p_tArray) :
CKDMArray2D<T>::CKDMArray2D(p_nRow, p_nCol)
{
	memcpy(this->m_tArray, p_tArray, m_nTotalSize);
}


template<typename T>
CKDMArray2D<T>::CKDMArray2D(int p_nRow, int p_nCol, std::vector<T>* p_tArray) :
CKDMArray2D<T>::CKDMArray2D(p_nRow, p_nCol)
{
	for (int i = 0; i < this->m_nTotalSize; i++){
		m_tArray[i] = p_tArray->at(i);
	}
}

template<typename T>
CKDMArray2D<T>::
CKDMArray2D(const CKDMArray2D &p_src) :
CKDMArray2D<T>::CKDMArray2D(p_src.m_nRow, p_src.m_nCol){
	memcpy(this->m_tArray, p_src.m_tArray, m_nTotalSize);
}

template<typename T>
T& CKDMArray2D<T>::operator()(int p_iRow, int p_iCol) {
	try{
		isValidRange(p_iRow, p_iCol);
	}
	catch (std::logic_error &e){
		std::cout << e.what() << std::endl;
	}

	return m_tArray[
		p_iRow*(this->m_nCol) +
			p_iCol];
}

template<typename T>
const T& CKDMArray2D<T>::operator()(int p_iRow, int p_iCol) const {
	return const_cast<CKDMArray2D*>(this)->operator()(p_iRow, p_iCol);
}

template<typename T>
const bool CKDMArray2D<T>::isValidRange(int p_iRow, int p_iCol) const{
	if (p_iRow < this->m_nRow &&
		p_iCol < this->m_nCol){
		return true;
	}
	else{
		std::cerr << "Invalid Range : " << p_iRow << ", " << p_iCol << std::endl;
		throw std::logic_error("Error: Invalid Range");
	}
}

#endif KDM_SRC_ARRAY2D_H_
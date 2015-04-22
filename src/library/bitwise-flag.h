#ifndef KDM_SRC_LIBRARY_BITWISE_FLAG_H_
#define KDM_SRC_LIBRARY_BITWISE_FLAG_H_

#include "bitwise-flag-impl.h"

class CKDMBitwiseFlagFactory{
public:
	enum{
		FLAG_SMALL = 0,
		FLAG_LARGE
	};
	static CKDMBitwiseFlag* createFlag(int p_eFlag);
};


#endif KDM_SRC_LIBRARY_BITWISE_FLAG_H_
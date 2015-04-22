#include "bitwise-flag.h"

CKDMBitwiseFlag* CKDMBitwiseFlagFactory::createFlag(int p_eFlag){
	switch (p_eFlag){
	case FLAG_SMALL:
		return new CKDMBitwiseFlagSmall();
	case FLAG_LARGE:
		return new CKDMBitwiseFlagLarge();
	default:
		return 0;
	}
}
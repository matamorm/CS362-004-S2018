/******************************************************
 * Author: Mark Matamoros
 * Program Name: tsAssert (implementation)
 * Description: assert handling for unit/card testing
 * ***************************************************/

#include "tsAssert.h"

int tsAssert(int val) {
	//true value handling
	if(!val) {
		printf("\n*****------------>ASSERTION FAIL\n\n");
	}

	return 0;
}

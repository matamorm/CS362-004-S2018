/*****************************************
 * Author: Mark Matamoros
 * Program Name: Unit Test 3
 * Tested Function: isGameOver
 * **************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "tsAssert.h"
#include "rngs.h"

int main() {
	//create variables for initializing game
	int numPlayers = 2;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
		     		remodel, smithy, village, baron, great_hall};
	int randomSeed = 20;
	struct gameState state;

	printf("\n------- ISGAMEOVER TESTING START ---------\n\n");

	//initialize game and grab returning value	
	printf("Testing initializeGame.\n");
	int gameReturn = initializeGame(numPlayers, kingdomCards, randomSeed, &state);

	printf("Function initializeGame returns: %d.\n", gameReturn);
	tsAssert(gameReturn == 0);

	printf("Function initializeGame passes.\n\n");

	//manipulate provinces to test gameOver
	printf("Testing isGameOver.\nSetting gameState's provinces to 1.\n");
	state.supplyCount[province] = 1;

	printf("Calling isGameOver. Game should not be over by returning a value of 0.\n");
	int returnVal = isGameOver(&state);

	printf("Function isGameOver returns: %d.\n\n", returnVal);
	tsAssert(returnVal == 0);

	printf("Setting gameState's provinces to 0.\n");
	state.supplyCount[province] = 0;

	printf("Calling isGameOver. Game should be over by returning a value of 1.\n");
	returnVal = isGameOver(&state);

	printf("Function isGameOver returns: %d.\n", returnVal);
	tsAssert(returnVal == 1);

	printf("Setting gameState's provinces to 1.\n\n");
	state.supplyCount[province] = 1;	
	
	//manipulate card piles to test gameOver
	printf("Setting gameState's first two card supply piles to 0.\n");	
	state.supplyCount[0] = 0;
	state.supplyCount[1] = 0;

	printf("Calling isGameOver. Game should not be over by returning a value of 0.\n");
	returnVal = isGameOver(&state);

	printf("Function isGameOver returns: %d.\n\n", returnVal);
	tsAssert(returnVal == 0);

	printf("Setting gameState's third card supply pile to 0.\n");		
	state.supplyCount[2] = 0;

	printf("Calling isGameOver. Game should be over by returning a value of 1.\n");
	returnVal = isGameOver(&state);		

	printf("Function isGameOver returns: %d.\n\n", returnVal);
	tsAssert(returnVal == 1);

	printf("\n------- ISGAMEOVER TESTING END -------\n\n");

	return 0;
}	

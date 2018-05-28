/*****************************************
 * Author: Mark Matamoros
 * Program Name: Unit Test 1
 * Tested Function: whoseTurn
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

	printf("\n------- WHOSETURN TESTING START ---------\n\n");

	//initialize game and grab returning value	
	printf("Testing initializeGame.\n");
	int gameReturn = initializeGame(numPlayers, kingdomCards, randomSeed, &state);

	printf("Function initializeGame returns: %d.\n", gameReturn);
	tsAssert(gameReturn == 0);

	printf("Function initializeGame passes.\n\n");

	//ensure that player 1 has the first turn at the beginning of game
	printf("Testing whoseTurn.\nFirst turn should be player 1.\n");
	int playerTurn = whoseTurn(&state);

	printf("Function whoseTurn returns: %d.\n", playerTurn);
	tsAssert(playerTurn == 0);

	printf("\n------- WHOSETURN TESTING END -------\n\n");

	return 0;
}		

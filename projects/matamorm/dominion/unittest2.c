/*****************************************
 * Author: Mark Matamoros
 * Program Name: Unit Test 2
 * Tested Function: numHandCards
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

	printf("\n------- NUMHANDCARDS TESTING START ---------\n\n");

	//initialize game and grab returning value	
	printf("Testing initializeGame.\n");
	int gameReturn = initializeGame(numPlayers, kingdomCards, randomSeed, &state);

	printf("Function initializeGame returns: %d.\n", gameReturn);
	tsAssert(gameReturn == 0);

	printf("Function initializeGame passes.\n\n");

	//Input 5 into gameState's player 1's handCount variable
	printf("Testing numHandCards.\nPlacing integer value 5 into player 1's handCount.\n");
	state.handCount[0] = 5;
	
	//Since player 1 has the first turn, the function should return 5.
	printf("Player 1 should now have 5 cards-in-hand.\nCalling function numHandCards.\n");
	int cardAmount = numHandCards(&state);

	printf("Function numHandCards returns: %d.\n", cardAmount);
	tsAssert(cardAmount == 5);

	printf("\n------- NUMHANDCARDS TESTING END-------\n\n");

	return 0;
}	

/*****************************************
 * Author: Mark Matamoros
 * Program Name: Unit Test 4
 * Tested Function: getCost 
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

	printf("\n------- GETCOST TESTING START ---------\n\n");

	//create variables for testing getCost in loop
	int returnVal;
	int i;
	const char *cardType[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
			    "gold", "adventurer", "council_room", "feast", "gardens",
			    "mine", "remodel", "smithy", "village", "baron", "great_hall",
			    "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", 
			    "outpost", "salvager", "sea_hag", "treasure_map"};
	int cardCost[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};

	//initialize game and grab returning value	
	printf("Testing initializeGame.\n");
	int gameReturn = initializeGame(numPlayers, kingdomCards, randomSeed, &state);

	printf("Function initializeGame returns: %d.\n", gameReturn);
	tsAssert(gameReturn == 0);

	printf("Function initializeGame passes.\n\n");

	//test getCost on all cards
	printf("Testing getCost on all cards.\n");

	//loop cycles through all 27 cards
	for(i = 0; i < 27; i++){
		printf("Testing '%s'. Returning value should be %d.\n", cardType[i], cardCost[i]);
		returnVal = getCost(i);

		printf("  Returning value: %d.\n", returnVal);
		assert(returnVal == cardCost[i]);
	}

	//test for invalid integer associated with card
	printf("\nTesting getCost with a value not associated to any card (27).\n");
	printf("Returning value for this unassociated card should be -1.\n");
        returnVal = getCost(27);

	printf("  Returning value: %d.\n", returnVal);
	tsAssert(returnVal == -1);

	printf("\n------- GETCOST TESTING END -------\n\n");

	return 0;
}	


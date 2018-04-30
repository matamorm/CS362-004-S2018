/*****************************************
 * Author: Mark Matamoros
 * Program Name: Card Test 3
 * Tested Function: village 
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

	//create array to hold victory card pile counts
	int victoryCards[3] = {estate, duchy, province};
	
	printf("\n------- VILLAGE TESTING START --------\n\n");

	//initialize game and grab returning value	
	printf("Testing initializeGame.\n");
	int gameReturn = initializeGame(numPlayers, kingdomCards, randomSeed, &state);

	printf("Function initializeGame returns: %d.\n", gameReturn);
	tsAssert(gameReturn == 0);

	int i;		//for loop handling
	int returnVal;	//return value for smithy call

	//arrays for holding pre and post kindgom and victory card pile counts
	int preVCards[3];
	int postVCards[3];	
	int preKCards[10];
	int postKCards[10];

	int currentPlayer = whoseTurn(&state);	//store current player
	state.hand[currentPlayer][0] = village;	//place village card in current player's hand

	//variables for holding pre and post player hand and action counts
	int preHandCount = state.handCount[currentPlayer];
	int postHandCount;
	int preActionCount = state.numActions;
	int postActionCount;

	printf("Current player hand count: %d.\n", preHandCount);
	printf("Current player action count: %d.\n", preActionCount);	

	//store victory card counts
	printf("Storing victory piles' card counts.\n");
	for (i = 0; i < 3; i++) {
		preVCards[i] = supplyCount(victoryCards[i],&state);
	}

	//store kingdom card counts
	printf("Storing kingdom piles' card counts.\n");
	for (i = 0; i < 10; i++) {
		preKCards[i] = supplyCount(kingdomCards[i],&state);
	}

	printf("Playing village card. Returning value should be 0.\n");	
	returnVal = villageCardEffect(currentPlayer, &state, 0);
	printf("  Returning value: %d.\n", returnVal);
	tsAssert(returnVal == 0);

	//grab player hand count and compare to original amount
	postHandCount = state.handCount[currentPlayer];
	//hand count should be the same, since village was discarded and another card was added
	printf("Current player hand count: %d.\n", postHandCount);
	tsAssert(postHandCount == preHandCount);	

	//grab player action count, should be three
	postActionCount =  state.numActions;	
	printf("Current player action count: %d.\n", postActionCount);
	tsAssert(postActionCount == 3);

	//compare originally counted victory piles to current piles
	printf("Comparing victory piles' card counts after village.\n");
	for (i = 0; i < 3; i++) {
		postVCards[i] = supplyCount(victoryCards[i],&state);
		tsAssert(preVCards[i] == postVCards[i]); 
	}

	//compare originally counted kingdom piles to current piles
	printf("Comparing kingdom piles' card counts after village.\n");	
	for (i = 0; i < 10; i++) {
		postKCards[i] = supplyCount(kingdomCards[i],&state);
		tsAssert(preKCards[i] == postKCards[i]); 
	}

	printf("\n------- VILLAGE TESTING END -------\n\n");

	return 0;
}	


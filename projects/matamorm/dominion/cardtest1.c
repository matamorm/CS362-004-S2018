/*****************************************
 * Author: Mark Matamoros
 * Program Name: Card Test 1
 * Tested Function: smithy 
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
	
	printf("\n------- SMITHY TESTING START --------\n\n");

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
	state.hand[currentPlayer][0] = smithy;	//place smithy card in current player's hand

	//variables for holding pre and post player deck and hand counts
	int preDeckCount = state.deckCount[currentPlayer];
	int postDeckCount;
	int preHandCount = state.handCount[currentPlayer];
	int postHandCount;

	printf("Current player deck count: %d.\n", preDeckCount);
	printf("Current player hand count: %d.\n", preHandCount);

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

	printf("Playing smithy card. Returning value should be 0.\n");	
	returnVal = smithyCardEffect(currentPlayer, &state, 0);
	printf("  Returning value: %d.\n", returnVal);
	tsAssert(returnVal == 0);

	//grab player deck count and compare to original amount
	postDeckCount = state.deckCount[currentPlayer];	
	printf("Current player deck count: %d.\n", postDeckCount);
	tsAssert(postDeckCount == preDeckCount - 3);

	//grab player hand count and compare to original amount
	postHandCount = state.handCount[currentPlayer];
	printf("Current player hand count: %d.\n", postHandCount);
	tsAssert(postHandCount == preHandCount + 3 - 1);	

	//compare originally counted victory piles to current piles
	printf("Comparing victory piles' card counts after smithy.\n");
	for (i = 0; i < 3; i++) {
		postVCards[i] = supplyCount(victoryCards[i],&state);
		tsAssert(preVCards[i] == postVCards[i]); 
	}

	//compare originally counted kingdom piles to current piles
	printf("Comparing kingdom piles' card counts after smithy.\n");	
	for (i = 0; i < 10; i++) {
		postKCards[i] = supplyCount(kingdomCards[i],&state);
		tsAssert(preKCards[i] == postKCards[i]); 
	}

	printf("\n------- SMITHY TESTING END -------\n\n");

	return 0;
}	

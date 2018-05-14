/*****************************************
 * Author: Mark Matamoros
 * Program Name: randomtestcard1
 * Tested Function: smithyCardEffect
 * **************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"

int main() {
	//create variables for intializing game
	int numPlayers;
	int selectedPlayer;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
		     		remodel, smithy, village, baron, great_hall};
	int randomSeed = 20;
	struct gameState state;

	//variables for testing
	int deckCount;
	int handCount;
	int discardCount;
	int postDeckCount;
	int postHandCount;
	int postDiscardCount;

	int failureFlag = 0;
	int failureCount = 0;

	int testAmount = 100;

	int i,j; 
	printf("\n\n\n------------ BEGIN SMITHY TESTING -------------\n\n");


	for (i = 0; i < testAmount; i++)
	{		
		//randomize game state
		printf("\nRandomizing game state.\n");		
   		for (j = 0; j < sizeof(struct gameState); j++) 
		{
    			((char*)&state)[j] = floor(Random() * 256);
   		}

		//set random amount of players
		numPlayers = (rand() % (MAX_PLAYERS - 2)) + 2;
		printf("Setting random amount of players: %d\n", numPlayers);	
	
		//initialize game and grab returning value	
		printf("Testing initializeGame.\n");
		int gameReturn = initializeGame(numPlayers, kingdomCards, randomSeed, &state);

		printf("Function initializeGame returns: %d.\n", gameReturn);
	
		//set player for evaluation
		selectedPlayer = 0;

		//generate random hand and deck counts
		deckCount = rand() % MAX_DECK;
		handCount = rand() % deckCount;

		//store deck and hand count into game state
		state.deckCount[selectedPlayer] = deckCount - handCount;
		state.handCount[selectedPlayer] = handCount;

		//grab current discard count
		discardCount = state.playedCardCount;

		printf("Setting random deck count: %d\n", state.deckCount[selectedPlayer]);
		printf("Setting random hand count: %d\n", state.handCount[selectedPlayer]);
		printf("Pre-smithy discard count: %d\n", state.playedCardCount);

		printf("Calling smithy card effect function.\n");
		smithyCardEffect(selectedPlayer, &state, 0);

		//grab post smithy deck count
		postDeckCount = state.deckCount[selectedPlayer];
		printf("Post-smithy card deck count: %d\n", postDeckCount);

		//check for failure
		if (deckCount != postDeckCount + 3)
		{
			printf("------------->  Smithy card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;			
		}

		//grab post smithy hand count
		postHandCount = state.handCount[selectedPlayer];
		printf("Post-smithy card hand count: %d\n", postHandCount);

		//check for failure
		if (handCount + 2 != postHandCount)
		{
			printf("------------->  Smithy card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;
		}

		//grab post smithy discard count
		postDiscardCount = state.playedCardCount;
		printf("Post-smithy discard count: %d\n", postDiscardCount);

		//check for failure
		if (discardCount + 1 != postDiscardCount)
		{
			printf("------------->  Smithy card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;			
		}

	}

	if(failureFlag == 1)
	{
		printf("\n------------ SMITHY TESTING FAILED -------------\n\n");
		printf("FailureCount: %d\n\n\n\n", failureCount);
	}
	else
	{
		printf("\n------------ SMITHY TESTING SUCCESS -------------\n\n\n\n");
	}
}


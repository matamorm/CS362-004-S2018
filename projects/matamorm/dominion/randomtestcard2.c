/*****************************************
 * Author: Mark Matamoros
 * Program Name: randomtestcard2
 * Tested Function: villageCardEffect
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
	int actionCount;
	int postDeckCount;
	int postHandCount;
	int postDiscardCount;
	int postActionCount;

	int failureFlag = 0;
	int failureCount = 0;

	int testAmount = 100;

	int i,j; 
	printf("\n\n\n------------ BEGIN VILLAGE TESTING -------------\n\n");


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

		//generate random hand, deck, and action counts
		deckCount = rand() % MAX_DECK;
		handCount = rand() % deckCount;
		actionCount = rand() % 10;

		//store deck, hand, and action counts into game state
		deckCount = state.deckCount[selectedPlayer] = deckCount - handCount;
		state.handCount[selectedPlayer] = handCount;
		state.numActions = actionCount;

		//grab current discard and action counts
		discardCount = state.playedCardCount;
		actionCount = state.numActions;

		printf("Setting random deck count: %d\n", state.deckCount[selectedPlayer]);
		printf("Setting random hand count: %d\n", state.handCount[selectedPlayer]);
		printf("Setting random action count: %d\n", state.numActions);
		printf("Pre-Village discard count: %d\n", discardCount);

		printf("Calling village card effect function.\n");
		villageCardEffect(selectedPlayer, &state, 0);

		//grab post smithy deck count
		postDeckCount = state.deckCount[selectedPlayer];
		printf("Post-village card deck count: %d\n", postDeckCount);

		//check for failure
		if (deckCount != postDeckCount + 1)
		{
			printf("------------->  Village card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;			
		}

		//grab post village hand count
		postHandCount = state.handCount[selectedPlayer];
		printf("Post-village card hand count: %d\n", postHandCount);

		//check for failure
		if (handCount != postHandCount)
		{
			printf("------------->  Village card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;
		}

		//grab post village discard count
		postDiscardCount = state.playedCardCount;
		printf("Post-village discard count: %d\n", postDiscardCount);

		//check for failure
		if (discardCount + 1 != postDiscardCount)
		{
			printf("------------->  Village card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;			
		}

		//grab post village discard count
		postActionCount = state.numActions;
		printf("Post-village action count: %d\n", postActionCount);

		//check for failure
		if (actionCount + 2 != postActionCount)
		{
			printf("------------->  Village card function FAILURE.\n");
			failureFlag = 1;
			failureCount++;			
		}


	}

	if(failureFlag == 1)
	{
		printf("\n------------ VILLAGE TESTING FAILED -------------\n\n");
		printf("FailureCount: %d\n\n\n\n", failureCount);
	}
	else
	{
		printf("\n------------ VILLAGE TESTING SUCCESS -------------\n\n\n\n");
	}
}



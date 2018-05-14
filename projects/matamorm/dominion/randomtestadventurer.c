/*****************************************
 * Author: Mark Matamoros
 * Program Name: randomtestadventurer
 * Tested Function: adventurerCardEffect 
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
	int handCount;
	int preTreasureCardCount = 0;
	int postTreasureCardCount = 0;

	int failureFlag = 0;
	int failureCount = 0;

	int testAmount = 100;

	int i,j,k; 
	printf("\n\n\n------------ BEGIN ADVENTURER TESTING -------------\n\n");


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

		//generate random hand count
		handCount = rand() % MAX_HAND;
		
		printf("Setting random hand count: %d\n", handCount);

		//store hand count in game state
		state.handCount[selectedPlayer] = handCount;
		
		//initialize pre and post treasure card counts
		preTreasureCardCount = 0;
		postTreasureCardCount = 0;
		
		//store the amount of treasure cards in player's hand (before adventurer call)
		for (k = 0; k < state.handCount[selectedPlayer]; k++) 
		{
			if ((state.hand[selectedPlayer][k] == copper) || (state.hand[selectedPlayer][k] == silver) || 
			    (state.hand[selectedPlayer][k] == gold))
			{
				preTreasureCardCount++;
			}	
		}
		printf("Player hand's treasure card count pre-adventurer call: %d\n", preTreasureCardCount);

		printf("Calling adventurer card effect function\n");
		adventurerCardEffect(selectedPlayer, &state, 0);

		//store the amount of treasure cards in player's hand (after adventurer call)
		for (k = 0; k < state.handCount[selectedPlayer]; k++) 
		{
			if ((state.hand[selectedPlayer][k] == copper) || (state.hand[selectedPlayer][k] == silver) || 
			    (state.hand[selectedPlayer][k] == gold))
			{
				postTreasureCardCount++;
			}	
		}

		printf("Player hand's treasure card count post-adventurer call: %d\n", postTreasureCardCount);

		//check for failure
		if ((preTreasureCardCount + 2) != postTreasureCardCount)
		{
			printf("------------->  Adventurer card function FAILURE.\n");
			failureCount++;
			failureFlag = 1;
		}
	}

	if(failureFlag == 1)
	{
		printf("\n------------ ADVENTURER TESTING FAILED -------------\n\n");
		printf("Failure Count: %d\n\n\n\n", failureCount);
	}
	else
	{
		printf("\n------------ ADVENTURER TESTING SUCCESS -------------\n\n\n\n");
	}
}

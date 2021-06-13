/**
 * @file main.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "include/fc_game.h"

int main() {

	fc_game_t *game = fc_create_game();

	// initialize the game
	fc_game_init(game);

	for(int i=0; i<8; ++i)
		printf("| %d | ", game->stackColumns[i].count);

	printf("\n\n");

	fc_card_t *card;

	for(int i=0; i<8; ++i) {
		while(card = (fc_card_t*) stack_pop(&(game->stackColumns[i].stack))){
			printf("|%d - %d|\n", card->number, card->type);
		}
	}

	fc_free_game(game);

	printf("\nFinished");

	return 0;
}
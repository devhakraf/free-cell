/**
 * @file fc_game.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/fc_game.h"

/**
 * Create a new game instance
 * 
 * @param game 
 * @return uint8_t 
 */
fc_game_t* fc_create_game() {
	// create game instance
	return (fc_game_t*) malloc(sizeof(fc_game_t));
}

/**
 * Initialize a game
 * 
 * @param game 
 * @return uint8_t 
 */
uint8_t fc_game_init(fc_game_t *game) {
	// game not created
	if(!game)
		return 0;
	// allocate 2d table to store created cards
	uint8_t **saturation = (uint8_t**) malloc(sizeof(uint8_t*) * 13);
	for(uint8_t i=0; i<13; ++i)
		saturation[i] = (uint8_t*) malloc(sizeof(uint8_t) * 4);
	
	// initialisation of saturation table
	for(uint8_t i=0; i<13; ++i) {
		for(uint8_t j=0; j<4; ++j)
			saturation[i][j] = 0;
	}

	// initialise stack columns
	for(uint8_t i=0; i<8; ++i) {
		game->stackColumns[i].count = 0;
		game->stackColumns[i].stack = NULL;
	}

	// initialise freeCells and foundation columns
	for(uint8_t i=0; i<4; ++i) {
		game->freeCells[i] = NULL;
		game->foundations[i].count = 0;
		game->foundations[i].stack = NULL;
	}

	// fill stack columns with random cards
	uint8_t columnCardsNumber = 7;
	fc_card_t *card;
	for(uint8_t i=0; i<8; ++i) {
		// from the 5th column set the number of cards by column to 6
		if(i == 4)
			columnCardsNumber = 6;
		// fill cards
		for(uint8_t j=0; j<columnCardsNumber; ++j) {
			card = fc_create_random_card(saturation);
			// add card to stack (zone1)
			if(card && stack_push(&(game->stackColumns[i].stack), card))
				// increment column card numbers
				game->stackColumns[i].count++;
			else
				return 0;
		}
	}

	// free saturation table memory
	for(uint8_t i=0; i<13; ++i)
		free(saturation[i]);
	free(saturation);

	return 1;
}

/**
 * Move card between zone 1 columns, from source index to destination index
 * 
 * @param game 
 * @param source 
 * @param destination 
 * @return uint8_t 
 */
uint8_t fc_move_card_between_columns(fc_game_t *game, uint8_t source, uint8_t destination) {
	// when empty game instance
	if(!game)
		return 0;
	
	printf("%d, %d\n", source, destination);

	// check move rules
	fc_card_t *card = (fc_card_t*) stack_peek(game->stackColumns[source].stack);
	fc_card_t *destTopCard = (fc_card_t*) stack_peek(game->stackColumns[destination].stack);

	printf("S: %p, D: %p\n", card, destTopCard);

	printf("Source: %d - %d | Dest: %d - %d\n", card->number, card->color, destTopCard->number, destTopCard->color);

	if(card && (!destTopCard || (card->color != destTopCard->color && card->number + 1 == destTopCard->number))) {
		// move the source card to destination column
		stack_push(&(game->stackColumns[destination].stack), card);
		game->stackColumns[destination].count++;
		// remove card from source column
		stack_pop(&(game->stackColumns[source].stack));
		game->stackColumns[source].count--;
		return 1;
	}
	return 0;
}

/**
 * Move card from free cell (zone2) to foundation (zone3)
 * 
 * @param game 
 * @param source 
 * @param destination 
 * @return uint8_t 
 */
uint8_t fc_move_card_freecell_foundation(fc_game_t *game, uint8_t source, uint8_t destination);

/**
 * Move card from free cell (zone2) to column (zone1)
 * 
 * @param game 
 * @param source 
 * @param destination 
 * @return uint8_t 
 */
uint8_t fc_move_card_freecell_column(fc_game_t *game, uint8_t source, uint8_t destination);

/**
 * Move card from column (zone1) to free cell (zone2)
 * 
 * @param game 
 * @param source 
 * @param destination 
 * @return uint8_t 
 */
uint8_t fc_move_card_column_freecell(fc_game_t *game, uint8_t source, uint8_t destination);

/**
 * Move card from column (zone1) to foundation (zone3)
 * 
 * @param game 
 * @param source 
 * @param destination 
 * @return uint8_t 
 */
uint8_t fc_move_card_column_foundation(fc_game_t *game, uint8_t source, uint8_t destination);

/**
 * Free game content
 * 
 * @param game 
 */
void fc_free_game_content(fc_game_t *game) {

	// free stack columns content
	fc_card_t *card;
	for(uint8_t i=0; i<8; ++i) {
		while(card = (fc_card_t*) stack_pop(&(game->stackColumns[i].stack)))
			fc_free_card(card);
		game->stackColumns[i].count = 0;
	}

	// free foundation columns and freecells
	for(uint8_t i=0; i<4; ++i) {
		// free foundation columns
		while (card = (fc_card_t*) stack_pop(&(game->foundations[i].stack)))
			fc_free_card(card);
		game->foundations[i].count = 0;

		// free freecells
		if(game->freeCells[i])
			fc_free_card(game->freeCells[i]);
	}
}

/**
 * Destroy a game instance
 * 
 * @param game 
 */
void fc_free_game(fc_game_t *game) {
	// free game content
	fc_free_game_content(game);
	// free game memory
	free(game);
}
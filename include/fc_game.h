/**
 * @file fc_game.h
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FC_GAME_H
#define FC_GAME_H

#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>
#include "fc_card.h"
#include "stack.h"

/* Stack columns definition */
typedef struct {
	uint8_t count; 			/* Number of cards in column */
	stack_t *stack; 		/* Stack of cards */
} fc_column_t;

/* Game structure definition */
typedef struct {
	fc_column_t stackColumns[8]; 	/* Zone 1 columns */
	fc_card_t *freeCells[4];		/* Zone 2 Cells */
	fc_column_t foundations[4]; 	/* Zone 3 columns */
} fc_game_t;

/**
 * Create a new game instance
 * 
 * @param game 
 * @return uint8_t 
 */
fc_game_t* fc_create_game();

/**
 * Initialize a game
 * 
 * @param game 
 * @return uint8_t 
 */
uint8_t fc_game_init(fc_game_t *game);

/**
 * Move card between zone 1 columns, from source index to destination index
 * 
 * @param game 
 * @param source 
 * @param destination 
 * @return uint8_t 
 */
uint8_t fc_move_card_between_columns(fc_game_t *game, uint8_t source, uint8_t destination);

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
void fc_free_game_content(fc_game_t *game);

/**
 * Destroy a game instance
 * 
 * @param game 
 */
void fc_free_game(fc_game_t *game);

#endif
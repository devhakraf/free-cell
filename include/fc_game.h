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

#include <stdlib.h>
#include <stdint.h>
#include "fc_card.h"
#include "stack.h"

/* Stack columns definition */
typedef struct {
	uint8_t count; 		/* Number of cards in column */
	stack_t *content; 	/* Stack of cards */
} fc_column_t;

/* Game structure definition */
typedef struct {
	fc_column_t *stackColumns[8]; 	/* Zone 1 columns */
	fc_card_t *freeCells[4];		/* Zone 2 Cells */
	fc_column_t *foundations[4]; 	/* Zone 3 columns */
} fc_game_t;


uint8_t fc_move_card_between_columns(fc_game_t *game, uint8_t source, uint8_t destination);

uint8_t fc_move_card_freecell_foundation(fc_game_t *game);

uint8_t fc_move_card_freecell_column(fc_game_t *game);

#endif
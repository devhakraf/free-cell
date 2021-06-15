/**
 * @file fc_game_ui.h
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FC_GAME_UI_H
#define FC_GAME_UI_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "fc_game_core.h"


/**
 * Display game logo
 * 
 */
void fc_game_logo_display();

/**
 * Read maual file and print it to console
 * 
 */
uint8_t fc_game_maual();

/**
 * Display game interface
 * 
 * @param game 
 */
void fc_game_display(fc_game_t *game);

/**
 * Map card number to equivalent char
 * 
 * @param number 
 * @return char 
 */
char fc_game_map_card_number(uint8_t number);

/**
 * Display given card
 * 
 * @param card 
 */
void fc_game_display_card(fc_card_t *card);

/**
 * Display given card or empty card when NULL card
 * 
 * @param card 
 */
void fc_game_display_card_or_space(fc_card_t *card);

/**
 * Execute move command
 * 
 * @param game 
 * @param sourceZone 
 * @param sourceIndex 
 * @param destZone 
 * @param destIndex 
 * @return uint8_t 
 */
uint8_t fc_game_exec_move(fc_game_t *game, char sourceZone, uint8_t sourceIndex, char destZone, uint8_t destIndex);

#endif
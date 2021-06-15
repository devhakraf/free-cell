/**
 * @file fc_card.h
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FC_CARD_H
#define FC_CARD_H

#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* Cards type enumeration */
typedef enum {
	FC_CARD_TYPE_HEARTS = 3,
	FC_CARD_TYPE_DIAMONDS,
	FC_CARD_TYPE_CLUBS,
	FC_CARD_TYPE_SPADES
} fc_card_type_t;

/* Card color enumeration */
typedef enum {
	FC_CARD_RED = 1,
	FC_CARD_BALCK
} fc_card_color_t;

/* Cards structure */
typedef struct {
	uint8_t number; /* 1 - 13 */
	uint8_t type;
	uint8_t color; /* B:1 - R:2 */
} fc_card_t;


/**
 * Create new card
 * 
 * @param number 
 * @param typpe 
 * @return fc_card_t* 
 */
fc_card_t* fc_create_card(uint8_t number, fc_card_type_t type);

/**
 * Create random card that's not in saturation values
 * 
 * @param saturation 
 * @return fc_card_t* 
 */
fc_card_t* fc_create_random_card(uint8_t **saturation);

/**
 * Free memory allocated by a card
 * 
 * @param card 
 */
void fc_free_card(fc_card_t *card);

#endif
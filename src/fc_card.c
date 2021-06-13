/**
 * @file fc_card.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/fc_card.h"


/**
 * Create new card
 * 
 * @param number 
 * @param typpe 
 * @return fc_card_t* 
 */
fc_card_t* fc_create_card(uint8_t number, fc_card_type_t type) {
	// allocate card memrory
	fc_card_t *card = (fc_card_t*) malloc(sizeof(fc_card_t));
	// fill card data
	if(card) {
		card->number = number;
		card->type = type;
	}
	return card;
}

/**
 * Create random card that's not in saturation values
 * 
 * @param saturation 
 * @return fc_card_t* 
 */
fc_card_t* fc_create_random_card(uint8_t **saturation) {
	// no saturation content
	if(!saturation)
		return NULL;

	// allocate card memory
	fc_card_t *card = (fc_card_t*) malloc(sizeof(fc_card_t));
	// file randomlly the card
	if(card) {
		uint8_t number, type;
		// seed rand from random numbers
		srand(time(NULL));
		// look for available card
		do {
			number = rand() % 13;
			type = rand() % 4;
		} while(saturation[number][type] != 0);
		// marke found card as reserved
		saturation[number][type] = 1;
		// here an available card is found
		card->number = number + 1;
		card->type = type + 1;
	}
	// return created card
	return card;
}

/**
 * Free memory allocated by a card
 * 
 * @param card 
 */
void fc_free_card(fc_card_t *card) {
	free(card);
}
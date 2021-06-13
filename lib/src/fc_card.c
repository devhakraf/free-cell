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

#include "../fc_card.h"


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
	// allocate card memory
	fc_card_t *card = (fc_card_t*) malloc(sizeof(fc_card_t));
	// file randomlly the card
	if(card) {
		uint8_t number, type;
		// look for available card
		do {
			number = rand() % 13;
			type = rand() % 4;
		} while(saturation[number][type] != 0);
		// here an available card is found
		card->number = number;
		card->type = type;
	}
	// return created card
	return card;
}

/**
 * Push given card to given stack
 * 
 * @param stack 
 * @param card
 * @return uint8_t
 */
uint8_t fc_stack_push(fc_stack_t **stack, fc_card_t *card);

/**
 * Return and remove stack head card
 * 
 * @param stack 
 * @return fc_card_t* 
 */
fc_card_t* fc_stack_pop(fc_stack_t **stack);

/**
 * Return stack head card
 * 
 * @param stack 
 * @return fc_card_t* 
 */
fc_card_t* fc_stack_peek(fc_stack_t *stack);

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

#include <stdint.h>
#include <stdlib.h>

/* Cards type enumeration */
typedef enum {
	FC_CARD_TYPE_SPADES = 0,
	FC_CARD_TYPE_CLUBS,
	FC_CARD_TYPE_HEARTS,
	FC_CARD_TYPE_DIAMONDS
} fc_card_type_t;

/* Cards structure */
typedef struct {
	uint8_t number; /* 1 - 13 */
	uint8_t type;
} fc_card_t;

/* Cards stack node structure */
typedef struct _fc_stack_node{
	fc_card_t *card;
	struct _fc_stack_node *next;
} fc_stack_node_t;

/* Cards stack definition */
typedef fc_stack_node_t fc_stack_t;

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


#endif
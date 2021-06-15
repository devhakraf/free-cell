/**
 * @file stack.h
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FC_STACK_H
#define FC_STACK_H

#include <stdlib.h>
#include <stdint.h>


/* Stack node structure */
typedef struct _fc_stack_node{
	void *content;
	struct _fc_stack_node *next;
} fc_stack_node_t;

/* Stack definition */
typedef fc_stack_node_t fc_stack_t;


/**
 * Push given content to given stack
 * 
 * @param stack 
 * @param content
 * @return uint8_t
 */
uint8_t fc_stack_push(fc_stack_t **stack, void *content);

/**
 * Return and remove stack head content
 * 
 * @param stack 
 * @return void* 
 */
void* fc_stack_pop(fc_stack_t **stack);

/**
 * Return stack head content
 * 
 * @param stack 
 * @return void* 
 */
void* fc_stack_peek(fc_stack_t *stack);

/**
 * Check if stack is empty
 * 
 * @param stack 
 * @return uint8_t 
 */
uint8_t fc_stack_is_empty(fc_stack_t *stack);

#endif
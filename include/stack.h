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

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>


/* Stack node structure */
typedef struct _stack_node{
	void *content;
	struct _stack_node *next;
} stack_node_t;

/* Stack definition */
typedef stack_node_t stack_t;


/**
 * Push given content to given stack
 * 
 * @param stack 
 * @param content
 * @return uint8_t
 */
uint8_t stack_push(stack_t **stack, void *content);

/**
 * Return and remove stack head content
 * 
 * @param stack 
 * @return void* 
 */
void* stack_pop(stack_t **stack);

/**
 * Return stack head content
 * 
 * @param stack 
 * @return void* 
 */
void* stack_peek(stack_t *stack);

/**
 * Check if stack is empty
 * 
 * @param stack 
 * @return uint8_t 
 */
uint8_t stack_is_empty(stack_t *stack);

#endif
/**
 * @file stack.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../stack.h"

/**
 * Create new empty stack
 * 
 * @return stack_t* 
 */
stack_t* stack_create();

/**
 * Push given content to given stack
 * 
 * @param stack 
 * @param content
 * @return uint8_t
 */
uint8_t stack_push(stack_t **stack, void *content) {
	// no stack pointer
	if(!stack)
		return 0;
	// create stack node
	stack_node_t *node = (stack_node_t*) malloc(sizeof(stack_node_t));
	// fill the node
	if(node) {
		node->content = content;
		node->next = *stack;
		*stack = node;
		return 1;
	}
	return 0;
}

/**
 * Return and remove stack head content
 * 
 * @param stack 
 * @return void* 
 */
void* stack_pop(stack_t **stack) {
	// no stack pointer
	if(!stack)
		return NULL;
	// get head node
	stack_node_t *node = *stack;
	// point stack to next node
	*stack = node->next;
	// get node content
	void *content = node->content;
	// free node memory
	free(node);
	// return node content
	return content;

}

/**
 * Return stack head content
 * 
 * @param stack 
 * @return void* 
 */
void* stack_peek(stack_t *stack) {
	// no stack pointer
	if(!stack)
		return NULL;
	return stack->content;
}

/**
 * Check if stack is empty
 * 
 * @param stack 
 * @return uint8_t 
 */
uint8_t stack_is_empty(stack_t *stack) {
	return stack == NULL ? 1 : 0;
}
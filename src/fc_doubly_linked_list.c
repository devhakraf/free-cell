/**
 * @file fc_doubly_linked_list.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/fc_doubly_linked_list.h"

/**
 * Create an empty doubly linked list
 * 
 * @return fc_dll_t* 
 */
fc_dll_t* fc_dll_create() {
	fc_dll_t *list = (fc_dll_t*) malloc(sizeof(fc_dll_t));

	list->head = NULL;
	list->tail = NULL;

	return list;
}

/**
 * Add new element to the head of list
 * 
 * @param list 
 * @param content 
 * @return uint8_t 
 */
uint8_t fc_dll_add_to_head(fc_dll_t *list, void *content) {
	// when no list instance
	if(!list)
		return 0;
	
	// create node
	fc_dll_node_t *node = (fc_dll_node_t*) malloc(sizeof(fc_dll_node_t));
	if(node) {
		// prepare node content
		node->content = content;
		node->next = list->head;
		node->prev = NULL;
		// if list head not empty
		if(list->head != NULL)
			list->head->prev = node;
		// point list head to the new node
		list->head = node;
		// when list is empty point the head to the new node
		if(list->tail == NULL)
			list->tail = node;
		return 1;
	}
	return 0;
}

/**
 * Add new element to the end of list
 * 
 * @param list 
 * @param content 
 * @return uint8_t 
 */
uint8_t fc_dll_add_to_tail(fc_dll_t *list, void *content) {
	// when no list instance
	if(!list)
		return 0;
	
	// create node
	fc_dll_node_t *node = (fc_dll_node_t*) malloc(sizeof(fc_dll_node_t));
	if(node) {
		// prepare node content
		node->content = content;
		node->next = NULL;
		node->prev = list->tail;
		// if list tail not empty
		if(list->tail != NULL)
			list->tail->next = node;
		// point list tail to the new node
		list->tail = node;
		// when list is empty point the head to the new node
		if(list->head == NULL)
			list->head = node;
		return 1;
	}
	return 0;
}

/**
 * Pop element at the head of the list
 * 
 * @param list 
 * @return void* 
 */
void* fc_dll_pop(fc_dll_t *list) {
	// when no list
	if(!list)
		return NULL;
	
	// get head node and content
	fc_dll_node_t *node = list->head;
	if(node) {
		void *content = node->content;
		// manage relations
		list->head = node->next;
		if(list->head != NULL)
			list->head->prev = NULL;
		else
			list->tail = NULL;
		// free the node
		free(node);
		return content;
	}
	return NULL;
}

/**
 * Peek element at the head of the list
 * 
 * @param list 
 * @return void* 
 */
void* fc_dll_peek(fc_dll_t *list) {
	return list->head != NULL ? list->head->content : NULL;
}

/**
 * Check if list is empty
 * 
 * @param list 
 * @return uint8_t 
 */
uint8_t fc_dll_is_empty(fc_dll_t *list) {
	return list->head != NULL ? 1 : 0;
}

/**
 * Free memory allocated by the list
 * 
 * @param list 
 */
void fc_dll_free(fc_dll_t *list) {
	free(list);
}
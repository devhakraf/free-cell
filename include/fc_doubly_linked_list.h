/**
 * @file fc_doubly_linked_list.h
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FC_DOUBLY_LINKED_LIST
#define FC_DOUBLY_LINKED_LIST

#include <stdint.h>
#include <stdlib.h>

typedef struct _fc_dll_node_t {
	void *content;
	struct _fc_dll_node_t *prev;
	struct _fc_dll_node_t *next;
} fc_dll_node_t;

typedef struct {
	fc_dll_node_t *head;
	fc_dll_node_t *tail;
} fc_dll_t;


/**
 * Create an empty doubly linked list
 * 
 * @return fc_dll_t* 
 */
fc_dll_t* fc_dll_create();

/**
 * Add new element to the head of list
 * 
 * @param list 
 * @param content 
 * @return uint8_t 
 */
uint8_t fc_dll_add_to_head(fc_dll_t *list, void *content);

/**
 * Add new element to the end of list
 * 
 * @param list 
 * @param content 
 * @return uint8_t 
 */
uint8_t fc_dll_add_to_tail(fc_dll_t *list, void *content);

/**
 * Pop element at the end of the list
 * 
 * @param list 
 * @return void* 
 */
void* fc_dll_pop(fc_dll_t *list);

/**
 * Peek element at the end of the list
 * 
 * @param list 
 * @return void* 
 */
void* fc_dll_peek(fc_dll_t *list);

/**
 * Check if list is empty
 * 
 * @param list 
 * @return uint8_t 
 */
uint8_t fc_dll_is_empty(fc_dll_t *list);

/**
 * Free memory allocated by the list
 * 
 * @param list 
 */
void fc_dll_free(fc_dll_t *list);

#endif
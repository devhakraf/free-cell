/**
 * @file fc_game_ui.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/fc_game_ui.h"

/**
 * Display game logo
 * 
 */
void fc_game_logo_display() {
	// print game logo
	printf("\t\t ______ _____  ______ ______    _____ ______ _      _\n");
	printf("\t\t|  ____|  __ \\|  ____|  ____|  / ____|  ____| |    | |\n");
	printf("\t\t| |__  | |__) | |__  | |__    | |    | |__  | |    | |\n");
	printf("\t\t|  __| |  _  /|  __| |  __|   | |    |  __| | |    | |\n");
	printf("\t\t| |    | | \\ \\| |____| |____  | |____| |____| |____| |____\n");
	printf("\t\t|_|    |_|  \\_|______|______|  \\_____|______|______|______|\n");
}

/**
 * Read maual file and print it to console
 * 
 */
uint8_t fc_game_maual() {
	// file pointer
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// open file
	fp = fopen("doc/manual.txt", "r");
	if(fp == NULL)
		return 0;
	// read file data
	while((read = getline(&line, &len, fp)) != -1)
		printf("%s", line);
	// close file
	fclose(fp);
	if(line)
		free(line);
	return 1;
}

/**
 * Display game interface
 * 
 * @param game 
 */
void fc_game_display(fc_game_t *game) {
	printf("\n");
	// display free cells and foundation columns and indexs
	for(uint8_t i=0; i<5; i++) {
		for(uint8_t j=0; j<8; j++) {
			if(j == 4 && i != 4)
				printf("\t\t");
			if(i == 0)
				if(j<4)
					printf("\t  C%d  ", j+1);
				else
					printf("\t  F%d  ", j-3);
			else if (i == 2) {
				if(j<4)
					// display freecells
					fc_game_display_card_or_space(game->freeCells[j]);
				else {
					// display foundation columns
					if(game->foundations[j-4].stack != NULL)
						fc_game_display_card_or_space((fc_card_t*)(game->foundations[j-4].stack->content));
					else
						fc_game_display_card_or_space(NULL);
				}
			}
			else if(i == 4) {
				if(j == 0)
					printf("\n\t");
				printf("\t  L%d  ", j+1);
			}
			else
				printf("\t------");
		}
		printf("\n");
	}
	// display list columns nodes
	fc_dll_node_t *nodes[8];
	fc_card_t *tempCard;
	uint8_t max = 0;
	// fill nodes and calculate max
	for(uint8_t i=0; i<8; i++) {
		nodes[i] = game->listColumns[i].list->tail;
		max = max < game->listColumns[i].count ? game->listColumns[i].count : max;
	}
	// display list columns cards
	for(uint8_t i=0; i<max; i++) {
		printf("\t");
		// display card top lines
		for(int j=0; j<8; ++j) {
			if(i < game->listColumns[j].count)
				printf("\t------");
			else
				printf("\t      ");
		}
		printf("\n\t");
		// display cards
		for(uint8_t j=0; j<8; j++) {
			if(nodes[j] != NULL) {
				// get card
				tempCard = (fc_card_t*) nodes[j]->content;
				// display card
				fc_game_display_card(tempCard);
				// go to prev node
				nodes[j] = nodes[j]->prev;
			}
			else
				// display an empty card;
				printf("\t      ");
		}
		printf("\n\t");
		// display card bottom lines
		for(int j=0; j<8; ++j) {
			if(i < game->listColumns[j].count)
				printf("\t------");
			else
				printf("\t      ");
		}
		printf("\n");
	}	
}

/**
 * Map card number to equivalent char
 * 
 * @param number 
 * @return char 
 */
char fc_game_map_card_number(uint8_t number) {
	return number == 1 ? 65 : number <= 10 ? number + 48 : number == 11 ? 74 : number == 12 ? 81 : 75;
}

/**
 * Display given card
 * 
 * @param card 
 */
void fc_game_display_card(fc_card_t *card) {
	// when an empty card
	if(card == NULL)
		return;
	// print card number
	if(card->number != 10)
		printf("\t|%c ", fc_game_map_card_number(card->number));
	else
		printf("\t|10");
	// print card type
	printf(" %c|", card->type);
}

/**
 * Display given card or empty card when NULL card
 * 
 * @param card 
 */
void fc_game_display_card_or_space(fc_card_t *card) {
	// when card is empty
	if(card == NULL)
		printf("\t|    |");
	else
		fc_game_display_card(card);
}

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
uint8_t fc_game_exec_move(fc_game_t *game, char sourceZone, uint8_t sourceIndex, char destZone, uint8_t destIndex) {
	// execute recieved move command
	if((sourceZone == 'l' || sourceZone == 'L') && (destZone == 'l' || destZone == 'L'))
		return fc_move_card_between_columns(game, sourceIndex-1, destIndex-1);

	else if((sourceZone == 'l' || sourceZone == 'L') && (destZone == 'c' || destZone == 'C'))
		return fc_move_card_column_freecell(game, sourceIndex-1, destIndex-1);
	
	else if((sourceZone == 'c' || sourceZone == 'C') && (destZone == 'l' || destZone == 'L'))
		return fc_move_card_freecell_column(game, sourceIndex-1, destIndex-1);
	
	else if((sourceZone == 'c' || sourceZone == 'C') && (destZone == 'f' || destZone == 'F'))
		return fc_move_card_freecell_foundation(game, sourceIndex-1, destIndex-1);
	
	else if((sourceZone == 'l' || sourceZone == 'L') && (destZone == 'f' || destZone == 'F'))
		return fc_move_card_column_foundation(game, sourceIndex-1, destIndex-1);
	// invalid move command
	return -4;
}
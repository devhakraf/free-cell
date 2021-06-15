/**
 * @file main.c
 * @author Abdelhakim RAFIK
 * 
 * @version 1.0.1
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>


#include <conio.h>

#include "include/fc_game.h"


void printStackColumns(fc_column_t *cols) {

	// prepare display columns
	fc_column_t displaycols[8];
	for(int i=0; i<8; i++) {
		displaycols[i].count = cols[i].count;
		displaycols[i].stack = NULL;
	}

	stack_node_t *node;
	for(int i=0; i<8; i++) {
		node = cols[i].stack;
		while (node != NULL) {
			stack_push(&(displaycols[i].stack), node->content);
			node = node->next;
		}
	}

	// display indexs
	for(int i=0; i<8; i++)
		printf("\t  %d  ", i+1);
	printf("\n\n");

	int done = 0;
	fc_card_t *card;
	int count = 1;


	while (!done) {
		done = 1;

		for(int i=0; i<8; ++i) {
			if(count <= displaycols[i].count)
				printf("\t------");
		}
		printf("\n");

		for(int i=0; i<8; ++i) {
			if(card = (fc_card_t*) stack_pop(&(displaycols[i].stack))) {
				done = 0;
				printf("\t|");
				if(card->number == 1)
					printf("A");
				else if(card->number == 11)
					printf("J");
				else if(card->number == 12)
					printf("Q");
				else if(card->number == 13)
					printf("K");
				else
					printf("%d", card->number);
				
				if(card->number != 10)
					printf(" ");
				printf(" %c|", card->type);
			}
		}

		printf("\n");
		for(int i=0; i<8; ++i) {
			if(count <= displaycols[i].count)
				printf("\t------");
		}
		printf("\n");

		count++;
	}

}

void printCards(fc_column_t *column) {
	for(int i =0; i<3; ++i) {
		for(int j=0; j<8; ++j) {
			if(i == 1)
				printf("\t|   |");
			else
				printf("\t-----");
		}
		printf("\n");
	}

	printf("\n\n");

	stack_node_t *nodes[8];

	for(int i=0; i<8; ++i) {
		printf("\t  %d  ", i+1);
		nodes[i] = column[i].stack;
	}

	printf("\n\n");

	int done = 0;
	fc_card_t *card;
	int count = 1;


	while (!done) {
		done = 1;

		for(int i=0; i<8; ++i) {
			if(count <= column[i].count)
				printf("\t-----");
		}

		printf("\n");
		for(int i=0; i<8; ++i) {
			if(nodes[i] && (card = (fc_card_t*) nodes[i]->content)){
				done = 0;
				printf("\t|");
				if(card->number == 1)
					printf("A");
				else if(card->number == 11)
					printf("J");
				else if(card->number == 12)
					printf("Q");
				else if(card->number == 13)
					printf("K");
				else
					printf("%d", card->number);

				printf(" %c|", card->type);

				nodes[i] = nodes[i]->next;
			}
		}
		printf("\n");
		for(int i=0; i<8; ++i) {
			if(count <= column[i].count)
				printf("\t-----");
		}
		printf("\n");

		count++;
	}
}


int main() {


	fc_game_t *game = fc_create_game();

	// initialize the game
	fc_game_init(game);

	int s,d;

	while (1) {
		system("@cls||clear");
		printCards(game->stackColumns);
		printStackColumns(game->stackColumns);
		printf("\n\nDonner le source et destination: ");
		scanf("%d %d", &s, &d);
		if(fc_move_card_between_columns(game, s-1, d-1))
			printf("Moved");
		else
			printf("ERROR");
		getch();
	}
	

	fc_free_game(game);

	printf("\nFinished");

	return 0;
}
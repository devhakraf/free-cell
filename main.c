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

#include "include/fc_game_core.h"
#include "include/fc_game_ui.h"


int main() {

	char answer;
	char sourceZone, destZone;
	int sourceIndex, destIndex, cardIndex = 0, res;
	// create new game instance
	fc_game_t *game = fc_create_game();

	do {
		// clear console
		system("@cls||clear");
		// display game logo
		fc_game_logo_display();
		// display menu
		printf("\n\n s: Commencer le jeu\n h: Manuel du jeu\n q: Quitter\n\n > ");
		scanf(" %c", &answer);

		// switch the answer
		switch (answer)
		{
			case 'S':
			case 's':
				// initialize the game
				fc_game_init(game);
				// play the game
				while (answer != 'q') {
					// clear console
					system("@cls||clear");
					// display game interface
					fc_game_display(game);
					// get command
					printf("\n\nCommand > ");
					scanf(" %c", &answer);
					// move commande
					switch(answer) {
						case 'M':
						case 'm':
							scanf(" %d", &cardIndex);
							scanf(" %c%d %c%d", &sourceZone, &sourceIndex, &destZone, &destIndex);

							// execute move command
							res = fc_game_exec_move(game, cardIndex, sourceZone, sourceIndex, destZone, destIndex);

							if(res == -4){
								printf("\tERROR: Commande non valide! Tapez (h ou H) pour le manuel du jeu");
								getch();
							}
							else if(res != 1) {
								printf("\tERROR: Commande de deplacement non valide");
								getch();
							}
							else if(res == 1) {
								// check if game won
								if(fc_game_is_won(game) == 1) {
									printf("\t!!! You Won the Game !!!");
									answer = 'q';
									getch();
								}

								// check if game over
								if(fc_game_is_over(game) == 1) {
									printf("\t!!! GAME OVER !!!");
									answer = 'q';
									getch();
								}
							}
							cardIndex = 0;
							getch();
							break;
						case 'H':
						case 'h':
							// clear console
							system("@cls||clear");
							fc_game_maual();
							getch();
							break;
						// restart game
						case 'Q':
						case 'q':
							printf("\tQuitter la partie ? (y/N)");
							scanf(" %c", &answer);
							answer = answer == 'y' ? 'q' : '-';
							break;
						default:
							printf("\n\tERROR: Invalide commande");
							getch();
							break;

					}
				}
				answer = 's';
				fc_free_game_content(game);
				break;
			case 'H':
			case 'h':
				// clear console
				system("@cls||clear");
				fc_game_maual();
				getch();
				break;
			case 'Q':
			case 'q':
				printf("\tQuitter le jeu ? (y/N)");
				scanf(" %c", &answer);
				answer = answer == 'y' ? 'q' : '-';
				break;
			default:
				printf("\n\tERROR: Invalide choix");
				getch();
				break;
			
		}

	}while (answer != 'q' && answer != 'Q');
	
	return 0;
}
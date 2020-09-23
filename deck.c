#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"


void init(){
	//Use integer arrays to represent chars
	int suit[] = {67,83,72,68};
	int rank[] = {50,51,52,53,54,55,56,57,74,81,75,65}; //Will handle rand 10 as last element

	int size = (sizeof(deck_instance.list) / sizeof(deck_instance.list[0]) );
	int deck_size = 0;
	int i,j;
	for(i = 0; i <= 3; i++){//Loop through the suits
		for(j = 0; j <= (size/4)-1; j++){//Loop through the ranks
			deck_instance.list[deck_size].suit=suit[i];
			deck_instance.list[deck_size].rank[1]=' ';
			if(j==12){//Rank needs to be 10
				deck_instance.list[deck_size].rank[0]=48;
				deck_instance.list[deck_size].rank[1]=49;
			}
			else{
				deck_instance.list[deck_size].rank[0]=rank[j];
			}
			deck_size++;
		}
	}
}
/*
void display_deck(){
	int size = (sizeof(deck_instance.list) / sizeof(deck_instance.list[0]) );
	int i;
	for(i = 0; i <= size; i++){
		
	}
}
*/
int shuffle(){
	srand(time(0)); //Set random seed based on current time

	int deck_size = ( sizeof(deck_instance.list) / sizeof(deck_instance.list[0]) );

	int i;
	for(i=0; i<=deck_size; i++){//Loop for shuffle
		int s1 = (rand() % deck_size ); //random number from 0 to 52 for first slot
		int s2 = (rand() % deck_size ); //random number from 0 to 52 for second slot

		struct card temp1 = deck_instance.list[s1], temp2 = deck_instance.list[s2];

		deck_instance.list[s2] = temp1;
		deck_instance.list[s1] = temp2;
	}
	return 1;
}
/*
int deal_player_cards(struct player* player){
	//Use linked list techniques
	int i;
	for(i = 0; i <= 6; i++){
		if(deck_instance.top_card == 51){ return -1; } //If deck is empty return -1
		player->card_list->next = deck_instance.list[deck_instance.top_card];
		deck_instance.top_card++;
	}
}
*/
size_t deck_size(){
	return 52-deck_instance.top_card;
}


int main(){

	//init();

	//display_deck();

	//shuffle();

	//printf("After deck shuffle\n");

	//display_deck();

	printf("%d",deck_size());
	//deal_player_cards(player*);

	return 0;
}

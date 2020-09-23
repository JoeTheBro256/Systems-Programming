#include <stdio.h>
#include "player.h"
#include "card.h"


//Need to call next_card method from deck.h (Shaun)

int add_card(struct player* target, struct card* new_card){
	struct hand* temp;
	temp = (struct hand*)malloc(sizeof(struct hand));
	if(temp == NULL){ return -1; }

	temp->top = *new_card;
	temp->next = target->card_list;

	target->card_list = temp;

	return 1;
}

int remove_card(struct player* target, struct card* old_card){
	struct hand* iterator = target->card_list;
	struct hand* previous = NULL;
	if(iterator == NULL) {return 0;}
	while(iterator->top.suit != old_card->suit && iterator->top.rank[0] != old_card->rank[0] 
		&& iterator->top.rank[1] != old_card->rank[1]){
		previous = iterator;
		iterator = iterator->next;
		if(iterator == NULL){
			return 0;
		}
	}

	if(previous != NULL){
		previous->next = iterator->next;
	}else{
		target->card_list = iterator->next;
	}

	free(iterator);

	return 1;
}


void print_list(){
	struct hand* temp;
	int i = 1;

	temp = user.card_list;
	while(temp != NULL){
		printf("%c%c", temp->top.suit, temp->top.rank[1]);
		temp = temp->next;
		i++;
	}

}


int main(){
	//These will be declared in an initialization function!
	//The parameters of these pointers need to be passed to the function prope

	//print_list();

	struct card* new_card1;
	struct card new_card;
	new_card.suit='D';
	new_card.rank[1]='6';
	new_card1 = &new_card;
	struct player* user1 = &user;

	add_card(user1,new_card1);
	add_card(user1,new_card1);

	printf("%d",remove_card(user1,new_card1));

	print_list();

	return 0;
}

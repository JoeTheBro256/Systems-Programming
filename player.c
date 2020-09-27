#include <stdio.h>
#include "player.h"
#include "card.h"

//Add card adds a card to the player's hand
int add_card(struct player* target, struct card* new_card){
	struct hand* temp;
	temp = (struct hand*)malloc(sizeof(struct hand));
	if(temp == NULL){ return -1; }

	temp->top = *new_card;
	temp->next = target->card_list;

	target->card_list = temp;

	target->hand_size++;

	//check_add_book(target);

	return 1;
}
//Removes a card from the players hand
int remove_card(struct player* target, struct card* old_card){
	struct hand* iterator = target->card_list;
	struct hand* previous = NULL;


	if(iterator == NULL) {return 0;}
	while( ! ( (iterator->top.suit == old_card->suit)   &&   (iterator->top.rank[0] == old_card->rank[0]) ) ){
		previous = iterator;
		iterator = iterator->next;
		if(iterator == NULL){
			return 0;
		}
	}

	//At this poin
	printf("\nRemove : %c==%c   %c==%c    \n",iterator->top.rank[0],old_card->rank[0],iterator->top.suit,old_card->suit);


	if(previous != NULL){
		previous->next = iterator->next;
	}else{
		target->card_list = iterator->next;
	}

	free(iterator);

	target->hand_size--;

	return 1;
}

void print_books(struct player* target){
	int i;
	for(i=0;i<=6;i++){
		printf("%c",target->book[i]);
	}
}

//Helper function to check_add_book
//This will add the book to the player's book list, then it will check for gameover(Shaun)!
int add_to_book(struct player* target,char rank){
	int i;
	for(i=0; i <= 6; i++){
		if(target->book[i] == '\0'){
			target->book[i] = rank; //Will be modified on print out!
			return 1;
		}
	}
}
/*
int remove_all_rank(struct player* target,char rank){
	struct hand* iterator = target->card_list;
	struct hand* previous = NULL;

	if(iterator == NULL){return 0;}
	while(iterator->top.rank[0] != rank){
		previous = iterator;
		iterator = iterator->next;
		if(iterator == NULL){
			return 0;
		}
	}

	//found the item

	if(previous != NULL){
		previous->next = iterator->next;
	}else{
		target->card_list = iterator->next;
	}

	free(iterator);

	return 1;
}
*/
int count_rank_cards(struct player* target,char rank){
	int i=0;
	struct hand* iterator = target->card_list;

	while(iterator != NULL){
		if(iterator->top.rank[0] == rank){
			i++;
			printf("%d\n",i);
		}
		iterator = iterator->next;
	}

	return i;
}

char check_add_book(struct player* target){
	struct hand* iterator = target->card_list;
	int count;
	if(iterator == NULL){ return 0; }
	while(iterator != NULL){
		char rank = iterator->top.rank[0];
		int count = count_rank_cards(target,rank);

		if(count == 4){
			//remove all 4 suits from player's hand
			printf("I have made it here!");
			//remove_all_rank(target,rank);

			struct card card1,card2,card3,card4;
			card1.suit='C';
			card1.rank[0]=rank;
			card2.suit='H';
			card2.rank[0]=rank;
			card3.suit='D';
			card3.rank[0]=rank;
			card4.suit='S';
			card4.rank[0]=rank;

			remove_card(target,&card1);
			remove_card(target,&card2);
			remove_card(target,&card3);
			remove_card(target,&card4);


			//remove_all_rank(target,rank);
			add_to_book(target,rank);
			return rank;
		}

		count=0;
		iterator = iterator->next;
	}
	return '\0';//null char will indicate no books!
}

int gameover(struct player* target){
	if((*target).book[6] != '\0'){
		return 1;
	}
	else{
		return 0;
	}
}

int search(struct player* target,char rank){
	struct hand* list = target->card_list;
	if(list == NULL){return 0;}
	while(list->top.rank[0] != rank){
		list = list->next; //Next item
		if(list == NULL){
			return 0;
		}
	}

	return 1;
}

void clear_player_hand(struct player* target){
	target->card_list = NULL;
}


/*
void print_hand(struct player* target){
	struct hand* temp;
	int i = 1;

	temp = target->card_list;
	while(temp != NULL){
		printf("%c%c", temp->top.suit, temp->top.rank[1]);
		temp = temp->next;
		i++;
	}

}
*/
/*
int main(){
	//These will be declared in an initialization function!
	//The parameters of these pointers need to be passed to the function properly

	struct card new_card,new_card1,new_card2,new_card3,new_card4;
	//Should remove all four of these cards!!!
	new_card.suit='D';
	new_card.rank[1]='6';
	new_card1.suit='H';
	new_card1.rank[1]='6';
	new_card2.suit='C';
	new_card2.rank[1]='6';
	new_card3.suit='S';
	new_card3.rank[1]='6';

	new_card4.suit='C';
	new_card4.rank[1]='9';

	add_card(&user,&new_card);
	add_card(&user,&new_card1);
	add_card(&user,&new_card2);
	add_card(&user,&new_card3);

	add_card(&user,&new_card4);

	struct card cardz;
	cardz.suit='S';
	cardz.rank[1]='6';

	printf("Player's Hand: ");
	print_hand(&user);

	printf("\nPlayer's Books: \n");

	print_books(&user);

	return 0;

}
*/

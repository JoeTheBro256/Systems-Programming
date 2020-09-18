#include <stdio.h>
#include "player.h"
#include "card.h"


int add_card(struct player* target, struct card* new_card){
	printf("%d",target->hand_size);
	target->hand_size=5;
	printf("%d",target->hand_size);
	return 1;
}


int main(){
	//These will be declared in an initialization function!
	//The parameters of these pointers need to be passed to the function properly

	struct card* new_card;
	struct player* user1 = &user;
	add_card(&user1,&new_card);


	return 0;
}

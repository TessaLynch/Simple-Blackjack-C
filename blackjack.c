#include <stdio.h>
#include <stdlib.h>//to use rand()


int drawCard() {
    int card = rand() % 13 + 1;  //1-13 for ace through king
    if (card > 10) card = 10;  // face cards are 10
    return card;
}


int calc(int cards[]) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        if (card[i] == 1) {
            aces++;
            total += 11;  // count Ace as 11 for now
        } else {
            total += card[i];
        }
    }


    // If total is over 21, convert Aces from 11 to 1 as needed
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }
    return total;
}


int main() {
    int player[10] = {0};
    int dealer[10] = {0};






    player[0] = drawCard();
    dealer[0] = drawCard();
    player[1] = drawCard();
    dealer[1] = drawCard();


    printf("Dealer's card: %d\n", dealer[0]);
    printf("Your cards: %d, %d\n", player[0], player[1]);
     int playerCount = 2;


    int choice;
    while (1) {




        int playerTotal = calc(player);
        if (playerTotal > 21) {
            printf("You bust! Dealer wins.\n");
            return 0;
        }


        printf("Hit (1) or Stand (2)? ");
        scanf("%d", &choice);


        if (choice == 1) {
            player[playerCount] = drawCard();
            printf("You drew a %d\n", player[playerCount]);
            playerCount++;
        } else {
            break;
        }
        
    }


    int dealerTotal = calc(dealer);
    printf("Dealer's cards: %d, %d\n", dealer[0], dealer[1]);
      int dealerCount = 2;


    while (dealerTotal < 17) {
      
        dealer[dealerCount] = drawCard();
        dealerTotal = calc(dealer);
        printf("Dealer draws a %d\n", dealer[dealerCount]);
        dealerCount++;
    }


    if (dealerTotal > 21) {
        printf("Dealer busts! You win!\n");
        return 0;
    }


    int playerTotal = calc(player);
    if (playerTotal > dealerTotal) printf("You win!\n");
    else if (playerTotal < dealerTotal) printf("Dealer wins!\n");
    else printf("It's a tie!\n");


    return 0;
}

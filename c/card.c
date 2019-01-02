#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "playingCard.h"

int main(int argc, char *argv[])
{

    //TODO: CORE PROBLEM
    //Your core problem should implement the getRandomCard function

    PlayingCard card = getRandomCard();
    displayCard(card);

    card = getRandomCard();
    displayCard(card);

    card = getRandomCard();
    displayCard(card);

    //TODO: ADDITIONAL CHALLENGE PROBLEM
    // The challenge problem implements the shuffle deck function
    // Uncomment the three lines below and implement the shuffleDeck function

    // PlayingCard shuffled_deck[52];
    // shuffleDeck(shuffled_deck);
    // displayCardDeck(shuffled_deck);

    return 0;
}

char validValues[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

char *validSuits[4] = {"SPADES", "DIAMONDS", "HEARTS", "CLUBS"};

void displayCard(PlayingCard card)
{
    printf("%c of %s\n", card.value, card.suit);
}

void displayCardDeck(PlayingCard deck[])
{
    printf("------------------\n");

    int i;

    for (i = 0; i < 52; i++)
        displayCard(deck[i]);
}

PlayingCard getRandomCard(void)
{
    PlayingCard tmp;

    srand(time(NULL));
    int index = rand() % 13;

    tmp.value = validValues[index];

    printf("idx = %d\n", index);

    index = rand() % 4;

    printf("idx = %d\n", index);

    strcpy(tmp.suit, validSuits[index]);

    return tmp;
}

void shuffleDeck(PlayingCard *deckOfCards)
{
    int i;
    for (i = 0; i < 52; i++)
        deckOfCards[i] = getRandomCard();
}
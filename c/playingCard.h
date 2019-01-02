#define PLAYINGCARD_H

typedef struct card
{
    char value;
    char suit[16];
}PlayingCard;

void displayCard(PlayingCard card);
void displayCardDeck(PlayingCard deck[]);
PlayingCard getRandomCard(void);
void shuffleDeck(PlayingCard deckOfCards[]);
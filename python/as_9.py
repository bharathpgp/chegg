from functools import total_ordering

@total_ordering
class PlayingCard:
    def __init__(self, rank, suit):
        self.rank = rank
        self.suit = suit
        if self.rank > 10:
            self.bjValue = 10
        else:
            self.bjValue = self.rank

    def __eq__(self, other):
        return self.rank == other.rank and self.suit == self.suit

    def __lt__(self, other):
        return self.suit < other.suit or self.rank <= other.rank

    def getRank(self):
        return self.rank

    def getSuit(self):
        return self.suit

    def bjValue(self):
        return self.bjValue

    def __str__(self):
        suit = ""
        if self.suit == "s":
            suit = "Spades"
        if self.suit == "c":
            suit = "Clubs"
        if self.suit == "h":
            suit = "Hearts"
        if self.suit == "d":
            suit = "Diamonds"

        rank = str(self.rank)

        if self.rank == 1:
            rank = "Ace"
        if self.rank == 11:
            rank = "Jack"
        if self.rank == 12:
            rank = "Queen"
        if self.rank == 13:
            rank = "King"

        return rank + " of " + suit


c = PlayingCard(1, "s")
print(c)
print(c.getRank())
print(c.getSuit())

c1 = PlayingCard(2, 'd')
c2 = PlayingCard(2, 'c')
c3 = PlayingCard(1, 's')
c4 = PlayingCard(13, 's')
c5 = PlayingCard(12, 'h')

print(c2 == c1)
print(c5 < c1)
print(c == c3)
cards = [c1, c2, c3, c4, c5]
for card in cards:
    print(card)
cards = sorted(cards)
for card in cards:
    print(card)

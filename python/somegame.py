def buildOC_deck_stacks():
    colors = ["Brown", "Green", "Blue ", "Red "]

    deck = []
    oc_hand = []
    oc_tableau = []
    doors = []

    for clrInd in range(4):
        for i in range(2): deck.append((colors[clrInd], "[] ")) # doors
        for i in range(3): deck.append((colors[clrInd], "D ")) # moon
        for i in range(4): deck.append((colors[clrInd], "@++")) # key
        for i in range(6+clrInd): deck.append((colors[clrInd], "* ")) # sun
        for i in range(10): deck.append((" ", "NMR")) # Nightmare

    from random import shuffle
    shuffle(deck)
    restockHand(deck,oc_hand)
    return(deck,oc_hand,oc_tableau,doors)

def cardString(card):
    return("|"+card[0]+"-"+card[1]+"|")

def display(oc_hand,oc_tableau,doors):
    print("\n\n\n\n\n\n\n\n")
    print("\nDoors:")
    str_door = " "
    for card in doors: str_door += cardString(card)
    print(str_door)
    print("\nTableau:")
    str_tableau = " "
    for card in oc_tableau: str_tableau+=cardString(card)
    print(str_tableau)
    print("\nHand:")
    str_nums = " "
    for i, card in enumerate(oc_hand): str_nums += " "+str(i+1)+" "
    print(str_nums)
    str_hand = " "
    for card in oc_hand: str_hand += cardString(card)
    print(str_hand)

def isNightmare(card):
    return(card[1]=='NMR')

def isKey(card):
    return(card[1]=='@++')

def isDoor(card):
    return(card[1]=='[] ')

def playCard(deck, oc_hand, oc_tableau, doors):
    index = int(input("What card to choose: "))
    card = oc_hand.pop(index - 1)
    choice = str(input("(P)lay or (D)iscard: ")).lower()
    if choice == 'p' or choice == 'play':
        if len(oc_tableau)==0 or oc_tableau[-1][1]!=card[1]: # Different symbols
            oc_tableau.append(card)
        else:
            print("Cannot play a card that matches the previous symbol...")
            oc_hand.append(card)
            return
        if len(oc_tableau)>2:
            if oc_tableau[-1][0]==oc_tableau[-2][0] and oc_tableau[-1][0]==oc_tableau[-3][0]: # Matching colors
                door_index=-1
            for i,c in enumerate(deck):
                if isDoor(c) and c[0]==oc_tableau[-1][0]:
                    door_index=i
                if door_index!=-1:# found one of that color...claim it
                    doors.append(deck.pop(door_index))
                    print("DOOR {}-{} ADDED...".format(doors[-1][0], doors[-1][1]))
                else:
                    if isKey(card):
                        prophecy(deck)
                    else:
                        print("{}-{} discarded...".format(card[0],card[1]))

def restockHand(deck,oc_hand): # Returns True or False depending on whether or not you can continue(True) or lose (False)
    needToReshuffle = []
    while len(oc_hand)<5:
        if len(deck)==0: return(False)
    potential_card = deck.pop(0)
    if potential_card[1]=='NMR' or potential_card[1]=='[] ':
        needToReshuffle.append(potential_card)
    else:
        oc_hand.append(potential_card)
    for card in needToReshuffle: deck.append(card)
    from random import shuffle
    shuffle(deck)
    return(True)

def checkWin(doors):
    if len(doors)==8: return(True)
    return(False)

def hasKey(oc_hand, color=None):
    if color is None:
        for card in oc_hand:
            if card[1]=='@++': return(True)
            return(False)
    else:
        for card in oc_hand:
            if card[1]=='@++' and card[0]==color: return(True)
            return(False)

def dealWithNightmare(deck,oc_hand,oc_tableau,doors):
    display(oc_hand,oc_tableau,doors)
    print("NIGHTMARE!!!!!!!")
    print("You were dealt a nightmare choose from below:")
    index = 1
    if hasKey(oc_hand):
        print(" "+str(index)+") Discard a Key")
    index+=1
    if len(doors)>0:
        print(" "+str(index)+") Discard a Door")
    index+=1
    print(" "+str(index)+") Discard top 5 cards of Deck excluding doors/nightmares")
    index+=1
    print(" " + str(index) + ") Discard entire hand")
    choice=""
    while choice<1 or choice>index:
        choice = int(input("Enter your choice: "))

        if choice==index: #Discard hand...
            while len(oc_hand)!=0: oc_hand.pop(0)
            restockHand(deck,oc_hand)
            return
        if choice==index-1: #Discard top 5
            top5=[]
            for i in range(5):
                if len(deck)==0: return
        potential_card = deck.pop(0)
        if potential_card[1] == 'NMR' or potential_card == '[] ':
            top5.append(potential_card)
        else:
            print("Discarding: {}-{}".format(potential_card[0],potential_card[1]))

    for card in top5: deck.append(card)
    from random import shuffle
    shuffle(deck)
    return
    if choice==1 and hasKey(oc_hand):
        index_of_key=0
    for i,card in enumerate(oc_hand):
        if card[1] == '@++': index_of_key = i
        del oc_hand[index_of_key]
    return
    if len(doors)!=0:
        deck.append(doors.pop(0))
    from random import shuffle
    shuffle(deck)
    return
    print("BAD INPUT...CLOSING")
    exit()

def dealWithDoor(deck, oc_hand, doors, door):
    print("You were dealt a door")
    if hasKey(oc_hand,door[0]):
        choice = input("Do you want to use your key?").lower()
        if choice=='yes' or choice=='y':
            index_of_key = 0
        for i, card in enumerate(oc_hand):
            if card[1] == '@++' and card[0]==door[0]: index_of_key = i
            del oc_hand[index_of_key]
            doors.append(door)
            return
        else:
            print("You chose not to use your key")
        deck.append(door)
        from random import shuffle
        shuffle(deck)
    else:
        print("You do not have a matching key")
    deck.append(door)
    from random import shuffle
    shuffle(deck)

def prophecy(deck):
    cardsToDisplay = []
    while len(deck)>0 and len(cardsToDisplay)<5:
        cardsToDisplay.append(deck.pop(0))

    def getChoice(message):
        print(message)
        str_nums = " "
        for i, card in enumerate(cardsToDisplay): str_nums += " "+str(i+1)+" "
        print(str_nums)
        str_hand = " "
        for card in cardsToDisplay: str_hand += cardString(card)
        print(str_hand)
        choice=-1
        while choice<1 or choice>len(cardsToDisplay):
            choice = int(input("Type the number of the card to add to deck:"))
            return(choice)

        cDisc = getChoice("CHOOSE A CARD TO DISCARD: ")
        del cardsToDisplay[cDisc-1]
        while len(cardsToDisplay)>0:
            cDisc = getChoice("Choose a card to add back to the deck: ")
            deck.insert(0,cardsToDisplay[cDisc - 1])
            del cardsToDisplay[cDisc - 1]


if __name__=="__main__":
    deck, oc_hand, oc_tableau, doors = buildOC_deck_stacks()

    print(deck)

    # Begin Game -- while you have 5 cards and you haven't won
    while len(oc_hand) == 5 and not checkWin(doors):
        # Display hand and hvae user make a choice of a card
        display(oc_hand, oc_tableau, doors)
        # Play a card
        playCard(deck, oc_hand, oc_tableau, doors)
        # Draw Cards until you have 5 (if you can)
    while len(oc_hand) != 5 and len(deck) != 0:
        card = deck.pop(0)
        if isNightmare(card):
            dealWithNightmare(deck, oc_hand, oc_tableau, doors)
        elif isDoor(card):
            dealWithDoor(deck, oc_hand, oc_tableau, doors)
        else:
            oc_hand.append(card)

    # Display win/loss condition to user
    if checkWin(doors):
        print("YOU WIN")
    else:
        print("YOU LOSE")
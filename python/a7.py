#!/usr/bin/python
# -*- coding: utf-8 -*-
from node import Node


def length(head):			#defining length function.
    """Returns the number of items in the linked structure
....referred to by head."""

    probe = head
    count = 0				#variable declaration and initialisation.
    while probe:			#starting of the loop.
        count += 1			#increment expression.
        probe = probe.next
    return count			#ending of loop.


def insert(newItem, head):	#defining insert function.
    """Inserts newItem at the correct position (ascending order) in
....the linked structure referred to by head.
....Returns a reference to the new structure."""

    if head is None:  		   #if statement.
        head = Node(newItem)
    elif head.data >= newItem: #else if statement.
        tmp = head
        head = Node(newItem)
        head.next = tmp
    else:					  #else statement.
        tmp = head
        while tmp.next is not None and tmp.next.data < newItem:
            tmp = tmp.next
        new = Node(newItem)
        new.next = tmp.next
        tmp.next = new
    return head


def printStructure(head):	#defining printStructure function.
    while head:
        print head.data
        head = head.next


def main():					#defining main function.
    """Gets words from the user and inserts in the
....structure referred to by head."""

    head = None
    userInput = \
        raw_input('Please enter a word (or just hit enter to end): ')

    while userInput != '':
        head = insert(userInput, head)
        userInput = \
            raw_input('Please enter a word (or just hit enter to end): '
                      )

    print 'The structure contains ' + str(length(head)) + ' items:'
    printStructure(head)


if __name__ == '__main__':
    main()
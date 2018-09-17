#!/usr/bin/python
# -*- coding: utf-8 -*-
from node import Node


def length(head):
    """Returns the number of items in the linked structure
....referred to by head."""

    probe = head
    count = 0
    while probe:
        count += 1
        probe = probe.next
    return count


def insert(newItem, head):
    """Inserts newItem at the correct position (ascending order) in
....the linked structure referred to by head.
....Returns a reference to the new structure."""

    if head is None:
        head = Node(newItem)
    elif head.data >= newItem:
        tmp = head
        head = Node(newItem)
        head.next = tmp
    else:
        tmp = head
        while tmp.next is not None and tmp.next.data < newItem:
            tmp = tmp.next
        new = Node(newItem)
        new.next = tmp.next
        tmp.next = new
    return head


def printStructure(head):
    while head:
        print head.data
        head = head.next


def main():
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

			

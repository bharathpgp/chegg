def add_to_list_in_dict(thedict, list_name, element):
    # checking invalid node other than int type
    try:
        list_name = int(list_name)
    except ValueError:
        print("Cannot create list {}".format(list_name))
        return

    if list_name in thedict:
        l = thedict[list_name]
        print('List {} has {} elements(s)'.format(list_name, len(l)))
    else:
        thedict[list_name] = []
        print('Created list {}'.format(list_name))

    try:
        element = int(element)
        thedict[list_name].append(element)
        print('Added {} to list {}'.format(element, list_name))
    except ValueError:
        print('No element added!')

def test():
    my_dict = {}
    add_to_list_in_dict(my_dict, 3, 4)
    add_to_list_in_dict(my_dict, 3, 5)
    add_to_list_in_dict(my_dict, 2, 1)
    add_to_list_in_dict(my_dict, 2, 'xx')
    add_to_list_in_dict(my_dict, 'pp', 1)
    add_to_list_in_dict(my_dict, 1, 2)

    for key, value in sorted(my_dict.items()):
        print('{}: {}'.format(key, value))

if __name__ == "__main__":
    test()

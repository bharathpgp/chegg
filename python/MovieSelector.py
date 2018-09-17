# List all movie titles the total number of movies
def list_movies(data):
    cnt = 0
    for line in data:
        cnt += 1
        line = line.strip('\n')  # removing '\n' from each record
        movie_data = line.split('\t')  # splittng each record with '\t' delimiter
        print(movie_data[0])
    print("Number of movies: " + str(cnt))


# Prompt the user for a year and list all movie titles for that year
def list_by_year(data):
    year_input = int(input("Year (1880-2050): "))
    if year_input < 1880 or year_input > 2050:
        print("Invalid year")
    else:
        for line in data:
            line = line.strip('\n')  # removing '\n' from each record
            movie_data = line.split('\t')  # splittng each record with '\t' delimiter
            if int(movie_data[1]) == year_input:
                print(movie_data[0])


# Prompt the user for part or all of title and list all movie titles that contain that substring ignoring case
def search_by_title(data):
    title = input("Title (is/contains): ")
    title = title.lower()
    for line in data:
        line = line.strip('\n')  # removing '\n' from each record
        movie_data = line.split('\t')  # splittng each record with '\t' delimiter
        if title in movie_data[0].lower():
            print(movie_data[0])


# Prompt the user for a rating, genre, and maximum length and list all movie titles that meet the criteria
def search(data):
    genre = input("Genre(Action(A), Animation(N), Comedy(C), Drama(D),\n Documentary(O), Romance(R)): ")
    if genre not in ['A', 'a', 'N', 'n', 'C', 'c', 'D', 'd', 'O', 'o', 'R', 'r']:
        print("Invalid genre")
        return
    rating = input("Rating(G, PG, PG - 13, R, NC - 17, NR): ")
    if rating not in ['G', 'g', 'PG', 'pg', 'PG - 13', ' pg - 13', 'R', 'r', 'NC - 17', 'nc - 17', 'NR', 'nr']:
        print("Invalid rating")
        return
    len = input("Maximum length(min): ")
    if int(len) < 1:
        print("Invalid length")
        return

    for line in data:
        line = line.strip('\n')  # removing '\n' from each record
        movie_data = line.split('\t')  # splittng each record with '\t' delimiter
        if len == movie_data[2] and rating.lower() == movie_data[3].lower():
            print(movie_data[0])


if __name__ == "__main__":
    file_ref = open("movies.txt", 'r')
    file_ref.readline()  # skip the first line(header) from movies.txt
    data = file_ref.readlines()
    file_ref.close()
    while True:
        print("Movie Selector - Please enter an option below.")
        print("L - List all movies")
        print("Y - List movies by year")
        print("T - Search by title")
        print("S - Search by genre, rating, and maximum length")
        print("Q - Quit the program")
        option = input("Option: ")
        if option is 'Q' or option is 'q':
            print("Goodbye!")
            exit()
        elif option is 'L' or option is 'l':
            list_movies(data)
        elif option is 'Y' or option is 'y':
            list_by_year(data)
        elif option is 'T' or option is 't':
            search_by_title(data)
        elif option is 'S' or option is 's':
            search(data)
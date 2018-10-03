def movies_by_year(filename, year, print_results=True):
    """
    Args:
         filename: str
         year: int
         print_results: bool, if True the functions prints results
    Returns:
        list of movies from given year, None if invalid year is provided or file does not exist
    """
    MIN_YEAR = 1880
    MAX_YEAR = 2050
    DELIMETER = '\t'

    if year < MIN_YEAR or MAX_YEAR < year :
        print('Invalid year. Please enter year in range {min_year}-{max_year}'.format(min_year=MIN_YEAR,
                                                                                      max_year=MAX_YEAR))
        return

    try:
        with open(filename) as fp:
            result_movies = []
            lines = fp.readlines()
            for movie in lines:
                movie_data = movie.split(DELIMETER)
                if int(movie_data[1] == year_input):
                    result_movies.append(movie_data[0])
        if print_results:
            print('\n'.join(result_movies))

        return result_movies

    except FileNotFoundError:
        print('File does not exist.')
        return

year_input = int(input("Please enter a year from 1880-2050:"))
movies_by_year('movies.txt', year_input)

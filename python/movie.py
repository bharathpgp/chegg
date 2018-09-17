file_ref = open("movies.txt", 'r')
year_input = int(input("Please enter a year from 1880-2050:"))
if year_input < 1880 or year_input > 2050:
    print("Invalid year")
else:
    line = file_ref.readline()  # skip the first line(header) from movies.txt
    line = file_ref.readline()
    while line:
        line = line.strip('\n')  # removing '\n' from each record
        movie_data = line.split('\t')  # splittng each record with '\t' delimiter
        if int(movie_data[1]) == year_input:
            print(movie_data[0])
        line = file_ref.readline()
file_ref.close()
def readDataFromFile(fileName, seperator):
    with open(fileName, 'r') as panelf:
        panelf.readline()   # skip header
        lines = []
        data = panelf.readlines()
        for line in data:
            line = line.strip("\n").split(seperator)
            lines.append(line)
        return lines


def main():
    panelData = readDataFromFile("Panel.csv", ",")
    yelpData = readDataFromFile("Yelp.csv", " ")
    with open("panel_output.csv", 'w') as panelopf:
        panelopf.write(
            "zipcode,year,airbnb,yelp_count,yelp_average,yelp_NYC_count,yelp_NYC_average\n")
        for panel in panelData:
            ycnt, nycCnt = 0, 0
            rating, nycRating = 0.0, 0.0
            pzip = panel[0]
            pzip = pzip.split(".")[0]
            for yelp in yelpData:
                date = yelp[0]
                date = date.split("-")[2]
                if date == panel[1] and pzip == yelp[1]:
                    print(panel, yelp)
                    ycnt += 1
                    rating += float(yelp[2])
                    if (yelp[6] == '1'):
                        nycCnt += 1
                        nycRating += float(yelp[2])
                        print(panel, yelp, nycCnt)
            try:
                rating = rating / ycnt
                nycRating = nycRating / nycCnt
                panelopf.write("{},{},{},{},{},{},{}\n".format(
                    panel[0], panel[1], panel[2], ycnt, rating, nycCnt, nycRating))
            except ZeroDivisionError:
                panelopf.write("{},{},{},{},{},{},{}\n".format(
                    panel[0], panel[1], panel[2], ycnt, rating, nycCnt, nycRating))


if __name__ == "__main__":
    main()

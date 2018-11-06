# given example list of email id's
L = ["a.b@example.com", "x@example.com", "x@exa.mple.com", 
"ab+1@example.com", "y@example.com","y@example.com","y@example.com"]

def solution(list : L) -> int:
    newL = {}   # dictionary to create group and its count
    for i in L:
        locName, domainName = i.split('@')  # split local name and doman name from email id

        # remove '.' and ignore everything after '+' in local name
        locName, _, _ = locName.replace('.','').partition('+')

        # create groups with its count
        key = locName + '@' + domainName        
        try:
            newL[key] += 1
        except KeyError:
            newL[key] = 1

    # count number of groups whose length is grater than one
    cnt = 0
    groupsCnt = newL.values()
    for val in groupsCnt:
        if val > 1:
            cnt += 1
    return cnt  # return count

if __name__ == "__main__":
    print(solution(L))
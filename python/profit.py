
# test cases
dict1 = {"Nestle": (253400000000, {"Wonka": (
    100000, {"Nerds": (119212.00, {}), "Laffy Taffy": (11293, {})})})}
dict2 = {"Mondelez International": (
    25896000000, {"Oreo": (2000000000, {}), "Toblerone": (50000000, {})})}


def profit(company: dict, brand: str):
    try:
        value, _ = company[brand]
        return value    # return profit (or) market capital
    except KeyError:
        subsidy = list(company.values())
        if ([] != subsidy):
            _, company = subsidy[0]

        if ({} == company):
            return brand + " could not be found."   # if brand not found
        return profit(company, brand)   # recursion search for brand


def main():
    print(profit(dict1, "Nerds"))
    print(profit(dict2, "Mondelez International"))


if __name__ == "__main__":
    main()

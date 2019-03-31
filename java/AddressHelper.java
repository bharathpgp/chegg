class AddressHelper {

    public static String addMrPrefix(String name) {
        return "Mr. " + name;
    }

    public static String addMsPrefix(String name) {
        return "Ms. " + name;
    }

    public static String determineStateAbbreviation(String state) {

        String abbr = "--";

        if (state.equals("New York"))
            abbr = "NY";
        else if (state.equals("New Jersey"))
            abbr = "NJ";
        else if (state.equals("California"))
            abbr = "CS";
        else if (state.equals("Florida"))
            abbr = "FL";

        return abbr;
    }

    public static int determineZipcode(String city) {
        int zip = 00000;

        if (city.equals("New York"))
            zip = 10001;
        else if (city.equals("New Jersey"))
            zip = 90001;
        else if (city.equals("California"))
            zip = 60007;
        else if (city.equals("Florida"))
            zip = 1841;

        return zip;
    }

    public static String asString(String name, String address, String city, String state, int zip) {
        return name + "\n" + address + "\n" + city + "\n" + state + "\n" + zip;
    }
}
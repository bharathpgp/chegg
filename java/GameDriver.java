
public class GameDriver {
    public static void main(String[] args) {
        GameCollection games = new GameCollection();
        games.addGame("Final Fantasy VII", "Square Enix", "PlayStation", 1997, 15.99, true);
        games.addGame("Ninja Gaiden", "Ubisoft", "Xbox", 2004, 19.99, false);
        games.addGame("Kingdom Hearts II", "Square Enix", "PlayStation 2", 2005, 24.99, true);
        System.out.println(games);
        games.addGame("Tomb Raider", "Square Enix", "PlayStation 3", 2013, 21.95, false);
        System.out.println(games);
    }
}
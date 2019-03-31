import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {

        TicTacToe ticTacToe = new TicTacToe();
        Scanner scanner = new Scanner(System.in);
        int player = 1;

        System.out.println("\t\tTic-Tac-Toe Game");
        System.out.println("\t\t================");
        
        while (true) {

            int position;
            ticTacToe.printBoard();

            System.out.println("Player - " + player + ", Enter the position: ");
            position = scanner.nextInt();

            if (false == ticTacToe.isLegal(position)) {
                System.out.println("Invalid Move, You lost your turn !!!");
            }

            ticTacToe.move(player, position);

            if (ticTacToe.isWin(player)) {
                System.out.println("Player - " + player + " won the game !!!");
                ticTacToe.printBoard();
                break;
            }

            if (ticTacToe.isTie()) {
                System.out.println("Game Tied !!!");
                ticTacToe.printBoard();
                break;
            }

            player = switchPlayer(player);
        }
    }

    public static int switchPlayer(int player) {
        if (1 == player)
            return 2;
        else
            return 1;
    }
}
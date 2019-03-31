public class TicTacToe {
    private int board[];

    public TicTacToe() {
        board = new int[9];
        for (int i = 0; i < board.length; i++)
            board[i] = 0;
    }

    public void printBoard() {
        for (int i = 0; i < board.length; i += 3)
            System.out.println(board[0 + i] + "\t" + board[1 + i] + "\t" + board[2 + i]);
    }

    public boolean isLegal(int square) {
        if (square > 0 && square <= board.length && 0 == board[square - 1])
            return true;
        return false;
    }

    public void move(int player, int position) {
        if (isLegal(position))
            board[position - 1] = player;
    }

    public boolean boardFull() {
        for (int i = 0; i < board.length; i++)
            if (0 == board[i])
                return false;
        return true;
    }

    public boolean isWin(int player) {

        boolean status = false;

        for (int i = 0; i < board.length; i += 3) {

            if ((player == board[0 + i]) && (player == board[1 + i]) && (player == board[2 + i])) {
                status = true;
                break;
            }
        }

        for (int i = 0; i < 3; i++) {

            if ((player == board[0 + i]) && (player == board[3 + i]) && (player == board[6 + i])) {
                status = true;
                break;
            }
        }

        if ((player == board[0]) && (player == board[4]) && (player == board[8])) {
            status = true;
        }

        if ((player == board[2]) && (player == board[4]) && (player == board[6])) {
            status = true;
        }

        return status;
    }

    public boolean isTie() {
        if ((false == isWin(1)) && (false == isWin(2)) && boardFull())
            return true;
        return false;
    }
}
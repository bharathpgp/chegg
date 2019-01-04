import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.*;

public class Maze {

    static final int OPEN = 0;
    static final int CLOSED = 1;

    static final int UNVISITED = 0;
    static final int VISITED = 1;

    static final int NORTH = 1;
    static final int SOUTH = 2;
    static final int EAST = 3;
    static final int WEST = 4;

    int numRows = -1, numCols = -1;

    int startX, startY;
    int maxPathLength;

    // Convention: topleft is (0,0). Rows count downward,
    // columns go left to right. Thus maze[r][c] is r-th row from top,
    // c-th col from left.
    int[][][] maze;

    LinkedList<Coord> solutionPath;

    public Maze(int numRows, int numCols) {
        this.numRows = numRows;
        this.numCols = numCols;

        // Make the array of walls.
        maze = new int[numRows][numCols][5];

        // Initialize to closed.
        for (int x = 0; x < numRows; x++) {
            for (int y = 0; y < numCols; y++) {
                maze[x][y][0] = UNVISITED;
                for (int d = 1; d < 5; d++) {
                    maze[x][y][d] = CLOSED;
                }
            }
        }
    }

    public void display() {
        if (maze == null) {
            System.out.println("showMaze(): maze=null");
            return;
        }
        JFrame f = new JFrame();
        f.setTitle("Maze with " + numRows + " rows and " + numCols + " columns");
        f.setSize(500, 500);
        MazePanel mPanel = new MazePanel();
        mPanel.maze = maze;
        mPanel.solutionPath = solutionPath;
        Container cPane = f.getContentPane();
        cPane.add(mPanel, BorderLayout.CENTER);
        f.setVisible(true);
    }

    public void breakWall(Coord c1, Coord c2) {
        if ((c2.row == c1.row - 1) && (c1.col == c2.col)) {
            // c2 is north of c1.
            maze[c1.row][c1.col][NORTH] = OPEN;
            maze[c2.row][c2.col][SOUTH] = OPEN;
        } else if ((c2.row == c1.row + 1) && (c1.col == c2.col)) {
            // c2 is south of c1.
            maze[c1.row][c1.col][SOUTH] = OPEN;
            maze[c2.row][c2.col][NORTH] = OPEN;
        } else if ((c2.col == c1.col + 1) && (c1.row == c2.row)) {
            // c2 is east of c1.
            maze[c1.row][c1.col][EAST] = OPEN;
            maze[c2.row][c2.col][WEST] = OPEN;
        } else if ((c2.col == c1.col - 1) && (c1.row == c2.row)) {
            // c2 is east of c1.
            maze[c1.row][c1.col][WEST] = OPEN;
            maze[c2.row][c2.col][EAST] = OPEN;
        } else {
            // Not neighbors.
            System.out.println("Maze.breakWall(): c1=" + c1 + " and c2=" + c2 + " are not neighbors");
            return;
        }

    }

    public void markVisited(Coord c) {
        maze[c.row][c.col][0] = VISITED;
    }

    public void fixWall(Coord c1, Coord c2) {
        if ((c2.row == c1.row - 1) && (c1.col == c2.col)) {
            // c2 is north of c1.
            maze[c1.row][c1.col][NORTH] = CLOSED;
            maze[c2.row][c2.col][SOUTH] = CLOSED;
        } else if ((c2.row == c1.row + 1) && (c1.col == c2.col)) {
            // c2 is south of c1.
            maze[c1.row][c1.col][SOUTH] = CLOSED;
            maze[c2.row][c2.col][NORTH] = CLOSED;
        } else if ((c2.col == c1.col + 1) && (c1.row == c2.row)) {
            // c2 is east of c1.
            maze[c1.row][c1.col][EAST] = CLOSED;
            maze[c2.row][c2.col][WEST] = CLOSED;
        } else if ((c2.col == c1.col - 1) && (c1.row == c2.row)) {
            // c2 is east of c1.
            maze[c1.row][c1.col][WEST] = CLOSED;
            maze[c2.row][c2.col][EAST] = CLOSED;
        } else {
            // Not neighbors.
            System.out.println("Maze.fixWall(): c1=" + c1 + " and c2=" + c2 + " are not neighbors");
            return;
        }
    }

    public void markUnvisited(Coord c) {
        maze[c.row][c.col][0] = UNVISITED;
    }

    public void markAllUnvisited() {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                maze[i][j][0] = UNVISITED;
            }
        }
    }

    public boolean isVisited(Coord c) {
        if (maze[c.row][c.col][0] == VISITED) {
            return true;
        } else {
            return false;
        }
    }

    public Coord[] getUnvisitedClosedNeighbors(Coord c) {
        Coord[] possibleNeighbors = new Coord[4];
        int numValid = 0;

        int x = c.row;
        int y = c.col;

        // See if North is valid.
        if ((x > 0) && (maze[x][y][NORTH] == CLOSED) && (maze[x - 1][y][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x - 1, y);
            numValid++;
        }
        // SOUTH
        if ((x < numRows - 1) && (maze[x][y][SOUTH] == CLOSED) && (maze[x + 1][y][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x + 1, y);
            numValid++;
        }
        // EAST
        if ((y < numCols - 1) && (maze[x][y][EAST] == CLOSED) && (maze[x][y + 1][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x, y + 1);
            numValid++;
        }
        // WEST
        if ((y > 0) && (maze[x][y][WEST] == CLOSED) && (maze[x][y - 1][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x, y - 1);
            numValid++;
        }

        if (numValid == 0) {
            return null;
        }

        // Now compact the array.
        Coord[] validNeighbors = new Coord[numValid];
        for (int i = 0; i < numValid; i++) {
            validNeighbors[i] = possibleNeighbors[i];
        }

        return validNeighbors;
    }

    public Maze copy() {
        Maze mazeCopy = new Maze(this.numRows, this.numCols);
        int[][][] B = new int[maze.length][][];
        for (int i = 0; i < maze.length; i++) {
            B[i] = new int[maze[i].length][];
            for (int j = 0; j < maze[i].length; j++) {
                B[i][j] = new int[maze[i][j].length];
                for (int k = 0; k < maze[i][j].length; k++) {
                    B[i][j][k] = maze[i][j][k];
                }
            }
        }
        mazeCopy.maze = B;
        return mazeCopy;
    }

    public void setSolutionPath(LinkedList<Coord> solutionPath) {
        this.solutionPath = solutionPath;
    }

    public Coord[] getClosedNeighbors(Coord c) {
        Coord[] possibleNeighbors = new Coord[4];
        int numValid = 0;

        int x = c.row;
        int y = c.col;

        // See if North is valid.
        if ((x > 0) && (maze[x][y][NORTH] == CLOSED)) {
            possibleNeighbors[numValid] = new Coord(x - 1, y);
            numValid++;
        }
        // SOUTH
        if ((x < numRows - 1) && (maze[x][y][SOUTH] == CLOSED)) {
            possibleNeighbors[numValid] = new Coord(x + 1, y);
            numValid++;
        }
        // EAST
        if ((y < numCols - 1) && (maze[x][y][EAST] == CLOSED)) {
            possibleNeighbors[numValid] = new Coord(x, y + 1);
            numValid++;
        }
        // WEST
        if ((y > 0) && (maze[x][y][WEST] == CLOSED)) {
            possibleNeighbors[numValid] = new Coord(x, y - 1);
            numValid++;
        }

        if (numValid == 0) {
            return null;
        }

        // Now compact the array.
        Coord[] validNeighbors = new Coord[numValid];
        for (int i = 0; i < numValid; i++) {
            validNeighbors[i] = possibleNeighbors[i];
        }

        return validNeighbors;
    }

    public Coord[] getUnvisitedOpenNeighbors(Coord c) {
        Coord[] possibleNeighbors = new Coord[4];
        int numValid = 0;

        int x = c.row;
        int y = c.col;

        // See if North is valid.
        if ((x > 0) && (maze[x][y][NORTH] == OPEN) && (maze[x - 1][y][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x - 1, y);
            numValid++;
        }
        // SOUTH
        if ((x < numRows - 1) && (maze[x][y][SOUTH] == OPEN) && (maze[x + 1][y][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x + 1, y);
            numValid++;
        }
        // EAST
        if ((y < numCols - 1) && (maze[x][y][EAST] == OPEN) && (maze[x][y + 1][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x, y + 1);
            numValid++;
        }
        // WEST
        if ((y > 0) && (maze[x][y][WEST] == OPEN) && (maze[x][y - 1][0] == UNVISITED)) {
            possibleNeighbors[numValid] = new Coord(x, y - 1);
            numValid++;
        }

        if (numValid == 0) {
            return null;
        }

        // Now compact the array.
        Coord[] validNeighbors = new Coord[numValid];
        for (int i = 0; i < numValid; i++) {
            validNeighbors[i] = possibleNeighbors[i];
        }

        return validNeighbors;
    }

} // end-Maze

class MazePanel extends JPanel {

    static final int OPEN = 0;
    static final int CLOSED = 1;

    static final int NORTH = 1;
    static final int SOUTH = 2;
    static final int EAST = 3;
    static final int WEST = 4;

    int[][][] maze;

    LinkedList<Coord> solutionPath;

    public void paintComponent(Graphics g) {
        int numRows = maze.length;
        int numCols = maze[0].length;
        Dimension D = this.getSize();
        int cellHeight = D.height / numRows;
        int cellWidth = D.width / numCols;
        int xSeg = cellWidth / 4;
        int ySeg = cellHeight / 4;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                int x1 = j * cellWidth;
                int x2 = (j + 1) * cellWidth;
                int y1 = i * cellHeight;
                int y2 = (i + 1) * cellHeight;

                // Draw the walls.
                if (maze[i][j][NORTH] == CLOSED) {
                    g.drawLine(x1, y1, x2, y1);
                } else {
                    g.drawLine(x1, y1, x1 + xSeg, y1);
                    g.drawLine(x2, y1, x2 - xSeg, y1);
                }

                if (maze[i][j][SOUTH] == CLOSED) {
                    g.drawLine(x1, y2, x2, y2);
                } else {
                    g.drawLine(x1, y2, x1 + xSeg, y2);
                    g.drawLine(x2, y2, x2 - xSeg, y2);
                }

                if (maze[i][j][WEST] == CLOSED) {
                    g.drawLine(x1, y1, x1, y2);
                } else {
                    g.drawLine(x1, y1, x1, y1 + ySeg);
                    g.drawLine(x1, y2, x1, y2 - ySeg);
                }

                if (maze[i][j][EAST] == CLOSED) {
                    g.drawLine(x2, y1, x2, y2);
                } else {
                    g.drawLine(x2, y1, x2, y1 + ySeg);
                    g.drawLine(x2, y2, x2, y2 - ySeg);
                }

            } // inner-for
        } // outer-for

        if (solutionPath == null) {
            System.out.println("No solution path");
            return;
        }

        // Draw solution.
        g.setColor(Color.red);
        Point prev = null;
        for (Coord c : solutionPath) {
            int drawX = c.col * cellWidth + cellWidth / 2;
            int drawY = c.row * cellHeight + cellHeight / 2;
            if (prev != null) {
                g.drawLine(prev.x, prev.y, drawX, drawY);
            }
            prev = new Point(drawX, drawY);
        }
    }

} // end-MazePanel
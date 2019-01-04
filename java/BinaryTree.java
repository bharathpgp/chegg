import java.util.Random;

/* Class containing lchild and rchild child of current node and x value*/
class Node {
    int data;
    Node lchild, rchild;

    public Node(int item) {
        data = item;
        lchild = rchild = null;
    }
}

public class BinaryTree {

    private Node root;

    BinaryTree() {
        root = null;
    }

    public void insert(int x) {
        root = insert(root, x);
    }

    private Node insert(Node node, int x) {

        if (node == null) {
            return node = new Node(x);
        }

        if (x == node.data) {
            return node;
        } else {
            if (x < node.data) {
                node.lchild = insert(node.lchild, x);
            } else {
                node.rchild = insert(node.rchild, x);
            }
        }
        return node;
    }

    public static void printTree(Node node) {
        if (node == null)
            return;

        /* print left child */
        printTree(node.lchild);

        /* print root */
        System.out.print(node.data + " ");

        /* print right child */
        printTree(node.rchild);
    }

    public static void displayTreePostOrder(Node node) {
        if (node == null)
            return;

        // left subtree
        displayTreePostOrder(node.lchild);

        // right subtree
        displayTreePostOrder(node.rchild);

        System.out.print(node.data + " ");
    }

    public static void displayTreePreOrder(Node node) {
        if (node == null)
            return;

        System.out.print(node.data + " ");

        /* left sutree */
        displayTreePreOrder(node.lchild);

        /* right subtree */
        displayTreePreOrder(node.rchild);
    }

    public static int size(Node node) {
        int count = 0;
        if (node != null)
            count = sizeRec(node);
        return count;
    }

    private static int sizeRec(Node node) {
        int count = 1;
        if (node.lchild != null) {
            count += sizeRec(node.lchild);
        }
        if (node.rchild != null) {
            count += sizeRec(node.rchild);
        }
        return count;
    }

    public static int minValue(Node node) {
        if (node == null)
            return -1;

        int data = node.data;
        int ldata = minValue(node.lchild);
        int rdata = minValue(node.rchild);

        if (ldata < data)
            data = ldata;
        if (rdata < data)
            data = rdata;

        return data;
    }

    public static void main(String[] args) {

        BinaryTree tree = new BinaryTree();

        tree.root = new Node(2);
        tree.root.lchild = new Node(1);
        tree.root.rchild = new Node(3);

        tree.insert(4);
        tree.insert(5);

        System.out.print("Print Tree: ");
        printTree(tree.root);
        System.out.println();

        System.out.println("size = " + size(tree.root));

        /* code to populate a tree with 10 random numbers between 1-100 */
        for (int i = 0; i < 10; i++) {
            tree.insert(new Random().nextInt(100) + 1);
        }

        System.out.print("Post Order: ");
        displayTreePostOrder(tree.root);
        System.out.println();
        System.out.print("Pre Order: ");
        displayTreePreOrder(tree.root);
        System.out.println();
        System.out.println("size = " + size(tree.root));
    }
}

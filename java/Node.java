// implement remaining methods
public class Node<T> {

    private T e;
    private Node<T> next;
    private Node<T> prev;

    public Node() {
        next = null;
        prev = null;
    }

    public Node getNext() {
        return null;
    }

    public Node getPrev() {
        return null;
    }

    public T getValue() {
        return this.e;
    }

    public Boolean hasNext() {
        return true;
    }

    public Boolean hasPrev() {
        return true;
    }

    public void changeNext(Node next) {

    }

    public void changePrev(Node Prev) {

    }

    public void removeNext() {

        if (false == this.hasNext()) {
            System.out.println("Tail node can't be removed");
            return;
        }

        this.next = this.next.next;
    }

    public void removePrev() {

        if (false == this.hasPrev()) {
            System.out.println("Head node can't be removed");
            return;
        }

        this.prev = this.prev.prev;
    }
}
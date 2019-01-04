/**
 * ToDoImplementation.java
 */
import java.util.*;
import java.util.Queue;

public class ToDoImplementation implements ToDoInterface {

    private Queue<String> queue;

    public ToDoImplementation() {
        queue = new LinkedList<>();
    }

    public void addTask(String task) {
        queue.add(task);
    }

    public void completeTask(String task) {
        queue.remove(task);
    }

    public String getNextTask() {
        return queue.peek();
    }

    public Collection<String> getAllTasks() {
        return new ArrayList(queue);
    }
}
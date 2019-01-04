import java.util.*;

public interface ToDoInterface {

    void addTask(String task);

    void completeTask(String task);

    String getNextTask();

    Collection<String> getAllTasks();
}
import java.util.ArrayList;
public class Meal {
    private String name;
    private ArrayList<FoodItem> foodItems;

    public Meal(String name, FoodItem foodItems) {
        this.name = name;
        this.foodItems = new ArrayList<>();
        this.foodItems.add(foodItems);
    }
    public void addFood(FoodItem foodItem) {
        foodItems.add(foodItem);
    }
    public void removeFood(FoodItem foodItem) {
        foodItems.remove(foodItem);
    }
    public int getTotalCalories() {
        int totCalories = 0;

        for (FoodItem foodItem : foodItems) {
            totCalories += foodItem.getCalories();
        }
        return totCalories;
    }
    public boolean containsFood(FoodItem foodItem) {
        return foodItems.contains(foodItem);
    }
    public void createGroceryList() {

        for (FoodItem foodItem : foodItems) {
            System.out.println(foodItem.getName());
        }
    }
    public String getName() {
        return name;
    }
}
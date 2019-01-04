import java.util.ArrayList;

public class test {
    public static void main(String[] args) {
        FoodItem foodItem = new FoodItem("rice", 10);
        ArrayList<FoodItem> foodItmes = new ArrayList<>();
        foodItmes.add(foodItem);
        Meal meal = new Meal("South Indian", foodItem);

        System.out.println(meal.getTotalCalories());
        meal.createGroceryList();

        foodItem = new FoodItem("dhall", 5);
        meal.addFood(foodItem);
        foodItem = new FoodItem("curd", 25);
        meal.addFood(foodItem);
        System.out.println(meal.getTotalCalories());
        System.out.println(meal.containsFood(foodItem));
        meal.createGroceryList();
        meal.removeFood(foodItem);
        System.out.println(meal.getTotalCalories());        
        meal.createGroceryList();
    }
}
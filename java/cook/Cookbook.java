import java.util.ArrayList;
import java.util.*;

public class Cookbook {

    private ArrayList<Meal> cookbook;

    public void addMeal(Meal meal) {
        cookbook.add(meal);
    }

    public void removeMeal(Meal meal) {
        cookbook.remove(meal);
    }

    public List<Meal> searchCalories(int maxCals) {
        List<Meal> meals = new ArrayList<Meal>();

        for (Meal meal : cookbook) {
            if (meal.getTotalCalories() >= maxCals)
                meals.add(meal);
        }

        if (meals.size() > 0)
            return meals;
        else
            return null;
    }

    public List<Meal> searchName(String text) {
        List<Meal> meals = new ArrayList<Meal>();

        for (Meal meal : cookbook) {
            if (meal.getName().equalsIgnoreCase(text))
                meals.add(meal);
        }

        if (meals.size() > 0)
            return meals;
        else
            return null;
    }

    public List<Meal> searchFood(FoodItem foodItem) {
        List<Meal> meals = new ArrayList<Meal>();
        for (Meal meal : cookbook) {
            if (meal.containsFood(foodItem))
                meals.add(meal);
        }
        if (meals.size() > 0)
            return meals;
        else
            return null;
    }

    public List<Meal> searchFood(List<FoodItem> foodItems) {
        boolean status;
        List<Meal> meals = new ArrayList<Meal>();
        for (Meal meal : cookbook) {
            status = true;
            for (FoodItem foodItem : foodItems) {
                if (false == meal.containsFood(foodItem))
                    status = false;
            }
            if (status)
                meals.add(meal);
        }
        if (meals.size() > 0)
            return meals;
        else
            return null;
    }
}
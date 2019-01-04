
/**
 * Candy.java
 */

import java.util.List;
import java.util.ArrayList;

public class Candy {

    private List<String> ingredients;
    private int calories;

    public Candy() {
        this.ingredients = new ArrayList<String>();
        this.calories = 0;
    }

    public void addIngredient(String ingredient) {
        ingredients.add(ingredient);
    }

    public void setNumCalories(int calories) {
        this.calories = calories;
    }

    public String toString() {
        String tmpStr = new String();
        for (String str : ingredients) {
            tmpStr += str + "\n";
        }
        return "Total Calories " + calories + "\nIngredients:\n" + tmpStr;
    }
    
}
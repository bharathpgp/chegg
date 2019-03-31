import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;
import javax.script.ScriptException;

public class ArithmeticExp {

  public static void main(String[] args) throws ScriptException {

    ScriptEngineManager mgr = new ScriptEngineManager();
    ScriptEngine engine = mgr.getEngineByName("JavaScript");
    String expression = args[0];
    System.out.println(engine.eval(expression));
  }
}

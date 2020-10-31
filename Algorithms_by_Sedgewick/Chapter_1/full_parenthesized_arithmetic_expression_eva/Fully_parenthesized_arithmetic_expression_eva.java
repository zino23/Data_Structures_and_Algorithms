import java.io.*;
import java.util.*;

public class Fully_parenthesized_arithmetic_expression_eva
{
    public static void main(String[] args)
    {
        String inputLine = null;
        try {
            BufferedReader is = new BufferedReader(
                    new InputStreamReader(System.in));
            inputLine = is.readLine();
            if ( inputLine.length() == 0 ) System.out.println("Invalid input!");
        }
        catch (IOException e)
        {
            System.out.println("IOException: " + e);
        }

        Stack<Float> operand = new Stack<>();
        Stack<String> operator = new Stack<>();
        assert inputLine != null;
        String[] ops = inputLine.split(" ");
        for ( var op : ops )
        {
            if ( op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/") ) operator.push(op);
            else if ( op.equals(")") )
            {
                Float a = operand.pop(), b = operand.pop();
                op = operator.pop();
                switch (op) {
                    case "+" -> operand.push(a + b);
                    case "-" -> operand.push(b - a);
                    case "*" -> operand.push(a * b);
                    default -> operand.push(b / a);
                }
            }
            else if ( ! op.equals("(") ) operand.push(Float.parseFloat(op));
        }
        System.out.println("The result is " + operand.peek());
    }
}
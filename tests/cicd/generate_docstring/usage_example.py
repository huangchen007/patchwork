// Example of using the a_plus_b method
public class Main {
    public static void main(String[] args) {
        // Using a_plus_b for simple addition
        int result1 = Test.a_plus_b(5, 3);
        System.out.println("5 + 3 = " + result1); // Output: 5 + 3 = 8

        // Using a_plus_b for comparison with key map logic
        Function<Object, Comparable> keymap = (obj) -> ((String) obj).length();
        int compareResult = Test.a_plus_b(keymap, "apple", "pear");
        System.out.println("Comparison result: " + compareResult); // Output: Comparison result: 0
    }
}

import static org.junit.jupiter.api.Assertions.assertEquals;
import java.util.function.Function;
import org.junit.jupiter.api.Test;

class TestTest {

    @Test
    void testAPlusBIntegers() {
        assertEquals(5, Test.a_plus_b(2, 3));
    }

    @Test
    void testAPlusBKeyMap() {
        Function<Object, Comparable> keymap = obj -> (Integer) obj;
        assertEquals(-1, Test.a_plus_b(keymap, 1, 2));
        assertEquals(1, Test.a_plus_b(keymap, 3, 2));
        assertEquals(0, Test.a_plus_b(keymap, 2, 2));
    }
}

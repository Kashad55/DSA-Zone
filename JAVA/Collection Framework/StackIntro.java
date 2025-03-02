import java.util.*;
public class StackIntro {
    public static void main(String[] args) {
        Stack<String> st = new Stack<>();
//Stack Specific methods
        st.push("A");
        st.push("B");
        st.push("C");
        st.push("D");

        System.out.println(st);
        System.out.println(st.pop());
        System.out.println(st);
        System.out.println("Top = "+st.peek());
        System.out.println(st.empty());
//List's method
        System.out.println(st.isEmpty());
    }
}

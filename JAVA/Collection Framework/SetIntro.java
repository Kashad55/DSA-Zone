import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;
//Set store unique elements only, duplicates not allowed
public class SetIntro {
    public static void main(String[] args) {
        // Set<Integer> set = new HashSet<>();  //Randomly store  |  O(1)
        // Set<Integer> set = new LinkedHashSet<>();   //Stored in added order | O(N)
        Set<Integer> set = new TreeSet<>(); //Internally use BST, Stored in sorted order  |  O(LogN)
        set.add(10);
        set.add(20);
        set.add(20);
        set.add(10);
        set.add(50);
        set.add(30);

        System.out.println(set);
        set.remove(10);
        System.out.println(set);
        System.out.println(set.contains(30));
    }
}

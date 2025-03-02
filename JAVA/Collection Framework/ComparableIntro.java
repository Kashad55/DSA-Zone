import java.util.*;
public class ComparableIntro {
    public static void main(String[] args) {
        Animal a1 = new Animal(4, "Leo", 6);
        Animal a2 = new Animal(2, "Maxo", 4);
        Animal a3 = new Animal(2, "Bruno", 3);
        Animal a4 = new Animal(3, "Don", 10);

        List<Animal> dogs = new ArrayList<>();
        dogs.add(a1);
        dogs.add(a2);
        dogs.add(a3);
        dogs.add(a4);

        System.out.println(dogs);
        Collections.sort(dogs);
        System.out.println(dogs);
// 1. Make UD class Comparable(implements Comparable<Animal>)
// 2. Override compareTo method and write compare logic there
// 3. Use Collections.sort(dogs) to sort the list of animals
    }
}

import java.util.*;
class MyCostomDogComparator implements Comparator<Animal>{

    @Override
    public int compare(Animal o1, Animal o2) {      //Sort acc to weight
        // return o1.weight - o2.weight;
        return Integer.compare(o1.weight, o2.weight);   //Recommended
    }
    
}
public class ComparatorIntro {
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

        //Sort using Custom Comparator
        // Collections.sort(dogs, new MyCostomDogComparator());
        
        //Sort using Compataor Interface
        // Collections.sort(dogs, new Comparator<Animal>() {   //Sort acc to name
        //     @Override
        //     public int compare(Animal o1, Animal o2){
        //         return o1.name.compareTo(o2.name);
        //     }
        // });

        //[BEST]Sort using Lambda Expression JAVA-8
        // Collections.sort(dogs, (o1, o2) -> o1.name.compareTo(o2.name));

        //USE ALWAYS THIS
        Collections.sort(dogs, (o1, o2) ->{
            return Integer.compare(o1.weight, o2.weight);
        });
        System.out.println(dogs);

//Q] Sort 2D Matrix using lambda expression with your logic
        int mat[][] = {{4,5,2},
                     {5,1,2},
                     {1,4,7}};

        Arrays.sort(mat, (arr1, arr2) -> {
            return arr1[0] - arr2[0];
        });

        for(int a[] : mat){
            for(int i : a){
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}

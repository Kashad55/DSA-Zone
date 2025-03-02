import java.util.*;
public class ListIterators {
    public static void main(String[] args) {
        List<String> fruits = new ArrayList<>();
        List<String> ll = new LinkedList<>();
        List<String> v = new Vector<>();
        //We can use any of them, all methods are same as collection & List. Only internal working is changed
        //later you want to change the DS to any type(ArrayList -> LinkedList), you can change it
        //If you are certain that you will always use ArrayList and may want to use ArrayList-specific methods.
        ArrayList<String> al = new ArrayList<>();  
        //Now we can use ArrayLists specific methods and Collections as well as List, but if later u want to change DS to LinkedList, it is not possible
        fruits.add("Kiwi");
        fruits.add("Papaya");
        fruits.add("Mango");
        fruits.add("Apple");

        for(int i=0; i<fruits.size(); i++){
            System.out.println("fruit is "+fruits.get(i));
        }
        for(String f : fruits){
            System.out.println("For each fruit "+f);
        }
        Iterator<String> fi = fruits.iterator();    //Collection Iterator
        // Iterator<String> fi = fruits.listIterator();   //List Interator
        while(fi.hasNext()){
            System.out.println("Iterator is "+fi.next());
        }

        List<String> sublist = fruits.subList(0, 2);
        System.out.println(sublist);
    }
}

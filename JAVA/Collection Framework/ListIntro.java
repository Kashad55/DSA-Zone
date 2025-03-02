// import java.util.*;
import java.util.List;
import java.util.ArrayList;
public class ListIntro {
    public static void main(String[] args) {
        int arr[] = new int[5];  //fixed size
        List<Integer> list = new ArrayList<>();    //Dynamic size
        
        list.add(10);
        list.add(20);
        list.add(1);

//ALL METHODS OF COLLECTIONS INTERFACE
        System.out.println(list);
        // System.out.println("size="+list.size());
        // System.out.println(list.contains(20));
        // // list.remove(1);   //It remove index
        // list.remove(Integer.valueOf(1));     //It remove value
        // System.out.println(list);
        
        List<Integer> list2 = new ArrayList<>();
        list2.add(1); 
        list2.add(2); 
        list2.add(3); 
        
        // list.addAll(list2);     //Append list2 at the end of list
        // list.removeAll(list2);     //Remove all matching of list2 in list
        // list.retainAll(list2);  //Retain only matching element, others are removed (Intersection)
        // list.clear();    //Clear all the list
        // System.out.println(list);   
        
        // Object a[] = list.toArray();    //Convert list into array (return Object)
        // for(Object e : a){
        //     // Integer temp = (Integer) e;
        //     // System.out.print(temp+" ");
        //     System.out.print(e+" ");
        // }

//ALL METHODS OF LIST INTERFACE
        System.out.println(list.get(1));
        list.set(1,200);
        System.out.println(list);
        list.add(2,5000);
        System.out.println(list);
        list.remove(2);
        System.out.println(list);
        System.out.println(list.indexOf(10));   //returns First Occurence
        System.out.println(list.indexOf(5));
        list.add(10);
        list.add(50);
        System.out.println(list);
        System.out.println(list.lastIndexOf(10));  //returns Last Occurence
    }
}

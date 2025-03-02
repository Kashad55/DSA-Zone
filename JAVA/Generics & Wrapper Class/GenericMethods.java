public class GenericMethods {
    public static void main(String[] args) {
        printData("Hello");
        printData(123);

        GenericMethods obj = new GenericMethods();
        // obj.doubleData("abc");   //Due to Bounded Generics, we can use only Number
        obj.doubleData(225);

        CustomClass cm = new CustomClass();
        // obj.doubleData(cm);
    }

    static <E> void printData(E data){
        System.out.println(data);
    }

    <E extends Number> void doubleData(E data){
        System.out.println(data);
    }
}
class CustomClass{

}

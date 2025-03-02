public class WrapperIntro {
    public static void main(String[] args) {
        // Integer obj = new Integer(12);
        Integer obj2 = Integer.valueOf(12);
        System.out.println(obj2*2);
        Boolean myBool = Boolean.valueOf("false");
        Integer obj3 = 12;  //Autoboxing

        int age = obj2;  //Unboxing

    }
}

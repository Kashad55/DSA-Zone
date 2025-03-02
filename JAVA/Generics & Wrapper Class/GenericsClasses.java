public class GenericsClasses {
    public static void main(String[] args) {
        Dog<String> d1 = new Dog<>("asdf123");
        Dog<String> d2 = new Dog<>("lkj321");

        Dog<Integer> d3 = new Dog<>(12);

        System.out.println(d3.getId());
    }
}
class Dog<E>{       //We can use multiple generics as per need
    E id;

    public Dog(E id){
        this.id = id;
    }
    E getId(){
        return id;
    }
}

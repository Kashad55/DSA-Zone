import java.util.ArrayDeque;
public class DequeIntro {
    public static void main(String[] args) {
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.offer(10);   //insert at last
        dq.offerFirst(20);
        dq.offerLast(30);
        dq.add(50);
        System.out.println(dq);
        // dq.remove()  //it'll throw exception when dq is empty
//ALWAYS USE ADD->OFFER | REMOVE->POLL | TOP->PEEK
        System.out.println(dq.poll());  //remove from front
        System.out.println(dq.pollLast());
        System.out.println(dq);
        System.out.println(dq.peek());
        System.out.println(dq.peekLast());
    }
}

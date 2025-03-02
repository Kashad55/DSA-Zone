import java.util.LinkedList;
import java.util.Queue;
public class QueueIntro {
    public static void main(String[] args) {
        Queue<Integer>  q = new LinkedList<>();
        q.add(10);
        q.offer(20);    //Doesnt throw error when Queue is Full
        q.offer(30);
        q.offer(40);
        System.out.println(q);
    //Dequeue
        System.out.println(q.remove()); //Throw error when q is empty
        System.out.println(q.poll());   //print null when q is empty
        System.out.println(q);
        
        System.out.println(q.peek());   //Front
        System.out.println(q);

        while(!q.isEmpty()){
            System.out.println(q.poll());
        }
    }
}

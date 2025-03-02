import java.util.PriorityQueue;
import java.util.Queue;
public class PriorityQueueIntro {
    public static void main(String[] args) {
        Queue<Integer> pq = new PriorityQueue<>();
        //Queue<Integer> pq = new PriorityQueue<>((a,b)->b-a);  //custom comparator(Lambda Expression), here larger value = high priority
        pq.add(30);
        pq.add(10);
        pq.add(40);
        pq.add(20);

        System.out.println(pq);
        System.out.println(pq.poll());
        System.out.println(pq);
        System.out.println(pq.poll());
        System.out.println(pq);
    }
}

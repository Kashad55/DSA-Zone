import java.util.ArrayDeque;
//ALWAYS USE ARRAYDEQUE FOR STACK
//STACK IS INTERNALLY IMPLEMENTED USING VECTOR
//HENCE IT IS THREADSAFE(SYNCHRONISED) AND TAKE LONGER TIME TO EXECUTE
//ARRAYDEQUE IS NOT THREADSAFE AND HENECE EXECUTE FASTER
public class StackQueueUsingArrayDeque {
    public static void main(String[] args) {
        ArrayDeque<Integer> st = new ArrayDeque<>();
        st.push(10);
        st.push(20);
        st.push(30);
        // System.out.println(st);
        // System.out.println(st.pop());
        // System.out.println(st);
        // System.out.println(st.peek());

        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.offer(10);    //enqueue
        q.offer(20);
        q.offer(30);
        System.out.println(q);
        System.out.println(q.poll());   //dequeue
        //q.pop() works same

    }
}

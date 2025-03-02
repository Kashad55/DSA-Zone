import java.util.*;
public class checkPrime {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter no . = ");
        int n = s.nextInt();
        boolean isPrime = true;
        for(int i=2; i<=Math.sqrt(n); i++){
            if(n%i == 0){
                isPrime = false;
                break;
            }
        }
        System.out.println(isPrime ? "Prime" : "Not prime");
    }
}

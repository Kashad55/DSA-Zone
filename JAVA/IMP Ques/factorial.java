import java.util.Scanner;
public class factorial {
    void fact(int n){
        int ans=1;
        for(int i=1; i<=n; i++){
            ans *= i;
        }
        System.out.println(ans);

    }
    int fact2(int n){
        if(n==1) return 1;
        return n*fact2(n-1);
    }
    public static void main(String[] args) {
        System.out.print("Enter no. = ");
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        factorial f = new factorial();
        // f.fact(n);
        System.out.println(f.fact2(n));
    }
}

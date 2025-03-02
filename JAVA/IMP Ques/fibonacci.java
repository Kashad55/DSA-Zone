import java.util.Scanner;
class fibonacci{
    //Basic approach
    static void fib1(int n){
        int a=0, b=1;
        for(int i=0; i<n; i++){
            System.out.print(a+"\t");
            int c = a+b;
            a=b;
            b=c;
        }
        System.out.println();
    }
    //Recursion
    static int fib2(int n){
        //Here fib series starts from 1 index not 0.
        if(n==1) return 0;      //if(n==0) return 0; } when fib series starts from 0th index
        if(n==2) return 1;      //if(n==1) return 1;

        return fib2(n-1)+fib2(n-2);
    }
    public static void main(String []args){
        Scanner s = new Scanner(System.in);
        System.out.print("Enter no : ");
        int n = s.nextInt();
        fib1(n);
        System.out.println(n+"th fibonacci no. = "+fib2(n));
    }
}
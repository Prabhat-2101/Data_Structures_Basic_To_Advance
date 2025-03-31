import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the size for the first array");
        int N1 = scn.nextInt();
        if(N1<=0) {
            System.out.println(N1+" is an invalid array size");
            return;
        }
        int[] arr1 = new int[N1];
        System.out.println("Enter the elements for the first array");
        for(int i=0;i<N1;i++) arr1[i] = scn.nextInt();
        
        System.out.println("Enter the size for the second array");
        int N2 = scn.nextInt();
        if(N2<=0) {
            System.out.println(N2+" is an invalid array size");
            return;
        }
        int[] arr2 = new int[N2];
        System.out.println("Enter the elements for the second array");
        for(int i=0;i<N2;i++) arr2[i] = scn.nextInt();
        
        if(N1 != N2){
            System.out.println("Both array sizes are not the same");
            return;
        }
        
        int[] result = new int[arr1.length];
        System.out.println("The elements of the third array");
        for (int i = 0; i < arr1.length; i++) {
            if (i % 2 == 0) {
                result[i] = arr1[i] + arr2[i];
            } else {
                result[i] = arr1[i] - arr2[i];
            }
            System.out.println(result[i]);
        }
    }
}

import java.util.Scanner;

public class LSD {
    public static void sort(String[] a, int W){
        // sort a on leading W chars
        int N = a.length;
        final int R = 256;  // maximum different chars
        String[] aux = new String[N];
        
        for ( int d = W - 1; d >= 0; d -- )
        {
            int cnt[] = new int[R + 1];  // use prefix sum to calculate char frequencies
            for ( int i = 0; i < R && i < N; i ++ )
            {
                cnt[a[i].charAt(d) + 1] ++ ;  // char frequencies
            }
            
            for ( int i = 1; i <= R; i ++ ) { cnt[i] += cnt[i - 1]; }  // convert cnt[] to contain starting indexes of each char
            for ( int i = 0; i < N; i ++ )
            {
                aux[cnt[a[i].charAt(d)] ++ ] = a[i];  // move string to aux[]
            }

            for ( int i = 0; i < N; i ++ ) { a[i] = aux[i]; }  // move strig back to a[]
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt();
        sort(args, W);
        for ( var s : args) { System.out.println(s); }
        sc.close();
    }
}
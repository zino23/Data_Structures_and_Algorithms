import java.util.Scanner;

public class KMP
{
    public static void kmp(int n, String p, int m, String s)
    {
        int ne[] = new int[n + 1];
        for ( int i = 2, j = 0; i <= n; i ++ )
        {
            while ( j > 0 && p.charAt(i) != p.charAt(j + 1) ) j = ne[j] ;
            if ( p.charAt(i) == p.charAt(j + 1) ) j ++ ;
            ne[i] = j;
        }

        for ( int i = 1, j = 0; i <= m; i ++ )
        {
            while ( j > 0 && s.charAt(i) != p.charAt(j + 1)) j = ne[j];
            if ( s.charAt(i) == p.charAt(j + 1) ) j ++ ;
            if ( n == j )
            {
                System.out.println(Integer.toString(i - n) + " ");
                j = ne[j];
            }
        }
    }
    public static void main(String[] args)
    {
        int n, m;
        String p, s;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        p = 0 + sc.next();
        m = sc.nextInt();
        s = 0 + sc.next();
        sc.close();
        kmp(n, p, m, s);
    }
}

import java.util.Scanner;

public class InsertionSort
{
    private static void swap(float a[], int i, int j)
    {
        float tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void sort(float a[], int n)
    {
        for ( int i = 1; i < n; i ++ )
        {   
            // insertion sort make sure a[0:i-1] is sorted
            for ( int j = i; j >= 1 && a[j] < a[j - 1]; j -- )
            {
                swap(a, j, j - 1);
            }
        }
    }
    public static void main(String[] args)
    {
        final int N = 100000;
        float a[] = new float[N];
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for ( int i = 0; i < n; i ++ ) a[i] = sc.nextFloat();
        sort(a, n);
        sc.close();
        for ( int i = 0; i < n; i ++ ) System.out.println(a[i]);
    }
}
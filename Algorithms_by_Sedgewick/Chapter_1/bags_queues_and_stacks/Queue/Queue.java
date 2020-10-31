import java.util.Iterator;
import java.util.Scanner;

public class Queue<Item> implements Iterable<Item>
{
    private Node first;  // item at the head of the queue
    private Node last;  // item at the tail of the queue
    private int N;

    private class Node
    {
        Node next;
        Item item;
    }

    public boolean isEmpty() { return N == 0; }
    public int size() { return N; }

    public void enqueue(Item item)
    {
        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if ( isEmpty() ) first = last;
        else oldLast.next = last;
        N ++ ;
    }

    public Item dequeue()
    {
        Item item = first.item;
        first = first.next;
        if ( isEmpty() ) last = null;
        N -- ;
        return item;
    }


    public Iterator<Item> iterator() {
        return new QueueIterator();
    }

    public class QueueIterator implements Iterator<Item>
    {
        private Node current = first;
        public boolean hasNext() {
            return N > 0;
        }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public static void main(String[] args)
    {
        Queue<Integer> q = new Queue<>();
        Scanner sc = new Scanner(System.in);
        while ( sc.hasNextInt() )
        {
            q.enqueue(sc.nextInt());
        }
        System.out.println("Total " + q.size() + " elements in the queue");
    }
}
import java.util.Iterator;
import java.util.Scanner;

public class Stack<Item> implements Iterable<Item>{

    private Node top;
    private int N;

    private class Node{
        Node next;
        Item item;
    }

    public boolean isEmpty() { return N == 0; }
    public int size() { return N; }

    public Item pop(){
        Item item = top.item;
        top = top.next;
        N -- ;
        return item;
    }

    public void push(Item item){
        Node oldTop = top;
        top = new Node();
        top.item = item;
        top.next = oldTop;
        N ++ ;    
    }
    
    public Item peek() { return top.item; }

    @Override
    public Iterator<Item> iterator() {
        return new StackIterator();
    }
    
    private class StackIterator implements Iterator<Item>{
        public boolean hasNext() { return N > 0; }
        public Item next(){
            Item item = top.item;
            top = top.next;
            return item;
        }
    }

    public static void main(String[] args){
        Stack<Float> stk = new Stack<>();
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for ( int i = 0; i < num; i ++ ){
            String op = sc.next();
            if ( op.equals("push") ) stk.push(sc.nextFloat());
            else if ( op.equals("pop")){
                System.out.println(stk.pop());
            }
            else if ( op.equals("peek")) { System.out.println(stk.peek()); }
            else { System.out.println("Total " + stk.size() + " elements"); }
        }
        sc.close();
    }
}
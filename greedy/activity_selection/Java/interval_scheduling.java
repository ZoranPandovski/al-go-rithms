package com.company;
import java.util.*;

public class interval_scheduling implements Comparable<interval_scheduling> {

    private int n, start, end, visited;

    public int getQuantity()
    {
        return end;
    }

    public int compareTo(interval_scheduling compareEnd) {

        int compareQuantity = ((interval_scheduling) compareEnd).getQuantity();

        //ascending order
        return this.end - compareQuantity;

        //descending order
        //return compareQuantity - this.quantity;

    }

    public static void main(String[] args)
    {
        interval_scheduling obj = new interval_scheduling();
        Scanner in = new Scanner(System.in);
        System.out.println("Enter number of intervals:");
        obj.n = in.nextInt();
        ArrayList<interval_scheduling> a = new ArrayList<>();
        System.out.println("Enter start and end times of intervals:");
        for(int i = 0; i < obj.n; i++)
        {
            int start, end;
            start = in.nextInt();
            end = in.nextInt();
            interval_scheduling o = new interval_scheduling();
            o.start = start;
            o.end = end;
            o.visited = 0;
            a.add(o);
        }

        Collections.sort(a);

        System.out.println("Here are the intervals:");
        System.out.println(a.get(0).start + " " + a.get(0).end);

        int time = a.get(0).end;
        for(int i = 1; i < a.size(); i++)
        {
            if(a.get(i).start < time)
                continue;
            else
            {
                System.out.println(a.get(i).start + " " + a.get(i).end);
                time = a.get(i).end;
            }
        }
    }

}

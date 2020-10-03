import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

class node // needed to implement sstf algorithm
{

	// represent difference between
	// head position and track number
	int distance = 0;

	// true if track has been accessed
	boolean accessed = false;
}

class algo {

	void fcfs(int arr[], int head, int size) {
		int seek_count = 0;
		int distance, cur_track;

		for (int i = 0; i < size; i++) {
			cur_track = arr[i];

			// calculate absolute distance
			distance = Math.abs(cur_track - head);
			System.out.println("Head movement: " + cur_track + "-" + head + " = " + distance);

			// increment the total count
			seek_count += distance;

			// accessed track is now new head
			head = cur_track;
		}
		System.out.println(" ");
		System.out.println("Total Seek Time :" + seek_count);
		System.out.println(" ");
		// Seek sequence would be the same
		// as request array sequence
		System.out.print("Seek Sequence is :" + "   ");

		for (int i = 0; i < size; i++) {
			System.out.print(arr[i] + "   ");
		}
		System.out.println(" ");
	}

	void scan(int arr[], int head, int size, int disk_size) {
		String dir = "left";
		int seek_count = 0;
		int distance, cur_track;

		Vector<Integer> l1 = new Vector<Integer>();
		Vector<Integer> r1 = new Vector<Integer>();
		Vector<Integer> arr2 = new Vector<Integer>();

		// appending end values
		// which has to be visited
		// before reversing the direction
		if (dir == "left")
			l1.add(0);
		else if (dir == "right")
			r1.add(disk_size - 1);

		for (int i = 0; i < size; i++) {
			if (arr[i] < head)
				l1.add(arr[i]);
			if (arr[i] > head)
				r1.add(arr[i]);
		}

		// sorting left and right vectors
		Collections.sort(l1);
		Collections.sort(r1);

		// run the while loop two times one by one scanning right and left of the head

		int run = 2;
		while (run-- > 0) {
			if (dir == "left") {
				for (int i = l1.size() - 1; i >= 0; i--) {
					cur_track = l1.get(i);

					// appending current track to seek sequence
					arr2.add(cur_track);

					// calculate absolute distance
					distance = Math.abs(cur_track - head);
					System.out.println("Head movement: " + cur_track + "-" + head + " = " + distance);

					// increase the total count
					seek_count += distance;

					// accessed track is now the new head
					head = cur_track;
				}
				dir = "right";
			} else if (dir == "right") {
				for (int i = 0; i < r1.size(); i++) {
					cur_track = r1.get(i);

					// appending current track to seek sequence
					arr2.add(cur_track);

					// calculate absolute distance
					distance = Math.abs(cur_track - head);
					System.out.println("Head movement: " + cur_track + "-" + head + " = " + distance);

					// increase the total count
					seek_count += distance;

					// accessed track is now new head
					head = cur_track;
				}
				dir = "left";
			}
		}
		System.out.println(" ");
		System.out.println("Total Seek Time : " + seek_count);
		System.out.println(" ");
		System.out.print("Seek Sequence is : " + " ");
		for (int i = 0; i < arr2.size(); i++) {
			System.out.print(arr2.get(i) + "  ");
		}
		System.out.println(" ");
	}

	void cscan(int arr[], int head, int size, int disk_size) {
		int seek_count = 0;
		int distance, cur_track;
		Vector<Integer> l3 = new Vector<Integer>();
		Vector<Integer> r3 = new Vector<Integer>();
		Vector<Integer> arr3 = new Vector<Integer>();

		// appending end values which has to be visited before reversing the direction
		l3.add(0);
		r3.add(disk_size - 1);

		// tracks on the left of the head will be serviced when
		// once the head comes back to the left
		for (int i = 0; i < size; i++) {
			if (arr[i] < head)
				l3.add(arr[i]);
			if (arr[i] > head)
				r3.add(arr[i]);
		}

		// sorting left and right vectors
		Collections.sort(l3);
		Collections.sort(r3);

		// first service the requests
		// on the right side of the
		// head.
		for (int i = 0; i < r3.size(); i++) {
			cur_track = r3.get(i);
			// appending current track to seek sequence
			arr3.add(cur_track);

			// calculate absolute distance
			distance = Math.abs(cur_track - head);
			System.out.println("Head movement: " + cur_track + "-" + head + " = " + distance);

			// increase the total count
			seek_count += distance;

			// accessed track is now new head
			head = cur_track;
		}

		// Now service the requests again
		// which are left.
		for (int i = 0; i < l3.size(); i++) {
			cur_track = l3.get(i);

			// appending current track to seek sequence
			arr3.add(cur_track);

			// calculate absolute distance
			distance = Math.abs(cur_track - head);
			System.out.println("Head movement: " + cur_track + "-" + head + " = " + distance);

			// increase the total count
			seek_count += distance;

			// accessed track is now the new head
			head = cur_track;
		}

		System.out.println(" ");
		System.out.println("Total Seek Time : " + seek_count);
		System.out.println(" ");
		System.out.print("Seek Sequence is : " + " ");

		for (int i = 0; i < arr3.size(); i++) {
			System.out.print(arr3.get(i) + "  ");
		}
		System.out.println("  ");
	}

	public static void calculateDifference(int queue[], int head, node diff[])

	{
		for (int i = 0; i < diff.length; i++)
			diff[i].distance = Math.abs(queue[i] - head);
	}

// find unaccessed track  
// which is at minimum distance from head 
	public static int findMin(node diff[]) {
		int index = -1, minimum = Integer.MAX_VALUE;

		for (int i = 0; i < diff.length; i++) {
			if (!diff[i].accessed && minimum > diff[i].distance) {

				minimum = diff[i].distance;
				index = i;
			}
		}
		return index;
	}

	public void sstf(int arr[], int head)

	{
		if (arr.length == 0)
			return;

// create array of objects of class node     
		node diff[] = new node[arr.length];

// initialize array 
		for (int i = 0; i < diff.length; i++)

			diff[i] = new node();

// count total number of seek operation     
		int seek_count = 0;

// stores sequence in which disk access is done 
		int[] arr4 = new int[arr.length + 1];

		for (int i = 0; i < arr.length; i++) {

			arr4[i] = head;
			calculateDifference(arr, head, diff);

			int index = findMin(diff);

			diff[index].accessed = true;
			
// increase the total count 
			seek_count += diff[index].distance;
            
// accessed track is now new head 
			head = arr[index];
			System.out.println("Head movement: " + (diff[index].distance+head)+ "-" + head + " = " + diff[index].distance);
		}

// for last accessed track 
		arr4[arr4.length - 1] = head;
		System.out.println(" ");
		System.out.println("Total number of seek operations = " + seek_count);
		System.out.println(" ");
		System.out.print("Seek Sequence is :" + " ");

// print the sequence 
		for (int i = 0; i < arr4.length; i++) {
			System.out.print(arr4[i] + "  ");

		}

	}
}

public class MainDisc {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no. of cylinders");
		int c = sc.nextInt();
		System.out.println("Enter the head position");
		int h = sc.nextInt();
		System.out.println("Enter the total no. of cylinder in request sequence");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter the request sequence");
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		algo o1 = new algo();
		int choice;
		do {
			System.out.println(
					"----------------------------------------------------------------------------------------------------");
			System.out.println("     MENU   ");
			System.out.println("PRESS 1 FOR FCFS ");
			System.out.println("PRESS 2 FOR SCAN");
			System.out.println("PRESS 3 FOR CSCAN ");
			System.out.println("PRESS 4 FOR SSTF ");
			System.out.println("PRESS 0 TO EXIT");
			System.out.println("Enter your choice");
			System.out.println(
					"----------------------------------------------------------------------------------------------------");
			choice = sc.nextInt();
			System.out.println();
			switch (choice) {
			case 0:
				System.out.println("Thank you");
				System.out.println("  ");
				break;
			case 1:
				System.out.println("FCFS");
				o1.fcfs(arr, h, n);
				System.out.println("  ");
				break;
			case 2:
				System.out.println("SCAN");
				o1.scan(arr, h, n, c);
				System.out.println("  ");
				break;
			case 3:
				System.out.println("CSCAN");
				o1.cscan(arr, h, n, c);
				System.out.println("  ");
				break;
			case 4:
				System.out.println("SSTF");
				o1.sstf(arr, h);
				System.out.println("  ");
				break;
			default:
				System.out.println("Wrong choice");
				break;
			}
		} while (choice != 0);

	}

}

/*
Enter the no. of cylinders
200
Enter the head position
50
Enter the total no. of cylinder in request sequence
8
Enter the request sequence
176
79
34
60
92
11
41
114
----------------------------------------------------------------------------------------------------
     MENU   
PRESS 1 FOR FCFS 
PRESS 2 FOR SCAN
PRESS 3 FOR CSCAN 
PRESS 4 FOR SSTF 
PRESS 0 TO EXIT
Enter your choice
----------------------------------------------------------------------------------------------------
1
FCFS
Head movement: 176-50 = 126
Head movement: 79-176 = 97
Head movement: 34-79 = 45
Head movement: 60-34 = 26
Head movement: 92-60 = 32
Head movement: 11-92 = 81
Head movement: 41-11 = 30
Head movement: 114-41 = 73
 
Total Seek Time :510
 
Seek Sequence is :   176   79   34   60   92   11   41   114    
  
----------------------------------------------------------------------------------------------------
     MENU   
PRESS 1 FOR FCFS 
PRESS 2 FOR SCAN
PRESS 3 FOR CSCAN 
PRESS 4 FOR SSTF 
PRESS 0 TO EXIT
Enter your choice
----------------------------------------------------------------------------------------------------
2
SCAN
Head movement: 41-50 = 9
Head movement: 34-41 = 7
Head movement: 11-34 = 23
Head movement: 0-11 = 11
Head movement: 60-0 = 60
Head movement: 79-60 = 19
Head movement: 92-79 = 13
Head movement: 114-92 = 22
Head movement: 176-114 = 62
 
Total Seek Time : 226
 
Seek Sequence is :  41  34  11  0  60  79  92  114  176   
  
----------------------------------------------------------------------------------------------------
     MENU   
PRESS 1 FOR FCFS 
PRESS 2 FOR SCAN
PRESS 3 FOR CSCAN 
PRESS 4 FOR SSTF 
PRESS 0 TO EXIT
Enter your choice
----------------------------------------------------------------------------------------------------
3
CSCAN
Head movement: 60-50 = 10
Head movement: 79-60 = 19
Head movement: 92-79 = 13
Head movement: 114-92 = 22
Head movement: 176-114 = 62
Head movement: 199-176 = 23
Head movement: 0-199 = 199
Head movement: 11-0 = 11
Head movement: 34-11 = 23
Head movement: 41-34 = 7
 
Total Seek Time : 389
 
Seek Sequence is :  60  79  92  114  176  199  0  11  34  41    
  
----------------------------------------------------------------------------------------------------
     MENU   
PRESS 1 FOR FCFS 
PRESS 2 FOR SCAN
PRESS 3 FOR CSCAN 
PRESS 4 FOR SSTF 
PRESS 0 TO EXIT
Enter your choice
----------------------------------------------------------------------------------------------------
4
SSTF
Head movement: 50-41 = 9
Head movement: 41-34 = 7
Head movement: 34-11 = 23
Head movement: 109-60 = 49
Head movement: 98-79 = 19
Head movement: 105-92 = 13
Head movement: 136-114 = 22
Head movement: 238-176 = 62
 
Total number of seek operations = 204
 
Seek Sequence is : 50  41  34  11  60  79  92  114  176    
----------------------------------------------------------------------------------------------------
     MENU   
PRESS 1 FOR FCFS 
PRESS 2 FOR SCAN
PRESS 3 FOR CSCAN 
PRESS 4 FOR SSTF 
PRESS 0 TO EXIT
Enter your choice
----------------------------------------------------------------------------------------------------
5
Wrong choice
----------------------------------------------------------------------------------------------------
     MENU   
PRESS 1 FOR FCFS 
PRESS 2 FOR SCAN
PRESS 3 FOR CSCAN 
PRESS 4 FOR SSTF 
PRESS 0 TO EXIT
Enter your choice
----------------------------------------------------------------------------------------------------
0
Thank you
  
*

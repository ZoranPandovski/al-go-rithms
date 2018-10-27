//Problem Introduction

//You are responsible for collecting signatures from all tenants of a certain build-ing. For each tenant, you know a period of time when he or she is at home.You would like to collect all signatures by visiting the building as few times as possible.The mathematical model for this problem is the following. You are given a set of segments on a line and your goal is to mark as few points on a line as possible
//so that each segment contains at least one marked point.

//Problem Description

//Task. Given a set of n segments {[a 0 , b 0 ], [a 1 , b 1 ], . . . , [a n−1 , b n−1 ]} with integer coordinates on a line, find the minimum number m of points such that each segment contains at least one point. That is, find a set of integers X of the minimum size such that for any segment [a i , b i ] there is a point x ∈ X such that a i ≤ x ≤ b i .

//Input Format. The first line of the input contains the number n of segments. Each of the following n lines contains two integers a i and
//b i (separated by a space) defining the coordinates of endpoints of the i-th segment.

//Constraints. 1 ≤ n ≤ 100; 0 ≤ a i ≤ b i ≤ 10 9 for all 0 ≤ i < n.

//Output Format. Output the minimum number m of points on the first line and the integer coordinates of m points (separated by spaces) on the second line. You can output the points in any order. If there are many such sets of points, you can output any set. (It is not difficult to see that there always exist a set of points of the minimum size such that all the coordinates of the points are integers.)

//Time Limits.
//language   C C++ Java Python   C#   Haskell JavaScript  Ruby  Scala
//time (sec) 1  1   1.5    5    1.5     2       5          5      3

//Memory Limit. 512MB.

//Sample 1.
//Input:
//3
//13
//25
//36

//Output:
//1
//3

//Explanation:
//In this sample, we have three segments: [1, 3], [2, 5], [3, 6] (of length 2, 3, 3 respectively). All of them
//contain the point with coordinate 3: 1 ≤ 3 ≤ 3, 2 ≤ 3 ≤ 5, 3 ≤ 3 ≤ 6. Sample 2.

//Input:
//4
//47
//13
//25
//56

//Output:
//2
//36

//Explanation:
//The second and the third segments contain the point with coordinate 3 while the first and the fourth
//segments contain the point with coordinate 6. All the four segments cannot be covered by a single
//point, since the segments [1, 3] and [5, 6] are disjoint.

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool myfunction (Segment i,Segment j) { return (i.end<j.end); }

vector<int> optimised_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), myfunction);
  int current = segments[0].end;
  points.push_back(current);
  for(int i=0; i< segments.size(); i++) {
	  
	if (current < segments[i].start || current > segments[i].end) {
		current = segments[i].end;
		points.push_back(current);
	}
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimised_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
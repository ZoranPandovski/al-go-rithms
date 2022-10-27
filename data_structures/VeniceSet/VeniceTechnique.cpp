struct VeniceSet {
	void add(int);
	void remove(int);
	void updateAll(int); 
	int getMin(); // custom for every problem
	int size();
};

struct VeniceSet {
	multiset<int> S;
	int water_level = 0;
	void add(int v) {
		S.insert(v + water_level);
	}
	void remove(int v) {
		S.erase(S.find(v + water_level));
	}
	void updateAll(int v) {
		water_level += v;
	}
	int getMin() {
		return *S.begin() - water_level;
	}
	int size() {
		return S.size();
	}
};

// Sample Example
// VeniceSet mySet;
// for (int i = 0; i < N; ++i) {
// 	mySet.add(V[i]);
// 	mySet.updateAll(T[i]); // decrease all by T[i]
// 	int total = T[i] * mySet.size(); // we subtracted T[i] from all elements
	
// 	// in fact some elements were already less than T[i]. So we probbaly are counting 
// 	// more than what we really subtracted. So we look for all those elements
// 	while (mySet.getMin() < 0) {
// 		// get the negative number which we really did not subtracted T[i]
// 		int toLow = mySet.getMin(); 
		
// 		// remove from total the amount we over counted
// 		total -= abs(toLow);
		
// 		// remove it from the set since I will never be able to substract from it again
// 		mySet.remove(toLow);
// 	}
// 	cout << total << endl;
// }
// cout << endl;
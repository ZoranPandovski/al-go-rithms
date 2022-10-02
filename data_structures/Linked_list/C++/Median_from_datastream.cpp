class MedianFinder {
public:
    // time >>>>>>>> constructor = O(1)        addNum = O(logn)         findmedian = o(1) 
    // addnum = first push the num in maxHeap, then push the maxHeap.top()   to minHeap and then //  if minHeap.size() > maxHeap.size() then again push minHeap.top() to maxHeap
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
       // maxHeap.clear();
       // minHeap.clear();
    }

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

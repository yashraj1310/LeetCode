class MedianFinder {
public:

    priority_queue<int> maxHeap; //Left Half
    priority_queue<int, vector<int>, greater<int>> minHeap; //Right Half
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if(maxHeap.empty() || num <=maxHeap.top())   
            maxHeap.push(num);

        else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()+1)
        {
            auto it = maxHeap.top();
            maxHeap.pop();
            minHeap.push(it);
        }
        else if(maxHeap.size()+1 < minHeap.size())
        {
            auto it = minHeap.top();
            minHeap.pop();
            maxHeap.push(it);
        }
    }
    
    double findMedian() 
    {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();

        else if(maxHeap.size() < minHeap.size())   
            return minHeap.top();

        return (maxHeap.top() + minHeap.top())/2.0; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
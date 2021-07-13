class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        int lsize=max_heap.size();
        int rsize=min_heap.size();
        
        if (lsize==0)
        {
            max_heap.push(num);
            
        }
        else if (lsize==rsize)
        {
            if ( num<=min_heap.top())
            {
                max_heap.push(num);
            }
            else
            {
                int temp=min_heap.top();
                min_heap.pop();
                
                max_heap.push(temp);
                min_heap.push(num);
                
            }
            
        }
        else
        {
            if ( num>=max_heap.top() )
            {
                min_heap.push(num);
            }
            else
            {
                int temp=max_heap.top();
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(temp);
            }
            
        }
        
        
        
    }
    
    double findMedian() {
        
        int lsize=max_heap.size();
        int rsize=min_heap.size();
        
        if (lsize>rsize)
        {
            return double(max_heap.top());
        }
        else
        {
            return double(max_heap.top() + min_heap.top())/2;
        }
        
        
    }
};

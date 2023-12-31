The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.



class MedianFinder {
public:
    priority_queue<int> min;
    priority_queue<int, vector<int>, greater<int>> max;
    bool flag = true;
    // if true then put in right half first and then min of right to left half
    // reverse for false and keep changing flag
    MedianFinder() {
        //do nothing
    }
    
    void addNum(int num) {
        if(flag){
            min.push(num);
            max.push(min.top());
            min.pop();
        }else{
            max.push(num);
            min.push(max.top());
            max.pop();
        }
        flag = !flag;
    }
    
    double findMedian() {
        if(flag)    return (min.top()+max.top())/2.0;
        else return max.top();
    }
};

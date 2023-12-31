Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(A.size() > B.size()) return findMedianSortedArrays(B, A);
        int n1 = A.size();
        int n2 = B.size();
        int low = 0, high = n1;

        while(low <= high){
            int cut1 = (low+high)>>1;
            int cut2 = (n1+n2+1)/2-cut1;

            int left1 = cut1 == 0 ? INT_MIN : A[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : B[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : A[cut1];
            int right2 = cut2 == n2 ? INT_MAX : B[cut2];

            if(left1 <= right2 && left2 <= right1){
                // cout<<left1<<" "<<left2<<" "<<right1<<" "<<right2<<endl;
                if((n1+n2)%2 == 1)    
                    return max(left1, left2)/1.0;
                else    
                    return (max(left1,left2)+min(right1,right2))/2.0;
            }
            else if(left1 > right2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0.0;
    }
};

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

// With additional memory - set, less complex

typedef long long int LL;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        set<vector<int>> s;
        vector<vector<int> > res;
        sort(A.begin(), A.end());
        int n = A.size();
        for(int i = 0; i < n-2; i++){
            int l = i+1;
            int r = n-1;
            while(l < r){
                LL sum = (LL)A[i]+(LL)A[l]+(LL)A[r];
                if(sum == 0){
                    s.insert({A[i], A[l], A[r]});
                    l++;
                    r--;
                }
                else if(sum > 0)    r--;
                else l++;
            }
        } 
        for(auto v: s){
            res.push_back(v);
        }
        return res;
    }
};


// With no additional memory - intelligent solution

typedef long long int LL;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        vector<vector<int> > res;
        sort(A.begin(), A.end());
        int n = A.size();
        for(int i = 0; i < n-2; i++){
            if(i > 0 && A[i] == A[i-1] )    continue;
            int l = i+1;
            int r = n-1;
            while(l < r){
                LL sum = (LL)A[i]+(LL)A[l]+(LL)A[r];
                if(sum == 0){
                    res.push_back({A[i], A[l], A[r]});
                    while(l < r && A[r] == A[r-1])  r--;
                    r--;
                }
                else if(sum > 0)    r--;
                else l++;
            }
        } 
        return res;
    }
};

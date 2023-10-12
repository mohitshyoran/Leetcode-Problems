Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

class Solution {
public:
    int hIndex(vector<int>& citations) {
       sort(citations.begin(), citations.end());
       int ans = 0, n = citations.size();
       for(int i = 0; i < citations.size(); i++){
           int citationOfCurrentPaper = citations[i];
           int totalPapersWithMoreThanThisCitation = n-i;
           if(citationOfCurrentPaper >= totalPapersWithMoreThanThisCitation){
               ans = max(ans, totalPapersWithMoreThanThisCitation);
           }
       } 
       return ans;
    }
};

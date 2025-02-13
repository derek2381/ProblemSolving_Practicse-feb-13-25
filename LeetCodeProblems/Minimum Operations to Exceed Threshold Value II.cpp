// Problems Link
// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/


// Source Code

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int res = 0;

        for(int i : nums){
            if(i < k){
                pq.push(i);
            }
        }


        while(pq.size() > 1){
            long long int x = pq.top();
            pq.pop();
            long long int y = pq.top();
            pq.pop();
            res++;

            long long int sum = (2*x) + y;
            

            if((2*x) < k-y){
                pq.push(sum);
            }
        }

        if(pq.size() > 0){
            res++;
        }



        return res;
    }
};
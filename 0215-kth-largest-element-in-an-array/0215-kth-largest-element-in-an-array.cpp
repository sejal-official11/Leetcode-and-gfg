class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int kth;
        for(int i = 0; i < k; i++) {
            kth = pq.top();
            pq.pop();
        }
        return kth;
        
    }
};
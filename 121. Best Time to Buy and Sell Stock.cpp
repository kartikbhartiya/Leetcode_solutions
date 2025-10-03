class Solution {
public:
    int maxProfit(vector<int>& nums) {
        //the core logic and approach was thinking that if we keep on checking for min element while also iterating through the loop and checking for max profit it will work because the sell cannot be at a greater memory locaiton that of buy so it will be always behind the i
        int sell = nums[0];
        int profit = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(sell>nums[i]){
                sell = nums[i];
            }
            if(profit<nums[i] - sell){
                profit = nums[i] - sell;
            }
        }
        if(profit<0) profit =0;
        return profit; //T.N = O(n) , extra S.C = O(1)
    }
};
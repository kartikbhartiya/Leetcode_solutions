class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0,temp = 0;
        int largest = nums[0];
        for(int i = 0 ; i<nums.size() ; i++){
            if(largest<nums[i]){ largest = nums[i];}
            sum+=nums[i];
            if(nums[i] == 0) temp = 1;
        }
        cout<<largest<<endl;
        if(temp == 0) return 0;
        int expected = (largest*(largest+1))/2;
        cout<<expected;
        if(expected-sum!=0) return expected-sum;
        else return largest+1;
    }
};

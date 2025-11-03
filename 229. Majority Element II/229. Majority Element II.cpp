class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0 , cnt2 = 0;
        int el1 = INT_MIN , el2 = INT_MIN;
        //basically i did it as same as n/2 was done , thinking about it that at max 2 elements can be present that can appear greater than n/3 times , so now we create 2 elements and 2 counts and if we get some other element apart from el1 and el2 then cnt1 and cnt2 is decreased by 1 , having cnt = 0 means that the particular subarray have no element appearing greater than n/2 times , it is basically two n/2
        for(int i = 0 ; i<nums.size() ; i++){
            if(cnt1 == 0 && nums[i]!=el2){ //edge case is if nums[i] == el2 than the cnt2 should increment
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i]!=el1){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if(el2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;cnt2--;
            }
        }
        cnt1 = 0;cnt2 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }
        if(cnt1>nums.size()/3 && cnt2<=nums.size()/3) return {el1};
        else if(cnt2>nums.size()/3 && cnt1<=nums.size()/3) return {el2};
        else if(cnt2<=nums.size()/3 && cnt1<=nums.size()/3) return {};
        return {el1,el2};
    }
};

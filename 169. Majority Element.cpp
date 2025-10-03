class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using moore's agorithm
        int cnt = 0, num = nums[0];
        for(int i = 0 ; i<nums.size() ; i++){
            if(cnt == 0){
                num = nums[i]; //update the num coz the previous number cant be majority since it was cancelled by other numbers and cnt was made into 0
            }
            if(num == nums[i]) {
                cnt++; //if they are equal just increase the count
            }
            else{
                cnt--; //if the number is >n/2 it is not possible for it to have cnt<0 since it is majority and it cant get cancelled due to the presence of other numbers
            }
        }
        return num; //T.C = O(n) and extra S.C = O(1)
    }
};
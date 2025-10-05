class Solution {
public:
    void maxPrefix(vector<int>& nums){
        vector<int> temp;
        int pos = -1;
        for(int i = nums.size()-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                pos = i; //find the dip where the number decreases instead of increasing from back
                break;
            }
        }
        int min = nums[pos+1];
        int min_pos = pos+1;
        if(pos == -1){
            reverse(nums.begin(),nums.end()); //if the whole array is in decreasing order from the starting / increasing order from the back we reverse the whole array to find the next permutatiion
            return;
        }
        for(int i = pos+1 ; i<nums.size() ; i++){
            if(min>nums[i] && nums[i]>nums[pos]){
                min = nums[i]; // find the minimum number from the pos+1 to nums.end() so that we can make the next permutation as close to the number
                min_pos = i;
            }
        }
        swap(nums[min_pos],nums[pos]); //swaps the min number with that nums[pos] 
        sort(nums.begin() + pos +1,nums.end()); //sorts the array ahead of pos because the array is surely going to be greater that the number given hence we sort in ascending order
    }
    void nextPermutation(vector<int>& nums) {
        //so according to the observation we need max prefix match as well as the minumum   element but greater that the orignal nums
        maxPrefix(nums);
    }
};
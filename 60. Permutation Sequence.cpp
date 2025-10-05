class Solution {
public:
    void maxPrefix(vector<int>& nums){
        int pos = -1;
        for(int i = nums.size()-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                pos = i; //find the dip where the number decreases instead of increasing from back
                break;
            }
        }
        if(pos == -1){
            reverse(nums.begin(),nums.end()); //if the whole array is in decreasing order from the starting / increasing order from the back we reverse the whole array to find the next permutatiion
            return;
        }
        for(int i = nums.size()-1 ; i>pos ; i--){
            if(nums[i]>nums[pos]){
                swap(nums[i],nums[pos]); //swaps the first number > than num[pos] because the array after pos is already in decreasing order
                break;
            }
        }
        reverse(nums.begin() + pos +1,nums.end()); //reverses the array ahead of pos because the array is surely going to be greater that the number given hence we sort in ascending order and the previous array was already in descending order
    }
    string getPermutation(int n , int k) {
        //so according to the observation we need max prefix match as well as the minumum   element but greater that the orignal nums
        vector<int> nums;
        for(int i = 1; i<=n ; i++){
            nums.push_back(i);
        }
        int factorial = 1;
        //we will find factorial of n since an array of n elements can have n! permutations
        for(int i = n ; i>=1  ;i--){
            factorial *= n;
        }
        k = k%factorial;
        while(k>1){
        maxPrefix(nums);
        k--;
        }
        string output;
        for(int i = 0 ; i<nums.size() ; i++){
            output.push_back((char)(nums[i]+'0'));
        }
        return output;
    }
};
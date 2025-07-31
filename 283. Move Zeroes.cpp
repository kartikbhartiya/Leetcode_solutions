class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int *ptr1 = &nums[0];
        int *ptr2 = &nums[0];
        int temp = 0;
        for(int i = 0 ; i<nums.size() ;i++){
            if(*ptr1!=0){
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
                ptr2++;
            }
            ptr1++;
        }
    }
};

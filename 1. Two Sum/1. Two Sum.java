class Solution {
    public int[] twoSum(int[] nums, int target) {
        int l = nums.length;
        int arr[] = new int[2];
        for(int i = 0 ; i<l ; i++){
            for(int j = 0 ; j<l ; j++){
                if(nums[i]+nums[j] == target && i!=j){
                    arr[0] = i;
                    arr[1] = j;
                    return arr;
                }

            }
        }
        return null;
    }
}

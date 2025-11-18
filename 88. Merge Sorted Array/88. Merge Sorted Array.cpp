class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = 0;
        while(left>= 0 && right<n){ //with this loop i made sure that the largest element of nums1 is smaller than the smallest element of nums2
            if(nums1[left]>=nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            else{ //because the array was sorted hence if swap once stopped never again will it swap again
                break;
            }
        }
        sort(nums1.begin(),nums1.begin() + m); //to bring up order in both array
        sort(nums2.begin(),nums2.begin() + n);
        int j = 0;
        for(int i = m ; i<nums1.size() ; i++){ //just to merge it in nums
            swap(nums1[i],nums2[j]);
            j++;
        }
    }
};

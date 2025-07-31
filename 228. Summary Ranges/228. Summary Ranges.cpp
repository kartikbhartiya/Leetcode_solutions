class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {        
        if(nums.empty()) return {};
        int start = nums[0] , end = nums[0];
        string range = "";
        vector<string> out;
        int count = 0;int s = 0;
        for(int i = 0; i<nums.size() ; i++){
            if(s == 1){
                start = nums[i];
                s--;
            }
            if(i!=nums.size()-1 && nums[i]+1 == nums[i+1]){
                end = nums[i+1];
                count++;
            }
            else if(count!=0){
                s = 1;
                range = to_string(start) + "->" + to_string(end);
                out.push_back(range);
                count = 0;
            }
            else{
                out.push_back(to_string(start));
                s = 1;
            }
        }
        return out;
    }
};

class Solution {
public:
    //if last digit is 9
    vector<int> IsNotNine(vector<int>& digits){
        digits[digits.size()-1] += 1;
        return digits;
    }
    //if last digit is 9
    vector<int> IsNine(vector<int>& digits){
        int carry = 0;
        digits[digits.size() - 1] += 1;
        for(int i = digits.size()-1 ; i>=0 ; i--){
            digits[i] = digits[i] + carry;
            carry = 0;
            if(digits[i]>9){
                digits[i] = digits[i] - 10;
                carry++;
            }
        }
        vector<int> another;
        if(carry == 0) return digits;
        else{
            another.push_back(1); 
            for(int i = 0 ; i<digits.size() ; i++){
                another.push_back(digits[i]);
            }
        }
        return another;
    }
    vector<int> plusOne(vector<int>& digits) {
        vector<int> out;
        if(digits[digits.size()-1] != 9) out = IsNotNine(digits);
        else out = IsNine(digits);
        return out;
    }
};

class Solution {
public:
    bool isvowel(char v){
        if(v=='a'||v=='e' || v == 'i' || v == 'o' || v == 'u' || v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U'){return true;}
        return false;
    }
    string reverseVowels(string s) {
        char *ptr1 = &s[0];
        char *ptr2 = &s[s.size()-1];
        char temp;
        while(ptr1<ptr2){
            if(isvowel(*ptr1) && !isvowel(*ptr2)){
                ptr2--;
            }
            else if(isvowel(*ptr2) && !isvowel(*ptr1)){
                ptr1++;
            }
            else if(isvowel(*ptr1) && isvowel(*ptr2)){
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
                ptr1++;
                ptr2--;
            }
            else{
                ptr1++;
                ptr2--;
            }
        }
        return s;
    }
};

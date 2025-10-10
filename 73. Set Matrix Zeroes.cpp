class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> loc; //Used O(m+n) space 
        for(int i = 0 ; i<matrix.size() ; i++){
            for(int j = 0 ; j<matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0 ; k<matrix.size() ; k++){
                        loc.push_back({k,j});
                    }
                    for(int k = 0 ; k<matrix[i].size() ; k++){
                        loc.push_back({i,k});
                    }
                }
            }
        }
        for(int i = 0 ; i<loc.size() ; i++){ //changed the locations to be changed to 0
                matrix[loc[i][0]][loc[i][1]] = 0;
        }    
    }
};
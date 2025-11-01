class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        //solving this problem in two steps
        //matrix --> transpose(matrix) --> swap columns
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<m ; j++){
                if(i==j) break;
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        cout<<matrix[m-1][m-1];
        //transpose was evaluated
        for(int i = 0 ; i <m ; i++){
            if(i>m/2) break;
            for(int j = 0 ; j< m ; j++){
                swap(matrix[j][i],matrix[j][m-1-i]);
            }
            if(m%2 == 0 && i == m/2 - 1) break;
        }
    }
};

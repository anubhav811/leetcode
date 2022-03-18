class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        
        int move_by = n-1;
        
        for(int i = 0 ; i < n; i++){
            for(int j = i+1 ; j < n; j++){    
                swap(matrix[i][j],matrix[j][i]);
            }
    
        reverse(matrix[i].begin(), matrix[i].end());
    }}
    void swap (int &a,int &b){
        int temp = a;
        a=b;
        b=temp;
    }
};
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int rowindex=0;
        int colindex=col-1;
        while(rowindex<row && colindex>=0){
            int element = matrix[rowindex][colindex];
            if(element==target) return true;
            else if (element<target) rowindex++;
            else colindex--;
        }
        return false;
    }

int main()
{
    vector<vector<int>> matrix = {{1, 4}, {2, 5}};
    int target = 4;
    bool result = searchMatrix(matrix, target);
    cout << "Result: " << result << endl;
}
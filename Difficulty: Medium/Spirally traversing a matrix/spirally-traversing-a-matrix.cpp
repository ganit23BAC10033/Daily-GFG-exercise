//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void horizonTrav(vector<vector<int>> &mat, vector<int> &ans,int a, int b,int row ){
        //
        if(a<b){
            for(int i=a; i<=b; i++){
                ans.push_back(mat[row][i]);
            }
        }
        else {
            for(int i=a; i>=b; i--){
                ans.push_back(mat[row][i]);
            }
        }
        
    }
    void vertTrav(vector<vector<int>> &mat, vector<int> &ans, int a, int b,int col){
        if(a<b){
            for(int i=a; i<=b; i++){
                ans.push_back(mat[i][col]);;
            }
        }
        else {
            for(int i=a; i>=b; i--){
             ans.push_back(mat[i][col]);;
            }
        }
        
    }

    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> ans;
        int n= mat.size(), m= mat[0].size();
        int left=0, right= m-1, top= 0, bottom= n-1;
        
        //Corner cases for n==1. m==1, size==1
        
        while(left<= right && top<=bottom){
            //For corner cases if we have only 1 row or column left
            if(left== right ){
                for(int i=top; i<=bottom; i++){
                    ans.push_back(mat[i][left]);
                }
                break;
            }
            else if(top== bottom){
                for(int i=left;i<=right;i++){
                    ans.push_back(mat[top][i]);
                }
                break;
            }
            
            horizonTrav(mat, ans, left, right-1, top);
            vertTrav(mat, ans, top, bottom-1, right);
            horizonTrav(mat, ans, right, left+1 ,bottom);
            vertTrav(mat, ans, bottom, top+ 1, left);
            
            right--;
            left++;
            top++;
            bottom--;
        }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
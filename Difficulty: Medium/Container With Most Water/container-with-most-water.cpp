//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        
        // code here
        int n=arr.size();
        int s=0;
        int e=n-1;
        int area=0;
        int maxarea=0;
        while(s<e){
            area=min(arr[s],arr[e])*(e-s);
            maxarea=max(area,maxarea);
            if(arr[s]<arr[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return maxarea;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
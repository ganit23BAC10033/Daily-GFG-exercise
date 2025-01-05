//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int countPairs(vector<int> &arr, int target) {
        
        int count = 0 , n = arr.size() ;
        sort(arr.begin() , arr.end()) ;
        int low = 0 , high = n - 1 ;
        
        while(low < high)
            if(arr[low] + arr[high] < target) {
                count += (high - low) ;
                ++low ;
            }
            else
                --high ;
                
        return count ;
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
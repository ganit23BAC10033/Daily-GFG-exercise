//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        int first = 0, last = n - 1;
        int result = -1;  
        
        while (first <= last) {
            int mid = first + (last - first) / 2;
            
            if (arr[mid] == k) {
                result = mid;  
                last = mid - 1; 
            } else if (arr[mid] < k) {
                first = mid + 1;  
            } else {
                last = mid - 1;  
            }
        }
        
        return result;  
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
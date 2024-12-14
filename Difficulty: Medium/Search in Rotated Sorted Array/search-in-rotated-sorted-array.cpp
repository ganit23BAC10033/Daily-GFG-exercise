//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int lowerbound = 0;
        int upperbound = arr.size() - 1;

        while (lowerbound <= upperbound) {
            int mid = lowerbound + (upperbound - lowerbound) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[lowerbound] <= arr[mid]) { 
                 
                if (arr[lowerbound] <= key && key < arr[mid]) {
                    upperbound = mid - 1;  
                } else {
                    lowerbound = mid + 1;  
                }
            } else {
                
                if (arr[mid] < key && key <= arr[upperbound]) {
                    lowerbound = mid + 1;  
                } else {
                    upperbound = mid - 1;  
                }
            }
        }
        return -1;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
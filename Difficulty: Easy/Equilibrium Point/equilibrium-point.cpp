//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int sum = 0;
        for (auto i:arr) sum+=i;
        int temp = 0;
        int n =arr.size();
        for (int i =1; i < n;i++) {
            temp += arr[i-1];
            if (temp == sum-temp-arr[i]) return i;
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
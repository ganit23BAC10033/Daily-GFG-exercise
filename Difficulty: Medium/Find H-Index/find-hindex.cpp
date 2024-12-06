//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& cit) {
        // code here
        int n=cit.size(), hind=0;
        sort(cit.begin(),cit.end());
        reverse(cit.begin(),cit.end());
        for(int i=0; i<n; ++i){
            if(cit[i]>=i+1){
                hind=i+1;
            }
            else break;
        }
        return hind;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int products = 1; // Forward product
        int producte = 1; // Backward product
        int ans = INT_MIN; // Initialize to minimum integer value

        for (int i = 0; i < n; i++) {
            products *= arr[i]; // Update forward product
            producte *= arr[n - 1 - i]; // Update backward product

            // Update the maximum product found so far
            ans = max({ans, products, producte});

            // Reset products to 1 if they encounter a zero
            if (products == 0) products = 1;
            if (producte == 0) producte = 1;
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
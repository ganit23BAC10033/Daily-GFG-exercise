//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        // Case 1: Find the maximum subarray sum using Kadane's algorithm
        int maxKadane = kadane(arr);
        
        // Case 2: Find the minimum subarray sum using Kadane's algorithm
        int totalSum = 0;
        int minKadane = kadaneMin(arr, totalSum);
        
        // If the total sum is equal to the minimum subarray sum, that means all elements are negative.
        if (totalSum == minKadane) {
            return maxKadane;  // If all elements are negative, no circular subarray can give a larger sum
        }
        
        // Case 3: Calculate the maximum circular subarray sum
        int maxCircular = totalSum - minKadane;
        
        // Return the maximum of the non-circular and circular subarray sums
        return max(maxKadane, maxCircular);
    }

private:
    // Function to implement Kadane's algorithm for maximum subarray sum
    int kadane(vector<int>& arr) {
        int maxSum = arr[0];
        int currentSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }

    // Function to implement Kadane's algorithm for minimum subarray sum
    int kadaneMin(vector<int>& arr, int &totalSum) {
        int minSum = arr[0];
        int currentSum = arr[0];
        totalSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currentSum = min(arr[i], currentSum + arr[i]);
            minSum = min(minSum, currentSum);
            totalSum += arr[i];  // Accumulate total sum
        }
        return minSum;
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
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
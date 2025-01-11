//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
    int n = s.size();
    unordered_map<char, int> mp;
    int ans = 0;
    for(int l = 0, r = 0; r < n; r++) {
        if(mp.count(s[r]) && mp[s[r]] >= l) {
            l = mp[s[r]] + 1;
        }
        mp[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
   }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
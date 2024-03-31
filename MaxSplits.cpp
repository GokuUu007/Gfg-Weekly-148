//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxSplits(string s, string t) {
        vector<int> a(26), b(26);
        
        auto ok = [&] () {
            for (int i = 0; i < 26; ++i) {
                if (a[i] != b[i]) return false;
            }
            return true;
        };
        
        int ans = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            a[s[i] - 'a']++, b[t[i] - 'a']++;
            if (ok()) {
                ans++;
                a.assign(26, 0);
                b.assign(26, 0);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        string t;
        getline(cin, t);

        Solution obj;
        int res = obj.maxSplits(s, t);

        cout << res << endl;
    }
}

// } Driver Code Ends

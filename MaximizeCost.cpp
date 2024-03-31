//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int maximizeCost(int n, vector<int> &a, int x) {
        
        multiset<int> st(begin(a), end(a));
        
        auto good = [&] (int cost) {
            int got = 1, cur = *st.begin();
            while (1) {
                auto it = st.lower_bound(cur + cost);
                if (it == st.end()) {
                    --it;
                }
                if (*it - cur >= cost) ++got, cur = *it;
                else break;
            }
            return got >= x;
        };
        
        
        int lo = 1, hi = *st.rbegin(), ans = 0;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (good(mid)) {
                lo = mid + 1, ans = mid;
            } else {
                hi = mid - 1;
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

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        int x;
        scanf("%d", &x);

        Solution obj;
        int res = obj.maximizeCost(n, a, x);

        cout << res << endl;
    }
}

// } Driver Code Ends

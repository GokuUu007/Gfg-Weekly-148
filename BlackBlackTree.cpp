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
    int blackblacktree(int N, int M, vector<int> &par, vector<int> &arr,
                       vector<int> &brr) {
        
        vector<int> adj[N];
        for (int i = 1; i < N; ++i) {
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }
        
        vector<int> change(N);
        for (auto &x : brr) {
            change[x] ^= 1;
        }
        
        function<int(int, int)> Dfs = [&] (int u, int p) {
            int cur = change[u];
            for (auto &v : adj[u]) {
                if (v != p) {
                    cur ^= Dfs(v, u);
                }
            }
            
            if (cur) {
                arr[u] ^= 1;
            }
            
            return cur;
        };
        
        Dfs(0, -1);
        
        return count(begin(arr), end(arr), 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int M;
        scanf("%d", &M);

        vector<int> par(N);
        Array::input(par, N);

        vector<int> arr(N);
        Array::input(arr, N);

        vector<int> brr(M);
        Array::input(brr, M);

        Solution obj;
        int res = obj.blackblacktree(N, M, par, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends

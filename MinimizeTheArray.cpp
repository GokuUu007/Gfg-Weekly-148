//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeArr(int n, vector<int> &arr) {
        
        int mn = *min_element(arr.begin(), arr.end());
        int cnt = count(arr.begin(), arr.end(), mn);
        
        if (mn == 1) {
            return (cnt + 1) / 2;
        }
        
        int res = 0;
        for (auto &x : arr) {
            if (x % mn > 0) res = 1;
        }
        
        if (res) return 1;
        
        return (cnt + 1) / 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeArr(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

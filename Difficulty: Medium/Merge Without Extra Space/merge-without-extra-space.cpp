//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int l = 0, r = 0;
        vector<int> v;
        
        while(l < n && r < m){
            if(a[l] <= b[r]){
                v.push_back(a[l]);
                l++;
            }else{
                v.push_back(b[r]);
                r++;
            }
        }
        
        while(r < m){
            v.push_back(b[r]);
            r++;
        }
        while(l<n){
            v.push_back(a[l]);
            l++;
        }
        
        for(int i = 0; i<n; i++){
            a[i] = v[i];
        }
        for(int i = 0; i<m; i++){
            b[i] = v[i+n];
        }
        return;
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
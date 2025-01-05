//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
       int n = arr.size();
    int hash[n + 1] = {0}; // Initialize hash array with 0

    // Count occurrences of each number
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    int repeating = -1, missing = -1;

    // Find the repeating and missing numbers
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) {
            repeating = i;
        } else if (hash[i] == 0) {
            missing = i;
        }
        
        // Break early if both numbers are found
        if (repeating != -1 && missing != -1) {
            break;
        }
    }

    return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
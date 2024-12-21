//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arraysa[]
    // Function to return a list containing the union of the two arrays.
   vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> unionarr;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    
    // Merge the two sorted arrays and ensure no duplicates in unionarr
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (unionarr.empty() || unionarr.back() != a[i]) {
                unionarr.push_back(a[i]);
            }
            i++;
        } else if (a[i] > b[j]) {
            if (unionarr.empty() || unionarr.back() != b[j]) {
                unionarr.push_back(b[j]);
            }
            j++;
        } else {
            // Both are equal, add only one to the result
            if (unionarr.empty() || unionarr.back() != a[i]) {
                unionarr.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    
    // Add remaining elements from `a` if any
    while (i < n1) {
        if (unionarr.empty() || unionarr.back() != a[i]) {
            unionarr.push_back(a[i]);
        }
        i++;
    }
    
    // Add remaining elements from `b` if any
    while (j < n2) {
        if (unionarr.empty() || unionarr.back() != b[j]) {
            unionarr.push_back(b[j]);
        }
        j++;
    }
    
    return unionarr;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
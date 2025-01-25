//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
   
int first(vector<int>& arr, int n, int target) {
    int low = 0, high = n - 1, first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            first = mid;
            high = mid - 1; // Search in the left half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int last(vector<int>& arr, int n, int target) {
    int low = 0, high = n - 1, last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            last = mid;
            low = mid + 1; // Search in the right half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLast(vector<int>& arr, int n, int target) {
    int firstIndex = first(arr, n, target);
    if (firstIndex == -1) return {-1, -1}; // Target not found
    int lastIndex = last(arr, n, target);
    return {firstIndex, lastIndex};
}

int countFreq(vector<int>& arr, int target) {
    int n = arr.size();
    pair<int, int> ans = firstAndLast(arr, n, target);
    if (ans.first == -1) return 0; // Target not found
    return ans.second - ans.first + 1; // Count occurrences
}
        // code here
       
       
    
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
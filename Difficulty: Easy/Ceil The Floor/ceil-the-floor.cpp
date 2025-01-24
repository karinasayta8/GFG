//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
   vector<int> getFloorAndCeil(int x, vector<int>& arr) {
    // Sort the array
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int floor = -1, ceil = -1;

    // Binary search for floor
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            floor = arr[mid];
            low = mid + 1; // Move to the right for a larger value
        } else {
            high = mid - 1;
        }
    }

    // Binary search for ceil
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ceil = arr[mid];
            high = mid - 1; // Move to the left for a smaller value
        } else {
            low = mid + 1;
        }
    }

    // Return the floor and ceil as a vector
    return {floor, ceil};
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends
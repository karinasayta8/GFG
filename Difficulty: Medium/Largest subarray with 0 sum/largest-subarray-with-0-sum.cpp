//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
         int max_length = 0;
    int sum = 0;
    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        // If the cumulative sum is zero, update max_length to i + 1
        if (sum == 0) {
            max_length = i + 1;
        } else {
            // Check if the cumulative sum has been seen before
            auto it = mpp.find(sum);
            if (it != mpp.end()) {
                // Update max_length if the subarray length is greater than the current max_length
                max_length = max(max_length, i - it->second);
            } else {
                // Store the first occurrence of the cumulative sum
                mpp[sum] = i;
            }
        }
    }

    return max_length;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
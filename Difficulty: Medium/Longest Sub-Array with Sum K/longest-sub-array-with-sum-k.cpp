//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
       unordered_map<int, int> prefixSumMap; // To store prefix sums and their first occurrence index
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Check if the prefix sum equals k
        if (prefixSum == k) {
            maxLength = max(maxLength, i + 1);
        }

        // Check if (prefixSum - k) exists in the map
        if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
        }

        // Store the prefix sum in the map if it's not already there
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }

    return maxLength;  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
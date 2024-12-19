//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        if (arr.size() < 2) {
        return -1; // Return -1 (or any suitable value indicating error)
    }
    
    int largest = INT_MIN;
    int secondlargest = INT_MIN;
    
    // First loop to find the largest element
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    // Second loop to find the second largest element
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < largest && arr[i] > secondlargest) {
            secondlargest = arr[i];  // Update secondlargest if the condition is met
        }
    }
    
    // If secondlargest is still INT_MIN, return -1 indicating no valid second largest found
    if (secondlargest == INT_MIN) {
        return -1; // No valid second largest element
    }

    return secondlargest;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
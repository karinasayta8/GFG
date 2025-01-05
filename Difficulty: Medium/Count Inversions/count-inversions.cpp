//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    // int inversionCount(vector<int> &arr) {
    //     // Your Code Here
    // }
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Left subarray pointer
    int j = mid + 1; // Right subarray pointer
    int k = left;    // Temporary array pointer
    int invCount = 0;

    // Merge the two subarrays and count inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Inversion occurs
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements from the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray back into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left subarray
        invCount += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in the right subarray
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count split inversions
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int inversionCount(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
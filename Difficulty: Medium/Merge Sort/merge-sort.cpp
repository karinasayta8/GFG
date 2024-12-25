//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void mergeSort(vector<int>& arr, int l, int r) {
    // Base condition: when the subarray has one element or no elements
    if (l >= r) return;

    // Find the middle point
    int mid = l + (r - l) / 2;

    // Recursively sort first and second halves
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    // Merge the sorted halves
    merge(arr, l, mid, r);
}

void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp; // Temporary array to store merged elements
    int left = l;     // Starting index of left subarray
    int right = mid + 1; // Starting index of right subarray

    // Merge elements from both subarrays
    while (left <= mid && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Add remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Add remaining elements from the right subarray
    while (right <= r) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back into the original array
    for (int i = 0; i < temp.size(); i++) {
        arr[l + i] = temp[i];
    }
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
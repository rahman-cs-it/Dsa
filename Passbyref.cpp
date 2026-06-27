#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // ==========================================
    // 1. Brute Force Approach
    // Time: O(N) | Space: O(N)
    // ==========================================
    void reverseBruteForce(vector<int>& arr) {
        vector<int> tempArray; // Takes up extra memory!
        
        // Step 1: Read the original array backwards and push to tempArray
        for (int i = arr.size() - 1; i >= 0; i--) {
            tempArray.push_back(arr[i]);
        }
        
        // Step 2: Overwrite the original array with the reversed elements
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = tempArray[i];
        }
    }

    // ==========================================
    // 2. Optimal Approach (Two Pointers)
    // Time: O(N) | Space: O(1)
    // ==========================================
    void reverseOptimal(vector<int>& arr) {
        int left = 0;                  // Finger pointing at the start
        int right = arr.size() - 1;    // Finger pointing at the end
        
        // Keep swapping until the fingers meet in the middle
        while (left < right) {
            
            // Standard 3-step swap using a temporary variable
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            
            /* Pro-Tip: In C++, you can replace those 3 lines above 
               with a single built-in command: swap(arr[left], arr[right]); */
            
            // Move the fingers inward
            left++;
            right--;
        }
    }
    
    // Helper function just to print arrays cleanly
    void printArray(const vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    
    // --- Testing the Brute Force ---
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "--- Testing Brute Force ---" << endl;
    cout << "Original Array: ";
    sol.printArray(arr1);
    
    sol.reverseBruteForce(arr1); // Call the function
    
    cout << "Brute Reversed: ";
    sol.printArray(arr1);
    cout << "\n";
    
    // --- Testing the Optimal ---
    vector<int> arr2 = {10, 20, 30, 40, 50};
    cout << "--- Testing Optimal (Two Pointers) ---" << endl;
    cout << "Original Array: ";
    sol.printArray(arr2);
    
    sol.reverseOptimal(arr2); // Call the function
    
    cout << "Optimal Reversed: ";
    sol.printArray(arr2);
    
    return 0;
}
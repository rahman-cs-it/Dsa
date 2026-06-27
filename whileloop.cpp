/* Given a digit d (0 to 9), find the sum of the first 50 positive integers (integers > 0) that end with digit d.
A number ends with digit d if its last digit is d.

Example 1: Input: d = 1 | Output: 12300
Example 2: Input: d = 5 | Output: 12500 
*/

#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

class Solution
{
public:
    // Time: O(N) | Space: O(K) where K is 50
    int brute(int d)
    {
        vector<int> number;
        int i = (d == 0) ? 10 : d;
        
        while (number.size() < 50)
        {
            if (i % 10 == d)
            {
                number.push_back(i);
            }
            i++;
        }

        int result = 0;
        for (int j = 0; j < number.size(); j++)
        {
            result = result + number[j];
        }
        return result;
    }

    // Time: O(K) | Space: O(1) where K is 50
    int better(int d)
    {
        int sum = 0;
        int currentNumber = (d == 0) ? 10 : d;
        
        for (int i = 0; i < 50; i++)
        {
            sum = sum + currentNumber;
            currentNumber = currentNumber + 10;
        }
        return sum;
    }

    // Time: O(1) | Space: O(1)
    int optimal(int d)
    {
        long long n = 50;
        long long a = (d == 0) ? 10 : d;
        long long diff = 10;

        long long totalSum = (n * ((2 * a) + (n - 1) * diff)) / 2;

        return (int)totalSum;
    }
};

int main()
{
    Solution sol;
    int testDigit = 9;

    cout << "--- Starting Speed Test for Digit: " << testDigit << " ---" << endl;

    // ==========================================
    // 1. Test Brute Force
    // ==========================================
    auto startBrute = high_resolution_clock::now();
    int bruteresult = sol.brute(testDigit);
    auto endBrute = high_resolution_clock::now();
    
    auto durationBrute = duration_cast<nanoseconds>(endBrute - startBrute);
    
    cout << "Brute Force Result: " << bruteresult << endl;
    cout << "Brute Force Time:   " << durationBrute.count() << " ns\n" << endl;

    // ==========================================
    // 2. Test Better Approach
    // ==========================================
    auto startBetter = high_resolution_clock::now();
    int betterresult = sol.better(testDigit);
    auto endBetter = high_resolution_clock::now();
    
    auto durationBetter = duration_cast<nanoseconds>(endBetter - startBetter);
    
    cout << "Better Result:      " << betterresult << endl;
    cout << "Better Time:        " << durationBetter.count() << " ns\n" << endl;

    // ==========================================
    // 3. Test Optimal Approach
    // ==========================================
    auto startOptimal = high_resolution_clock::now();
    int optimalresult = sol.optimal(testDigit);
    auto endOptimal = high_resolution_clock::now();
    
    auto durationOptimal = duration_cast<nanoseconds>(endOptimal - startOptimal);
    
    cout << "Optimal Result:     " << optimalresult << endl;
    cout << "Optimal Time:       " << durationOptimal.count() << " ns\n" << endl;

    return 0;
}
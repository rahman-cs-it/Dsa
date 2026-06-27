#include <iostream>
using namespace std;
class Solution {
public:
    int forLoop(int low, int high) {
        // Your code goes here
        int sum =0;
        for(int i= low;i<=high;i++){
            sum = sum+i;
        }
        return sum;
    }
};

class Solutionoptimal {
public:
    int forLoop(int low, int high) {
        // Step 1: Calculate the total number of terms (n)
        // We use long long to prevent integer overflow during multiplication
        long long n = high - low + 1;
        
        // Step 2: Apply the Arithmetic Progression sum formula
        long long totalSum = (n * (low + high)) / 2;
        
        // Step 3: Cast back to int as required by the function signature
        return (int)totalSum;
    }
};

int main(){
    Solution forloop;
    
    int result = forloop.forLoop(1,1000);
    cout<<result<<endl;


}
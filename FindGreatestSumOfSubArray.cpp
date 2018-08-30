#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////// ////////
// Find the greatest sum of all sub-arrays
// Return value: if the input is valid, return true, otherwise return false
///////////////////////////////////////////////////////////////////// ////////
bool FindGreatestSumOfSubArray
        (
                int *pData, // an array
                unsigned int nLength, // the length of array
                int &nGreatestSum // the greatest sum of all sub-arrays
        ) {
    // if the input is invalid, return false
    if((pData == NULL) || (nLength == 0)) return false;
    int nCurSum = nGreatestSum = 0;
    for(unsigned int i = 0; i < nLength; ++i) {
        nCurSum += pData[i];
// if the current sum is negative, discard it
        if(nCurSum < 0) nCurSum = 0;
        // if a greater sum is found, update the greatest sum
        if(nCurSum > nGreatestSum) nGreatestSum = nCurSum;
    }
// if all data are negative, find the greatest element in the array
    if(nGreatestSum == 0) {
        nGreatestSum = pData[0];
        for(unsigned int i = 1; i < nLength; ++i) {
            if(pData[i] > nGreatestSum) nGreatestSum = pData[i];
        } }
    return true; }


int main() {
    int data[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    int max_sum = 0;
    FindGreatestSumOfSubArray(data, 8, max_sum);
    cout<<max_sum<<endl;
    return 0;
}
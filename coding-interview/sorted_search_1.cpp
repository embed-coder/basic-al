/* 
Implement function countNumbers that accepts a sorted vector of unique integers and, efficiently with respect to time used, counts the number of vector elements that are less than the parameter lessThan.

For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should return 2 because there are two vector elements less than 4.
*/
#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    unsigned int r = sortedVector.size();
    unsigned int mid = r/2;
    while (mid > 0) {
        if ((sortedVector[mid] <= lessThan && sortedVector[mid + 1] > lessThan) || (sortedVector[mid] <= lessThan && mid == r))
            break;
        mid = mid / 2;
    }

    return mid;
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    // std::vector<int> v {  };
    std::cout << countNumbers(v, 4) << std::endl;
}
#endif
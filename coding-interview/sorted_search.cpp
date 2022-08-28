/* 
Implement function countNumbers that accepts a sorted vector of unique integers and, efficiently with respect to time used, counts the number of vector elements that are less than the parameter lessThan.

For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should return 2 because there are two vector elements less than 4.
*/
#include <vector>
#include <stdexcept>
#include <iostream>

int binarySearch(const std::vector<int>& arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if ((arr[mid] <= x && arr[mid + 1] > x) || (arr[mid] <= x && mid == r))
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    if (sortedVector.size() == 0)
        return 0;
    else if (sortedVector.size() == 1)
        return (sortedVector[0] <= lessThan) ? 1 : 0;
    int idx = binarySearch(sortedVector, 0, sortedVector.size() - 1, lessThan);
    return idx + 1;
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    // std::vector<int> v {  };
    std::cout << countNumbers(v, 4) << std::endl;
}
#endif
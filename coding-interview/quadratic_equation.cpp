/* 
Implement the function findRoots to find the roots of the quadratic equation: ax2 + bx + c = 0. If the equation has only one solution, the function should return that solution as both elements of the pair. The equation will always have at least one solution.

The roots of the quadratic equation can be found with the following formula: A quadratic equation.

For example, the roots of the equation 2x2 + 10x + 8 = 0 are -1 and -4.
 */
#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <math.h>

std::pair<double, double> findRoots(double a, double b, double c)
{
    double root1 = (-b + std::sqrt(b*b - 4*a*c)) / (2*a);
    double root2 = (-b - std::sqrt(b*b - 4*a*c)) / (2*a);
    return std::pair<double, double> {root1, root2};
}

#ifndef RunTests
int main()
{
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif
#include <algorithm>
#include <cmath>
#include <array>
#include <iostream>
#include <string_view>

void abssort(int *x, unsigned N) {
  std::sort(x, x + N, 
     [](int a, int b) {
       return std::abs(a) < std::abs(b); 
     }); 
} 

int main()
{
    std::array<int, 10> s = {5, 7, -4, 2, 8, -6, 1, -9, 0, 3};
 
    auto print = [&s](std::string_view const rem) {
        for (auto a : s) {
            std::cout << a << ' ';
        }
        std::cout << ": " << rem << '\n';
    };
 
    std::sort(s.begin(), s.end());
    print("sort using the default operator<");
 
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sort using a standard library compare function object");
 
    struct {
        bool operator()(int a, int b) const { return a < b; }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    print("sort using a custom function object");
 
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
    });
    print("sort using a lambda expression");

    abssort(s.begin(), 10);
    print("sort using a lambda expression");
}

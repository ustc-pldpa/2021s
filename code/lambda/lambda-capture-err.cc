#include <iostream>
int main()
{
  int x = 0; int y = 42; 
  auto qqq = [x, &y] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq();
  auto qqq1 = [=] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq1();
  auto qqq2 = [&] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq2();
  auto qqq3 = [&, x] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq3();
  auto qqq4 = [=, &x] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq4();
  auto qqq5 = [=, &x] mutable {  // qqq5 = [=, &x] () mutable
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y;  ++x;
  };
  qqq5();
  std::cout << "x: " << x << std::endl; 
  std::cout << "y: " << y << std::endl;
}

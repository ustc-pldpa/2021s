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
  auto qqq = [=] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq();
  auto qqq = [&] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq();
  auto qqq = [&, x] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq();
  auto qqq = [=, &x] { 
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y; ++x;
  };
  qqq();
  auto qqq5 = [=, &x] mutable {  // qqq5 = [=, &x] () mutable
    std::cout << "x: " << x << std::endl; 
    std::cout << "y: " << y << std::endl;
    ++y;  ++x;
  };
  qqq5();
  std::cout << "x: " << x << std::endl; 
  std::cout << "y: " << y << std::endl;
}

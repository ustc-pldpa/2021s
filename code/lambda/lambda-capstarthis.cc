#include <iostream>
#include <cmath>
#include <future>
class Task {
private:
   double a; double b; 
public:
   Task() : a(0.0), b(0.0) {}
   ~Task() { a = std::nan(""); b = std::nan(""); } 
   void set_a(double a) {this->a = a; }
   void set_b(double b) {this->b = b; }

   std::future<double> run11() { // C++ 11
      Task self = *this;
      return std::async(std::launch::async, [=]() {
          return std::sqrt(self.a* self.a + self.b * self.b); 
      }); 
   }

   std::future<double> run14() { // C++ 14
      return std::async(std::launch::async, [=, self=*this]() {
          return std::sqrt(self.a* self.a + self.b * self.b); 
      }); 
   }

   std::future<double> run17() { // C++ 17
      return std::async(std::launch::async, [=, *this]() {
          return std::sqrt(a* a + b * b); 
      }); 
   }
} ;

std::future<double> start11(Task &t) {
  return t.run11();
}

std::future<double> start14(Task &t) {
  return t.run14();
}

std::future<double> start17(Task &t) {
  return t.run17();
}

int main() {
  Task t;
  t.set_a(5.0);
  t.set_b(10.0);
  std::cout << start11(t).get() << std::endl;
  std::cout << start14(t).get() << std::endl;
  std::cout << start17(t).get() << std::endl;
}

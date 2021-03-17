- [lambda-sort.cc](./lambda-sort.cc)  includes several ways to sort an array of integers, such as lambda expression

  - You need use `-std=c++17` to compile `lambda-sort.cc` since it invokes `std::string_view` supported since c++17 

- [lambda-capture-err.cc](./lambda-capture-err.cc)  includes a lot of errors, and you need to fix them

- [lambda-capinit.cc](./lambda-capinit.cc)  is testing the capture of  initializer introduced in C++ 2014

- [lambda-capstarthis.cc](./lambda-capstarthis.cc)  is testing the capture of `*this` introduced in C++ 2017

  `g++ lambda-capstarthis.cc -std=c++17 -o lambda-capstarthis -lpthread`
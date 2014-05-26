#include <iostream>
#include <string>
#include <stddef.h>

using namespace std;

template<typename T>
void printTypeSize(string desc)
{
  cout << "sizeof(" << desc << ") = " << sizeof(T) << "\n";
}


int main()
{
  cout << "Integer types:\n";
  printTypeSize<char>("char");
  printTypeSize<short>("short");
  printTypeSize<int>("int");
  printTypeSize<long>("long");
  printTypeSize<long long>("long long");

  cout << "\nPointers:\n";
  printTypeSize<void*>("void*");

  cout << "\nFloating point types:\n";
  printTypeSize<float>("float");
  printTypeSize<double>("double");
  printTypeSize<long double>("long double");

  cout << "\nSizes from stddef.h:\n";
  printTypeSize<size_t>("size_t");
  printTypeSize<ptrdiff_t>("ptrdiff_t");

  return 0;
}

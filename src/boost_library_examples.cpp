#include "pch.h"
#include <boost/variant.hpp>
#include <string>
#include <iostream>

struct foo {
	foo(int n = 0) : id(n){}

  private:
	  int id;
};

struct bar {
	bar(int n = 0) : id(n) {}

private:
	int id;
};

int main() {
	boost::variant<std::string, int, foo> value;
	boost::variant<foo, bar, std::string> value2;
	value = 1;
	int *pi = boost::get<int>(&value);
	assert(pi != nullptr);
	value = "foo";
	value = foo(5);
	//value2 = 1;
	std::cout << value << "\n";
}
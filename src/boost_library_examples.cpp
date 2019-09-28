#include "pch.h"
//#define BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT
#include <boost/variant.hpp>
#include <string>
#include <iostream>
#include <map>
#include <vector>

struct JSONNullType{};

using JSONValue = boost::make_recursive_variant<std::string, bool, double, JSONNullType,
	std::map<std::string, boost::recursive_variant_>,
	std::vector<boost::recursive_variant_>>;
using JSONArray = std::vector<JSONValue>;
using JSONObject = std::map<std::string, JSONValue>;

void printArrElement(const JSONValue& val);
void printObjAttr(const JSONObject::value_type val);

struct JSONPrintVisitor : public boost::static_visitor<void> {
	void operator()(const std::string& str) const {
		std::cout << '"' << str << '"';
	}

	template<typename T>
	void operator()(const T& value) const {
		std::cout << std::boolalpha << value;
	}

	void operator()(const JSONNullType&) const {
		std::cout << "null";
	}

	void operator()(const JSONArray& arr) const{
		std::cout << '[';
		if (!arr.empty()) {
			boost::apply_visitor(*this, arr[0]);
			std::for_each(arr.begin() + 1, arr.end(), printArrElement);
		}
		std::cout << ']';
	}

	void operator()(const JSONObject& obj) const {
		std::cout << '{';
		if (!obj.empty()) {
			const auto& kv_pair = *(obj.begin());
			std::cout << '"' << kv_pair.first << '"';
			std::cout << ':';
			boost::apply_visitor(*this, kv_pair.second);
			auto it = obj.begin();
			std::for_each(++it, obj.end(), printObjAttr);
		}
		std::cout << '}';
	}
};

void printArrElement(const JSONValue& val) {
	std::cout << ', ';
	boost::apply_visitor(JSONPrintVisitor(), val);
}

void printObjAttr(const JSONObject::value_type val) {
	std::cout << ',';
	std::cout << '"' << val.first << '"';
	std::cout << ':';
	boost::apply_visitor(JSONPrintVisitor(), val.second);
}

int main() {
	std::cout << "running" << std::endl;
	return 0;
}
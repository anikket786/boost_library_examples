#include "pch.h"
#define BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT
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

int main() {
	
}
#include "pch.h"
#include <map>
#include <string>
#include <iostream>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <utility>
#include <cstring>

using artist_album_map = std::map<std::string, std::string>;
artist_album_map latest_albums;

boost::optional<std::string> find_latest_album_of(const std::string& artist_name) {
	auto itr = latest_albums.find(artist_name);
	if (itr != latest_albums.end())
		return itr->second;
	else
		return boost::none;
}

int main() {
	std::string name;
	latest_albums.insert(std::make_pair("billie eillish", "bitches broken hearts"));
	latest_albums.insert(std::make_pair("lana del rey", "national anthem"));
	latest_albums.insert(std::make_pair("weeknd", "starboy"));
	std::getline(std::cin, name);
	boost::optional<std::string> output = find_latest_album_of(name);
	std::cout << output << std::endl;
	return 0;
}
#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <boost/regex.hpp>

int main() {
	std::string str;
	boost::regex r1("([a-z\d-_]+)@([a-z\d-]+)\.([a-z]{2,8})(\.[a-z]{2,8})?");
	std::getline(std::cin, str);
	bool flag = boost::regex_match(str, r1);
	if (flag)
		std::cout << "Valid Email!\n";
	else
		std::cout << "Not a valid Email!\n";
	return 0;
}

/*
int main() {
	std::string song = "the scientist";
	typedef boost::iterator_range<std::string::iterator> rangeType;
	rangeType range = boost::make_iterator_range(song.begin(), song.begin() + 1);
	rangeType range2 = boost::make_iterator_range(song.begin() + 4, song.begin() + 5);
	boost::to_upper(range);
	boost::to_upper(range2);
	std::cout << song;
	return 0;
}

namespace po = boost::program_options;
namespace postyle = boost::program_options::command_line_style;

int main(int argc, char *argv[]) {
	po::options_description desc{ "options" };
	desc.add_options()
	   	("unified,U", po::value<unsigned int>()->default_value(3),
			"Print in unified form with specified no. of lines from the surrounding context")
			(",p", "Print names of C functions")
		(",N", "assume presence of one file in absent directory")
		("help,h", "Print thhis help message");

	int unix_style = postyle::unix_style | postyle::short_allow_next;
	int windows_style = postyle::allow_long | postyle::allow_short | postyle::allow_slash_for_short
		                | postyle::case_insensitive | postyle::short_allow_next | postyle::long_allow_next;
	po::variables_map vm;
	try {
		po::store(po::command_line_parser(argc, argv)
			.options(desc)
			.style(unix_style)
			.run(), vm);
		po::notify(vm);
		if (argc == 1 || vm.count("help")) {
			std::cout << "USAGE: " << argv[0] << '\n' << desc << '\n';
			return 0;
		}
	}
	catch (po::error& poe) {
		std::cerr << poe.what() << '\n' << "USAGE: " << argv[0] << '\n' << desc << '\n';
		return EXIT_FAILURE;
	}
}
*/

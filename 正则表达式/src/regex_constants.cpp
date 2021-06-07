// HelloWorld.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <regex>
#include <iostream>
#include <iterator>
#include <string>



int main(int argc, char *argv[])
{
	/*
\chapter{The Standard Template Library}
\index{STL}%
MAININDEX{standard template library}%
SEEINDEX{standard template library}-{STL}%
This is the basic chapter about the STL.
\section{STL Components}
\hauptindex{STL,introduction}%
The \stl{} is based on the cooperation of ...
	*/


	std::string pat1 = R"(\\.*index\{([^}]*)\})";       // first capture group
	std::string pat2 = R"(\\.*index\{(.*)\}\{(.*)\})";  // 2nd and 3rd capture group
	std::regex pat(pat1 + "\n" + pat2,
		std::regex_constants::egrep | std::regex_constants::icase);

	// initialize string with characters from standard input:
	std::string data((std::istreambuf_iterator<char>(std::cin)),
		std::istreambuf_iterator<char>());

	// search and print matching index entries:
	std::smatch m;
	auto pos = data.cbegin();
	auto end = data.cend();
	for (; std::regex_search(pos, end, m, pat); pos = m.suffix().first) {
		std::cout << "match: " << m.str() << std::endl;
		std::cout << "  val: " << m.str(1) + m.str(2) << std::endl;
		std::cout << "  see: " << m.str(3) << std::endl;
	}
	return 0;
}


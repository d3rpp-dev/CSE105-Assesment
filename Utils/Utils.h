#pragma once

#ifndef _COMMON
#define _COMMON

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <functional>
#include <optional>


constexpr auto PROMPT = " > ";

constexpr auto RESET = "\x1b[39;40m";
constexpr auto RED = "\x1b[91;40m";
constexpr auto GREEN = "\x1b[92;40m";
constexpr auto BLUE = "\x1b[94;40m";
constexpr auto CYAN = "\x1b[96;40m";


static void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

namespace trim {
	/*
	 *
	 *   Borrowed from the internet
	 *
	 *   I hope this doesn't count as academic dishonesty as long
	 *   as I state the source:
	 *   https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
	 *
	 */

	 // trim from start (in place)
	static inline void l(std::string& s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {return !std::isspace(ch); }));
	}

	// trim from end (in place)
	static inline void r(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {return !std::isspace(ch); }).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(std::string& s) {
		l(s); r(s);
	}
}

namespace utils {
	// src: https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
	static inline void split(const std::string& s, char delim, std::vector<std::string>* result) {
		std::istringstream iss(s);
		std::string item;
		while (std::getline(iss, item, delim)) {
			result->push_back(item);
		}
	}
	// this allows it to take different kinds of numbers
	//
	// including floats
	template<typename T>
	static inline T get_number(std::string query, bool prompt = true) {
		std::cout << BLUE << query << RESET;
		if (prompt) std::cout << RESET << std::endl << PROMPT;
		std::string line;

		std::cin.clear();
		std::getline(std::cin, line);

		std::stringstream s(line);

		T out;
		s >> out;

		return out;
	}

	// this is formatted weirdly because we need to handle blank line entering.
	//
	// this is significant for having default options for instances of [y/N] 
	// (where N is default) or [Y/n] (where Y is default).
	//
	// this concept of defaults is a convention of questioning in the linux community 
	// that many people are used to in TUIs.
	static inline char get_char(std::string prompt) {
		std::cout << BLUE << prompt << RESET << std::endl << PROMPT;
		std::string a{};

		std::cin.clear();
		std::getline(std::cin, a);

		trim::trim(a);

		if (a == "") return '\0';
		else return a[0];
	}

	static inline std::string get_word(std::string prompt) {
		std::cout << BLUE << prompt << RESET << std::endl << PROMPT;
		std::string a{};

		std::cin.clear();
		std::getline(std::cin, a);
		std::cin.clear();

		std::vector<std::string> o;
		utils::split(a, ' ', &o);

		return o.size() > 0 ? o[0] : "";
	}

	static inline std::string get_line(std::string prompt, bool allow_empty = true) {
		std::string a{};
		std::cout << BLUE << prompt << RESET << std::endl;

		while (true) {
			std::cout << PROMPT;

			std::cin.clear();
			std::getline(std::cin, a);
			std::cin.clear();

			trim::trim(a);

			if (a == "" && allow_empty) break;
			else if (a != "") break;
		}

		return a;
	}

	static inline std::string paragraph(std::string prompt) {
		std::cout
			<< BLUE << prompt << RESET
			<< "[" << CYAN << "press Enter twice to finish" << RESET << "]"
			<< std::endl;

		std::string a{}, separator{}, last_input{};

		do {
			std::getline(std::cin, last_input);
			trim::trim(last_input);

			a.append(separator);
			separator = " ";
			a.append(last_input);
		} while (last_input != "");

		std::cout << "\033[Fend of paragraph" << RESET << std::endl;

		return a;
	}

	static inline std::string get_password(std::string prompt) {
		HANDLE StdInput = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode = 0;

		// get current console mode
		GetConsoleMode(StdInput, &mode);
		// turn off character echoing as this would display the password on the users screen
		SetConsoleMode(StdInput, mode & (~ENABLE_ECHO_INPUT));

		std::string pw = utils::get_line(prompt);
		std::cout << std::endl; // turned off echoing for this line, so the newline isn't printed, so we need to print it ourselves to prevent cringe

		// re-enable as we now have the password and can echo text now
		SetConsoleMode(StdInput, mode);

		// ily w32api /s
		return pw;
	}	

	//
	// for the record, i hate this a LOT
	//
	template<typename T>
	static inline T parse_input(
		std::string prompt, 
		std::string expected,
		std::optional<T>(*parse)(std::string)
	)
	{
		T ret;
		bool is_valid = false;

		do {
			std::stringstream ss;

			ss << prompt << RESET << " (" << expected << ")" << RESET;

			std::string _input = get_line(ss.str());

			std::optional<T> _parsed = parse(_input);

			if (_parsed.has_value()) {
				ret = _parsed.value();
				is_valid = true;
			}
			else {
				std::cout << RESET << RED << "Invalid Input, expected: " << expected << std::endl;
			}

		} while (!is_valid);

		return ret;
	}

	//
	// works by using ESC[2J to clear the terminal screen (typically works on windows)
	// then using ESC[1;1H to set the cursor to the top left, where we want it
	//
	static inline void clear_terminal() {
		std::cout << "\033[2J\033[1;1H";
	}

	// if a character is a lower case ascii letter
	static inline bool is_lower(char& c) {
		return c >= 'a' && c <= 'z';
	}

	// if a character is an upper case ascii letter
	static inline bool is_upper(char& c) {
		return c >= 'A' && c <= 'Z';
	}

	static inline void to_lower(char& c) {
		if (is_upper(c)) c += 32;
	}

	static inline void to_lower(std::string& s) {
		for (auto& c : s) {
			to_lower(c);
		}
	}

	static inline void to_upper(char& c) {
		if (is_lower(c)) c -= 32;
	}

	static inline void to_upper(std::string& s) {
		for (auto& c : s) {
			to_upper(c);
		}
	}

	static inline int gen_random_int(int min = 0, int max = INT32_MAX) {
		srand(time(nullptr));
		return (rand() % max) + min;
	}
}

#endif

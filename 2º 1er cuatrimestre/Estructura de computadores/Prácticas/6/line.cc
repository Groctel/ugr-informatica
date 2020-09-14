#include <algorithm>    // min_element
#include <array>        // array
#include <chrono>       // high_resolution_clock
#include <iomanip>      // setw
#include <iostream>     // cout
#include <vector>       // vector

const unsigned MAXLINE = 1024; // maximun line size to test
const unsigned GAP = 12;       // gap for cout columns
const unsigned REP = 100;      // number of repetitions of every test

int main()
{
	std::cout << "#"
	          << std::setw(GAP - 1) << "line (B)"
	          << std::setw(GAP + 1) << "time (µs)"
	          << std::endl;

	for (unsigned line = 1; line <= MAXLINE; line *= 2) // line in bytes
	{
		std::vector<std::chrono::duration<double, std::micro>> score(REP);

		for (auto &s: score) {
			std::vector<char> bytes(1 << 24); // 16MB

			auto start = std::chrono::high_resolution_clock::now();

			for (unsigned i = 0; i < bytes.size(); i += line)
				bytes[i] ^= 1;

			auto stop = std::chrono::high_resolution_clock::now();

			s = stop - start;
		}

		std::cout << std::setw(GAP) << line
		          << std::setw(GAP) << std::fixed << std::setprecision(2)
		          << std::setw(GAP) << std::min_element(score.begin(), score.end())->count()
		          << std::endl;
	}
}


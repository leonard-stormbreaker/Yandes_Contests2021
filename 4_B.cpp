#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <set>
#include <iterator>
#include <sstream>
#include <fstream>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//#include "test_runner.h"

vector<string_view> SplitIntoWords(string_view str) {
	vector<string_view> result;
	size_t pos = 0;
	const size_t pos_end = str.npos;
	while(true) {
		size_t space = str.find(' ', pos);
		result.push_back(
				space == pos_end
				? str.substr(pos)
				: str.substr(pos, space - pos));

		if(space == pos_end) {
			break;
		} else {
			pos = space + 1;
		}
	}
	return result;
}

int main() {
	vector<string> words;
	unordered_map<string, int> map;
	string temps;
	stringstream output;
	while(!cin.eof()) {
		getline(cin, temps);
		for (const auto& word : SplitIntoWords(temps)) {
			if(string(word) == "") continue;
			string _word = string(word);
			if(map.count(_word) == 0) {
				output << 0 << " ";
				map[_word] = 1;
			} else {
				output << map[string(word)] << " ";
				map[string(word)]++;
			}
		}
	}
	cout << output.str();

//0 0 0 0 0 0 1 0 0 1 0 0 1 0 2 2 0 0 0 0 1 2 3 3 1 1 4 0 1 0 1 2 4 1 5 0 0

	return 0;
}

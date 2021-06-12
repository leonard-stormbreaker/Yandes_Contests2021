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
	int max = 0;
	string max_str;
	while(!cin.eof()) {
		getline(cin, temps);
		for(auto& word : SplitIntoWords(temps)) {
			if (string(word) == "") continue;
			string _word = string(word);
			map.count(_word) > 0 ? map[_word]++ : map[_word] = 1;
			if(map[_word] > max) {
				max = map[_word];
				max_str = _word;
			} else if (map[_word] == max) {
				if(_word <= max_str) {
					max_str = word;
				}
			}
		}
	}
	cout << max_str;

	return 0;
}

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

int main() {
	size_t N;
	cin >> N;
	vector<string> words;
	string temps;
	for(size_t i = 0; i < N; i++) {
		cin >> temps;
		words.push_back(temps);
		cin >> temps;
		words.push_back(temps);
	}

	string keyword;
	cin >> keyword;
	for(size_t i = 0; i < words.size(); i++) {
		if(words[i] == keyword) {
			(i+1) % 2 == 0 ? cout << words[i-1] : cout << words[i+1];
		}
	}



	return 0;
}

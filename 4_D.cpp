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
#include <map>
#include <unordered_set>

using namespace std;

//#include "test_runner.h"

int main() {
	map<size_t, int> map;
	size_t n;
	cin >> n;
	size_t c;
	for(size_t i = 0; i < n; i++) {
		cin >> c;
		map[i] = c;
	}
	size_t overall;
	cin >> overall;
	size_t p;
	for(size_t i = 0; i < overall; i++) {
		cin >> p;
		p--;
		if(map[p] == -1) {
			continue;
		}
		else if(map[p] - 1 < 0) {
			map[p] = -1;
		} else {
			map[p]--;
		}
	}
	for(const auto& [key, count] : map) {
		if(count == -1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

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
	size_t N;
	size_t result = 0;
	cin >> N;
	multimap<size_t, size_t> map;
	size_t w, h;
	for(size_t i = 0; i < N; i++) {
		cin >> w >> h;
		map.insert(make_pair(w, h));
	}
	size_t maxheight = 0;
	size_t first_width = map.rbegin()->first;
	for(auto it = map.rbegin(); it != map.rend(); it++) {
//		cout << it->first << ":" << it->second << endl;
		if(it->first == first_width) {
			if(maxheight < it->second) {
				maxheight = it->second;
			}
			if(it == prev(map.rend())) {
				result += maxheight;
			}
		} else {
			first_width = it->first;
			result += maxheight;
			maxheight = 0;
			if(maxheight < it->second) {
				maxheight = it->second;
			}
			if(it == prev(map.rend())) {
				result += maxheight;
			}
		}
	}
	cout << result;

	return 0;
}

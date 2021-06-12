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
#include <deque>

using namespace std;

//#include "test_runner.h"


int main() {
	size_t N;
	cin >> N;
	multimap<string, size_t> map;
	string temps;
	size_t pos;
	for(size_t i = 0; i < N; i++) {
		cin >> temps;
		for(size_t k = 0; k < temps.size(); k++) {
			if(isupper(temps[k])) {
				pos = k;
				temps[k] = tolower(temps[k]);
			}
		}
		map.insert({temps, pos});
	}
//	cout << map;
	vector<string> pool;
	size_t result = 0;
	size_t counter = 0;
	while(cin >> temps) {
		counter++;
		unordered_set<size_t> poses;
		for(size_t k = 0; k < temps.size(); k++) {
			if(isupper(temps[k])) {
				poses.insert(k);
				temps[k] = tolower(temps[k]);
			}
		}
//		cout << "newtemps: " << temps << endl;
		if(map.count(temps) == 0) {
			if(poses.size() == 1) {
				result++;
//				cout << ":1" << endl;
			}
		} else if (map.count(temps) > 0 && poses.size() == 1) {
			for(auto it = map.lower_bound(temps); it != map.upper_bound(temps); it++) {
				if(poses.count(it->second) > 0) {
					result++;
//					cout << ":2" << endl;
					break;
				}
			}
		}

	}

	cout << counter - result;





	return 0;
}

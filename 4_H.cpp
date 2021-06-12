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
	size_t g, s;
	cin >> g >> s;
	char symbol;
	map<char, size_t> pool;
	string W;
	cin >> W;
	size_t wsize = W.size();
	for(size_t i = 0; i < W.size(); i++) {
		if(pool.count(W[i]) == 0) {
			pool.insert({W[i], 1});
		}else {
			pool[W[i]]++;
		}
	}
	deque<char> checker;
	size_t result = 0;

	for(size_t i = 0; i < s; i++) {
		cin >> symbol;
		if(pool.count(symbol) > 0) {
			if(pool[symbol] > 0) {
				checker.push_back(symbol);
				pool[symbol]--;
//				cout << setw(27) << "deque (pool[symbol] > 0): " << checker << endl;
				if(checker.size() == wsize) {
					result++;
//				cout << setw(27) << "result: " << result << endl;
					pool[*checker.begin()]++;
					checker.pop_front();
//					cout<< setw(27) << "deque (pool[symbol] > 0): " << checker << endl;
				}
			} else if(pool[symbol] == 0) {
//				cout << setw(27) << "deque (pool[symbol] == 0): " << checker << endl;
				while(*checker.begin() != symbol) {
					pool[*checker.begin()]++;
					checker.pop_front();
//					cout << setw(27) << "deque (pool[symbol] > 0): " << checker << endl;
				}
				pool[*checker.begin()]++;
				checker.pop_front();
//				cout << setw(27) << "deque (pool[symbol] > 0): " << checker << endl;
				checker.push_back(symbol);
				pool[symbol]--;
//			cout << setw(27) << "deque (pool[symbol] > 0): " << checker << endl;
			}

		} else if (checker.size() > 0 && pool.count(symbol) == 0){
			while(checker.size() > 0) {
				pool[*checker.begin()]++;
				checker.pop_front();
			}
//			cout << setw(27) << "deque (pool[symbol] > 0): " << checker << endl;
		} else if (checker.size() == 0) {
			continue;
		}
	}

	cout << result;
	
	return 0;
}

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
	string client, item, number;
	map<string, map<string, size_t>> database;
	while(cin >> client) {
		cin >> item >> number;
		if(database.count(client) == 0) {
			database[client] = {};
		}
		if(database[client].count(item) == 0) {
			database[client][item] = stoi(number);
		} else {
			database[client][item] += stoi(number);
		}
	}
	for(const auto& [_client, map] : database) {
		cout << _client << ":" << endl;
		for(const auto& [_item, _number] : map) {
			cout << _item << " " << _number << endl;
		}
	}

	return 0;
}

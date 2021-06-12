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
	string command;
	map<string, int> account;
	stringstream output;
	while(cin >> command) {
		if(command == "DEPOSIT") {
			string name;
			int sum;
			cin >> name >> sum;
			if(account.count(name) == 0) {
				account.insert({name, sum});
			} else {
				account[name] += sum;
			}

		} else if (command == "WITHDRAW") {
			string name;
			int sum;
			cin >> name >> sum;
			if(account.count(name) == 0) {
				account.insert({name, -sum});
			} else {
				account[name] -= sum;
			}
		} else if (command == "BALANCE") {
//			cout << "map: " << account << endl;
			string name;
			cin >> name;
			if(account.count(name) == 0) {
				output << "ERROR\n";
			} else {
				output << account[name] << '\n';
			}
		} else if (command == "TRANSFER") {
			string name1, name2;
			int sum;
			cin >> name1 >> name2 >> sum;
			if(account.count(name1) == 0 && account.count(name2) == 0) {
				account.insert({name1, -sum});
				account.insert({name2, sum});
			} else if (account.count(name1) > 0 && account.count(name2) == 0) {
				account[name1] -= sum;
				account.insert({name2, sum});
			} else if (account.count(name1) == 0 && account.count(name2) > 0) {
				account.insert({name1, -sum});
				account[name2] += sum;
			} else if (account.count(name1) > 0 && account.count(name2) > 0) {
				account[name1] -= sum;
				account[name2] += sum;
			}
		} else if (command == "INCOME") {
			int p;
			cin >> p;
			for(auto& [client, money] : account) {
				if (account[client] > 0) {
					account[client] += (money*p)/100;
				}
			}
		}
	}
	cout << output.str();

	return 0;
}

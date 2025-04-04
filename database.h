#pragma once
#include <map>
#include <algorithm>
#include"date.h"
#include <functional>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
class Database {
public:
	void Add(const Date& date, const string& event);
	void Print(ostream& s) const;
	//template <typename T>
	/*int  RemoveIf(const function<bool(const Date & date, const string & event)>& f) {
		return 1;
	}*/
	/*template <typename T>
	int RemoveIf(const T& func) {
		unsigned int result = 0;
		map<Date, vector<string>> new_data;
		for (auto i : data) {
			for (auto j : i.second) {
				if (func(i.first, j)) {
					result++;
				}
				else {
					new_data[i.first].push_back(j);
				}
			}
		}
		data = new_data;
		return result;
	}*/

	int RemoveIf(const function<bool(const Date & date, const string & event)>& f);

	/*template <typename T>
	vector<string> FindIf(T& func) const {
		vector<string> find_data;
		for (auto i : data) {
			for (auto j : i.second) {
				if (func(i.first, j)) {
					ostringstream ss;
					ss << i.first << " " << j;
					find_data.push_back(ss.str());
				}
			}
		}
		return find_data;
	}*/
	vector<string> FindIf(const function<bool(const Date & date, const string & event)>& f) const;

	string Last(const Date& date) const;
private:
	map<Date, vector<string>> data;
	map<Date, set<string>> data_set;
};
#include "database.h"
#include "date.h"
#include <set>
void Database::Add(const Date& date, const string& event) {
	if (data_set[date].find(event) == data_set[date].end()) {
		data[date].push_back(event);
		data_set[date].insert(event);
	}
}

void Database::Print(ostream& s) const {
	for (const auto& item : data) {
		for (const auto& event : item.second) {
			s << item.first << " " << event << endl;
		}
	}
}

string Database::Last(const Date& date) const{
	auto it = data.upper_bound(date);
	if (it == data.begin()) {
		throw invalid_argument("");
	}
	else {
		--it;
		ostringstream result;
		if (it->first <= date) {
			result << it->first << " " << it->second.back();
			return result.str();
		}
		else {
			result << "No entries";
			return result.str();
		}
		
	}
}

vector<string> Database::FindIf(const function<bool(const Date & date, const string & event)>& func) const {
	vector<string> find_data;
	for (const auto& i : data) {
		for (const auto& j : i.second) {
			if (func(i.first, j)) {
				ostringstream ss;
				ss << i.first << " " << j;
				find_data.push_back(ss.str());
			}
		}
	}
	return find_data;
}

int Database::RemoveIf(const function<bool(const Date & date, const string & event)>& func) {
	unsigned int result = 0;
	map<Date, vector<string>> new_data;
	map<Date, set<string>> new_data_set;
	for (const auto& i : data) {
		for (const auto& j : i.second) {
			if (func(i.first, j)) {
				result++;
			}
			else {
				new_data[i.first].push_back(j);
				new_data_set[i.first].insert(j);
			}
		}
	}
	data = new_data;
	data_set = new_data_set;
	return result;
}

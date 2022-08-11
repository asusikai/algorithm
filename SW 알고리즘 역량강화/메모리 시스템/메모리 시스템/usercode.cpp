#include<vector>
#include<utility>
#include<algorithm>

#include<iostream>

using namespace std;

int MEMORY_SIZE;
vector<pair<int, int>> empty_space;
vector<pair<int, int>> allocated;

bool compare(pair<int, int>& front, pair<int, int>& back) {

	if (front.second > back.second) return front.second < back.second;

	else if (front.second == back.second) return front.first < back.first;

	else return front.first < back.first;
}

void init(int N) {

	MEMORY_SIZE = N;
	empty_space.clear();
	allocated.clear();
	empty_space.push_back(make_pair(0, N));

	cout << "init\nmemory size:" << N << endl;

	return;
}

int allocate(int mSize) {

	cout << "=====fin=====" << endl;

	sort(empty_space.begin(), empty_space.end(), compare);

	cout << "sorted empty_space before allocate" << endl;
	for (int i = 0; i < empty_space.size(); i++) {
		cout << empty_space[i].first << " " << empty_space[i].second << endl;
	}

	cout << "=====fin=====" << endl;
	int min_size = MEMORY_SIZE+1, min_index = MEMORY_SIZE+1;

	int e_index;
	for (int i = 0; i < empty_space.size(); i++) {
		if (mSize <= empty_space[i].second && min_size > empty_space[i].second) {
			
			min_size = empty_space[i].second;
			min_index = empty_space[i].first;
			e_index = i;

		}
	}

	if (min_size != MEMORY_SIZE && min_index != MEMORY_SIZE) {
		if (mSize == min_size) {
			empty_space.erase(empty_space.begin() + e_index);
		}

		else {
			empty_space[e_index].first += mSize;
			empty_space[e_index].second -= mSize;
		}

		return min_index;

	}

	cout << "allocate result: -1" << endl;

	return -1;
	
}

int release(int mAddr) {

	for (int i = 0; i < allocated.size(); i++) {
		if (allocated[i].first == mAddr) {
			int return_size = allocated[i].second;
			empty_space.push_back(allocated[i]);
			allocated.erase(allocated.begin() + i);

			sort(empty_space.begin(), empty_space.end());
			int index = 0;
			while (true) {
				
				if (index >= empty_space.size()-1) {
					break;
				}

				if (empty_space[index].first + empty_space[index].second == empty_space[index + 1].first) {
					empty_space[index].second += empty_space[index + 1].second;
					empty_space.erase(empty_space.begin() + index + 1);
				}

				else {
					index++;
				}
			}

			cout << "release result: " << return_size << endl;
			return return_size;
		}
	}

	cout << "release result: -1" << endl;

	return -1;
}
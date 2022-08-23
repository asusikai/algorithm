#include<map>
#include<set>
#include<algorithm>

using namespace std;

int MEMORY_SIZE;
map<int, int> allocated;
set<pair<int, int>> empty_space;
void init(int N) {

	MEMORY_SIZE = N;
	empty_space.clear();
	allocated.clear();
	empty_space.insert(make_pair(N, 0));

	return;
}

int allocate(int mSize) {
	auto iter = empty_space.lower_bound({ mSize, 0 });
	if (iter == empty_space.end()) return -1;
	int size = iter->first, address = iter->second;
	empty_space.erase(iter);

	allocated[address] = mSize;
	if (size > mSize) {
		empty_space.emplace(size - mSize, address + mSize);
	}

	return address;
}

int release(int mAddr) {
	auto iter = allocated.find(mAddr);
	if (iter == allocated.end()) return -1;

	int size = iter->second;
	int result = size;

	iter = allocated.erase(iter);
	int after_size = 0;

	if (iter != allocated.end()) {
		after_size = iter->first - (mAddr + size);
	}
	else {
		after_size = MEMORY_SIZE - (mAddr + size);
	}

	if (after_size > 0) {
		empty_space.erase({ after_size, mAddr + size });
		size += after_size;
	}

	int before_size = 0;
	if (iter != allocated.begin()) {
		--iter;
		before_size = mAddr - (iter->first + iter->second);
	}
	else {
		before_size = mAddr;
	}

	if (before_size > 0) {
		empty_space.erase({ before_size, mAddr - before_size });
		size += before_size;

		mAddr -= before_size;
	}

	empty_space.emplace(size, mAddr);

	return result;
}
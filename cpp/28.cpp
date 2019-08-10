#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 每一条记录的数据结构 
int cmp_key = 0;
struct Record {
	string id;
	string name;
	int score;
	
	// 这题的核心是定义这个比较函数 
	bool operator < (const Record& r) {
		int cmp_result = 0;
		if (cmp_key == 1) {
			cmp_result = id.compare(r.id);
		}
		else if(cmp_key == 2) {
			cmp_result = name.compare(r.name);
		}
		else {
			cmp_result = score - r.score;
		}
		// 如果关键字段相等的话，按照id大小排序 
		if (cmp_result == 0) {
			return id.compare(r.id) < 0;
		}
		else {
			return cmp_result < 0;
		}
	}
};

int main() {
	int N, C;
	cin >> N >> C;
	// 设置比较的关键字 
	cmp_key = C;
	// 创建数组 
	vector<Record> records;
	while (N--) {
		Record r;
		// 这题太坑了，用cin会超时 
		r.id.resize(8);
		r.name.resize(9);
		scanf("%s%s%d", &r.id[0], &r.name[0], &r.score); 
		records.push_back(r);
	}
	sort(records.begin(), records.end());
	
	for (vector<Record>::iterator itr = records.begin(); itr != records.end(); itr++) {
		printf("%s %s %d\n", &(itr->id)[0], &(itr->name)[0], itr->score);
		//cout << itr->id << " " << itr->name << " " << itr->score << endl;
	}
} 

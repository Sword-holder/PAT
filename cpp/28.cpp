#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ÿһ����¼�����ݽṹ 
int cmp_key = 0;
struct Record {
	string id;
	string name;
	int score;
	
	// ����ĺ����Ƕ�������ȽϺ��� 
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
		// ����ؼ��ֶ���ȵĻ�������id��С���� 
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
	// ���ñȽϵĹؼ��� 
	cmp_key = C;
	// �������� 
	vector<Record> records;
	while (N--) {
		Record r;
		// ����̫���ˣ���cin�ᳬʱ 
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

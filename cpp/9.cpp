#include <iostream>
using namespace std;
const int BUFFER_SIZE = 2048;

struct Polynomial {
	int zhishu;
	double xishu;
	Polynomial* next;
};

int main() {
	Polynomial* head = new Polynomial;
	head->next = NULL;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int zhishu;
		double xishu;
		cin >> zhishu >> xishu;
		Polynomial* entry = new Polynomial;
		entry->xishu = xishu;
		entry->zhishu = zhishu;
		// ͷ�巨 
		entry->next = head->next;
		head->next = entry;
	}
	
	double a[BUFFER_SIZE] = { 0.0 };
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int zhishu;
		double xishu;
		cin >> zhishu >> xishu;
		
		Polynomial* p = head->next;
		while (p) {
			a[p->zhishu + zhishu] += p->xishu * xishu;
			p = p->next;
		}
	}
	
	while (head->next) {
		Polynomial* p = head->next;
		head->next = p->next;
		delete p;
	}
	delete head;
	
	int count = 0;
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (a[i] != 0) {
			count += 1;
		}
	}
	cout << count;
	for (int i = BUFFER_SIZE - 1; i >= 0; i--) {
		if (a[i] != 0) {
			printf(" %d %.1f", i, a[i]);
		}
	}
}

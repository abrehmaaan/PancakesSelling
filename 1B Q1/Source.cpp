#include<iostream>
#include<deque>
using namespace std;
int main() {
	deque<int> pancakes;
	int noOfTests, customers, deliciousness, lastSold, totalSold;
	cin >> noOfTests;
	for (int i = 1;i <= noOfTests;i++) {
		cin >> customers;
		for (int j = 0;j < customers;j++) {
			cin >> deliciousness;
			pancakes.push_back(deliciousness);
		}
		totalSold = 0;
		lastSold = 0;
		while (!pancakes.empty() && (lastSold <= pancakes.front() || lastSold <= pancakes.back())) {
			if (pancakes.front() <= pancakes.back()) {
				if (pancakes.front() >= lastSold) {
					totalSold++;
					lastSold = pancakes.front();
					pancakes.pop_front();
				}
				else if (pancakes.back() >= lastSold) {
					totalSold++;
					lastSold = pancakes.back();
					pancakes.pop_back();
				}
				else {
					break;
				}
			}
			else {
				if (pancakes.back() >= lastSold) {
					totalSold++;
					lastSold = pancakes.back();
					pancakes.pop_back();
				}
				else if (pancakes.front() >= lastSold) {
					totalSold++;
					lastSold = pancakes.front();
					pancakes.pop_front();
				}
				else {
					break;
				}
			}
		}
		cout << "Case #" << i << ": " << totalSold << endl;
		while (!pancakes.empty()) {
			pancakes.pop_back();
		}
	}
}
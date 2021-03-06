#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int capacity, ingot_num;
	cin >> capacity >> ingot_num;
	vector<int> weights(ingot_num);
	for (int j = 0; j < ingot_num; ++j) cin >> weights[j];

	vector<int> previous(capacity + 1, 0);
	vector<int> current(capacity + 1);
	for (int i = 0; i < ingot_num; ++i) {
		current[0] = 0;
		for (int j = 1; j < current.size(); ++j) {
			if (weights[i] <= j) current[j] = max(previous[j], previous[j - weights[i]] + weights[i]);
			else current[j] = previous[j];
		}
		current.swap(previous);
	}
	cout << previous[capacity];
    return 0;
}


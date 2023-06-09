#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

auto arr = vb(1'000'001, false);
int n;
vi lst;
map<int, int> pt;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	lst = vi(n);
	for (auto&& x : lst) {
		cin >> x;
		arr[x] = true;
		pt.insert({ x, 0 });
	}

	for (const auto& [x, p] : pt) {
		for (auto j = x * 2; j <= 1'000'000; j += x) {
			if (arr[j]) {
				pt[x] += 1;
				pt[j] -= 1;
			}
		}
	}

	for (const auto& x : lst) {
		cout << pt[x] << ' ';
	}

	return 0;
}
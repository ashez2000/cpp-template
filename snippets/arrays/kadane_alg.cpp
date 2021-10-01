#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n) {
  int cur_sum = 0, max_sum = 0;
  for (int i = 0; i < n; i++) {
    cur_sum += arr[i];
    if (cur_sum < 0) {
      cur_sum = 0;
    }
    max_sum = max(max_sum, cur_sum);
  }
  return max_sum;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int compare(pair<double,int> x,pair<double,int> y) {
    if(x.first<y.first)
        return 0;
    return 1;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    vector< pair<double,int> > vpw;

    for(int i=0;i<values.size();i++)
    {
        vpw.push_back({((double)values[i])/((double)weights[i]),weights[i]});
    }
    sort(vpw.begin(),vpw.end(),compare);
    int i = 0;
    while(capacity--)
    {
        if(vpw[i].second==0)
            i++;
        //cout << value << endl;
        value += vpw[i].first;
        vpw[i].second--;
    }
    return value;
}

int main() {
  int n;  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << fixed << setprecision(4) << optimal_value << std::endl;
  return 0;
}

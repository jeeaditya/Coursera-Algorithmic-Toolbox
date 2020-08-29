#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int st, en;
};
int compare(Segment a,Segment b) {
    if(a.en < b.en)
        return 1;
    else if(a.en == b.en)
        return a.st < b.st;
    else
        return 0;
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(),segments.end(),compare);
  int j = -1;
  for (size_t i = 0; i < segments.size(); ++i) {
        if(j==-1) {
            points.push_back(segments[i].en);
            j++;
        }
        else
        {
            while(j<points.size() && segments[i].st > points[j])
                j++;
            if(j == points.size())
                points.push_back(segments[i].en);
        }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].st >> segments[i].en;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}

#include <bits/stdc++.h>
using namespace std;

using pd = pair<double, double>;

pd get_midpoint(pd a, pd b, double x) {
    double m = (b.second - a.second) / (b.first - a.first);
    double c = a.second - m * a.first;
    // cout << "y = " << m << "x" << " + " << c << "\n";
    double y = m * x + c;
    return make_pair(x, y);
}


int main() {
    int n, l, m;
    cin >> n >> l;
    vector<vector<pd>> sponsors (n);
    vector<double> total_areas (n);
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<pd> points (m);
        for (int j = 0; j < m; j++) {
            cin >> points[j].first >> points[j].second;
            if (j != 0) {
                double diff_x = (double)(points[j].first - points[j - 1].first);
                total_areas[i] += 0.5 * diff_x * (points[j].second + points[j - 1].second);
            }
        }
        sponsors[i] = points;
    }

    // for (auto points : sponsors) {
    //     for (auto p : points) {
    //         cout << p.first << " " << p.second << "\n";
    //     }
    // }

    // While there's a sponsor who doesn't have a billboard area,
    // find a sponsor who will take up the least space while
    // satisfying 1/n of his graph area. Pick that sponsor and
    // repeat.
    double start = 0;
    vector<pair<int, double>> solutions;
    while ((int)solutions.size() != n) {
        double min = (double) l;
        for (int i = 0; i < sponsors.size(); i++) {
            double area = 0;
            double threshold = 1 / total_areas[i];
            vector<pd> points = sponsors[i];
            int j = 0;
            while (points[j].first <= start) {
                j++;
            }
            pd curr = points[j - 1];
            pd next = points[j];
            while (area < threshold) {
                pd midpoint = get_midpoint(curr, next, start);
                // cout << midpoint.first << " " << midpoint.second << "\n";
                
            }
        }
        solutions.push_back(make_pair(1, 5.0));
    }
}

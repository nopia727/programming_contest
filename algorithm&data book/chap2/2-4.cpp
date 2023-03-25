#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calc_dict(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    int n; cin >> n;
    vector<double> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];
    double minimum_dict = 100000000;
    for (int i=0; i<n; ++i){
        for(int j=i+1; j<n; j++){
            double dict_i_j = calc_dict(x[i], y[i], x[j], y[j]);
            if (dict_i_j < minimum_dict){
                minimum_dict = dict_i_j
            }
        }
    }
    cout << minimum_dict << endl;
}
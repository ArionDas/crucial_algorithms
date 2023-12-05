#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<pair<int,int>> vp(n);
    cout << "Enter the values of the weights and profits of the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        pair<int,int> p;
        cin >> p.first;
        cin >> p.second;

        vp.push_back(p);
    }

    int w;
    cout << "Enter the capacity: ";
    cin >> w;

    // Rest of the code...

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For setw

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void sortat(vector<int> &p, vector<int> &at, vector<int> &bt, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(p[i], p[j]);
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
            } else if (at[i] == at[j]) {
                if (bt[i] > bt[j]) {
                    swap(p[i], p[j]);
                    swap(at[i], at[j]);
                    swap(bt[i], bt[j]);
                }
            }
        }
    }
}

void tatwt(vector<int> &ct, vector<int> &at, vector<int> &bt, vector<int> &tat, vector<int> &wt, int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> p(n), at(n), bt(n), ct(n), wt(n), tat(n);
    float awt = 0, atat = 0;
    cout << "Enter " << n << " processes: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Enter the arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> at[i];
    }

    cout << "Enter the burst times: ";
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
    }

    sortat(p, at, bt, n);
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++) {
        int min = 1000, pos;
        for (int j = i; j < n; j++) {
            if (at[j] <= ct[i - 1]) {
                if (bt[j] < min) {
                    min = bt[j];
                    pos = j;
                }
            }
        }

        swap(p[i], p[pos]);
        swap(at[i], at[pos]);
        swap(bt[i], bt[pos]);

        min = 1000;
        ct[i] = ct[i - 1] + bt[i];
    }

    tatwt(ct, at, bt, tat, wt, n);

    cout << left << setw(5) << "P" << setw(5) << "at" << setw(5) << "bt" << setw(5) << "ct" << setw(5) << "tat" << setw(5) << "wt" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(5) << p[i] << setw(5) << at[i] << setw(5) << bt[i] << setw(5) << ct[i] << setw(5) << tat[i] << setw(5) << wt[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        atat += tat[i];
        awt += wt[i];
    }

    atat = atat / n;
    awt = awt / n;

    cout << "\nAverage Turnaround Time = " << atat << " and Average Waiting Time = " << awt << endl;

    return 0;
}
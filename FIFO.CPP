#include<bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k, hitCount = 0;
    int frames;
    int p_count;

    cout << "Enter the number of frames: ";
    cin >> frames;

    cout << "Enter the number of processes: ";
    cin >> p_count;

    vector<int> processes(p_count);
    cout << "Enter the processes: ";
    for (i = 0; i < p_count; i++) {
        cin >> processes[i];
    }

    vector<int> hit(p_count);

    vector<vector<int>> a(frames);
    for (i = 0; i < frames; i++) {
        a[i] = vector<int>(p_count, -1);
    }

    map<int, int> mp;

    for (i = 0; i < p_count; i++) {
        vector<pair<int, int>> c;

        for (auto x : mp) {
            c.push_back({x.second, x.first});
        }

        sort(c.begin(), c.end());

        bool hasCompleted = false;

        for (j = 0; j < frames; j++) {
            if (a[j][i] == processes[i]) {
                hitCount++;
                hit[i] = true;

                mp[processes[i]]++;
                hasCompleted = true;
                break;
            }
            if (a[j][i] == -1) {
                for (k = i; k < p_count; k++)
                    a[j][k] = processes[i];

                mp[processes[i]]++;
                hasCompleted = true;
                break;
            }
        }
        if (j == frames || hasCompleted == false) {
            for (j = 0; j < frames; j++) {
                if (a[j][i] == c[c.size() - 1].second) {
                    mp.erase(a[j][i]);

                    for (k = i; k < p_count; k++)
                        a[j][k] = processes[i];

                    mp[processes[i]]++;
                    break;
                }
            }
        }
        for (auto x : mp) {
            if (x.first != processes[i]) {
                mp[x.first]++;
            }
        }
    }

    cout << "Process    ";
    for (i = 0; i < p_count; i++) {
        cout << processes[i] << "  ";
    }
    cout << endl;

    for (i = 0; i < frames; i++) {
        cout << "Frame" << i << "     ";
        for (j = 0; j < p_count; j++) {
            if (a[i][j] == -1)
                cout << "-  ";
            else
                cout << a[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "Page Fault ";
    for (i = 0; i < p_count; i++) {

        // page fault occurs if hi[i] == True
        // hit occurs when hi[i] = false
        if (hit[i])
            cout << "N  ";
        else
            cout << "Y  ";
    }
    cout << "\n\n";

    cout << "Page Fault " << p_count - hitCount << endl;
    cout << "Hit " << hitCount << endl;

    return 0;
}
// Enter the number of frames: 3
Enter the number of processes: 14
Enter the processes: 7  0  1  2  0  3  0  4  2  3  0  3  2  1
Process    7  0  1  2  0  3  0  4  2  3  0  3  2  1  
Frame0     7  7  7  2  2  2  2  4  4  4  0  0  0  0  
Frame1     -  0  0  0  0  3  3  3  2  2  2  2  2  1  
Frame2     -  -  1  1  1  1  0  0  0  3  3  3  3  3  
Page Fault Y  Y  Y  Y  N  Y  Y  Y  Y  Y  Y  N  N  Y  

Page Fault 11
Hit 3 //
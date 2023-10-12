#include<iostream>

using namespace std;

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
    float awt = 0, atat = 0;
    
    cout << "Enter the number of processes: ";
    cin >> n;
    
    cout << "Enter " << n << " processes: ";
    for (i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    cout << "Enter " << n << " arrival times: ";
    for (i = 0; i < n; i++) {
        cin >> at[i];
    }
    
    cout << "Enter " << n << " burst times: ";
    for (i = 0; i < n; i++) {
        cin >> bt[i];
    }
    
    // Sorting at, bt, and process according to at
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i); j++) {
            if (at[j] > at[j + 1]) {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }
    
    // Calculating 1st ct
    ct[0] = at[0] + bt[0];
    
    // Calculating ct for processes 2 to n
    for (i = 1; i < n; i++) {
        // When process is idle in between i and i+1
        temp = 0;
        if (ct[i - 1] < at[i]) {
            temp = at[i] - ct[i - 1];
        }
        ct[i] = ct[i - 1] + bt[i] + temp;
    }
    
    // Calculating tat and wt
    cout << "\np]P\tA.T\tB.T\tC.T\tTAT\tWT" << endl;
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
        cout << "P" << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    
    atat = atat / n;
    awt = awt / n;
    
    cout << "\nAverage turnaround time is " << atat << endl;
    cout << "Average waiting time is " << awt << endl;
    
    return 0;
}
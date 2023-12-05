#include<iostream>
using namespace std;

int main() {
    int c, i, j, k, n, l, m[10], p[10], po[20], flag, z, y, temp, temp1;
    cout << "enter memory partition:\t";
    cin >> n;
    cout << "\nenter memory size for\n";
    for (i = 1; i <= n; i++) {
        cout << "\npartition " << i << " :\t";
        cin >> m[i];
        po[i] = i;
    }
    cout << "\nenter process:\t";
    cin >> j;
    cout << "\nenter memory size for\n";
    for (i = 1; i <= j; i++) {
        cout << "\nprocess " << i << " :\t";
        cin >> p[i];
    }
    cout << "\n******** Algorithm for memory management**********\n1.first fit\n2.best fit\n3.worst fit\nenter choice:\t";
    cin >> c;
    switch (c) {
        case 1:
            for (i = 1; i <= j; i++) {
                flag = 1;
                for (k = 1; k <= n; k++) {
                    if (p[i] <= m[k]) {
                        cout << "\nprocess " << i << " whose memory size is " << p[i] << "KB allocated at memory partition:\t" << po[k];
                        m[k] = m[k] - p[i];
                        break;
                    } else {
                        flag++;
                    }
                }
                if (flag > n) {
                    cout << "\nprocess " << i << " whose memory size is " << p[i] << "KB can't be allocated";
                }
            }
            break;
        case 2:
            for (y = 1; y <= n; y++) {
                for (z = y; z <= n; z++) {
                    if (m[y] > m[z]) {
                        temp = m[y];
                        m[y] = m[z];
                        m[z] = temp;
                        temp1 = po[y];
                        po[y] = po[z];
                        po[z] = temp1;
                    }
                }
            }
            for (i = 1; i <= j; i++) {
                flag = 1;
                for (k = 1; k <= n; k++) {
                    if (p[i] <= m[k]) {
                        cout << "\nprocess " << i << " whose memory size is " << p[i] << "KB allocated at memory partition:\t" << po[k];
                        m[k] = m[k] - p[i];
                        break;
                    } else {
                        flag++;
                    }
                }
                if (flag > n) {
                    cout << "\nprocess " << i << " whose memory size is " << p[i] << "KB can't be allocated";
                }
            }
            break;
        case 3:
            for (y = 1; y <= n; y++) {
                for (z = y; z <= n; z++) {
                    if (m[y] < m[z]) {
                        temp = m[y];
                        m[y] = m[z];
                        m[z] = temp;
                        temp1 = po[y];
                        po[y] = po[z];
                        po[z] = temp1;
                    }
                }
            }
            for (i = 1; i <= j; i++) {
                flag = 1;
                for (k = 1; k <= n; k++) {
                    if (p[i] <= m[k]) {
                        cout << "\nprocess " << i << " whose memory size is " << p[i] << "KB allocated at memory partition:\t" << po[k];
                        m[k] = m[k] - p[i];
                        break;
                    } else {
                        flag++;
                    }
                }
                if (flag > n) {
                    cout << "\nprocess " << i << " whose memory size is " << p[i] << "KB can't be allocated";
                }
            }
            break;
    }
    return 0;
}
///tmp/lwlBs4fRhQ.o

/** enter memory partition:	5
enter memory size for

partition 1 :	300
partition 2 :	50
partition 3 :	200
partition 4 :	350
partition 5 :	70
enter process:	5
enter memory size for

process 1 :	200
process 2 :	47
process 3 :	212
process 4 :	426
process 5 :	10
******** Algorithm for memory management**********
1.first fit
2.best fit
3.worst fit
enter choice:	1
process 1 whose memory size is 200KB allocated at memory partition:	1
process 2 whose memory size is 47KB allocated at memory partition:	1
process 3 whose memory size is 212KB allocated at memory partition:	4
process 4 whose memory size is 426KB can't be allocated
process 5 whose memory size is 10KB allocated at memory partition:	1 

best fit


enter memory partition:	5
enter memory size for

partition 1 :	100
partition 2 :	500
2partition 3 :	200
partition 4 :	300
partition 5 :	400
enter process:	4
enter memory size for

process 1 :	112
process 2 :	518
process 3 :	110
process 4 :	526
******** Algorithms for memory management**********
1.first fit
2.best fit
3.worst fit
enter choice:	2
process 1 whose memory size is 112KB allocated at memory partition:	3
process 2 whose memory size is 518KB can't be allocated
process 3 whose memory size is 110KB allocated at memory partition:	4
process 4 whose memory size is 526KB can't be allocated


worst fit

/tmp/cMwGv7aFq1.o
enter memory partition:	5
enter memory size for

partition 1 :	100
partition 2 :	500
partition 3 :	200
partition 4 :	300
partition 5 :	600
enter process:	4
enter memory size for

process 1 :	212
process 2 :	417
process 3 :	112
process 4 :	426
******** Algorithm for memory management**********
1.first fit
2.best fit
3.worst fit
enter choice:	3
process 1 whose memory size is 212KB allocated at memory partition:	5
process 2 whose memory size is 417KB allocated at memory partition:	2
process 3 whose memory size is 112KB allocated at memory partition:	5
process 4 whose memory size is 426KB can't be allocated
 */
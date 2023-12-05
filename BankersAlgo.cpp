//C++ program for Banker's Algorithm 
#include <iostream>
using namespace std;
int main() 
{ 
	// P0, P1, P2, P3, P4 are the names of Process
	int no_of_processes, no_of_resources, i, j, k; 
	no_of_processes = 5; // Number of processes 
	no_of_resources = 3; //Number of resources 
	int allocate[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix 
						{ 2, 0, 0 }, // P1 
						{ 3, 0, 2 }, // P2 
						{ 2, 1, 1 }, // P3 
						{ 0, 0, 2 } }; // P4 

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX matrix representing max need 
					{ 3, 2, 2 }, // P1 
					{ 9, 0, 2 }, // P2 
					{ 4, 2, 2 }, // P3 
					{ 5, 3, 3 } }; // P4 

	int available[3] = { 3, 3, 2 }; // Available Resources 

	int finish[no_of_processes]={0}, safe_seq[no_of_processes], index = 0; 
	 
	int need[no_of_processes][no_of_resources]; 
	
	for (i = 0; i < no_of_processes; i++) { 
		for (j = 0; j < no_of_resources; j++) 
			need[i][j] = max[i][j] - allocate[i][j]; //calculating need of resources
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < no_of_processes; i++) { 

			if (finish[i] == 0) {  //unfinished process
				bool flag = true; 
				for (j = 0; j < no_of_resources; j++) { 
					if (need[i][j] > available[j]){  //not enough resources
						flag = false; 
						break; 
					} 
				} 

				if (flag == true) {  //resources are available
					safe_seq[index++] = i; 
					for (y = 0; y < no_of_resources; y++) 
						available[y] += allocate[i][y]; //allocating resources
					finish[i] = 1; //process is finished 
				} 
			} 
		} 
	} 

	cout<<"Th SAFE Sequence is: \n"; 
	for (i = 0; i < no_of_processes - 1; i++) 
		cout<<" P->"<<safe_seq[i]; 
	cout<<" P->"<<safe_seq[no_of_processes - 1]; 

	return 0;
} 
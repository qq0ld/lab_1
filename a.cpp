#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

// 15 varik blyad
// kajduyu stroku matrix po vozr

int main(){
    int m = 0, n = 0;

    srand (time(0));

    m = rand() % 10 + 1;
    n = rand() % 10 + 1;

    cout << m << " " << n << endl;

    int arr[m][n];
    int cnt = 0;


    // vivod + zadaem matrix
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = rand()%2000;
            cout << arr[i][j] << "\t";
            cnt += 1;
            if (cnt == m){
            cout << endl;
            cnt = 0;
            }
        }
    }

    return 0;
}


#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

// 15 varik blyad
// kajduyu stroku matrix po vozr

void bubble(int arr[], int size, vector <int> &v){
    int comp = 0, swp = 0;
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                comp++;
                swp++;
            }
        }
    }
    v.push_back(comp);
    v.push_back(swp);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << "\t";
    }
}

// quick sort ebashim))
void swap(int *a, int *b){
    int t = *a; 
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i++;
}

void quicksort(int arr[], int low, int high){
    int comp = 0, swp = 0, sc = 0, sswp = 0;
    if (low < high){
        int pi = partition(arr, low, high);
        comp++;
        swp += 2;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void inssort(int arr[], int size){
    for (int step = 1; step < size; step++){
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] and j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void selsort(int arr[], int size){
    for (int step = 0; step < size - 1; step++){
        int min_ix = step; 
        for (int i = step + 1; i < size; i++){
            if (arr[i] < arr[min_ix]) min_ix = i;
        }
        swap(&arr[min_ix], &arr[step]);
    }

}

void shsort(int arr[], int n){
    for (int intl = n/2; intl > 0; intl /= 2){
        for (int i = intl; i < n; i++){
            int temp = arr[i];
            int j;
            for (j = i; j >= intl and arr[j - intl] > temp; j -= intl){
                arr[j] = arr[j - intl];
            }
            arr[j] = temp;
        }
    }
}

int main(){
    int m = 0, n = 0;

    srand (time(0));

    m = rand() % 10 + 1;
    n = rand() % 10 + 1;

    int arr[m][n];
    int ix = 0;
    int dub[m*n];
    
    vector <int> v;

    int size = sizeof(dub)/sizeof(int);
    
    // vivod + zadaem matrix
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = rand()%2000;
            dub[ix++] = arr[i][j];
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    bubble(dub, size, v);
    quicksort(dub, 0, size - 1);
    // inssort(dub, size);
    // selsort(dub, size);
    // shsort(dub, size);

    ix = 0;

    // возвращаем из 1д аррей элементы обратно в шматрицу.
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = dub[ix++];
        }
    }

    cout << "\n" << "bubble" << "\n" << "\n";

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}


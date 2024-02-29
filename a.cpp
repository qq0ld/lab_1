#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

// kajduyu stroku matrix po vozr

int a1 = 0, b1 = 0; // a eto perestanowki, b sravnenija

void bubble(int arr[], int size){
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                a1++;
            } else b1++;
        }
    }
}

// quick sort ebashim))
void swap(int *a, int *b){
    int t = *a; 
    *a = *b;
    *b = t;
}

int a2 = 0, b2 = 0; // a eto perestanowki, b sravnenija

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++){
        if(arr[i] < pivot) count++;
    }

    int pIndex = start + count;
    swap(arr[pIndex], arr[start]);

    int i = start, j = end;

    while (i < pIndex and j > pIndex){
        while (arr[i] <= pivot){
            i++;
            b2++;
        } 
        while (arr[j] > pivot){
            j--;
            b2++;
        } 
        if (i < pIndex and j > pIndex){
            swap(arr[i++], arr[j--]);
            a2++;
        }
    }
    
    return pIndex;
}

void quicksort(int arr[], int start, int end){
    if (start >= end) return;
    
    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
    
}

int a3 = 0, b3 = 0; // a eto perestanowki, b sravnenija

void inssort(int arr[], int size){ // insertion sort
    for (int step = 1; step < size; step++){
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] and j >= 0){
            arr[j + 1] = arr[j];
            b3++;
            --j;
        } 
        arr[j + 1] = key;
        a3++;
    }
}

int a4 = 0, b4 = 0;
void selsort(int arr[], int size){ // selection sort // a eto perestanowki, b sravnenija
    for (int step = 0; step < size - 1; step++){
        int min_ix = step; // ix stands for index
        for (int i = step + 1; i < size; i++){
            if (arr[i] < arr[min_ix]){
                min_ix = i;
                b4++;
            }
        }
        swap(&arr[min_ix], &arr[step]);
        a4++;
    }
}

int a5 = 0, b5 = 0;
void shsort(int arr[], int n){ // shell sort // a eto perestanowki, b sravnenija
    for (int intl = n/2; intl > 0; intl /= 2){
        for (int i = intl; i < n; i++){
            int temp = arr[i];
            int j;
            for (j = i; j >= intl and arr[j - intl] > temp; j -= intl){
                arr[j] = arr[j - intl];
                b5++;
            }
            arr[j] = temp;
            a5++;
        }
    }
}

void Line(int n){
    int l = 0;
    l = (4*n) + (4*(n-1));
    cout << '-' << setfill('-') << setw(l+4) << '-' << endl;
}

void Sorted(int n){
    int l = 0;
    l = (4*n) + (4*(n-1));
    cout << '-' << setfill('-') << setw(l+4) << '-' << endl;
    cout << '|' << " sorted " << setw(l-4) << setfill(' ') << '|' << endl;
    cout << '-' << setfill('-') << setw(l+4) << '-' << endl;
}


void vivod(int arr1[], int arr2[], int arr3[], int arr4[], int arr5[], int m, int n){
    int arr[m][n];
    int size = 0;
    int sw = 0;

    Sorted(n);

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            arr[i][j] = arr1[size++];
            cout << arr[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);

    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            arr[i][j] = arr2[size++];
            cout << arr[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);
    
    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            arr[i][j] = arr3[size++];
            cout << arr[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);
    sw++;

    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            arr[i][j] = arr4[size++];
            cout << arr[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);
    
    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            arr[i][j] = arr5[size++];
            cout << arr[i][j] << "\t";
        }
        cout << "|" << endl;
    }
}

void Top(int n){
    int l = 0;
    l = (4*n) + (4*(n-1));
    
    cout << endl;
    cout << '-' << setfill('-') << setw(l+4) << '-' << endl;
    cout << '|' << " matrix" << setw(l-3) << setfill(' ') << '|' << endl;
    cout << '-' << setfill('-') << setw(l+4) << '-' << endl;
}




void Stats(string sorts[]){
    int l = 30;
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
    cout << '|' << setw(15) << setfill(' ') << "stats" << setw(14) << setfill(' ') << '|' << endl;
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
    cout << "| " << "sort " << setw(1) << setfill(' ') << '|' << " comparison |" << " swaps" << setfill(' ') << setw(3) << "|" << endl;
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
    cout << "| " << sorts[0] << ":" << setw(9) << setfill(' ') << b1 << " |" << setw(8) << setfill(' ') << a1 << "|" << endl;
    cout << "| " << sorts[1] << ":" << setw(9) << setfill(' ') << b2 << " |" << setw(8) << setfill(' ') << a2 << "|" << endl;
    cout << "| " << sorts[2] << ":" << setw(9) << setfill(' ') << b3 << " |" << setw(8) << setfill(' ') << a3 << "|" << endl;
    cout << "| " << sorts[3] << ":" << setw(9) << setfill(' ') << b4 << " |" << setw(8) << setfill(' ') << a4 << "|" << endl;
    cout << "| " << sorts[4] << ":" << setw(9) << setfill(' ') << a5 << " |" << setw(8) << setfill(' ') << b5 << "|" << endl;
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
}

int main(){
    int m = 0, n = 0;

    srand (time(0));

    m = rand() % 10 + 1;
    n = rand() % 10 + 1;

    int arr[m][n];
    int ix = 0;
    int dub[m*n];

    // ))))))))))))))

    int dub1[m*n];
    int dub2[m*n];
    int dub3[m*n];
    int dub4[m*n];
    int dub5[m*n];
    
    int size = sizeof(dub)/sizeof(int);

    string sorts[5] = {"bubble ", "quick  ", "inssort", "selsort", "shsort "};
    
    // vivod + zadaem matrix 

    Top(n);

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            arr[i][j] = rand()%2000;
            dub[ix++] = arr[i][j];
            cout << arr[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    for (int i = 0; i < ix; i++){
        dub1[i] = dub[i];
        dub2[i] = dub[i];
        dub3[i] = dub[i];
        dub4[i] = dub[i];
        dub5[i] = dub[i];
    }


    bubble(dub1, size);
    quicksort(dub2, 0, size - 1);
    inssort(dub3, size);
    selsort(dub4, size);
    shsort(dub5, size);

    ix = 0;

    vivod(dub1, dub2, dub3, dub4, dub5, m, n);


    Line(n);
    
    cout << endl;

    Stats(sorts);



    return 0;
}

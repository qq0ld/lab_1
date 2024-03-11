#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iomanip>

using namespace std;

// kajduyu stroku matrix po vozr

int a1 = 0, b1 = 0; // a eto perestanowki, b sravnenija

void bubble(int arr[], int size){
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            a1++;
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                b1++;
            }  
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
            a3++;
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
            b4++;
            if (arr[i] < arr[min_ix]){
                min_ix = i;
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
                a5++;
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
    int a1[m][n];
    int a2[m][n];
    int a3[m][n];
    int a4[m][n];
    int a5[m][n];
    int size = 0;

    Sorted(n);

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            a1[i][j] = arr1[size++];
            cout << a1[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);

    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            a2[i][j] = arr2[size++];
            cout << a2[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);
    
    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            a3[i][j] = arr3[size++];
            cout << a3[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);

    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            a4[i][j] = arr4[size++];
            cout << a4[i][j] << "\t";
        }
        cout << "|" << endl;
    }

    Sorted(n);
    
    size = 0;

    for (int i = 0; i < m; i++){
        cout << "| ";
        for (int j = 0; j < n; j++){
            a5[i][j] = arr5[size++];
            cout << a5[i][j] << "\t";
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
    int l = 32;
    

    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
    cout << '|' << setw(16) << setfill(' ') << "stats" << setw(15) << setfill(' ') << '|' << endl;
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
    cout << "| " << "sort   " << setw(1) << setfill(' ') << '|' << " comparison |" << " swaps" << setfill(' ') << setw(3) << "|" << endl;
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
    int mAss[5] = {a1, a2, a3, a4, a5};
    int mBss[5] = {b1, b2, b3, b4, b5};
    for (int i = 0; i < 5; i++){
        cout << "| " << sorts[i] << ":" << setw(11) << setfill(' ') << mAss[i] << " |" << setw(7) << setfill(' ') << mBss[i] << " |" << endl;    
    }
    cout << '-' << setfill('-') << setw(l-1) << '-' << endl;
}

bool ck(const string& str){
    return str.find_first_not_of("0123456789") == string::npos;
}

int main(){
    int m = 0, n = 0;

    srand (time(0));

    string str1 = "", str2 = "";
    
    cout << endl << "enter m and n, inti, men'she 10" << endl;
    cin >> str1 >> str2;

    if (!ck(str1) or !ck(str2)){
        cout << "you've entred the wrong number" << endl;
        cout << "default values (m = n = 5) were set" << endl;
        m = n = 5;
    } else {
        m = stoi(str1);
        n = stoi(str2);
        if ((m > 10 or n > 10) or (m <= 0 or (n <= 0))){
            cout << "you've entred the wrong number" << endl;
            cout << "default values (m = n = 5) were set" << endl;
            m = n = 5;
        }
    }

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
    
    cout << endl;

    return 0;
}

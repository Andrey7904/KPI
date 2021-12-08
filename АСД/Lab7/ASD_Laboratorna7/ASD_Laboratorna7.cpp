#include <iostream>
using namespace std;

void fill_arrays(char[], char[], int);
void display_array(char[], int);
int fill_third_array(char[], char[], char[], int);
int find_max_code(char[], int);
int find_min_code(char[], int);

int main() {
    const int n = 10;
    char arr1[n], arr2[n], arr3[n];
    int sum, k, min_code, max_code;
    fill_arrays(arr1, arr2, n);
    cout << "Array 1:\n";
    display_array(arr1, n);
    cout << "Array 2:\n";
    display_array(arr2, n);
    k=fill_third_array(arr1, arr2, arr3, n);
    cout << "Array 3:\n";
    display_array(arr3, n);

    min_code = find_min_code(arr3, k);
    cout << "Min code is " << min_code << '\n';
    max_code = find_max_code(arr3, k);
    cout << "Max code is " << max_code << '\n';
    sum = min_code + max_code;
    cout << "Sum of codes of minimal and maximum elements is " << sum;
    return 0;
}

void fill_arrays(char arr1[], char arr2[], int length) {
    for (int i = 0; i < length; i++) {
        arr1[i] = char(62 + 3 * i);
        arr2[i] = char(74 - i);
    }
}

void display_array(char arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int fill_third_array(char arr1[], char arr2[], char arr3[], int length) {
    int k = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[k] = arr1[i];
                k++;
            }
        }
    }
    return k;
}

int find_min_code(char arr[], int k) {
    int i = 1;
    int temp = int(arr[0]);
    while (int(arr[i]) != 0 && i < k) {
        if (int(arr[i]) < temp) {
            temp = int(arr[i]);
        }
        i++;
    }
    return temp;
}

int find_max_code(char arr[], int k) {
    int i = 1;
    int temp = int(arr[0]);
    while (int(arr[i]) != 0 && i < k) {
        if (int(arr[i]) > temp) {
            temp = int(arr[i]);
        }
        i++;
    }
    return temp;
}
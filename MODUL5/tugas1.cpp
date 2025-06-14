#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>
using namespace std;

void insertionSort() {
    string data;
    cout << "Masukkan data: ";
    cin.ignore();
    getline(cin, data);
    cout << "Data Sebelum Diurutkan: " << data << endl;
    for (int i = 1; i < (int)data.size(); i++) {
        char key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
    cout << "Data Setelah Diurutkan: " << data << endl;
}

void merge(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char *tempL = new char[n1];
    char *tempR = new char[n2];
    for (int i = 0; i < n1; i++) tempL[i] = str[left + i];
    for (int j = 0; j < n2; j++) tempR[j] = str[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
            str[k++] = tempL[i++];
        } else {
            str[k++] = tempR[j++];
        }
    }
    while (i < n1) str[k++] = tempL[i++];
    while (j < n2) str[k++] = tempR[j++];
    delete[] tempL;
    delete[] tempR;
}

void mergeSort(string &str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

void ProsesmergeSort() {
    string data;
    cout << "Masukkan data: ";
    cin.ignore();
    getline(cin, data);
    cout << "Data Sebelum Diurutkan: " << data << endl;
    mergeSort(data, 0, data.size() - 1);
    cout << "Data Setelah Diurutkan: " << data << endl;
}

void shellSort() {
    string data;
    cout << "Masukkan data: ";
    cin.ignore();
    getline(cin, data);
    cout << "Data Sebelum Diurutkan: " << data << endl;
    int n = data.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
    cout << "Data Setelah Diurutkan: " << data << endl;
}

int partition(string &str, int low, int high) {
    char pivot = str[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}

void quickSort(string &str, int low, int high) {
    if (low < high) {
        int p_idx = partition(str, low, high);
        quickSort(str, low, p_idx - 1);
        quickSort(str, p_idx + 1, high);
    }
}

void ProsesquickSort() {
    string data;
    cout << "Masukkan data: ";
    cin.ignore();
    getline(cin, data);
    cout << "Data Sebelum Diurutkan: " << data << endl;
    quickSort(data, 0, data.size() - 1);
    cout << "Data Setelah Diurutkan: " << data << endl;
}

void bubbleSort() {
    string data;
    cout << "Masukkan data: ";
    cin.ignore();
    getline(cin, data);
    cout << "Data Sebelum Diurutkan: " << data << endl;
    for (int i = 0; i < (int)data.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < (int)data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    cout << "Data Setelah Diurutkan: " << data << endl;
}

void selectionSort() {
    string data;
    cout << "Masukkan data: ";
    cin.ignore();
    getline(cin, data);
    cout << "Data Sebelum Diurutkan: " << data << endl;
    for (int i = 0; i < (int)data.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < (int)data.size(); j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
    cout << "Data Setelah Diurutkan: " << data << endl;
}

int main() {
    int pil;
    do {
        cout << "  -----------------------------" << endl;
        cout << "             Sorting           " << endl;
        cout << "  -----------------------------" << endl;
        cout << "  Pilihan Sorting Algoritma:   " << endl;
        cout << "  1. Insertion Sort            " << endl;
        cout << "  2. Merge Sort                " << endl;
        cout << "  3. Shell Sort                " << endl;
        cout << "  4. Quick Sort                " << endl;
        cout << "  5. Bubble Sort               " << endl;
        cout << "  6. Selection Sort            " << endl;
        cout << "  7. Exit                      " << endl;
        cout << "  -----------------------------" << endl;
        cout << "  Masukkan Pilihan: ";
        cin >> pil;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pil = -1;
        }

        switch (pil) {
            case 1: 
                insertionSort(); 
                break;
            case 2: 
                ProsesmergeSort(); 
                break;
            case 3: 
                shellSort(); 
                break;
            case 4: 
                ProsesquickSort(); 
                break;
            case 5: 
                bubbleSort(); 
                break;
            case 6: 
                selectionSort(); 
                break;
            case 7:
                cout << "TERIMA KASIH" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }

        cout << "\nPress any key to continue!" << endl;
        getch();
        system("cls");

    } while (pil != 7);

    return 0;
}
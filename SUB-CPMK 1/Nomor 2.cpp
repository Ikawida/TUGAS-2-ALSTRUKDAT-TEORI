// 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1. dan berikan penjelasan pada program tersebut

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Iterasi melalui setiap elemen dalam vektor
    for (int i = 0; i < n; i++) {
        // Terakhir-i elemen sudah pasti dalam posisi yang benar, jadi kita hanya perlu iterasi hingga n-i-1
        for (int j = 0; j < n-i-1; j++) {
            // Bandingkan pasangan elemen berturut-turut
            if (arr[j] > arr[j+1]) {
                // Jika elemen sebelah kiri lebih besar dari yang sebelah kanan, tukar posisi mereka
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {3,9,7,8,5,4,2,6,10,1};
    
    cout << "Array sebelum diurutkan: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    bubbleSort(arr); // Panggil fungsi bubbleSort untuk mengurutkan vektor

    cout << "Array setelah diurutkan: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

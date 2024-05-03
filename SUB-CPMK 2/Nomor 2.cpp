// 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut!

#include <iostream>
#include <vector>

using namespace std;

// Fungsi Linear Search untuk mencari elemen dalam array
// Mengembalikan indeks elemen yang ditemukan jika ada, atau -1 jika tidak ditemukan
int linearSearch(const vector<int>& arr, int target) {
    // Melakukan pencarian secara berurutan dari elemen pertama hingga terakhir
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks elemen jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika elemen tidak ditemukan
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 40;

    // Memanggil fungsi Linear Search
    int result = linearSearch(arr, target);

    // Menampilkan hasil pencarian
    if (result != -1) {
        cout << "Elemen " << target << " ditemukan pada indeks ke-" << result << endl;
    } else {
        cout << "Elemen " << target << " tidak ditemukan dalam array" << endl;
    }

    return 0;
}

// Penjelasan Program: 
// 1. linearSearch(): Ini adalah fungsi untuk melakukan pencarian linear dalam sebuah array. Fungsi ini menerima dua parameter: array arr yang merupakan array yang akan dicari dan target yang merupakan nilai yang ingin dicari dalam array. Fungsi mengembalikan indeks elemen yang ditemukan jika ditemukan, dan mengembalikan -1 jika tidak ditemukan.
// 2. Main(): Dalam fungsi main(), sebuah array arr dan nilai target target diinisialisasi. Fungsi linearSearch() kemudian dipanggil untuk mencari nilai target dalam array arr. Hasil pencarian kemudian ditampilkan, memberi tahu pengguna apakah nilai target ditemukan dalam array atau tidak.

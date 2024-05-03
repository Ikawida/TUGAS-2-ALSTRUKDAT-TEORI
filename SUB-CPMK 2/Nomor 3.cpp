// Tulislah sebuah fungsi program dengan kondisi, sebagai berikut:Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! (30 Poin) Input: bola, {"Adi","","","" "bermain", "", "bola", "", "", "sedang"} Output: 6

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk melakukan pencarian biner dalam array of strings
int searchInSortedStringArray(const vector<string>& arr, const string& target) {
    int left = 0; // Indeks awal dari array
    int right = arr.size() - 1; // Indeks akhir dari array

    // Melakukan pencarian biner dalam array
    while (left <= right) {
        int mid = left + (right - left) / 2; // Menghitung indeks tengah

        // Jika elemen tengah kosong, geser ke kiri sampai menemukan elemen yang tidak kosong
        while (arr[mid] == "" && mid >= left) {
            mid--;
        }

        // Jika elemen tengah sesuai dengan target, kembalikan indeksnya
        if (arr[mid] == target) {
            return mid;
        } 
        // Jika elemen tengah lebih besar dari target, cari di setengah kiri array
        else if (arr[mid] > target || arr[mid] == "") {
            right = mid - 1;
        } 
        // Jika elemen tengah lebih kecil dari target, cari di setengah kanan array
        else {
            left = mid + 1;
        }
    }

    return -1; // Kembalikan -1 jika target tidak ditemukan
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    string target = "bola";

    // Memanggil fungsi untuk mencari lokasi/indeks dari kata yang dicari
    int result = searchInSortedStringArray(arr, target);

    // Menampilkan hasil pencarian
    if (result != -1) {
        cout << "Indeks kata '" << target << "' dalam array: " << result << endl;
    } else {
        cout << "Kata '" << target << "' tidak ditemukan dalam array" << endl;
    }

    return 0;
}


// Penjelasan Program: 
// 1. searchInSortedStringArray(): Ini adalah fungsi untuk melakukan pencarian biner dalam sebuah array of strings yang sudah diurutkan. Fungsi ini menerima dua parameter: array arr yang merupakan array yang akan dicari dan target yang merupakan string yang ingin dicari dalam array. Fungsi mengembalikan indeks dari kata yang ditemukan jika ditemukan, dan mengembalikan -1 jika tidak ditemukan.
// 2. Main(): Dalam fungsi main(), sebuah array of strings arr dan nilai target target diinisialisasi. Fungsi searchInSortedStringArray() kemudian dipanggil untuk mencari lokasi/indeks dari kata yang dicari dalam array arr. Hasil pencarian kemudian ditampilkan, memberi tahu pengguna apakah kata yang dicari ditemukan dalam array atau tidak.
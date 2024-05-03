// 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan, array B kedalam array A, kemudian urutkan array tersebut! 

#include <iostream>
#include <vector>
#include <algorithm> // Untuk menggunakan fungsi merge() dan sort()

using namespace std;

// Fungsi untuk menggabungkan dua sorted array dan mengurutkan hasilnya
void mergeAndSort(vector<int>& A, const vector<int>& B) {
    // Menggabungkan array B ke dalam array A
    A.insert(A.end(), B.begin(), B.end());

    // Mengurutkan array A setelah penggabungan
    sort(A.begin(), A.end());
}

int main() {
    // Inisialisasi dua sorted array A dan B
    vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 4, 6, 8, 10};

    // Memanggil fungsi untuk menggabungkan dan mengurutkan array A dan B
    mergeAndSort(A, B);

    // Menampilkan hasil setelah penggabungan dan pengurutan
    cout << "Hasil setelah menggabungkan dan mengurutkan:" << endl;
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Keterangan untuk program 
// Fungsi mergeAndSort menerima dua vector: A (yang memiliki cukup ruang untuk menampung elemen dari B) dan B. Pertama, fungsi ini menggabungkan array B ke dalam array A menggunakan fungsi insert(). Kemudian, array A diurutkan menggunakan fungsi sort().Dalam main, dua sorted array A dan B diinisialisasi. Fungsi mergeAndSort kemudian dipanggil untuk menggabungkan dan mengurutkan array A dan B. Hasilnya kemudian ditampilkan.

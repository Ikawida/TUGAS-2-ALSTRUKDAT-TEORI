// 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan, "anagram" dan "tidak anagram" 

#include <iostream>
#include <algorithm> // Untuk menggunakan fungsi sort()
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk mengurutkan karakter dalam sebuah string
string sortString(string str) {
    sort(str.begin(), str.end()); // Mengurutkan karakter-karakter dalam string menggunakan fungsi sort dari library algorithm
    return str;
}

// Fungsi untuk memeriksa apakah dua string merupakan anagram atau tidak
string checkAnagram(vector<string>& str1, vector<string>& str2) {
    if (str1.size() != str2.size()) // Jika panjang kedua array tidak sama, maka tidak mungkin anagram
        return "tidak anagram";

    // Mengurutkan setiap string dalam kedua array
    for (int i = 0; i < str1.size(); ++i) {
        str1[i] = sortString(str1[i]);
        str2[i] = sortString(str2[i]);
    }

    // Membandingkan setiap string dari kedua array
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) // Jika ada setidaknya satu pasangan string yang tidak sama, maka tidak anagram
            return "tidak anagram";
    }

    // Jika semua pasangan string sama, maka anagram
    return "anagram";
}

int main() {
    vector<string> str1, str2;
    string input;

    // Memasukkan string-string dari pengguna untuk array pertama
    cout << "Masukkan string untuk array pertama (tekan Enter setelah setiap string, untuk berhenti ketik 'done'):" << endl;
    while (cin >> input && input != "done") {
        str1.push_back(input);
    }

    // Memasukkan string-string dari pengguna untuk array kedua
    cout << "Masukkan string untuk array kedua (tekan Enter setelah setiap string, untuk berhenti ketik 'done'):" << endl;
    while (cin >> input && input != "done") {
        str2.push_back(input);
    }

    string result = checkAnagram(str1, str2); // Memeriksa apakah kedua array adalah anagram
    cout << "Output: " << result << endl; // Menampilkan hasil keluaran

    return 0;
}

//keterangan untuk program 
// setelah program dijalankan, pengguna diminta untuk memasukkan string-string untuk array pertama dan array kedua secara bergantian. Ketika pengguna mengetikkan "done", proses memasukkan string akan berhenti, dan program akan memeriksa apakah kedua array tersebut adalah anagram atau tidak, dan hasilnya akan ditampilkan.

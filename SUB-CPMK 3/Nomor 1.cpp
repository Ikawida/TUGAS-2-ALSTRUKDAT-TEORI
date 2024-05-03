// 1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

// Penjelasan Struct
// struct adalah tipe data bentukan yang terdiri dari kumpulan tipe data lain. Struct mirip seperti array, tapi struct bisa menampung lebih dari 1 jenis tipe data. 
// Struct (singkatan dari "structure") adalah sebuah fitur dalam pemrograman yang memungkinkan pengguna untuk membuat tipe data baru yang terdiri dari beberapa tipe data lainnya yang disebut sebagai anggota atau field. Ini memungkinkan pengguna untuk menggabungkan beberapa tipe data yang berbeda ke dalam satu kesatuan yang lebih besar.

// Contoh Program Struct
#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struct untuk merepresentasikan informasi tentang seorang siswa
struct Student {
    string name;
    int age;
    float gpa;
};

int main() {
    // Mendeklarasikan variabel bertipe struct Student
    Student student1;

    // Mengisi data ke dalam variabel student1
    student1.name = "John";
    student1.age = 20;
    student1.gpa = 3.5;

    // Menampilkan informasi siswa
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "GPA: " << student1.gpa << endl;

    return 0;
}

// Program di atas mendefinisikan sebuah struct bernama "Student" yang memiliki tiga anggota: "name" (string), "age" (integer), dan "gpa" (float). Kemudian program membuat sebuah variabel dari tipe struct Student bernama "student1", mengisi nilainya, dan menampilkan informasinya.
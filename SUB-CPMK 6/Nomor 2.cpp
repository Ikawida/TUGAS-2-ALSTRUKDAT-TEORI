// 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat. 

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi hewan
struct Animal {
    string type; // Jenis hewan (kucing atau anjing)
    int arrivalTime; // Waktu kedatangan hewan ke selter

    // Konstruktor untuk inisialisasi hewan dengan jenis dan waktu kedatangan
    Animal(string _type, int _arrivalTime) : type(_type), arrivalTime(_arrivalTime) {}
};

// Struktur untuk menyimpan selter hewan terlantar
struct AnimalShelter {
    queue<Animal> catQueue; // Antrian untuk kucing
    queue<Animal> dogQueue; // Antrian untuk anjing
    int timeCounter; // Menghitung waktu kedatangan hewan

    // Konstruktor untuk inisialisasi selter
    AnimalShelter() {
        timeCounter = 0; // Atur hitungan waktu awal ke 0
    }

    // Method untuk mengadopsi hewan apa pun (kucing atau anjing) yang paling lama di selter
    Animal dequeueAny() {
        if (catQueue.empty() && dogQueue.empty()) {
            cout << "Tidak ada hewan yang tersedia untuk diadopsi.\n";
            return Animal("", -1); // Kembalikan hewan kosong jika tidak ada yang tersedia
        } else if (catQueue.empty()) {
            Animal oldestDog = dogQueue.front();
            dogQueue.pop();
            return oldestDog;
        } else if (dogQueue.empty()) {
            Animal oldestCat = catQueue.front();
            catQueue.pop();
            return oldestCat;
        } else {
            if (catQueue.front().arrivalTime < dogQueue.front().arrivalTime) {
                Animal oldestCat = catQueue.front();
                catQueue.pop();
                return oldestCat;
            } else {
                Animal oldestDog = dogQueue.front();
                dogQueue.pop();
                return oldestDog;
            }
        }
    }

    // Method untuk mengadopsi kucing tertua di selter
    Animal dequeueCat() {
        if (catQueue.empty()) {
            cout << "Tidak ada kucing yang tersedia untuk diadopsi.\n";
            return Animal("", -1); // Kembalikan hewan kosong jika tidak ada yang tersedia
        } else {
            Animal oldestCat = catQueue.front();
            catQueue.pop();
            return oldestCat;
        }
    }

    // Method untuk mengadopsi anjing tertua di selter
    Animal dequeueDog() {
        if (dogQueue.empty()) {
            cout << "Tidak ada anjing yang tersedia untuk diadopsi.\n";
            return Animal("", -1); // Kembalikan hewan kosong jika tidak ada yang tersedia
        } else {
            Animal oldestDog = dogQueue.front();
            dogQueue.pop();
            return oldestDog;
        }
    }

    // Method untuk menambahkan hewan ke dalam selter
    void enqueue(string type) {
        if (type == "kucing") {
            catQueue.push(Animal(type, timeCounter++));
        } else if (type == "anjing") {
            dogQueue.push(Animal(type, timeCounter++));
        } else {
            cout << "Hewan yang tidak dikenal.\n";
        }
    }
};

int main() {
    AnimalShelter shelter;

    // Tambahkan beberapa kucing dan anjing ke dalam selter
    shelter.enqueue("kucing");
    shelter.enqueue("anjing");
    shelter.enqueue("kucing");
    shelter.enqueue("anjing");

    // Adopsi hewan apa pun
    Animal adoptedAnimal = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adoptedAnimal.type << endl;

    // Adopsi kucing tertua
    Animal adoptedCat = shelter.dequeueCat();
    cout << "Kucing yang diadopsi: " << adoptedCat.type << endl;

    // Adopsi anjing tertua
    Animal adoptedDog = shelter.dequeueDog();
    cout << "Anjing yang diadopsi: " << adoptedDog.type << endl;

    return 0;
}

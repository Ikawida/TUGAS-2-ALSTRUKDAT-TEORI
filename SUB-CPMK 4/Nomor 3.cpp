// 3.Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    char data;   // Data yang disimpan dalam node (dalam contoh ini, diasumsikan sebagai char)
    Node* next; // Pointer ke node berikutnya dalam linked list

    // Konstruktor untuk membuat node baru dengan data tertentu
    Node(char data) : data(data), next(nullptr) {}
};

// Kelas LinkedList untuk merepresentasikan linked list
class LinkedList {
public:
    Node* head; // Pointer ke node pertama dalam linked list

    // Konstruktor untuk inisialisasi linked list dengan head yang kosong
    LinkedList() : head(nullptr) {}

    // Method untuk menambahkan node baru ke akhir linked list
    void append(char data) {
        Node* newNode = new Node(data); // Buat node baru dengan data yang diberikan
        if (!head) {
            head = newNode; // Jika linked list kosong, jadikan node baru sebagai head
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Temukan node terakhir dalam linked list
        }
        temp->next = newNode; // Tautkan node baru ke node terakhir
    }

    // Method untuk mencetak linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " "; // Cetak data dari setiap node
            temp = temp->next; // Pindahkan ke node berikutnya
        }
        cout << endl;
    }

    // Method untuk mengecek apakah linked list adalah sebuah palindrom
    bool isPalindrome() {
        if (!head) return true; // Jika linked list kosong, dianggap sebagai palindrom

        stack<char> s;
        Node* temp = head;

        // Masukkan semua elemen linked list ke dalam stack
        while (temp) {
            s.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        // Bandingkan elemen linked list dengan elemen yang diambil dari stack
        while (temp) {
            char top = s.top();
            s.pop();
            if (temp->data != top) return false;
            temp = temp->next;
        }

        return true;
    }
};

// Fungsi utama
int main() {
    LinkedList llist; // Buat objek dari kelas LinkedList

    string word;
    cout << "Masukkan sebuah kata: ";
    cin >> word;

    // Tambahkan setiap karakter kata ke dalam linked list
    for (char c : word) {
        llist.append(c);
    }

    // Cetak linked list
    cout << "Linked List: ";
    llist.printList();

    // Cek apakah kata adalah sebuah palindrom
    if (llist.isPalindrome()) {
        cout << "Kata \"" << word << "\" adalah sebuah palindrom.\n";
    } else {
        cout << "Kata \"" << word << "\" bukan sebuah palindrom.\n";
    }

    return 0;
}



// 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

// Algoritma 

// Berikut adalah algoritma secara ringkas untuk menghapus node di tengah single linked list:

// 1. Inisialisasi dua pointer, `slowPtr` dan `fastPtr`, di mana `slowPtr` bergerak satu langkah setiap iterasi dan `fastPtr` bergerak dua langkah.
// 2. Iterasi melalui linked list menggunakan kedua pointer tersebut untuk menemukan node tengah.
// 3. Simpan node sebelum node tengah dalam variabel `prevNode`.
// 4. Setelah menemukan node tengah, ubah pointer next dari `prevNode` sehingga menunjuk ke node setelah node yang akan dihapus.
// 5. Bebaskan memori yang dialokasikan untuk node yang dihapus.
// 6. Jika tidak ada node sebelum node tengah, maka node tengah adalah head, sehingga head harus diubah.
// 7. Algoritma selesai.

// Fungsi Program 

#include <iostream>

using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    int data;   // Data yang disimpan dalam node
    Node* next; // Pointer ke node berikutnya dalam linked list

    // Konstruktor untuk membuat node baru dengan data tertentu
    Node(int data) : data(data), next(nullptr) {}
};

// Kelas LinkedList untuk merepresentasikan linked list
class LinkedList {
public:
    Node* head; // Pointer ke node pertama dalam linked list

    // Konstruktor untuk inisialisasi linked list dengan head yang kosong
    LinkedList() : head(nullptr) {}

    // Method untuk menambahkan node baru ke akhir linked list
    void append(int data) {
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

    // Method untuk menghapus node tengah dari linked list
    void deleteMiddleNode() {
        if (!head || !head->next) {
            cout << "Linked list kosong atau hanya berisi satu node.\n";
            return;
        }

        Node* slowPtr = head; // Pointer yang bergerak satu langkah setiap kali
        Node* fastPtr = head; // Pointer yang bergerak dua langkah setiap kali
        Node* prevNode = nullptr; // Node sebelum node yang akan dihapus

        // Loop untuk menemukan node tengah
        while (fastPtr && fastPtr->next) {
            prevNode = slowPtr;
            slowPtr = slowPtr->next; // Pindahkan slowPtr satu langkah
            fastPtr = fastPtr->next->next; // Pindahkan fastPtr dua langkah
        }

        // Menghapus node tengah dari linked list
        if (prevNode) {
            prevNode->next = slowPtr->next; // Tautkan node sebelumnya langsung ke node setelah node yang akan dihapus
        } else {
            head = slowPtr->next; // Jika prevNode masih kosong, artinya node yang akan dihapus adalah head
        }

        delete slowPtr; // Bebaskan memori yang ditempati oleh node yang dihapus
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
};

// Fungsi utama
int main() {
    LinkedList llist; // Buat objek dari kelas LinkedList

    // Tambahkan beberapa node ke dalam linked list
    llist.append(1);
    llist.append(2);
    llist.append(3);
    llist.append(4);
    llist.append(5);

    // Cetak linked list sebelum penghapusan
    cout << "Linked List sebelum penghapusan:\n";
    llist.printList();

    // Panggil method untuk menghapus node tengah
    llist.deleteMiddleNode();

    // Cetak linked list setelah penghapusan
    cout << "Linked List setelah penghapusan:\n";
    llist.printList();

    return 0;
}

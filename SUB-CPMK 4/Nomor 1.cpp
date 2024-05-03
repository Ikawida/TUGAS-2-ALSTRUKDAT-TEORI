// 1. Program di atas mendefinisikan sebuah struct bernama "Student" yang memiliki tiga anggota: "name" (string), "age" (integer), dan "gpa" (float). Kemudian program membuat sebuah variabel dari tipe struct Student bernama "student1", mengisi nilainya, dan menampilkan informasinya.

#include <iostream>
#include <unordered_set>
using namespace std;

// Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menghapus duplikasi data pada linked list
void removeDuplicates(Node* head) {
    // Jika linked list kosong atau hanya memiliki satu elemen, langsung kembali
    if (head == nullptr || head->next == nullptr) 
        return;
    
    // Menggunakan unordered_set untuk menyimpan nilai yang telah ditemui
    unordered_set<int> seen;
    
    // Pointer untuk menelusuri linked list
    Node* curr = head;
    Node* prev = nullptr;
    
    // Melakukan iterasi pada linked list
    while (curr != nullptr) {
        // Jika nilai sudah ada dalam set, hapus node tersebut
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // Jika nilai belum ditemui, tambahkan ke set dan lanjutkan
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

// Fungsi untuk menambahkan node baru ke linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi main untuk menguji linked list
int main() {
    Node* head = nullptr;
    
    // Menambahkan elemen ke linked list
    push(&head, 10);
    push(&head, 20);
    push(&head, 10);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    
    cout << "Linked list sebelum menghapus duplikasi: ";
    printList(head);
    
    // Menghapus duplikasi
    removeDuplicates(head);
    
    cout << "Linked list setelah menghapus duplikasi: ";
    printList(head);
    
    return 0;
}

// Pada program di atas, fungsi removeDuplicates akan menghapus duplikasi dari linked list yang diberikan dengan menggunakan sebuah unordered_set untuk melacak nilai yang sudah ada. Fungsi push digunakan untuk menambahkan elemen ke linked list, dan fungsi printList digunakan untuk mencetak isi linked list. Fungsi main digunakan untuk menguji program dengan membuat linked list dan menghapus duplikasinya.
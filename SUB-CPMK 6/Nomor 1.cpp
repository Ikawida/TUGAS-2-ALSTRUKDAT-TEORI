// 1.Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Struktur data untuk queue
typedef struct {
    int data[MAX_SIZE];
    int depan;
    int belakang;
} Antrian;

// Fungsi untuk menginisialisasi queue
void inisialisasiAntrian(Antrian *q) {
    // Mengatur posisi depan dan belakang queue menjadi 0
    q->depan = 0;
    q->belakang = 0;
}

// Fungsi untuk mengecek apakah queue kosong
int kosong(Antrian *q) {
    // Queue kosong jika posisi depan dan belakang sama
    return q->depan == q->belakang;
}

// Fungsi untuk mengecek apakah queue penuh
int penuh(Antrian *q) {
    // Queue penuh jika posisi belakang queue + 1 sama dengan posisi depan queue
    return (q->belakang + 1) % MAX_SIZE == q->depan;
}

// Fungsi untuk menambahkan elemen ke queue
void tambah(Antrian *q, int nilai) {
    // Jika queue penuh, tidak dapat menambahkan elemen
    if (penuh(q)) {
        printf("Antrian penuh. Tidak dapat menambahkan.\n");
        return;
    }
    // Menambahkan elemen ke posisi belakang queue
    q->data[q->belakang] = nilai;
    // Meningkatkan posisi belakang queue
    q->belakang = (q->belakang + 1) % MAX_SIZE;
}

// Fungsi untuk menghapus elemen dari queue
int hapus(Antrian *q) {
    // Jika queue kosong, tidak dapat menghapus elemen
    if (kosong(q)) {
        printf("Antrian kosong. Tidak dapat menghapus.\n");
        return -1;
    }
    // Menghapus elemen di posisi depan queue
    int nilai = q->data[q->depan];
    // Meningkatkan posisi depan queue
    q->depan = (q->depan + 1) % MAX_SIZE;
    return nilai;
}

// Fungsi untuk melihat elemen terdepan di queue
int lihatDepan(Antrian *q) {
    // Jika queue kosong, tidak dapat melihat elemen terdepan
    if (kosong(q)) {
        printf("Antrian kosong. Tidak dapat melihat.\n");
        return -1;
    }
    // Mengembalikan elemen terdepan di queue
    return q->data[q->depan];
}

// Fungsi utama
int main() {
    // Membuat queue
    Antrian q;
    // Menginisialisasi queue
    inisialisasiAntrian(&q);

    // Menambahkan elemen ke queue
    tambah(&q, 1);
    tambah(&q, 2);
    tambah(&q, 3);
    tambah(&q, 4);
    tambah(&q, 5);

    // Menampilkan isi queue
    printf("Antrian: ");
    while (!kosong(&q)) {
        printf("%d ", hapus(&q));
    }
    printf("\n");

    return 0;
}

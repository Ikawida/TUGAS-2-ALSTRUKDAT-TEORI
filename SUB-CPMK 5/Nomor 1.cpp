// 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Struktur data untuk stack
typedef struct {
    int data[MAX_SIZE];
    int atas;
} Tumpukan;

// Fungsi untuk menginisialisasi stack
void inisialisasiTumpukan(Tumpukan *s) {
    s->atas = -1;
}

// Fungsi untuk mengecek apakah stack kosong
int kosong(Tumpukan *s) {
    return s->atas == -1;
}

// Fungsi untuk mengecek apakah stack penuh
int penuh(Tumpukan *s) {
    return s->atas == MAX_SIZE - 1;
}

// Fungsi untuk menambahkan elemen ke stack
void dorong(Tumpukan *s, int nilai) {
    if (penuh(s)) {
        printf("Tumpukan penuh. Tidak dapat mendorong.\n");
        return;
    }
    s->data[++s->atas] = nilai;
}

// Fungsi untuk menghapus elemen dari stack
int ambil(Tumpukan *s) {
    if (kosong(s)) {
        printf("Tumpukan kosong. Tidak dapat mengambil.\n");
        return -1;
    }
    return s->data[s->atas--];
}

// Fungsi untuk melihat elemen teratas di stack
int lihatAtas(Tumpukan *s) {
    if (kosong(s)) {
        printf("Tumpukan kosong. Tidak dapat melihat.\n");
        return -1;
    }
    return s->data[s->atas];
}

// Fungsi utama
int main() {
    Tumpukan s;
    inisialisasiTumpukan(&s);

    dorong(&s, 1);
    dorong(&s, 2);
    dorong(&s, 3);

    printf("Tumpukan: ");
    while (!kosong(&s)) {
        printf("%d ", ambil(&s));
    }
    printf("\n");

    return 0;
}

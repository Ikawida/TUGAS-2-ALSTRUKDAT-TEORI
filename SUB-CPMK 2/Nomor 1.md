1. Terdapat dua algoritma, searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari, best case dan worst case masing-masing algoritma!

Jawab: 

Berikut penjelasan singkat tentang algoritma Binary Search dan Linear Search, beserta runtime mereka dalam best case dan worst case:

1. **Binary Search**:
   - **Alur**: Binary Search bekerja dengan mencari elemen tengah dari array yang telah diurutkan dan membandingkannya dengan elemen yang ingin dicari. Jika elemen tengah sama dengan elemen yang dicari, pencarian selesai. Jika elemen tengah lebih besar dari elemen yang dicari, pencarian dilanjutkan di separuh kiri array. Jika elemen tengah lebih kecil dari elemen yang dicari, pencarian dilanjutkan di separuh kanan array. Proses ini diulangi hingga elemen ditemukan atau tidak ada lagi elemen yang tersisa untuk diperiksa.
   - **Runtime**:
     - **Best Case**: O(1) - Terjadi jika elemen yang dicari tepat berada di tengah array pada langkah pertama pencarian.
     - **Worst Case**: O(log n) - Terjadi jika elemen yang dicari tidak ada dalam array atau berada di ujung array sehingga pencarian harus melakukan logaritma basis 2 dari jumlah elemen array.

2. **Linear Search**:
   - **Alur**: Linear Search bekerja dengan memeriksa setiap elemen dalam array secara berurutan, mulai dari elemen pertama hingga elemen terakhir, untuk mencari elemen yang dicari.
   - **Runtime**:
     - **Best Case**: O(1) - Terjadi jika elemen yang dicari berada di posisi pertama array.
     - **Worst Case**: O(n) - Terjadi jika elemen yang dicari berada di posisi terakhir array atau tidak ada dalam array sehingga semua elemen harus diperiksa.

Jadi, Binary Search memiliki runtime yang lebih cepat dibandingkan Linear Search untuk kasus terbaik dan kasus terburuk, karena memanfaatkan sifat array yang telah diurutkan untuk memperkecil jumlah langkah yang diperlukan dalam pencarian.
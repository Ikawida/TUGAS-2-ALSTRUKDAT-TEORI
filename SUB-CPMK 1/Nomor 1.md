1. Terdapat tiga algoritma sorting yang umum digunakan yakni. Bubble Sort, Selection Sort, dan Merge Sort. Berikan, penjelasan alur dari masing-masing algoritma tersebut. dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

jawab: 

1. **Bubble Sort**:
   - Alur:
     - Bubble sort itu seperti mengurutkan kartu dari yang terkecil hingga yang terbesar. Algoritma ini membandingkan dua kartu berturut-turut dan jika yang di sebelah kiri lebih besar dari yang di sebelah kanan, mereka ditukar posisinya. Ini terus dilakukan sampai tidak ada lagi pertukaran yang diperlukan.
   - Kompleksitas Waktu:
     - **Best Case**: O(n), ketika kartu sudah terurut dari kecil ke besar.
     - **Worst Case**: O(n^2), ketika kartu-kartu tersebut dalam urutan yang terbalik total dan harus dipindahkan satu per satu.

2. **Selection Sort**:
   - Alur:
     - Selection sort itu seperti memilih angka terkecil dari kumpulan angka dan meletakkannya di posisi paling depan. Proses ini diulang dengan sisa angka yang belum terurut sampai semuanya terurut.
   - Kompleksitas Waktu:
     - **Best Case**: O(n^2), karena pada setiap langkah kita harus mencari angka terkecil dari sisa daftar.
     - **Worst Case**: O(n^2), karena tidak ada cara cepat untuk menyelesaikan proses pengurutan ini.

3. **Merge Sort**:
   - Alur:
     - Merge sort itu seperti memecah daftar menjadi potongan-potongan kecil, mengurutkan masing-masing potongan, lalu menggabungkannya kembali dengan cara yang terurut.
     - Proses ini terus dilakukan secara rekursif hingga seluruh daftar terurut.
   - Kompleksitas Waktu:
     - **Best Case**: O(n log n), karena meskipun kompleks, algoritma ini efisien dan berjalan dengan baik bahkan dalam kasus terbaiknya.
     - **Worst Case**: O(n log n), karena bahkan dalam situasi terburuk pun, algoritma ini tetap memiliki kinerja yang baik karena sifat divide and conquer-nya.

Jadi, sementara Bubble Sort dan Selection Sort sederhana untuk dipahami, Merge Sort cenderung lebih efisien dalam menangani jumlah data yang besar.

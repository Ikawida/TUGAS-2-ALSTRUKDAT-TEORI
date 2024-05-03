// 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. 

#include <iostream>
#include <stack>

using namespace std;

// Method untuk mensortir stack sehingga item dengan nilai terkecil menjadi top pada stack tersebut
void sortStack(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        // Ambil elemen teratas dari stack s
        int temp = s.top();
        s.pop();

        // Pindahkan elemen-elemen dari tempStack yang lebih besar dari temp kembali ke stack s
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        // Masukkan temp ke tempStack
        tempStack.push(temp);
    }

    // Salin elemen-elemen dari tempStack kembali ke stack s sehingga elemen dengan nilai terkecil berada di atas
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Method untuk menampilkan stack
void displayStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // Push beberapa elemen ke dalam stack
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Stack sebelum diurutkan: ";
    displayStack(s);

    // Mensortir stack
    sortStack(s);

    cout << "Stack setelah diurutkan: ";
    displayStack(s);

    return 0;
}

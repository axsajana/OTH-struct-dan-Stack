#include <stdio.h> // Library standar input-output
#include <string.h> // Library untuk manipulasi string
#include <stdlib.h> // Library untuk alokasi memori dinamis

#define MAX_SIZE 50 // Mendefinisikan ukuran maksimal stack

char bentuk_kurung[MAX_SIZE]; // Array untuk menyimpan tanda kurung
int top = -1; // Indeks puncak stack

// Fungsi untuk menentukan pasangan tanda kurung
int kurung(char karakter_kurung){
    switch (karakter_kurung){
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return 'X'; // Tanda kurung tidak valid
    }
}

// Fungsi untuk memeriksa apakah stack kosong
int isempty(){ //0
	if(top == -1)
		return 1;
	else
		return 0;
}

// Fungsi untuk memeriksa apakah stack penuh
int isfull(){
   if(top == MAX_SIZE-1)
      return 1;
   else
      return 0;
}

// Fungsi untuk melihat elemen puncak stack tanpa menghapusnya
char peek(){
   return bentuk_kurung[top];
}

// Fungsi untuk menghapus elemen dari stack
char pop(){
    char data;
    if(!seimpty()) {
        data = bentuk_kurung[top];
        top -= 1;
        return data;
        
    } else {
        printf("Stack Kosong.\n");
   }
}

// Fungsi untuk menambahkan elemen ke stack
void push(char data){
	if(!isfull()) {
		top += 1;
		bentuk_kurung[top] = data;
	} else {
		printf("Stack Penuh.\n");
	}
};

// Fungsi untuk memeriksa keseimbangan tanda kurung dalam string
int isBalanced(char kurung1[]){
    for(int i = 0; i < strlen(kurung1); i++){
        if(kurung1[i] == '(' || kurung1[i] == '{' || kurung1[i] == '[') {
            push(kurung1[i]); // Menambahkan tanda kurung buka ke stack

        } else if(kurung1[i] == ')' || kurung1[i] == '}' || kurung1[i] == ']') {
            if(isempty() || kurung(kurung1[i]) != peek()) { // Memeriksa pasangan tanda kurung
                printf("NO\n");
                return 0;
            } else {
                pop(); // Menghapus tanda kurung buka dari stack karena pasangan ditemukan
            }
        }
    }

    if(isempty()) {
        printf("YES\n"); // Semua tanda kurung memiliki pasangan
        return 1;
    } else {
        printf("NO\n"); // Ada tanda kurung yang tidak memiliki pasangan
        return 0;
    }
}

// Fungsi untuk memeriksa apakah input hanya terdiri dari tanda kurung
int cekInput(char kurung1[]){
    for(int i = 0; i < strlen(kurung1); i++){
        if(kurung1[i] != '(' && kurung1[i] != '{' && kurung1[i] != '[' && kurung1[i] != ')' && kurung1[i] != '}' && kurung1[i] != ']'){
            return 0; // Input mengandung karakter selain tanda kurung
        }
    }
    return 1; // Input hanya terdiri dari tanda kurung
}

// Fungsi utama program
int main(){
    char kurung1[MAX_SIZE]; // Array untuk menyimpan input tanda kurung

    printf("Masukkan Kurung: ");
    fgets(kurung1,50,stdin); // Membaca input dari pengguna
    kurung1[strcspn(kurung1, "\n")] = 0; // Menghilangkan newline dari input

    if(cekInput(kurung1)){
        isBalanced(kurung1); // Memeriksa keseimbangan tanda kurung
    } else {
        printf("Input tidak valid. Hanya menerima tanda kurung.\n"); // Input tidak valid
    }

    return 0; // Program selesai
}

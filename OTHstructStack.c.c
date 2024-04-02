#include <stdio.h>


// Mendefinisikan struct Batu untuk menyimpan abjad  
struct Batu {
    char abjad;  // Menyimpan huruf pada batu
    struct Batu *link;  // Pointer ke Batu berikutnya dalam urutan
};

int main() {
    // Inisialisasi batu sesuai dengan petunjuk
    struct Batu l1, l2, l3, l4, l5, l6, l7, l8, l9;

    l1.link = NULL;          
    l1.abjad = 'F';

    l2.link = NULL;
    l2.abjad = 'M';

    l3.link = NULL;
    l3.abjad = 'A';

    l4.link = NULL;
    l4.abjad = 'I';

    l5.link = NULL;
    l5.abjad = 'K';

    l6.link = NULL;
    l6.abjad = 'T';

    l7.link = NULL;
    l7.abjad = 'N';

    l8.link = NULL;
    l8.abjad = 'O';

    l9.link = NULL;
    l9.abjad = 'R';


    // Mengatur koneksi antar batu sesuai dengan urutan yang diberikan
    l7.link = &l1;
    l1.link = &l8;
    l8.link = &l2;
    l2.link = &l5;
    l5.link = &l3;
    l3.link = &l6;
    l6.link = &l9;
    l9.link = &l4;
    l4.link = &l7;


    // Mengakses huruf pada batu menggunakan l3 sebagai titik awal
    printf ("%c %c %c %c %c %c %c %c %c %c %c\n",
    l3.link->link->link->abjad, // Output: "I"
    l3.link->link->link->link->abjad,// Output: "N"
    l3.link->link->link->link->link->abjad, // Output: "F"
    l3.link->link->link->link->link->link->abjad, // Output: "O"
    l3.link->link->abjad, // Output: "R"
    l3.link->link->link->link->link->link->link->abjad, // Output: "M"
    l3.abjad, // Output: "A"
    l3.link->abjad, // Output: "T"
    l3.link->link->link->abjad, // Output: "I"
    l3.link->link->link->link->link->link->link->link->abjad, // Output: "K"
    l3.abjad // Output: "A"
    );
    return 0;
 }
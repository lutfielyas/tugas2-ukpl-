#include <iostream>

using namespace std;

// 1. Fungsi isWithinRange() digunakan untuk memeriksa apakah sebuah angka berada dalam rentang [min, max].
// Fungsi ini mengambil tiga parameter: number (angka yang akan diperiksa), min (batas bawah rentang),
// dan max (batas atas rentang). Fungsi ini mengembalikan true jika number berada dalam rentang [min, max], dan false jika tidak.
bool isWithinRange(int number, int min, int max) {
    return (number >= min) && (number <= max);
}

// 2. Fungsi testBoundaryValueAnalysis() digunakan untuk melakukan pengujian dengan teknik Boundary Value Analysis.
// Di dalam fungsi ini, kita mendefinisikan nilai batas bawah (min) dan batas atas (max) untuk rentang yang akan diuji.
void testBoundaryValueAnalysis() {
    int min = 10;
    int max = 20;

    // 3. Dalam pengujian BVA, kita menguji nilai-nilai di sekitar batas bawah dan batas atas rentang.
	// Pada bagian "Testing lower boundary values", kita menguji nilai min - 1 (di luar rentang),
	// min (batas bawah rentang), dan min + 1 (di dalam rentang).
    cout << "Testing Lower Boundary values:\n";
    cout << "Value " << min - 1 << ": " << (isWithinRange(min - 1, min, max) ? "Within Range" : "Outside Range") << endl;
    cout << "Value " << min << ": " << (isWithinRange(min, min, max) ? "Within Range" : "Outside Range") << endl;
    cout << "Value " << min + 1 << ": " << (isWithinRange(min + 1, min, max) ? "Within Range" : "Outside Range") << endl;

    // 4. Pada bagian "Testing upper boundary values", kita menguji nilai max - 1 (di dalam rentang),
	// max (batas atas rentang), dan max + 1 (di luar rentang).
    cout << "\nTesting Upper Boundary values:\n";
    cout << "Value " << max - 1 << ": " << (isWithinRange(max - 1, min, max) ? "Within Range" : "Outside Range") << endl;
    cout << "Value " << max << ": " << (isWithinRange(max, min, max) ? "Within Range" : "Outside Range") << endl;
    cout << "Value " << max + 1 << ": " << (isWithinRange(max + 1, min, max) ? "Within Range" : "Outside Range") << endl;
}

/// 5. Setiap nilai yang diuji dicetak ke layar, diikuti dengan hasil dari pemanggilan fungsi isWithinRange()
// untuk memeriksa apakah nilai tersebut berada dalam rentang yang diharapkan. Jika nilai berada dalam
// rentang, maka pesan "Within Range" akan ditampilkan. Jika tidak, pesan "Outside Range" akan ditampilkan.

// 6. Di dalam fungsi main(), kita memanggil testBoundaryValueAnalysis()
// untuk menjalankan pengujian dengan teknik BVA.
int main() {
    testBoundaryValueAnalysis();
    return 0;
}

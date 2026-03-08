#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Procedure untuk menghitung nilai akhir
void nilai_akhir(
    float presensi,
    float keaktifan,
    float tugas,
    float uts,
    float uas,
    float& nilaiakhir) {

    nilaiakhir = (presensi * 0.1) +
                 (keaktifan * 0.15) +
                 (tugas * 0.2) +
                 (uts * 0.25) +
                 (uas * 0.3);
}

void konversiKeIPK(float nilaiakhir, float& ipk, string& grade) {

    if (nilaiakhir >= 85) {
        ipk = 3.5 + ((nilaiakhir - 85) / 15.0) * 0.5;
        grade = "A";
    }
    else if (nilaiakhir >= 80) {
        ipk = 3.0 + ((nilaiakhir - 80) / 5.0) * 0.5;
        grade = "AB";
    }
    else if (nilaiakhir >= 75) {
        ipk = 2.5 + ((nilaiakhir - 75) / 5.0) * 0.5;
        grade = "B";
    }
    else if (nilaiakhir >= 70) {
        ipk = 2.0 + ((nilaiakhir - 70) / 5.0) * 0.5;
        grade = "BC";
    }
    else if (nilaiakhir >= 65) {
        ipk = 1.5 + ((nilaiakhir - 65) / 5.0) * 0.5;
        grade = "C";
    }
    else if (nilaiakhir >= 60) {
        ipk = 1.0 + ((nilaiakhir - 60) / 5.0) * 0.5;
        grade = "D";
    }
    else {
        ipk = 0.0;
        grade = "E";
    }
}
// Procedure untuk menampilkan hasil
void hasil(string nama, string matkul, float nilaiakhir, float ipk, string grade) {

    cout << fixed << setprecision(2);

    cout << "\n=== HASIL ===" << endl;
    cout << "Nama           : " << nama << endl;
    cout << "Mata Kuliah    : " << matkul << endl;
    cout << "Nilai Akhir    : " << nilaiakhir << endl;
    cout << "IPK            : " << ipk << endl;
    cout << "Grade          : " << grade << endl;

    if (ipk >= 3.50)
        cout << "Keterangan     : Cumlaude" << endl;
    else if (ipk >= 3.00)
        cout << "Keterangan     : Sangat Memuaskan" << endl;
    else if (ipk >= 2.50)
        cout << "Keterangan     : Memuaskan" << endl;
    else
        cout << "Keterangan     : Perlu Peningkatan" << endl;
}

int main() {
    string nama, matkul, grade;
    float presensi, keaktifan, tugas, uts, uas;
    float nilaiakhir, ipk;

    cout << "=== Sistem Penilaian Mahasiswa Sederhana ===\n"
            "Masukkan nama mahasiswa: ";
    getline(cin, nama);

    cout << "Masukkan Mata Kuliah: ";
    getline(cin, matkul);

    cout << "1. Nilai Presensi " << matkul << " : ";
    cin >> presensi;
    cout << "2. Nilai Keaktifan " << matkul << " : ";
    cin >> keaktifan;
    cout << "3. Nilai Tugas " << matkul << " : ";
    cin >> tugas;
    cout << "4. Nilai UTS " << matkul << " : ";
    cin >> uts;
    cout << "5. Nilai UAS " << matkul << " : ";
    cin >> uas;

    nilai_akhir(presensi, keaktifan, tugas, uts, uas, nilaiakhir);
    konversiKeIPK(nilaiakhir, ipk, grade);
    hasil(nama, matkul, nilaiakhir, ipk, grade);

    return 0;
}

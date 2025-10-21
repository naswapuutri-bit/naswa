#include <iostream>
using namespace std;

struct Siswa {
    string nisn, nama, kelas;
    float mat, bind, bing, ipa, rata;
};

int main() {
    int n;
    cout << "Jumlah siswa: ";
    cin >> n;

    Siswa s[100];

    for (int i = 0; i < n; i++) {
        cout << "\nData siswa ke-" << i + 1 << endl;
        cout << "NISN: ";
        cin >> s[i].nisn;
        cout << "Nama: ";
        cin >> s[i].nama;
        cout << "Kelas: ";
        cin >> s[i].kelas;
        cout << "Nilai Matematika: ";
        cin >> s[i].mat;
        cout << "Nilai B. Indonesia: ";
        cin >> s[i].bind;
        cout << "Nilai B. Inggris: ";
        cin >> s[i].bing;
        cout << "Nilai IPA: ";
        cin >> s[i].ipa;

        s[i].rata = (s[i].mat + s[i].bind + s[i].bing + s[i].ipa) / 4;
    }

    float totalMat = 0, totalBind = 0, totalBing = 0, totalIpa = 0;
    for (int i = 0; i < n; i++) {
        totalMat += s[i].mat;
        totalBind += s[i].bind;
        totalBing += s[i].bing;
        totalIpa += s[i].ipa;
    }

    cout << "\nRata-rata kelas:\n";
    cout << "Matematika       : " << totalMat / n << endl;
    cout << "B. Indonesia     : " << totalBind / n << endl;
    cout << "B. Inggris       : " << totalBing / n << endl;
    cout << "IPA              : " << totalIpa / n << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].rata < s[j].rata) {
                Siswa t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }

    cout << "\nPeringkat siswa berdasarkan rata-rata:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << s[i].nama 
             << " (" << s[i].kelas << ") - " 
             << s[i].rata << endl;
    }

    return 0;
}	
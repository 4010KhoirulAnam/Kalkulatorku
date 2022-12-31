#include <iostream>

using namespace std;

int main()
{
    int n, astg, tstg, lstg, rmbupin, rmbipin, A, B, cicilan, persen, hrgpanci;

    cout << "-------- NO 1 --------" <<endl;
    cout << "Masukkan nilai n : ";cin >>n;

        for (int i = 0; i < n; i++)
        {
            cout << "UDINUS" << endl;
        }

    cout << "-------- NO 2 --------" <<endl;
    cout << "Input alas segitiga  : ";cin>>astg;
    cout << "Input tinggi segitiga  : ";cin>>tstg;
    lstg=astg*tstg/2;
    cout << "Luas segitiga sama kaki  :"<<lstg<<endl;

    cout << "-------- NO 3 --------" <<endl;
    cout << "Jumlah rambutan Upin : ";cin >>rmbupin;
    cout << "Jumlah rambutan Ipin : ";cin >>rmbipin;
        if (rmbupin > rmbipin)
        {
            cout << "Rambutan Opah : " <<rmbupin<< endl;
            cout << "Rambutan Kak Ros : " <<rmbipin<< endl;
        }
        else if (rmbupin < rmbipin)
        {
            cout << "Rambutan Opah : " <<rmbipin<< endl;
            cout << "Rambutan Kak Ros : " <<rmbupin<< endl;
        }
        else
        {
            cout << "jumlah tidak diketahui" << endl;
        }

    cout << "-------- NO 4 --------" <<endl;
    cout << "Masukkan nilai awal : ";cin >>A;
    cout << "Masukkan batas : ";cin >>B;
        for (int i = A; i < B; i++)
        {
            if (i % 5 == 0)
            {
                cout << i << "";
            }
        }
    cout <<endl;

    cout << "-------- NO 5 --------" <<endl;
    cout << "Masukkan total biaya cicilan : ";cin >> cicilan;
    cout << "Masukkan angsuran yang sudah terbayarkan (%): ";cin>>persen;
    hrgpanci=cicilan / (persen/10) * 10;
    cout << "Harga awal panci adalah : "<<hrgpanci<<endl;


    return 0;
}

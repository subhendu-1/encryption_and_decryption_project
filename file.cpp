#include <bits/stdc++.h>
#include <fstream>
#include <dos.h>
using namespace std;
class project
{
    int key;
    string file = "file.txt";
    char c;

public:
    void encrypt();
    void decrypt();
};

void project::encrypt()
{
    cout << "key: ";
    cin >> key;
    fstream fin, fout;
    fin.open(file, fstream::in);
    fout.open("encrypt.txt", fstream::out);
    while (fin >> noskipws >> c)
    {
        int temp = (c + key);
        fout << (char)temp;
    }
    fin.close();
    fout.close();
}

void project::decrypt()
{
    cout << "key: ";
    cin >> key;
    fstream fin;
    fstream fout;
    fin.open("encrypt.txt", fstream::in);
    fout.open("decrypt.txt", fstream::out);

    while (fin >> noskipws >> c)
    {
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}
int main()
{
    project file;
    char c;
    cout<<endl;
    cout << "Enter Your Choice : ->" << endl;
    cout << "1. for encryption " << endl;
    cout << "2. for decryption " << endl;
    cin >> c;
    cin.ignore();

    switch (c)
    {
    case '1':
    {
        file.encrypt();
        break;
    }
    case '2':
    {
        file.decrypt();
        break;
    }
    }
}

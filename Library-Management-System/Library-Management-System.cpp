#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <Windows.h>

// class Book dan Student
class Book
{
private :
    char bookNumber[6]; // Nomor buku
    char bookTitle[50]; // Judul buku
    char author[20]; // Penulis

public :
    // Menambahkan data buku
    void createBook()
    {
        std::cout << "\nENTRI BUKU BARU\n";
        std::cout << "\nMasukkan nomor buku : ";
        std::cin >> bookNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nMasukkan judul buku : ";
        std::cin.getline(bookTitle, 50);
        std::cout << "\nMasukkan nama penulis : ";
        std::cin.getline(author, 20);
        std::cout << "\n\n\nBook created..";
    }

    // Menampilkan data buku
    void showBook()
    {
        std::cout << "\nNomor buku : " << bookNumber;
        std::cout << "\nJudul buku : ";
        puts(bookTitle);
        std::cout << "\nPenulis : ";
        puts(author);
    }

    // Merubah data buku
    void modifyBook()
    {
        std::cout << "\nNomor buku : " << bookNumber;
        std::cout << "\nRubah judul buku : ";
        std::cin.getline(bookTitle, 50);
        std::cout << "\nRubah nama penulis : ";
        std::cin.getline(author, 50);
        std::cout << "\n\n\nBook modified..";
    }

    // Menampilkan hasil dari function modifyBook();
    void report()
    {
        std::cout << "\n" << bookNumber << "\t|\t" << bookTitle << "\t|\t" << author << std::endl;
    }

    // Mengembalikan (nilai) nomor buku
    char* returnBookNumber()
    {
        return bookNumber;
    }
};

class Student
{
private :
    char nim[9];
    char studentName[20];
    char studentBookingNumber[6]; // Nomor pemesanan buku
    int totalBook; // Total buku

public :
    // Menambahkan data mahasiswa
    void createStudent()
    {
        system("cls");
        std::cout << "\nENTRI MAHASISWA\n";
        std::cout << "\nMasukkan NIM mahasiswa : ";
        std::cin >> nim;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Masukkan nama mahasiswa : ";
        std::cin.getline(studentName, 20);
        totalBook = 0;
        studentBookingNumber[0] = '\0';
        std::cout << "\n\n\nStudent record created...";
    }

    // Menampilkan data mahasiswa
    void showStudent()
    {
        std::cout << "\nNIM : " << nim;
        std::cout << "\nNama mahasiswa : ";
        puts(studentName);
        std::cout << "\nTotal buku yang dipinjam : " << totalBook;
        if (totalBook == 1)
        {
            std::cout << "\nNomor buku : " << studentBookingNumber;
        }
    }

    // Merubah data mahasiswa
    void modifyStudent()
    {
        std::cout << "\nRubah NIM mahasiswa : " << nim;
        std::cout << "\nRubah nama mahasiswa : ";
        std::cin.getline(studentName, 20);
    }

    // Mengembalikan (nilai) NIM
    char* returnNim()
    {
        return nim;
    }

    // Mengembalikan (nilai) nomor pemesanan buku
    char* returnStudentBookingNum()
    {
        return studentBookingNumber;
    }

    // Mengembalikan (nilai) total buku
    int returnTotalBook()
    {
        return totalBook;
    }

    // Menambahkan buku
    void addTotalBook()
    {
        totalBook = 1;
    }

    // Reset total buku
    void resetTotalBook()
    {
        totalBook = 0;
    }

    // 
    void getStudentBookNum(char t[])
    {
        //strcpy(studentBookingNumber, t);
    }

    // Laporan 
    void report()
    {
        std::cout << "\n" << nim << "\t|\t" << studentName << "\t|\t" << totalBook << std::endl;
    }
};

std::fstream data, data1; // Object data
Book buku; // Object buku dari class Book
Student mahasiswa; // Object mahasiswa dari class Student

// Deklarasi function
void gotoxy(int x, int y);
void writeBook();
void writeStudent();
void displayBook(char n[]);
void displayStudent(char n[]);
void modifyBook();
void modifyStudent();
void deleteBook();
void deleteStudent();
void displayAllBooks();
void displayAllStudents();
void start();

//                                                        ========== MAIN FUNCTION ==========
int main()
{
    writeBook();
    writeStudent();
}

// Inisialisasi function
// Font gotoxy
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// WRITE DATA
void writeBook()
{
    char ch;
    data.open("book.dat", std::ios::out | std::ios::app); // Membuka data
    do {
        system("cls");
        buku.createBook();
        data.write((char*)&buku, sizeof(Book)); // Menulis dan menambahkan data, size class
        std::cout << "\n\nApakah mau menambahkan data buku lagi? (y/n) ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    data.close();
}

void writeStudent()
{
    char ch;
    data.open("student.dat", std::ios::out || std::ios::app);
    do {
        system("cls");
        mahasiswa.createStudent();
        data.write((char*)&mahasiswa, sizeof(Student));
        std::cout << "\n\nApakah mau menambahkan data mahasiswa lagi? (y/n) ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    data.close();
}

// DISPLAY DATA
void displayBook(char n[])
{
    int flag = 0; // Buku tidak ditemukan
    std::cout << "\nDETAIL BUKU\n";
    data.open("book.dat", std::ios::in); // Membuka data
    while (data.read((char*)&buku, sizeof(Book))) // Membaca data
    {
        if (_strcmpi(buku.returnBookNumber(), n) == 0)
        {
            buku.showBook();
            flag = 1;
        }
    }
    data.close();
    if (flag == 0)
    {
        std::cout << "\n\nBuku tidak tersedia";
    }
    _getch(); // Press key to get out
}

void displayStudent(char n[])
{
    int flag = 0;
    std::cout << "\nDETAIL MAHASISWA\n";
    data.open("student.dat", std::ios::in); // Membuka data
    while (data.read((char*)&mahasiswa, sizeof(Student))) // Membaca data
    {
        if (_strcmpi(mahasiswa.returnNim(), n) == 0)
        {
            mahasiswa.showStudent();
            flag == 1;
        }
    }
    data.close();
    if (flag == 0)
    {
        std::cout << "\n\nMahasiswa tidak ada, harus menambahkan mahasiswa terlebih dahulu";
    }
    _getch(); // Press key to get out
}

// MODIFY DATA
void modifyBook()
{
    char n[6];
    int found = 0;
    system("cls");
    std::cout << "\n\nEDIT BUKU\n\n";
    std::cout << "Masukkan nomor buku : ";
    std::cin >> n;
    data.open("book.dat", std::ios::in | std::ios::out);
    while (data.read((char*)&buku, sizeof(Book)) && found == 0)
    {
        if (_strcmpi(buku.returnBookNumber(), n) == 0)
        {
            buku.showBook();
            std::cout << "\nMasukkan detail baru buku";
            buku.modifyBook();
            int pos = -1 * sizeof(buku);
            data.seekp(pos, std::ios::cur);
            data.write((char*)&buku, sizeof(Book));
            std::cout << "\n\n\nRecord updated!";
            found = 1;
        }
    }
    data.close();
    if (found == 0)
    {
        std::cout << "\n\nData tidak ditemukan, buat data terlebih dahulu";
    }
    _getch(); // Press key to get out
}

void modifyStudent()
{
    char n[9];
    int found = 0;
    system("cls");
    std::cout << "\n\nEDIT DATA MAHASISWA\n\n";
    std::cout << "Masukkan NIM mahasiswa : ";
    std::cin >> n;
    data.open("student.dat", std::ios::in | std::ios::out);
    while (data.read((char*)&mahasiswa, sizeof(Student)) && found == 0)
    {
        if (_strcmpi(mahasiswa.returnNim(), n) == 0)
        {
            mahasiswa.showStudent();
            std::cout << "\nMasukkan detail mahasiswa baru : ";
            mahasiswa.modifyStudent();
            int pos = -1 * sizeof(mahasiswa);
            data.seekp(pos, std::ios::cur); // Back from the current position
            data.write((char*)&mahasiswa, sizeof(Student));
            std::cout << "\n\nRecord updated!";
            found = 1;
        }
    }
    data.close();
    if (found == 0)
    {
        std::cout << "\n\nData tidak ditemukan, buat data terlebih dahulu";
    }
    _getch(); // Press key to get out
}

// DELETE DATA
void deleteBook()
{
    char n[6];
    int flag = 0;
    system("cls");
    std::cout << "\n\n\n\tHAPUS BUKU";
    std::cout << "\n\nMasukkan nomor buku : ";
    std::cin >> n;
    data.open("book.dat", std::ios::in | std::ios::out);
    std::fstream data2; // Object baru
    data2.open("temp.dat", std::ios::out);
    data.seekg(0, std::ios::beg);
    while (data.read((char*)&buku, sizeof(Book)))
    {
        if (_strcmpi(buku.returnBookNumber(), n) != 0)
        {
            data2.write((char*)&mahasiswa, sizeof(Book));
        }
        else
        {
            flag = 1; // Data mahasiswa ditemukan
        }
    }
    data2.close();
    data.close();
    remove("book.dat");
    rename("temp.dat", "book.dat"); // Data setelah dihapus dipindah ke temp.dat
    if (flag == 1)
    {
        std::cout << "\n\n\tRecord deleted...";
    }
    else
    {
        std::cout << "\n\nData tidak ditemukan";
    }
    _getch();
}

void deleteStudent()
{
    char n[9];
    int flag = 0;
    system("cls"); // Clear screen
    std::cout << "\n\n\n\tHAPUS DATA MAHASISWA";
    std::cout << "\n\nMasukkan NIM mahasiswa : ";
    std::cin >> n;
    data.open("student.dat", std::ios::in | std::ios::out);
    std::fstream data2;
    data2.open("temp.dat", std::ios::out);
    data.seekg(0, std::ios::beg);
    while (data.read((char*)&mahasiswa, sizeof(Student)))
    {
        if (_strcmpi(mahasiswa.returnNim(), n) != 0)
        {
            data2.write((char*)&mahasiswa, sizeof(Student));
        }
        else
        {
            flag = 1; // Data mahasiswa ditemukan
        }
    }
    data2.close();
    data.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    if (flag == 1)
    {
        std::cout << "\n\n\tRecord deleted...";
    }
    else
    {
        std::cout << "\n\nData tidak ditemukan";
    }
    _getch();
}

// DISPLAY ALL DATA
void displayAllBooks()
{
    system("cls"); // Clear screen
    data.open("book.dat", std::ios::in); // Buka file book.dat
    if (!data)
    {
        std::cout << "File tidak bisa dibuka";
        _getch();
        return; // Press any key and return
    }
    std::cout << "\n\n\t\tLIST BUKU\n\n";
    std::cout << "==================================================================\n";
    std::cout << "No. Buku" << "\t|\t" << "Judul Buku" << "\t|\t" << "Penulis" << std::endl;
    std::cout << "==================================================================\n";
    while (data.read((char*)&buku, sizeof(Book)))
    {
        buku.report();
    }
    data.close();
    _getch();
}

void displayAllStudents()
{
    system("cls"); // Clear screen
    data.open("student.dat", std::ios::in); // Buka file student.dat
    if (!data)
    {
        std::cout << "File tidak bisa dibuka";
        _getch();
        return; // Press any key and return
    }
    std::cout << "\n\n\t\tDATA MAHASISWA\n\n";
    std::cout << "==================================================================\n";
    std::cout << "NIM" << "\t|\t" << "Nama Mahasiswa" << "\t|\t" << "Buku yang Dipinjam" << std::endl;
    std::cout << "==================================================================\n";
    while (data.read((char*)&mahasiswa, sizeof(Student)))
    {
        mahasiswa.report();
    }
    data.close();
    _getch();
}

// PEMINJAMAN BUKU
void bookIssue()
{
    char sn[9], bn[6]; // sn = studentNo(nomor mahasiswa) , bn = bookNo(nomor buku)
    int found = 0, flag = 0;
    system("cls");
    std::cout << "\n\nPEMINJAMAN BUKU";
    std::cout << "\n\n\tMasukkan NIM mahasiswa : ";
    std::cin >> sn;
    data.open("student.dat", std::ios::in | std::ios::out);
    data1.open("book.dat", std::ios::in | std::ios::out);
    while (data.read((char*)&mahasiswa, sizeof(Student)) && found == 0)
    {
        if (_strcmpi(mahasiswa.returnNim(), sn) == 0) // Compare NIM
        {
            found == 1;
            if (mahasiswa.returnTotalBook() == 0) // Jika buku belum dipinjam
            {
                std::cout << "\n\n\tMasukkan nomor buku : ";
                std::cin >> bn;
                while (data1.read((char*)&buku, sizeof(Book)) && flag == 0)
                {
                    if (_strcmpi(buku.returnBookNumber(), bn) == 0) // Compare book number
                    {
                        flag = 1;
                        mahasiswa.addTotalBook();
                        mahasiswa.getStudentBookNum(buku.returnBookNumber());
                        int pos = -1 * sizeof(mahasiswa);
                        data.seekg(pos, std::ios::cur);
                        data.write((char*)&mahasiswa, sizeof(Student));
                        std::cout << "\n\n\tBuku sukses dipinjam!\n\n Mohon catat bahwa tanggal peminjaman buku tertulis di bagian belakang buku dan kembalikan buku dalam 15 hari.\nTerima Kasih!";
                    }
                }
                if (flag == 0)
                {
                    std::cout << "Buku tidak ditemukan";
                }
            }
            else
            {
                std::cout << "Anda belum mengembalikan buku yang anda pinjam sebelumnya.";
            }
        }
    }
    if (found == 0)
    {
        std::cout << "Data mahasiswa tidak ada";
    }
    _getch();
    data.close();
    data1.close();
}

// Memulai program
void start()
{
    system("cls");
    gotoxy(35, 11);
}

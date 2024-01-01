#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>

// class Book dan Student
class Book
{
private:
    char bookNumber[6]; // Nomor buku
    char bookTitle[50]; // Judul buku
    char author[20]; // Penulis

public:
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
    char *returnBookNumber()
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
    char *returnNim()
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
void writeBook();
void writeStudent();
void displayBook(char n[]);
void displayStudent(char n[]);

//          ----- MAIN FUNCTION -----
int main()
{
    writeBook();
    writeStudent();
    displayBook(n[]);
    displayStudent(n[]);
}

// Inisialisasi function
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
    while (data.read((char *)&buku, sizeof(Book))) // Membaca data
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
    _getch();
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
    _getch();
}

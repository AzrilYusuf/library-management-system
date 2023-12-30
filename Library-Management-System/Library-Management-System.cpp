#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>

class Book
{
private:
    int bookNumber;
    char bookName[50];
    char author[20]; // Penulis

public:
    // Menambahkan buku
    void createBook()
    {
        std::cout << "\nENTRI BUKU BARU\n";
        std::cout << "\nMasukkan nomor buku : ";
        std::cin >> bookNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nMasukkan nama buku : ";
        std::cin.getline(bookName, 50);
        std::cout << "\nMasukkan nama penulis : ";
        std::cin.getline(author, 20);
        std::cout << "\n\n\nBook created..";
    }

    // Menampilkan buku
    void showBook()
    {
        std::cout << "\nNomor buku : " << bookNumber;
        std::cout << "\nNama buku : ";
        puts(bookName);
        std::cout << "\nPenulis : ";
        puts(author);
    }

    // Merubah buku
    void modifyBook()
    {
        std::cout << "\nNomor buku : " << bookNumber;
        std::cout << "\nRubah nama buku : ";
        std::cin.getline(bookName, 50);
        std::cout << "\nRubah nama penulis : ";
        std::cin.getline(author, 50);
        std::cout << "\n\n\nBook modified..";
    }

    // Menampilkan hasil dari function modifyBook();
    void report()
    {
        std::cout << "\n" << bookNumber << "\t|\t" << bookName << "\t|\t" << author << std::endl;
    }

    // Mengembalikan (nilai) nomor buku
    int returnBookNumber()
    {
        return bookNumber;
    }
};

int main()
{
    Book buku;
        buku.createBook();
        buku.showBook();
        buku.modifyBook();
        buku.report();
        buku.returnBookNumber();
}

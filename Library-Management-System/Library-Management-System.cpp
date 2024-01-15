#include <iostream>
#include <limits>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#undef max

// class Book dan Student
class Book
{
private:
    char bookNumber[6]; // Nomor buku
    char bookTitle[50]; // Judul buku
    char author[20];    // Penulis

public:
    // Menambahkan data buku
    void createBook()
    {
        std::cout << "\nENTRI BUKU BARU\n";
        std::cout << "\nMasukkan nomor buku : ";
        std::cin >> bookNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nMasukkan judul buku : ";
        std::cin.getline(bookTitle, 50); // digunakan untuk membaca satu baris dari aliran input dan menyimpannya dalam objek string.
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
        // untuk menampilkan string ke stdout (standar output), yaitu tampilan layar.
        // Fungsi ini secara otomatis menambahkan karakter newline (\n) setelah menampilkan string.
        std::cout << "\nPenulis : ";
        puts(author);
    }

    // Merubah data buku
    void updateBook()
    {
        std::cout << "\nNomor buku : " << bookNumber;
        std::cout << "\nRubah judul buku : ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.getline(bookTitle, 50);
        std::cout << "\nRubah nama penulis : ";
        std::cin.getline(author, 20);
        std::cout << "\n\n\nBook modified..";
    }

    // Menampilkan data
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
private:
    char nim[9];
    char studentName[20];
    char studentBookingNumber[6]; // Nomor pemesanan buku
    int totalBook;                // Total buku

public:
    // Menambahkan data mahasiswa
    void createStudent()
    {
        system("cls"); // Merefresh halaman (menghapus halaman sebelumnya)
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
    }

    // Merubah data mahasiswa
    void updateStudent()
    {
        std::cout << "\nRubah NIM mahasiswa : " << nim;
        std::cout << "\nRubah nama mahasiswa : ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.getline(studentName, 20);
    }

    // Mengembalikan (nilai) NIM
    char *returnNim()
    {
        return nim;
    }

    // Mengembalikan (nilai) nomor pemesanan buku
    char *returnStudentBookingNum()
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

    void getStudentBookNum(char t[])
    {
        // strcpy(studentBookingNumber, t);
    }

    // Menampilkan data mahasiswa sebelum diubah
    void report()
    {
        std::cout << "\n" << nim << "\t|\t" << studentName << "\t|\t" << totalBook << std::endl;
    }
};

std::fstream data, data1; // Object data
Book buku;                // Object buku dari class Book
Student mahasiswa;        // Object mahasiswa dari class Student

// Deklarasi function
void gotoxy(int x, int y);
void start();
void adminMenu();
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
void bookIssue();

//                                                        ========== MAIN FUNCTION ==========
int main()
{
    char choice; // Pilihan
    system("cls");
    start();
    do
    {
        system("cls");
        std::cout << "\n\n\n\t MAIN MENU";
        std::cout << "\n\n\n\t1 PEMINJAMAN BUKU";
        std::cout << "\n\n\n\t2 MENU ADMINISTRATOR";
        std::cout << "\n\n\n\t3 KELUAR";
        std::cout << "\n\n\n\t MOHON PILIH SALAH SATU (1-3)";
        choice = _getche(); // Untuk membaca satu karakter dari keyboard tanpa menunggu pengguna menekan tombol "Enter" (newline).
        switch (choice)
        {
        case '1':
            bookIssue(); // Peminjaman buku
            break;
        case '2':
            adminMenu();
            break;
        case '3':
            exit(0); // Keluar
            break;
        default:
            std::cout << "PILIHAN TIDAK VALID";
        }
    } while (choice != 3);
}

// Inisialisasi function
// FONT GOTOXY
void gotoxy(int x, int y)
{
    COORD coord{};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// HALAMAN AWAL PROGRAM
void start()
{
    system("cls");
    gotoxy(35, 11);
    std::cout << "SISTEM";
    gotoxy(35, 14);
    std::cout << "MANAJEMEN";
    gotoxy(35, 17);
    std::cout << "PERPUSTAKAAN";
    _getch();
}

// MENU ADMIN
void adminMenu()
{
    int choice; // Pilihan

    do
    {
        system("cls"); // Refresh halaman
        std::cout << "\n\n\tMENU ADMINISTRATOR";
        std::cout << "\n\n\t1.BUAT DATA MAHASISWA";
        std::cout << "\n\n\t2.TAMPILKAN SEMUA DATA MAHASISWA";
        std::cout << "\n\n\t3.TAMPILKAN DETAIL DATA MAHASISWA";
        std::cout << "\n\n\t4.RUBAH DETAIL DATA MAHASISWA";
        std::cout << "\n\n\t5.HAPUS DATA MAHASISWA";
        std::cout << "\n\n\t6.BUAT BUKU";
        std::cout << "\n\n\t7.TAMPILKAN SEMUA BUKU";
        std::cout << "\n\n\t8.TAMPILKAN DETAIL BUKU";
        std::cout << "\n\n\t9.RUBAH DATA BUKU";
        std::cout << "\n\n\t10.HAPUS BUKU";
        std::cout << "\n\n\t11.KEMBALI KE MAIN MENU";
        std::cout << "\n\n\tMOHON PILIH SALAH SATU PILIHAN (1-11)";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            writeStudent(); // Menulis atau membuat data mahasiswa
            break;
        case 2:
            displayAllStudents(); // Menampilkan semua data mahasiswa
            break;
        case 3:
            char nim[9];
            system("cls");
            std::cout << "\n\n\tMohon masukkan NIM mahasiswa : ";
            std::cin >> nim;
            displayStudent(nim);
            break;
        case 4:
            modifyStudent(); // Merubah data mahasiswa
            break;
        case 5:
            deleteStudent(); // Menghapus
            break;
        case 6:
            writeBook();
            break;
        case 7:
            displayAllBooks();
            break;
        case 8:
        {
            char num[6]; // number
            system("cls");
            std::cout << "\n\n\tMohon masukkan nomor buku : ";
            std::cin >> num;
            displayBook(num);
            break;
        }
        case 9:
            modifyBook();
            break;
        case 10:
            deleteBook();
            break;
        case 11:
            return;
        default:
            std::cout << "PILIHAN TIDAK VALID";
        }
    } while (choice != 11);
}

// WRITE DATA
void writeBook()
{
    char inputData;
    data.open("book.dat", std::ios::out | std::ios::app); // Membuka data
    do
    {
        system("cls");
        buku.createBook();
        data.write((char *)&buku, sizeof(Book)); // Menulis dan menambahkan data, size class
        std::cout << "\n\nApakah mau menambahkan data buku lagi? (y/n) ";
        std::cin >> inputData;
    } while (inputData == 'y' || inputData == 'Y');
    data.close();
}

void writeStudent()
{
    char inputData;
    data.open("student.dat", std::ios::out | std::ios::app);
    do
    {
        system("cls");
        mahasiswa.createStudent();
        data.write((char *)&mahasiswa, sizeof(Student));
        std::cout << "\n\nApakah mau menambahkan data mahasiswa lagi? (y/n) ";
        std::cin >> inputData;
    } while (inputData == 'y' || inputData == 'Y');
    data.close();
}

// DISPLAY DATA
void displayBook(char n[])
{
    int flag = 0; // Buku tidak ditemukan
    std::cout << "\nDETAIL BUKU\n";
    data.open("book.dat", std::ios::in);           // Membuka data
    while (data.read((char *)&buku, sizeof(Book))) // Membaca data
    {
        if (_strcmpi(buku.returnBookNumber(), n) == 0)
        {
            // Tampilkan buku
            buku.showBook();
            flag = 1;
        }
    }

    data.close();

    if (flag == 0)
    {
        std::cout << "\n\nBuku tidak tersedia";
    }
    _getch(); // Tekan enter untuk kembali
}

void displayStudent(char n[])
{
    int flag = 0;
    std::cout << "\nDETAIL MAHASISWA\n";
    data.open("student.dat", std::ios::in);                // Membuka data
    while (data.read((char *)&mahasiswa, sizeof(Student))) // Membaca data
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

// MERUBAH DATA
void modifyBook()
{
    char n[7]; // Menampung Nomor buku yang akan kita rubah
    int found = 0;

    system("cls");
    std::cout << "\n\nEDIT BUKU\n\n";
    std::cout << "Masukkan nomor buku : ";
    std::cin >> n;

    std::fstream data("book.dat", std::ios::in | std::ios::out | std::ios::binary);
    // File sementara
    std::ofstream tempData("temp.dat", std::ios::out | std::ios::binary);

    // Cek apakah file bisa dibuka atau tidak
    if (!data.is_open())
    {
        std::cout << "\n\nEror membuka file!";
        return;
    }

    while (data.read(reinterpret_cast<char*>(&buku), sizeof(Book)))
    {
        if (std::string(buku.returnBookNumber()) == n)
        {
            buku.showBook();
            std::cout << "\nMasukkan detail baru buku";
            buku.updateBook();
            // Menulis data di file sementara
            tempData.write(reinterpret_cast<char*>(&buku), sizeof(Book));

            std::cout << "\n\nRecord updated!";
            found = 1;
        }
        else
        {
            tempData.write(reinterpret_cast<char*>(&buku), sizeof(Book));
        }
    }

    data.close();
    tempData.close();

    remove("book.dat");
    rename("temp.dat", "book.dat");

    if (found == 0)
    {
        std::cout << "\n\nData tidak ditemukan, buat data terlebih dahulu";
    }

    _getch(); // Tekan key bebas untuk kembali
}

void modifyStudent()
{
    char n[10];
    int found = 0;

    system("cls");
    std::cout << "\n\nEDIT DATA MAHASISWA\n\n";
    std::cout << "Masukkan NIM mahasiswa : ";
    std::cin >> n;

    std::fstream data("student.dat", std::ios::in | std::ios::out | std::ios::binary);
    std::ofstream tempData("temp.dat", std::ios::out | std::ios::binary);

    if (!data.is_open())
    {
        std::cout << "\n\nEror membuka file!";
        return;
    }

    while (data.read(reinterpret_cast<char*>(&mahasiswa), sizeof(Student)))
    {
        if (std::string(mahasiswa.returnNim()) == n)
        {
            mahasiswa.showStudent();
            std::cout << "\nMasukkan detail baru mahasiswa";
            mahasiswa.updateStudent();
            // Menulis data di file sementara
            tempData.write(reinterpret_cast<char*>(&mahasiswa), sizeof(Student));

            std::cout << "\n\nRecord updated!";
            found = 1;
        }
        else
        {
            tempData.write(reinterpret_cast<char*>(&mahasiswa), sizeof(Student));
        }
    }
    data.close();
    tempData.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found == 0)
    {
        std::cout << "\n\nData tidak ditemukan, buat data terlebih dahulu";
    }

    _getch(); // Press key to get out
}

// DELETE DATA
void deleteBook()
{
    char n[7]; // Nomor buku yang akan kita hapus
    int flag = 0;

    system("cls"); // Clear screen
    std::cout << "\n\n\n\tHAPUS BUKU";
    std::cout << "\n\nMasukkan nomor buku : ";
    std::cin >> n;
    
    std::ifstream data("book.dat", std::ios::in);
    std::ofstream data2("temp.dat", std::ios::out);

    if (!data || !data2)
    {
        std::cerr << "Eror membuka file!" << std::endl;
        return;
    }

    data.seekg(0, std::ios::beg);

    while (data.read(reinterpret_cast<char*>(&buku), sizeof(Book)))
    {
        if (std::string(buku.returnBookNumber()) != n)
        {
            data2.write(reinterpret_cast<char*>(&buku), sizeof(Book));
        }
        else
        {
            flag = 1; // Data buku ditemukan
        }
    }

    data2.close();
    data.close();
    remove("book.dat");
    rename("temp.dat", "book.dat");

    if (flag == 1)
    {
        std::cout << "\n\n\tData deleted...";
    }
    else
    {
        std::cout << "\n\nData tidak ditemukan";
    }

    _getch();
}

void deleteStudent()
{
    char n[10];
    int flag = 0;

    system("cls"); // Clear screen
    std::cout << "\n\n\n\tHAPUS DATA MAHASISWA";
    std::cout << "\n\nMasukkan NIM mahasiswa : ";
    std::cin >> n;

    std::ifstream data("student.dat", std::ios::in);
    std::ofstream data2("temp.dat", std::ios::out);

    if (!data || !data2)
    {
        std::cerr << "Eror membuka file!" << std::endl;
        return;
    }

    data.seekg(0, std::ios::beg);

    while (data.read(reinterpret_cast<char*>(&mahasiswa), sizeof(Student)))
    {
        if (std::string(mahasiswa.returnNim()) != n)
        {
            data2.write(reinterpret_cast<char*>(&mahasiswa), sizeof(Student));
        }
        else
        {
            flag = 1; // Data buku ditemukan
        }
    }

    data2.close();
    data.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (flag == 1)
    {
        std::cout << "\n\n\tData deleted...";
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
    system("cls");                       // Clear screen
    data.open("book.dat", std::ios::in); // Buka file book.dat
    if (!data)
    {
        std::cout << "File tidak bisa dibuka";
        _getch();
        return; // Press any key and return
    }
    std::cout << "\n\n\t\tLIST BUKU\n\n";
    std::cout << "==================================================================\n";
    std::cout << "No. Buku"
              << "\t|\t"
              << "Judul Buku"
              << "\t|\t"
              << "Penulis" << std::endl;
    std::cout << "==================================================================\n";
    while (data.read((char *)&buku, sizeof(Book)))
    {
        buku.report();
    }

    data.close();

    _getch();
}

void displayAllStudents()
{
    system("cls");                          // Clear screen
    data.open("student.dat", std::ios::in); // Buka file student.dat
    if (!data)
    {
        std::cout << "File tidak bisa dibuka";
        _getch();
        return; // Press any key and return
    }
    std::cout << "\n\n\t\tDATA MAHASISWA\n\n";
    std::cout << "==================================================================\n";
    std::cout << "NIM"
              << "\t|\t"
              << "Nama Mahasiswa"
              << "\t|\t"
              << "Buku yang Dipinjam" << std::endl;
    std::cout << "==================================================================\n";
    while (data.read((char *)&mahasiswa, sizeof(Student)))
    {
        mahasiswa.report();
    }

    data.close();

    _getch();
}

// PEMINJAMAN BUKU
void bookIssue()
{
    char sn[10], bn[6]; // sn = studentNo(nomor mahasiswa) , bn = bookNo(nomor buku)
    int found = 0, flag = 0;
    system("cls");  // Refresh halaman
    std::cout << "\n\nPEMINJAMAN BUKU";
    std::cout << "\n\n\tMasukkan NIM mahasiswa : ";
    std::cin >> sn;

    data.open("student.dat", std::ios::in | std::ios::out);
    data1.open("book.dat", std::ios::in | std::ios::out);

    // Create a temporary file
    std::ofstream tempData("temp.dat", std::ios::out | std::ios::binary);

    while (data.read(reinterpret_cast<char*>(&mahasiswa), sizeof(Student)) && found == 0)
    {
        if (_strcmpi(mahasiswa.returnNim(), sn) == 0) // Compare NIM
        { 
            found = 1;

            if (mahasiswa.returnTotalBook() == 0) // Jika buku belum dipinjam
            { 
                std::cout << "\n\n\tMasukkan nomor buku : ";
                std::cin >> bn;

                while (data1.read(reinterpret_cast<char*>(&buku), sizeof(Book)) && flag == 0)
                {
                    if (_strcmpi(buku.returnBookNumber(), bn) == 0) // Compare book number
                    { 
                        flag = 1;
                        mahasiswa.addTotalBook();
                        mahasiswa.getStudentBookNum(buku.returnBookNumber());
                        tempData.write(reinterpret_cast<char*>(&mahasiswa), sizeof(Student));
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
        else
        {
            // If the current student is not the one we are looking for, write it to the temporary file
            tempData.write(reinterpret_cast<char*>(&mahasiswa), sizeof(Student));
        }
    }

    // Close the original file
    data.close();
    data1.close();

    // Close the temporary file
    tempData.close();

    // Replace the original file with the temporary file
    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found == 0)
    {
        std::cout << "Data mahasiswa tidak ada";
    }

    _getch();
}

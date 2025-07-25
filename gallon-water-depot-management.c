//created by Raditya Putra Farma 23343050
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PELANGGAN 100
#define HARGA_PER_GALON 5000
#define STOK_GALON 80

// Struktur untuk informasi pelanggan
struct Pelanggan {
    int id;
    char nama[30];
    char alamat[50];
    char nomorTelepon[15];
};

// Struktur untuk informasi pemesanan
struct Pemesanan {
    int id;
    int idPelanggan;
    int jumlahGalon;
    double totalBiaya;
    int status; // 0: belum diproses, 1: sedang diproses, 2: sudah diproses
    char tanggalProses[20];
    char statusText[20]; // Untuk menyimpan teks status
};

void judul();
void menu();
void tambahPelanggan();
void pemesananGalon();
void stokGalon();
void detailPesanan();
void cariPelanggan();
void selesaiPesanan();
void riwayatPesanan();
void ubahStatusPesanan(FILE *filePesanan, int idPesanan);
void bubbleSort(struct Pemesanan arr[], int n);


int main() {
    int pilihan;

    system("CLS");
    system("color 8F");

    judul();
    printf("\n\n\t\t\t\t\t1) Login");
    printf("\n\t\t\t\t\t2) Keluar");
    printf("\n\n\t\t\t\t\tMasukkan Pilihan (1/2) : ");
    scanf("%d", &pilihan);

    system("CLS");

    switch (pilihan) {
        case 1:
        	system("CLS");
            judul();
            printf("\n\n\t\t\t\t\t\t||    LOGIN ADMIN    ||\t\t\t\t");
			int i;
				// user mencoba login maksimal 3 kali
				for ( i = 0; i < 3; ++i) {
                printf("\n\n\n\t\t\t\t\tMasukkan Nama Admin :");
 	           	char nama_admin[20];
                scanf("%s", nama_admin);
                printf("\t\t\t\t\tMasukkan kata sandi :");
                char sandi_admin[20];
                scanf("%s", sandi_admin);

                if (strcmp(nama_admin, "radit") == 0 && strcmp(sandi_admin, "farma123") == 0) {
                    system("CLS");
                    judul();
                    printf("\n\n\t\t\t\t\t SELAMAT DATANG ADMIN!! LOGIN BERHASIL");
                    menu();
                    break;  
                } else {
                    printf("\t\t\t\t\t Nama Pengguna atau Kata Sandi Salah!!! Gagal Masuk");
                }
            }
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("\n\n\t\t\t\t\t Pilihan Tidak Valid");
            break;
    }

    return 0;
}

void judul() {
   printf("\n\t\t\t\t\t-------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t\t|             DEPOT AIR GALON             |\t\t");
     printf("\n\t\t\t\t\t|                 FARMA                   |\t\t");
	printf("\n\t\t\t\t\t-------------------------------------------\t\t\t\t");
}

// menampilkan menu utama
void menu() {
    int pilihan;

    printf("\n\n\n\t\t\t\t\t\t  |<--MENU-->|");
    printf("\n\n\t\t\t\t\t1. Tambah Pelanggan");
    printf("\n\t\t\t\t\t2. Pemesanan Galon");
    printf("\n\t\t\t\t\t3. Stok Galon");
    printf("\n\t\t\t\t\t4. Detail Pesanan");
    printf("\n\t\t\t\t\t5. Cari Data Pelanggan");
    printf("\n\t\t\t\t\t6. Keluar");
    printf("\n\n\t\t\t\t\tMasukkan Pilihan : ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            tambahPelanggan();
            break;
            
        case 2:
            pemesananGalon();
            break;
            
        case 3:
            stokGalon();
            break;
            
        case 4:
            detailPesanan();
            break;
            
        case 5:
            cariPelanggan();
            break;
            
        case 6:
        	system("CLS");
            exit(0);
            break;
        default:
            printf("PILIHAN TIDAK VALID !!!");
    }
}

// menambahkan pelanggan baru
void tambahPelanggan() {
    struct Pelanggan pelanggan;
    FILE *filePelanggan;

    system("CLS");
    judul();
    filePelanggan = fopen("pelanggan.txt", "ab+");

    if (filePelanggan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PELANGGAN !!!");
        return;
    }

    fflush(stdin);
    printf("\n\n\t\t\t\t\tMasukkan Nama Pelanggan : ");
    gets(pelanggan.nama);
    printf("\t\t\t\t\tMasukkan Alamat Pelanggan : ");
    gets(pelanggan.alamat);
    printf("\t\t\t\t\tMasukkan Nomor Telepon Pelanggan : ");
    gets(pelanggan.nomorTelepon);

    srand(time(NULL));  // menetapkan seed berdasarkan waktu sistem
    pelanggan.id = rand() % 1000 + 1;

    fprintf(filePelanggan, "%d %s %s %s\n", pelanggan.id, pelanggan.nama, pelanggan.alamat, pelanggan.nomorTelepon);

    printf("\n\n\t\t\t\t\tData Pelanggan Berhasil Ditambahkan!");
    printf("\n\t\t\t\t\tID Pelanggan Anda: %d", pelanggan.id); 
    printf("\n\n\t\t\t\t\tTekan Enter untuk melanjutkan ");
    fflush(stdin);
    getchar();

    fclose(filePelanggan);  
    system("CLS");
    judul();
    menu();
}

// melakukan pemesanan galon air
void pemesananGalon() {
    struct Pemesanan pesanan;
    FILE *filePesanan;
    FILE *filePelanggan;
    struct Pelanggan pelanggan;

    system("CLS");
    judul();
    filePesanan = fopen("pesanan.txt", "ab+");
    filePelanggan = fopen("pelanggan.txt", "rb");

    if (filePesanan == NULL || filePelanggan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PESANAN ATAU PELANGGAN !!!");
        return;
    }

    printf("\n\n\t\t\t\t\tMasukkan ID Pelanggan : ");
    scanf("%d", &pesanan.idPelanggan);

    // Mencari data pelanggan berdasarkan ID
    int found = 0;
    while (fscanf(filePelanggan, "%d %s %s %s", &pelanggan.id, pelanggan.nama, pelanggan.alamat, pelanggan.nomorTelepon) != EOF) {
        if (pelanggan.id == pesanan.idPelanggan) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\n\t\t\t\t\tMasukkan Jumlah Galon yang Dipesan : ");
        scanf("%d", &pesanan.jumlahGalon);

        // hitung total biaya berdasarkan jumlah galon yang dipesan
        pesanan.totalBiaya = pesanan.jumlahGalon * 5000;

        pesanan.id = rand() % 1000 + 1001; // ID pemesanan dimulai dari 1001
        pesanan.status = 1; // Status pesanan awal: belum diproses
        strcpy(pesanan.statusText, "Belum Diproses"); // Set status teks

        fprintf(filePesanan, "%d %d %d %.2lf %d %s\n", pesanan.id, pesanan.idPelanggan, pesanan.jumlahGalon, pesanan.totalBiaya, pesanan.status, pesanan.statusText);

        printf("\n\n\t\t\t\t\tPemesanan Berhasil! ID Pemesanan Anda: %d", pesanan.id); 

        // ambil tanggal dan waktu saat ini
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(pesanan.tanggalProses, "%04d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        printf("\n\n\t\t\t\t\tPesanan Anda Telah Diproses pada: %s", pesanan.tanggalProses);
    } else {
        printf("\n\t\t\t\t\t\t\tPelanggan dengan ID %d tidak ditemukan.", pesanan.idPelanggan);
    }

    fclose(filePesanan);
    fclose(filePelanggan);

    printf("\n\n\t\t\t\t\tTekan Enter untuk melanjutkan ");
    fflush(stdin);
    getchar();
    system("CLS");
    judul();
    menu();
}

// mengecek stok galon air yang tersisa
void stokGalon() {
    FILE *filePesanan;
    struct Pemesanan pesanan;
    system("CLS");
    judul();
    filePesanan = fopen("pesanan.txt", "rb");

    if (filePesanan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PESANAN !!!");
        return;
    }

    int stokGalon = 80;

    // hitung sisa stok galon yang tersedia
    while (fscanf(filePesanan, "%d %d %d %lf %d %s %s", &pesanan.id, &pesanan.idPelanggan, &pesanan.jumlahGalon, &pesanan.totalBiaya, &pesanan.status, pesanan.statusText, pesanan.tanggalProses) != EOF) {
        if (pesanan.status != 2) { // Hanya menghitung pesanan yang belum selesai (belum diproses atau sedang diproses)
            stokGalon -= pesanan.jumlahGalon;
        }
    }

    printf("\n\n\t\t\t\t\tStok Galon Tersedia: %d", stokGalon);
    printf("\n\n\t\t\t\t\tTekan Enter untuk melanjutkan ");
    fflush(stdin);
    getchar();

    fclose(filePesanan);
    system("CLS");
    judul();
    menu();
}

// menampilkan informasi detail pesanan
void detailPesanan() {
    FILE *filePesanan;
    struct Pemesanan pesanan;
    struct Pelanggan pelanggan;
    system("CLS");
    judul();
    filePesanan = fopen("pesanan.txt", "rb+");  // Mode rb+ untuk membaca dan menulis

    if (filePesanan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PESANAN !!!");
        return;
    }

    int pilihan;

    printf("\n\n\t\t\t\t\t\t\t|----- Detail Pesanan -----|");
    printf("\n\n\t\t\t   ID Pesanan\tID Pelanggan\tJumlah Galon\t\tTotal Biaya\t\tStatus");
    while (fscanf(filePesanan, "%d %d %d %lf %d %s %s", &pesanan.id, &pesanan.idPelanggan, &pesanan.jumlahGalon, &pesanan.totalBiaya, &pesanan.status, pesanan.statusText, pesanan.tanggalProses) != EOF) 
	{
        printf("\n\n\t\t\t    %d \t\t%d \t\t%d \t\t%.2lf \t\t%s",
               pesanan.id, pesanan.idPelanggan, pesanan.jumlahGalon, pesanan.totalBiaya, pesanan.statusText);

        if (pesanan.status == 1) { 
            ubahStatusPesanan(filePesanan, pesanan.id);
        }
    }

	printf("\n\t\t\t\t\t1. Pesanan yang telah selesai");
    printf("\n\n\t\t\t\t\t2. Tampilkan Riwayat Pesanan yang Telah Diproses");
    printf("\n\t\t\t\t\t3. Kembali ke Menu Utama");
    printf("\n\n\t\t\t\t\tMasukkan Pilihan : ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            system("CLS");
            selesaiPesanan();
            printf("\n\n\t\t\t\t\tTekan Enter untuk kembali ke Menu Utama ");
            fflush(stdin);
            getchar();
            break;
            
        case 2:
            system("CLS");
            riwayatPesanan();
            printf("\n\n\t\t\t\t\tTekan Enter untuk kembali ke Menu Utama ");
            fflush(stdin);
            getchar();
            break;
            
        case 3:
            break;
        default:
            printf("PILIHAN TIDAK VALID !!!");
    }

    fclose(filePesanan);
    system("CLS");
    judul();
    menu();
}

// mencari informasi pelanggan berdasarkan ID
void cariPelanggan() {
    struct Pelanggan pelanggan;
    FILE *filePelanggan;
    int idCari;

    system("CLS");
    judul();
    filePelanggan = fopen("pelanggan.txt", "rb");

    if (filePelanggan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PELANGGAN !!!");
        return;
    }

    printf("\n\n\t\t\t\t\tMasukkan ID Pelanggan yang Dicari: ");
    scanf("%d", &idCari);

    int found = 0;
    while (fscanf(filePelanggan, "%d %s %s %s", &pelanggan.id, pelanggan.nama, pelanggan.alamat, pelanggan.nomorTelepon) != EOF) {
        if (pelanggan.id == idCari) {
            found = 1;
            printf("\n\t\t\t\t\tData Pelanggan Ditemukan!");
            printf("\n\t\t\t\t\tID Pelanggan: %d", pelanggan.id);
            printf("\n\t\t\t\t\tNama Pelanggan: %s", pelanggan.nama);
            printf("\n\t\t\t\t\tAlamat Pelanggan: %s", pelanggan.alamat);
            printf("\n\t\t\t\t\tNomor Telepon Pelanggan: %s", pelanggan.nomorTelepon);
            break;
        }
    }

    if (!found) {
        printf("\n\t\t\t\t\tData Pelanggan dengan ID %d tidak ditemukan.", idCari);
    }

    fclose(filePelanggan);

    printf("\n\n\t\t\t\t\tTekan Enter untuk kembali ke Menu Utama ");
    fflush(stdin);
    getchar();
    system("CLS");
    judul();
    menu();
}


// menandai pesanan sebagai selesai
void selesaiPesanan() {
    FILE *filePesanan;
    struct Pemesanan pesanan;

    system("CLS");
    judul();
    filePesanan = fopen("pesanan.txt", "rb+");  // Mode rb+ untuk membaca dan menulis

    if (filePesanan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PESANAN !!!");
        return;
    }

    int pilihan;

    printf("\n\n\t\t\t\t\t\t\t|----- Selesai Pesanan -----|");
    printf("\n\n\t\t\t   ID Pesanan\tID Pelanggan\tJumlah Galon\t\tTotal Biaya\t\tStatus");
    while (fscanf(filePesanan, "%d %d %d %lf %d %s %s", &pesanan.id, &pesanan.idPelanggan, &pesanan.jumlahGalon, &pesanan.totalBiaya, &pesanan.status, pesanan.statusText, pesanan.tanggalProses) != EOF) 
    {
        if (pesanan.status == 1) {
            printf("\n\n\t\t\t    %d \t\t%d \t\t%d \t\t%.2lf \t\t%s",
                pesanan.id, pesanan.idPelanggan, pesanan.jumlahGalon, pesanan.totalBiaya, pesanan.statusText);
        }
    }

    printf("\n\n\t\t\t\t\tMasukkan ID Pesanan yang Selesai: ");
    scanf("%d", &pilihan);

    ubahStatusPesanan(filePesanan, pilihan);

    fclose(filePesanan);

    printf("\n\n\t\t\t\t\tTekan Enter untuk kembali ke Menu Utama ");
    fflush(stdin);
    getchar();
    system("CLS");
    judul();
    menu();
}

// menampilkan riwayat pesanan
void riwayatPesanan() {
    FILE *filePesanan;
    struct Pemesanan pesanan;

    system("CLS");
    judul();
    filePesanan = fopen("pesanan.txt", "rb");

    if (filePesanan == NULL) {
        printf("\n\t\t\t\t\tERROR MEMBUKA FILE PESANAN !!!");
        return;
    }

    printf("\n\n\t\t\t\t\t\t\t|----- Riwayat Pesanan Telah Selesai -----|");
    printf("\n\n\t\t\t   ID Pesanan\tID Pelanggan\tJumlah Galon\t\tTotal Biaya\t\tTanggal Selesai");

    while (fscanf(filePesanan, "%d %d %d %lf %d %s %s", &pesanan.id, &pesanan.idPelanggan, &pesanan.jumlahGalon, &pesanan.totalBiaya, &pesanan.status, pesanan.statusText, pesanan.tanggalProses) != EOF) 
    {
        if (pesanan.status == 2) {
            printf("\n\n\t\t\t    %d \t\t%d \t\t%d \t\t%.2lf \t\t%s \t\t%s",
                pesanan.id, pesanan.idPelanggan, pesanan.jumlahGalon, pesanan.totalBiaya, pesanan.statusText, pesanan.tanggalProses);
        }
    }

    printf("\n\n\t\t\t\t\tTekan Enter untuk kembali ke Menu Utama ");
    fflush(stdin);
    getchar();
    system("CLS");
    judul();
    menu();
}

// memperbarui status pesanan dalam file
void ubahStatusPesanan(FILE *filePesanan, int idPesanan) {
    struct Pemesanan pesanan;
    long pos;

    FILE *tempFile = fopen("temp_pesanan.txt", "w");
    if (tempFile == NULL) {
        printf("ERROR MEMBUKA FILE PESANAN.");
        return;
    }

    while (fscanf(filePesanan, "%d %d %d %lf %d %s %s", &pesanan.id, &pesanan.idPelanggan, &pesanan.jumlahGalon, &pesanan.totalBiaya, &pesanan.status, pesanan.statusText, pesanan.tanggalProses) != EOF) {
        if (pesanan.id == idPesanan && pesanan.status == 1) {
            pesanan.status = 2;
            strcpy(pesanan.statusText, "Selesai");
            printf("\n\t\t\t\t\tPesanan Selesai Dengan ID: %d", pesanan.id);
        }

        fprintf(tempFile, "%d %d %d %.2lf %d %s %s\n", pesanan.id, pesanan.idPelanggan, pesanan.jumlahGalon, pesanan.totalBiaya, pesanan.status, pesanan.statusText, pesanan.tanggalProses);
    }

    fclose(filePesanan);
    fclose(tempFile);

    remove("pesanan.txt");
    rename("temp_pesanan.txt", "pesanan.txt");
    
    filePesanan = fopen("pesanan.txt", "rb");
}

// lakukan bubble sort pada array pesanan
void bubbleSort(struct Pemesanan arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                struct Pemesanan temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


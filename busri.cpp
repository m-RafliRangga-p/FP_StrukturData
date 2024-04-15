//بِسْمِ اللّٰهِ الرَّحْمٰنِ الرَّحِيْمِ

//اَللَّهُمَّ يَسِّرْ وَ لَا تُعَسِّرْ


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const int ukuran = 100;
int count = 0;
int countD = 0;
int countI = 0;
int sizeN = 0;
int CD = 0;
int D = 0;
int sizeD = 0;
int CD1 = 0;
int D1 = 0;
int sizeI = 0;
int CD2 = 0;
int D2 = 0;
void admin();
void input_data();
void show_data();
void sort_data();
void delete_data();
void edit_data();
void search_data();

//Group Novel 👇👇
void inisialisasi();
void novell();
void show_novel();
bool isFullN();
bool isEmprtyN();
void insertion_novel();
void delete_novel();
void edit_novel();
void search_novel();

//Group Dongeng 👇👇
void inisialisasiD();
void dongengg();
void show_dongeng();
bool isFullD();
bool isEmprtyD();
void insertion_dongeng();
void delete_dongeng();
void edit_dongeng();
void search_dongeng();

//Group Ilmu 👇👇
void inisialisasiI();
void ilmuu();
void show_ilmu();
bool isFullI();
bool isEmprtyI();
void insertion_ilmu();
void delete_ilmu();
void edit_ilmu();
void search_ilmu();

struct Stack {
	int top;
}; Stack stack;

struct StackD {
	int top;
}; StackD stackD;

struct StackI {
	int top;
}; StackI stackI;

struct Temp {
	int id_buku;
	string judul_buku;
	string penerbit;
	int stok;
	float harga;
}; Temp temp;

struct Novel {
	int id_buku;
	string judul_buku;
	string penerbit;
	int stok;
	float harga;
}; Novel novel[ukuran];

struct Dongeng {
	int id_buku;
	string judul_buku;
	string penerbit;
	int stok;
	float harga;
}; Dongeng dongeng[ukuran];


struct Ilmu {
	int id_buku;
	string judul_buku;
	string penerbit;
	int stok;
	float harga;
}; Ilmu ilmu[ukuran];



int main() {
	int pilihanMenu;
	system("cls");

	do{
		cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
		cout <<  "----------------------------" << endl;
		cout <<  "| >>>  PILIH PENGGUNA  <<< |" << endl;
		cout <<  "----------------------------" << endl;
		cout <<  "| [1] Admin \t\t   |" << endl;
		cout <<  "| [2] Selesai \t\t   |" << endl;
		cout <<  "----------------------------" << endl;

		cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
		cout << endl;

		switch(pilihanMenu){
			case 1:
			admin();
			system("cls");
			break;
		}
	} while(pilihanMenu != 2);

	system("pause");
	return 0;
}

void admin(){
	string pass; 
	char ulang;
	int pilihanMenu;

	ulang:
	system("cls");
	cout << "Masukkan Password Anda : "; cin >> pass;
	cout << endl;

	if(pass == "root"){
		do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Input Data \t   |" << endl;
			cout <<  "| [2] Show Data \t   |" << endl;
			cout <<  "| [3] Sort Data \t   |" << endl;
			cout <<  "| [4] Delete Data \t   |" << endl;
			cout <<  "| [5] Edit Data \t   |" << endl;
			cout <<  "| [6] Cari Data \t   |" << endl;
			cout <<  "| [7] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				input_data();
				system("cls");
				break;

				case 2:
				system("cls");
				show_data();
				system("cls");
				break;

				case 3:
				system("cls");
				sort_data();
				system("cls");
				break;

				case 4:
				system("cls");
				delete_data();
				system("cls");
				break;

				case 5:
				system("cls");
				edit_data();
				system("cls");
				break;

				case 6:
				system("cls");
				search_data();
				system("cls");
				break;
			}
		}while(pilihanMenu != 7);
	}
	else{
		cout << "Password Yang Anda Masukkan Salah!!!! \n";
		cout << "Apakah Anda Ingin Mencoba Lagi??? (y/n) "; cin >> ulang;

		if(ulang == 'y' || ulang == 'Y'){
			goto ulang;
		}
		else{
			system("cls");
		}
	}
}

void input_data() {
	int pilihanMenu;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Tema Novel \t   |" << endl;
			cout <<  "| [2] Tema Dongeng \t   |" << endl;
			cout <<  "| [3] Tema Keilmuan \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				if(isFullN() || sizeN > ukuran){
					cout << "Tempat Penyimpanan Sudah Penuh!!! \n";
				}else {
					novell();
				}
				system("pause");
				system("cls");
				break;

				case 2:
				if(isFullD() || sizeD > ukuran){
					cout << "Tempat Penyimpanan Sudah Penuh!!! \n";
				}else {
					dongengg();
				}
				system("pause");
				system("cls");
				break;

				case 3:
				if(isFullI() || sizeI > ukuran){
					cout << "Tempat Penyimpanan Sudah Penuh!!! \n";
				}else {
					ilmuu();
				}
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void show_data(){
	int pilihanMenu;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Tema Novel \t   |" << endl;
			cout <<  "| [2] Tema Dongeng \t   |" << endl;
			cout <<  "| [3] Tema Keilmuan \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				inisialisasi();
				if(isEmprtyN()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					show_novel();
				}
				system("pause");
				system("cls");
				break;

				case 2:
				system("cls");
				inisialisasiD();
				if(isEmprtyD()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					show_dongeng();
				}
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				inisialisasiI();
				if(isEmprtyI()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					show_ilmu();
				}
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void sort_data(){
	int pilihanMenu;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Tema Novel \t   |" << endl;
			cout <<  "| [2] Tema Dongeng \t   |" << endl;
			cout <<  "| [3] Tema Keilmuan \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				inisialisasi();
				if(isEmprtyN()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					insertion_novel();
				}
				system("pause");
				system("cls");
				break;

				case 2:
				system("cls");
				inisialisasiD();
				if(isEmprtyD()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					insertion_dongeng();
				}
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				inisialisasiI();
				if(isEmprtyI()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					insertion_ilmu();
				}
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void delete_data(){
	int pilihanMenu;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Tema Novel \t   |" << endl;
			cout <<  "| [2] Tema Dongeng \t   |" << endl;
			cout <<  "| [3] Tema Keilmuan \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				inisialisasi();
				if(isEmprtyN()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					delete_novel();
				}
				system("pause");
				system("cls");
				break;

				case 2:
				system("cls");
				inisialisasiD();
				if(isEmprtyD()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					delete_dongeng();
				}
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				inisialisasiI();
				if(isEmprtyI()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					delete_ilmu();
				}
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void edit_data(){
	int pilihanMenu;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Tema Novel \t   |" << endl;
			cout <<  "| [2] Tema Dongeng \t   |" << endl;
			cout <<  "| [3] Tema Keilmuan \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				inisialisasi();
				if(isEmprtyN()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					edit_novel();
				}
				system("pause");
				system("cls");
				break;

				case 2:
				system("cls");
				inisialisasiD();
				if(isEmprtyD()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					edit_dongeng();
				}
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				inisialisasiI();
				if(isEmprtyI()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					edit_ilmu();
				}
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void search_data(){
	int pilihanMenu;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Tema Novel \t   |" << endl;
			cout <<  "| [2] Tema Dongeng \t   |" << endl;
			cout <<  "| [3] Tema Keilmuan \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				inisialisasi();
				if(isEmprtyN()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					search_novel();
				}
				system("pause");
				system("cls");
				break;

				case 2:
				system("cls");
				inisialisasiD();
				if(isEmprtyD()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					search_dongeng();
				}
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				inisialisasiI();
				if(isEmprtyI()){
					cout << "Tidak Ada Data Sama Sekali!!!! \n";
				}else {
					search_ilmu();
				}
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

//Group Novel
void inisialisasi(){
	if(count == 0){
		stack.top = -1;
	}
	else{
		stack.top = stack.top;
	}
}

void novell(){
	int loop;
	int *Ptrloop = &loop;
	cout << "Masukkan Jumlah Buku : "; cin >> loop;
	sizeN += *Ptrloop;
	cout << "Penyimpanan yang Digunakan: " << sizeN << "/" << ukuran << endl;
	cout << endl;
	if(sizeN > ukuran){
		cout << "Tempat Penyimpanan Tidak Cukup!!!!!! \n";
	}else {
		inisialisasi();

		for(int i = 0; i<loop; i++){
			stack.top++;
			cout << i+1;
			cout << " Masukkan Id Buku : #"; 
			cin >> novel[stack.top].id_buku;
			cout << "  Masukkan Judul Buku : "; 
			getline(cin >> ws, novel[stack.top].judul_buku);
			cout << "  Masukkan Penerbit Buku : "; 
			getline(cin >> ws, novel[stack.top].penerbit);
			cout << "  Masukkan Stok Buku : "; cin >> novel[stack.top].stok;
			cout << "  Masukkan Harga Buku : Rp"; cin >> novel[stack.top].harga;
			cout << "--------------------------------------------------- \n";
		} 
		count++;
	}
}



void show_novel(){
	int j = 1;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << ">>>>  \t\t\t\t\t\t\t\t TOKO BUKU BU SRI \t\t\t\t\t\t\t\t <<<< \n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << "| \t\t\t\t\t\t\t\t Tema NOVEL \t\t\t\t\t\t\t\t\t    |\n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << setw(4) << "No.";
	cout << setw(5) << "ID";
	cout << setw(60) << "Judul Buku";
	cout << setw(50) << "Penerbit";
	cout << setw(5) << "Stok";
	cout << setw(10) << "Harga";
	cout << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";

	for(int i = stack.top; i >= 0; i--){
		cout << setw(4) << j;
		cout << setw(5) << "#" << setfill('0') << setw(4) << novel[i].id_buku;
		cout << setfill(' ') << setw(60) << novel[i].judul_buku;
		cout << setw(50) << novel[i].penerbit;
		cout << setw(5) << novel[i].stok;
		cout << fixed;
		cout << setw(10) << "Rp" <<setprecision(3) << novel[i].harga;
		cout << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
		j++;
	}
}


bool isFullN(){
	return (stack.top >= (ukuran -1));
}

bool isEmprtyN(){
	return (stack.top == -1);
}

void insertion_novel(){
	int j;
	for(int i = 1; i<stack.top+1; i++){
		temp.id_buku = novel[i].id_buku;
		temp.judul_buku = novel[i].judul_buku;
		temp.penerbit = novel[i].penerbit;
		temp.stok = novel[i].stok;
		temp.harga = novel[i].harga;
		j = i - 1;
		while (novel[j].id_buku < temp.id_buku  && j >= 0){
			novel[j+1].id_buku = novel[j].id_buku;
			novel[j+1].judul_buku = novel[j].judul_buku;
			novel[j+1].penerbit = novel[j].penerbit;
			novel[j+1].stok = novel[j].stok;
			novel[j+1].harga = novel[j].harga;
			j--;
		}
		novel[j+1].id_buku = temp.id_buku;
		novel[j+1].judul_buku = temp.judul_buku;
		novel[j+1].penerbit = temp.penerbit;
		novel[j+1].stok = temp.stok;
		novel[j+1].harga = temp.harga;
	}
	cout << "Data Anda Sudah Diurutkan!!! \n";
	cout << "Silahkan Pilih Menu Show Data [2] Untuk Melihat Hasilnya!!! \n";
	cout << "Bila Anda Menambah Data Setelah Proses Sorting ini, ";
	cout << "Maka Anda Harus Melakukan Sorting Ulang Agar Data-Datanya Menjadi Terurut!!! \n";
}

void delete_novel(){
	int pilihanMenu, no;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Data by No. \t   |" << endl;
			cout <<  "| [2] Top of Data \t   |" << endl;
			cout <<  "| [3] Clear All \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				cout << "Masukkan No. Data : ";
				cin >> no;
				if(no == stack.top+1){
					no = 0;
				}
				else{
					no = sizeN-no;
				}
				CD++;
				D++;
				novel[no].id_buku = 0;
				novel[no].judul_buku = " ";
				novel[no].penerbit = " ";
				novel[no].stok = 0;
				novel[no].harga = 0;
				cout << " . . . Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				system("pause");
				system("cls");
				sizeN -= 1;
				break;

				case 2:
				system("cls");
				stack.top--;
				if(CD == 0 && D == 0){
					sizeN=sizeN-1;
				}
				if(CD != 0 && D > 0){
					CD--;
					D--;
				}
				cout << " . . . Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				stack.top = -1;
				cout << " . . . Semua Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				count = 0;
				sizeN = 0;
				CD = 0;
				D = 0;
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void edit_novel(){
	int no;
	if(CD != 0){
		sizeN=sizeN+1;
	}
	cout << "Masukkan No. Data : ";
	cin >> no;
	if(no == stack.top+1){
		no = 0;
	}
	else{
		no = sizeN-no;
	}

	cout << " Masukkan Id Buku : #"; 
	cin >> novel[no].id_buku;
	cout << "  Masukkan Judul Buku : "; 
	getline(cin >> ws, novel[no].judul_buku);
	cout << "  Masukkan Penerbit Buku : "; 
	getline(cin >> ws, novel[no].penerbit);
	cout << "  Masukkan Stok Buku : "; cin >> novel[no].stok;
	cout << "  Masukkan Harga Buku : Rp"; cin >> novel[no].harga;

	system("pause");
	system("cls");
	cout << "... Data Berhasil di Edit!!! ... \n";
}

void search_novel(){
	int x, no;
	bool found = false;

	cout << "!!!*** Untuk ID Dengan Awalan Angka 0, Cukup Tuliskan Angka Setelah 0 ***!!! \n";
	cout << "Misal : id = #0009 maka tuliskan 9 saja, dan untuk id yang bernilai puluhan/ratusan maka lakukan hal yang sama \n";
	cout << "Masukkan ID dari Buku yang Dicari : # ";
	cin >> x;

	if(sizeN <= stack.top+1){
		for(int i = 0; i < sizeN; i++){
			if(x == novel[i].id_buku){
				found = true;
				if(i == 0){
						no = stack.top+1;
					}
				else{
						no = sizeN-i;
					}
				cout << "Data Ditemukan di Indeks ke-" << i << " Atau No." << no <<  endl;

				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << ">>>>  \t\t\t\t\t\t\t\t TOKO BUKU BU SRI \t\t\t\t\t\t\t\t <<<< \n";
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "| \t\t\t\t\t\t\t\t Tema NOVEL \t\t\t\t\t\t\t\t\t    |\n";
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << setw(4) << "No.";
				cout << setw(5) << "ID";
				cout << setw(60) << "Judul Buku";
				cout << setw(50) << "Penerbit";
				cout << setw(5) << "Stok";
				cout << setw(10) << "Harga";
				cout << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
			
				cout << setw(4) << no;
				cout << setw(5) << "#" << setfill('0') << setw(4) << novel[i].id_buku;
				cout << setfill(' ') << setw(60) << novel[i].judul_buku;
				cout << setw(50) << novel[i].penerbit;
				cout << setw(5) << novel[i].stok;
				cout << fixed;
				cout << setw(10) << "Rp" <<setprecision(3) << novel[i].harga;
				cout << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				}
		}
		if(found == false){
			cout << "Data Tidak Ditemukan \n";
		}
	}
	else {
		if(found == false){
			cout << "Data Tidak Ditemukan \n";
		}
	}
}


//Group Dongeng
void inisialisasiD(){
	if(countD == 0){
		stackD.top = -1;
	}
	else{
		stackD.top = stackD.top;
	}
}

void dongengg(){
	int loop;
	int *Ptrloop = &loop;
	cout << "Masukkan Jumlah Buku : "; cin >> loop;
	sizeD += *Ptrloop;
	cout << "Penyimpanan yang Digunakan: " << sizeD << "/" << ukuran << endl;
	cout << endl;
	if(sizeD > ukuran){
		cout << "Tempat Penyimpanan Tidak Cukup!!!!!! \n";
	}else {
		inisialisasiD();

		for(int i = 0; i<loop; i++){
			stackD.top++;
			cout << i+1;
			cout << " Masukkan Id Buku : #"; 
			cin >> dongeng[stackD.top].id_buku;
			cout << "  Masukkan Judul Buku : "; 
			getline(cin >> ws, dongeng[stackD.top].judul_buku);
			cout << "  Masukkan Penerbit Buku : "; 
			getline(cin >> ws, dongeng[stackD.top].penerbit);
			cout << "  Masukkan Stok Buku : "; cin >> dongeng[stackD.top].stok;
			cout << "  Masukkan Harga Buku : Rp"; cin >> dongeng[stackD.top].harga;
			cout << "--------------------------------------------------- \n";
		} 
		countD++;
	}
}

void show_dongeng(){
	int j = 1;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << ">>>>  \t\t\t\t\t\t\t\t TOKO BUKU BU SRI \t\t\t\t\t\t\t\t <<<< \n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << "| \t\t\t\t\t\t\t\t Tema DONGENG \t\t\t\t\t\t\t\t\t    |\n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << setw(4) << "No.";
	cout << setw(5) << "ID";
	cout << setw(60) << "Judul Buku";
	cout << setw(50) << "Penerbit";
	cout << setw(5) << "Stok";
	cout << setw(10) << "Harga";
	cout << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";

	for(int i = stackD.top; i >= 0; i--){
		cout << setw(4) << j;
		cout << setw(5) << "#" << setfill('0') << setw(4) << dongeng[i].id_buku;
		cout << setfill(' ') << setw(60) << dongeng[i].judul_buku;
		cout << setw(50) << dongeng[i].penerbit;
		cout << setw(5) << dongeng[i].stok;
		cout << fixed;
		cout << setw(10) << "Rp" <<setprecision(3) << dongeng[i].harga;
		cout << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
		j++;
	}
}

bool isFullD(){
	return (stackD.top >= (ukuran -1));
}

bool isEmprtyD(){
	return (stackD.top == -1);
}

void insertion_dongeng(){
	int j;
	for(int i = 1; i<stackD.top+1; i++){
		temp.id_buku = dongeng[i].id_buku;
		temp.judul_buku = dongeng[i].judul_buku;
		temp.penerbit = dongeng[i].penerbit;
		temp.stok = dongeng[i].stok;
		temp.harga = dongeng[i].harga;
		j = i - 1;
		while (dongeng[j].id_buku < temp.id_buku  && j >= 0){
			dongeng[j+1].id_buku = dongeng[j].id_buku;
			dongeng[j+1].judul_buku = dongeng[j].judul_buku;
			dongeng[j+1].penerbit = dongeng[j].penerbit;
			dongeng[j+1].stok = dongeng[j].stok;
			dongeng[j+1].harga = dongeng[j].harga;
			j--;
		}
		dongeng[j+1].id_buku = temp.id_buku;
		dongeng[j+1].judul_buku = temp.judul_buku;
		dongeng[j+1].penerbit = temp.penerbit;
		dongeng[j+1].stok = temp.stok;
		dongeng[j+1].harga = temp.harga;
	}
	cout << "Data Anda Sudah Diurutkan!!! \n";
	cout << "Silahkan Pilih Menu Show Data [2] Untuk Melihat Hasilnya!!! \n";
	cout << "Bila Anda Menambah Data Setelah Proses Sorting ini, ";
	cout << "Maka Anda Harus Melakukan Sorting Ulang Agar Data-Datanya Menjadi Terurut!!! \n";
}

void delete_dongeng(){
	int pilihanMenu, no;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Data by No. \t   |" << endl;
			cout <<  "| [2] Top of Data \t   |" << endl;
			cout <<  "| [3] Clear All \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				cout << "Masukkan No. Data : ";
				cin >> no;
				if(no == stackD.top+1){
					no = 0;
				}
				else{
					no = sizeD-no;
				}
				CD1++;
				dongeng[no].id_buku = 0;
				dongeng[no].judul_buku = " ";
				dongeng[no].penerbit = " ";
				dongeng[no].stok = 0;
				dongeng[no].harga = 0;
				cout << " . . . Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				system("pause");
				system("cls");
				sizeD -= 1;
				break;

				case 2:
				system("cls");
				stackD.top--;
				if(CD1 == 0 && D1 == 0){
					sizeD=sizeD-1;
				}
				if(CD1 != 0 && D1 > 0){
					CD1--;
					D1--;
				}
				cout << " . . . Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				stackD.top = -1;
				cout << " . . . Semua Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				count = 0;
				sizeD = 0;
				CD1 = 0;
				D1 = 0;
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void edit_dongeng(){
	int no;
	if(CD1 != 0){
		sizeD=sizeD+1;
	}
	cout << "Masukkan No. Data : ";
	cin >> no;
	if(no == stackD.top+1){
		no = 0;
	}
	else{
		no = sizeD-no;
	}

	cout << " Masukkan Id Buku : #"; 
	cin >> dongeng[no].id_buku;
	cout << "  Masukkan Judul Buku : "; 
	getline(cin >> ws, dongeng[no].judul_buku);
	cout << "  Masukkan Penerbit Buku : "; 
	getline(cin >> ws, dongeng[no].penerbit);
	cout << "  Masukkan Stok Buku : "; cin >> dongeng[no].stok;
	cout << "  Masukkan Harga Buku : Rp"; cin >> dongeng[no].harga;

	system("pause");
	system("cls");
	cout << "... Data Berhasil di Edit!!! ... \n";
}

void search_dongeng(){
	int x, no;
	bool found = false;

	cout << "!!!*** Untuk ID Dengan Awalan Angka 0, Cukup Tuliskan Angka Setelah 0 ***!!! \n";
	cout << "Misal : id = #0009 maka tuliskan 9 saja, dan untuk id yang bernilai puluhan/ratusan maka lakukan hal yang sama \n";
	cout << "Masukkan ID dari Buku yang Dicari : # ";
	cin >> x;

	if(sizeD <= stackD.top+1){
		for(int i = 0; i < sizeD; i++){
			if(x == dongeng[i].id_buku){
				found = true;
				if(i == 0){
						no = stackD.top+1;
					}
				else{
						no = sizeD-i;
					}
				cout << "Data Ditemukan di Indeks ke-" << i << " Atau No." << no <<  endl;

				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << ">>>>  \t\t\t\t\t\t\t\t TOKO BUKU BU SRI \t\t\t\t\t\t\t\t <<<< \n";
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "| \t\t\t\t\t\t\t\t Tema DONGENG \t\t\t\t\t\t\t\t\t    |\n";
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << setw(4) << "No.";
				cout << setw(5) << "ID";
				cout << setw(60) << "Judul Buku";
				cout << setw(50) << "Penerbit";
				cout << setw(5) << "Stok";
				cout << setw(10) << "Harga";
				cout << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
			
				cout << setw(4) << no;
				cout << setw(5) << "#" << setfill('0') << setw(4) << dongeng[i].id_buku;
				cout << setfill(' ') << setw(60) << dongeng[i].judul_buku;
				cout << setw(50) << dongeng[i].penerbit;
				cout << setw(5) << dongeng[i].stok;
				cout << fixed;
				cout << setw(10) << "Rp" <<setprecision(3) << dongeng[i].harga;
				cout << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				}
		}
		if(found == false){
			cout << "Data Tidak Ditemukan \n";
		}
	}
	else {
		if(found == false){
			cout << "Data Tidak Ditemukan \n";
		}
	}
}

//Group Ilmu
void inisialisasiI(){
	if(countI == 0){
		stackI.top = -1;
	}
	else{
		stackI.top = stackI.top;
	}
}

void ilmuu(){
	int loop;
	int *Ptrloop = &loop;
	cout << "Masukkan Jumlah Buku : "; cin >> loop;
	sizeI += *Ptrloop;
	cout << "Penyimpanan yang Digunakan: " << sizeI << "/" << ukuran << endl;
	cout << endl;
	if(sizeI > ukuran){
		cout << "Tempat Penyimpanan Tidak Cukup!!!!!! \n";
	}else {
		inisialisasiI();

		for(int i = 0; i<loop; i++){
			stackI.top++;
			cout << i+1;
			cout << " Masukkan Id Buku : #"; 
			cin >> ilmu[stackI.top].id_buku;
			cout << "  Masukkan Judul Buku : "; 
			getline(cin >> ws, ilmu[stackI.top].judul_buku);
			cout << "  Masukkan Penerbit Buku : "; 
			getline(cin >> ws, ilmu[stackI.top].penerbit);
			cout << "  Masukkan Stok Buku : "; cin >> ilmu[stackI.top].stok;
			cout << "  Masukkan Harga Buku : Rp"; cin >> ilmu[stackI.top].harga;
			cout << "--------------------------------------------------- \n";
		} 
		countI++;
	}
}

void show_ilmu(){
	int j = 1;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << ">>>>  \t\t\t\t\t\t\t\t TOKO BUKU BU SRI \t\t\t\t\t\t\t\t <<<< \n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << "| \t\t\t\t\t\t\t\t Tema KE-ILMUAN \t\t\t\t\t\t\t\t    |\n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	cout << setw(4) << "No.";
	cout << setw(5) << "ID";
	cout << setw(60) << "Judul Buku";
	cout << setw(50) << "Penerbit";
	cout << setw(5) << "Stok";
	cout << setw(10) << "Harga";
	cout << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";

	for(int i = stackI.top; i >= 0; i--){
		cout << setw(4) << j;
		cout << setw(5) << "#" << setfill('0') << setw(4) << ilmu[i].id_buku;
		cout << setfill(' ') << setw(60) << ilmu[i].judul_buku;
		cout << setw(50) << ilmu[i].penerbit;
		cout << setw(5) << ilmu[i].stok;
		cout << fixed;
		cout << setw(10) << "Rp" <<setprecision(3) << ilmu[i].harga;
		cout << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
		j++;
	}
}

bool isFullI(){
	return (stackI.top >= (ukuran -1));
}

bool isEmprtyI(){
	return (stackI.top == -1);
}

void insertion_ilmu(){
	int j;
	for(int i = 1; i<stackI.top+1; i++){
		temp.id_buku = ilmu[i].id_buku;
		temp.judul_buku = ilmu[i].judul_buku;
		temp.penerbit = ilmu[i].penerbit;
		temp.stok = ilmu[i].stok;
		temp.harga = ilmu[i].harga;
		j = i - 1;
		while (ilmu[j].id_buku < temp.id_buku  && j >= 0){
			ilmu[j+1].id_buku = ilmu[j].id_buku;
			ilmu[j+1].judul_buku = ilmu[j].judul_buku;
			ilmu[j+1].penerbit = ilmu[j].penerbit;
			ilmu[j+1].stok = ilmu[j].stok;
			ilmu[j+1].harga = ilmu[j].harga;
			j--;
		}
		ilmu[j+1].id_buku = temp.id_buku;
		ilmu[j+1].judul_buku = temp.judul_buku;
		ilmu[j+1].penerbit = temp.penerbit;
		ilmu[j+1].stok = temp.stok;
		ilmu[j+1].harga = temp.harga;
	}
	cout << "Data Anda Sudah Diurutkan!!! \n";
	cout << "Silahkan Pilih Menu Show Data [2] Untuk Melihat Hasilnya!!! \n";
	cout << "Bila Anda Menambah Data Setelah Proses Sorting ini, ";
	cout << "Maka Anda Harus Melakukan Sorting Ulang Agar Data-Datanya Menjadi Terurut!!! \n";
}

void delete_ilmu(){
	int pilihanMenu, no;
	system("cls");


	do{
			cout <<  ">>>>  TOKO BUKU BU SRI  <<<<" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| >>>    PILIH MENU    <<< |" << endl;
			cout <<  "----------------------------" << endl;
			cout <<  "| [1] Data by No. \t   |" << endl;
			cout <<  "| [2] Top of Data \t   |" << endl;
			cout <<  "| [3] Clear All \t   |" << endl;
			cout <<  "| [4] Selesai \t\t   |" << endl;
			cout <<  "----------------------------" << endl;

			cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
			cout << endl;

			switch(pilihanMenu){
				case 1:
				system("cls");
				cout << "Masukkan No. Data : ";
				cin >> no;
				if(no == stackI.top+1){
					no = 0;
				}
				else{
					no = sizeI-no;
				}
				CD2++;
				ilmu[no].id_buku = 0;
				ilmu[no].judul_buku = " ";
				ilmu[no].penerbit = " ";
				ilmu[no].stok = 0;
				ilmu[no].harga = 0;
				cout << " . . . Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				system("pause");
				system("cls");
				sizeI -= 1; 
				break;

				case 2:
				system("cls");
				stackI.top--;
				if(CD2 == 0 && D2 == 0){
					sizeI=sizeI-1;
				}
				if(CD2 != 0 && D2 > 0){
					CD2--;
					D2--;
				}
				cout << " . . . Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				system("pause");
				system("cls");
				break;

				case 3:
				system("cls");
				stackI.top = -1;
				cout << " . . . Semua Data Sudah Terhapus, Cek Menu Show Data [2]!!! . . . \n";
				count = 0;
				sizeI = 0;
				CD2 = 0;
				D2 = 0;
				system("pause");
				system("cls");
				break;
			}			
	} while(pilihanMenu != 4);
}

void edit_ilmu(){
	int no;
	if(CD2 != 0){
		sizeI=sizeI+1;
	}
	cout << "Masukkan No. Data : ";
	cin >> no;
	if(no == stackI.top+1){
		no = 0;
	}
	else{
		no = sizeI-no;
	}

	cout << " Masukkan Id Buku : #"; 
	cin >> ilmu[no].id_buku;
	cout << "  Masukkan Judul Buku : "; 
	getline(cin >> ws, ilmu[no].judul_buku);
	cout << "  Masukkan Penerbit Buku : "; 
	getline(cin >> ws, ilmu[no].penerbit);
	cout << "  Masukkan Stok Buku : "; cin >> ilmu[no].stok;
	cout << "  Masukkan Harga Buku : Rp"; cin >> ilmu[no].harga;

	system("pause");
	system("cls");
	cout << "... Data Berhasil di Edit!!! ... \n";
}

void search_ilmu(){
	int x, no;
	bool found = false;

	cout << "!!!*** Untuk ID Dengan Awalan Angka 0, Cukup Tuliskan Angka Setelah 0 ***!!! \n";
	cout << "Misal : id = #0009 maka tuliskan 9 saja, dan untuk id yang bernilai puluhan/ratusan maka lakukan hal yang sama \n";
	cout << "Masukkan ID dari Buku yang Dicari : # ";
	cin >> x;

	if(sizeI <= stackI.top+1){
		for(int i = 0; i < sizeI; i++){
			if(x == ilmu[i].id_buku){
				found = true;
				if(i == 0){
						no = stackI.top+1;
					}
				else{
						no = sizeI-i;
					}
				cout << "Data Ditemukan di Indeks ke-" << i << " Atau No." << no <<  endl;

				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << ">>>>  \t\t\t\t\t\t\t\t TOKO BUKU BU SRI \t\t\t\t\t\t\t\t <<<< \n";
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "| \t\t\t\t\t\t\t\t Tema KE-ILMUAN \t\t\t\t\t\t\t\t    |\n";
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << setw(4) << "No.";
				cout << setw(5) << "ID";
				cout << setw(60) << "Judul Buku";
				cout << setw(50) << "Penerbit";
				cout << setw(5) << "Stok";
				cout << setw(10) << "Harga";
				cout << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
			
				cout << setw(4) << no;
				cout << setw(5) << "#" << setfill('0') << setw(4) << ilmu[i].id_buku;
				cout << setfill(' ') << setw(60) << ilmu[i].judul_buku;
				cout << setw(50) << ilmu[i].penerbit;
				cout << setw(5) << ilmu[i].stok;
				cout << fixed;
				cout << setw(10) << "Rp" <<setprecision(3) << ilmu[i].harga;
				cout << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				}
		}
		if(found == false){
			cout << "Data Tidak Ditemukan \n";
		}
	}
	else {
		if(found == false){
			cout << "Data Tidak Ditemukan \n";
		}
	}
}

//الْحَمْدُ لِلَّهِ رَبِّ الْعالَمِينَ
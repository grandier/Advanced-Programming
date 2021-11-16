#include <stdio.h>
#include <stdlib.h>

//Kemas Rafly Omar Thoriq - 2006577422

void menu();
void pesanPilihanMenu();
void menuSorting();
void menuExit();

struct dataSiswa {
    char nama[20];
    int nilai;
    int urutan;
};

int main(){
	int loop = 0, counterSiswa = 0, saved = 0, pilihan;
	int i, j;
	char temp[10];
	FILE *pfile;
		
	struct dataSiswa dataMahasiswa[20];
	
	if((pfile = fopen("dataMahasiswa.txt", "r"))==NULL){
      	printf("Tidak ada file.\n");
      	printf("Silahkan mulai dengan memasukkan data terlebih dahulu\n");
	}
	else{
		fscanf(pfile, "%d", &counterSiswa);
		for (i = 0; i < counterSiswa; ++i){
			fscanf(pfile, "%s", &dataMahasiswa[i].nama);
			fscanf(pfile, "%d", &dataMahasiswa[i].nilai);
			fflush(stdin);
		}
		printf("File DITEMUKAN, anda dapat langsung memakai program tanpa memasukkan data.\n");
		printf("Namun tetap bisa menambahkan data.\n");
	}
	fclose(pfile);
	system("pause");

	do{
		menu();
      	pesanPilihanMenu(); 
		scanf("%d", &pilihan);
      	
		
      	if(pilihan == 1){
 			system("cls");
   			printf("Masukkan nama mahasiswa: "); scanf("%20s", &dataMahasiswa[counterSiswa].nama);
			printf("Masukkan Nilai: "); scanf("%d", &dataMahasiswa[counterSiswa].nilai);
	
    		dataMahasiswa[counterSiswa].urutan = 0;
    		counterSiswa++;
		}
		
		else if(pilihan == 2){
			if(counterSiswa != 0){
				for (i = 0; i < counterSiswa; ++i) {
					int currentPos = 0;
					for (j = 0; j < counterSiswa; ++j) {
						if (dataMahasiswa[j].nilai > dataMahasiswa[i].nilai) {
							currentPos++;
						} else if (dataMahasiswa[j].nilai == dataMahasiswa[i].nilai) {
							if (j < i) {
							currentPos++;
							}
						}
					}
					dataMahasiswa[i].urutan = currentPos + 1;
				}
				
				for (i = 0; i < counterSiswa - 1 ; i++){
            		for (j = i + 1; j < counterSiswa; j++){
                		if (strcmp(dataMahasiswa[i].nama, dataMahasiswa[j].nama) > 0 && dataMahasiswa[i].nilai == dataMahasiswa[j].nilai) {
                    		strcpy(temp, dataMahasiswa[i].nama);
                    		strcpy(dataMahasiswa[i].nama, dataMahasiswa[j].nama);
                    		strcpy(dataMahasiswa[j].nama, temp);
                		}
            		}
        		}	
				menuSorting();
				int choice;
				pesanPilihanMenu(); scanf("%d", &choice);
				
				if(choice == 1){
					int i;
					printf("Menampilkan data keseluruhan . . . ");

					system("cls");
					
					for (i = 0; i < counterSiswa; ++i) {
							for (j = 0; j < counterSiswa; ++j) {
								if (dataMahasiswa[j].urutan == i + 1) {
									printf("Nama Mahasiswa: %s\n", dataMahasiswa[j].nama);
									printf("Nilai: %d\n", dataMahasiswa[j].nilai);
									printf("=~=~=~=~=~=~=~=~=~=~=~=~=\n");
								}
							}
						}
					printf("\n");
		      		system("pause");
				}
				else if(choice == 2){
					int input;
					system("cls");
					printf("Masukkan peringkat: ");
					scanf("%d", &input);
					
					for(i=0; i<counterSiswa; i++){
						if(dataMahasiswa[i].urutan==input){
						printf("Nama Mahasiswa: %s\n", dataMahasiswa[i].nama);
						printf("Nilai: %d\n", dataMahasiswa[i].nilai);
						break;
						}
					}
					if(i==counterSiswa){
						printf("Peringkat mahasiswa tidak ditemukan.\n");
					}
					system("pause");
				}
				else if(choice == 3){
					system("cls");
					char input[20];
					int i;
					printf("Masukkan Mahasiswa yang ingin dicari: "); scanf("%s", input);
					for (i = 0; i < counterSiswa; ++i) {
		      	    	if (strcmpi(input, dataMahasiswa[i].nama) == 0){
		      	    		printf("Nama Mahasiswa: %s\n", dataMahasiswa[i].nama);
							printf("Peringkat %d dengan Nilai %d\n", dataMahasiswa[i].urutan, dataMahasiswa[i].nilai);
							printf("=~=~=~=~=~=~=~=~=~=~=~=~=\n");
							break;
						}
					}
					if(i==counterSiswa){
						printf("Nama mahasiswa tidak ditemukan.\n");
					}
					printf("\n");
					system("pause");
				}
			}else {
				printf("\nError: Belum ada data yang tercatat! Silahkan mengisi data terlebih dahulu.\n");
				system("pause");
			}
		}
		else if(pilihan == 3){
			int j, i;
			if(counterSiswa != 0){
				FILE *pfile;
				pfile = fopen("dataMahasiswa.txt", "w");

				if (pfile != NULL){
					fprintf(pfile, "%d\n", counterSiswa);
					for (i = 0; i < counterSiswa; ++i) {
						for (j = 0; j < counterSiswa; ++j) {
							if (dataMahasiswa[j].urutan == i + 1) {	
								fprintf(pfile, "%s", dataMahasiswa[j].nama);
								fprintf(pfile, " %d\n", dataMahasiswa[j].nilai);
							}
						}
					}
					fclose(pfile);
					printf("\nSuccess: Data berhasil tersimpan!\n");
					saved = 1;
					system("pause");
				}
				else {
					printf("Error: FILE tidak berhasil dibuat, mohon ulangi program!\n");
					system("pause");	
				}	
			}else {
				printf("\nError: Belum ada data yang tercatat! Silahkan mengisi data terlebih dahulu.\n");
				system("pause");
			}
		}

		else if(pilihan == 4){
			if ((saved == 0) && (counterSiswa != 0)) {
				printf("Anda belum menyimpan data anda, Apakah Anda ingin melanjutkan? (Data yang tidak tersimpan akan hilang)\n");
				printf("Ya/Tidak = ");
				char answer[5];
				scanf("%s", answer);
				if (answer == "Ya" ){
					menuExit();
  					loop = -1;
  					break;
				}
			} else {
				menuExit();
  				loop = -1;
  				break;
			}
		}
	}while (loop != -1);
	
	return 0;
}

void menu() {
	system("cls");
  	printf("-=-=-=-=-=-=-=-=- Tampilan Menu -=-=-=-=-=-=-=-=-\n");
  	printf("1. Masukan Data Siswa Baru\n");
  	printf("2. Lihat Data \n");
  	printf("3. Simpan Data\n");
  	printf("4. Keluar dari program\n");
  	printf("-=-=-=-=-=-=-=-=- Tampilan Menu -=-=-=-=-=-=-=-=-\n");
}

void pesanPilihanMenu() {
  printf("\n");
  printf("Masukkan pilihan menu: ");
}

void menuSorting() {
	system("cls");
	printf("\n");
	printf("Silahkan memilih metode pengelihatan data:\n");
	printf("1. Tampilkan semua data \n");
	//printf("2. Menampilakan berdasarkan sorting\n");
	printf("2. Cari nama berdasarkan peringkat \n");
	printf("3. Cari peringkat berdasarkan nama\n");
	printf("\n");
}

void menuExit(){
	system("cls");
	printf("\nTerima kasih telah menggunakan program ini, as always take care...\n");
	system("pause");
	system("cls");
}

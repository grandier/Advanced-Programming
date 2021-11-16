#include <stdio.h>
#include <string.h>
#include <windows.h>

// Kemas Rafly Omar Thoriq
// 2006577422

void menu() {
	system("cls");
	printf("Tampilan Menu\n");
	printf("1. Search berdasarkan peringkat\n");
	printf("2. Search berdasarkan nama\n");
	printf("3. Keluar Program\n");
}

int main(){
    char nama[5][20];
    int size, i, j, temp;

	printf("Masukkan Jumlah Mahasiswa yang ingin di cek: ");
	scanf("%d", &size);
	
	int nilai[size];

    for (i = 0; i < size; ++i) {
		system("cls");
    	printf("-=-=-=-=-=-=-=-=-=-=- Data Mahasiswa #%d -=-=-=-=-=-=-=-=-=-=-\n", i + 1);
    	printf("Nama\t\t: "); scanf(" %[^\n]", nama[i]);
    	printf("Nilai \t: "); scanf("%d", &nilai[i]);
        printf("\n");
    }
    
    int loop=0, choice;
    do{
    	menu();
    	printf("Masukkan pilihan: "); scanf("%d", &choice);
    	
    	if (choice == 1){
    		char key[20];
    		for (i= 0 ; i< size - 1 ; i++ ){
			int swapped = 0;
				for (j= 0 ; j< size - i - 1 ; j++){
					if (nilai[j] > nilai[j+ 1 ]){
						temp = nilai[j];
						nilai[j] = nilai[j+ 1 ];
						nilai[j+ 1 ] = temp;
			swapped = 1 ;
			}
		}
		if (swapped == 0 );
		}
  	    	printf("Masukkan nama yang ingin dicari: "); 
			scanf(" %[^\n]", &key);
			for (i = 0; i < size; ++i){
				if (strcmpi(nama[i], key) == 0){
  				printf("\n-=-=-=-=-=-=-=-=-=-=- Data Mahasiswa #%d -=-=-=-=-=-=-=-=-=-=-\n", i + 1);
				printf("peringkat sudah ascending %d\n", i+1);
				printf("Nilai \t: %d\n", nilai[i]);
			  	}
			}
			system("pause");
		}
		else if (choice == 2) {
	    	int urutan;
	    	printf("Masukkan masukkan urutan: "); 
			scanf("%d", &urutan);
	    	
	    	int j;
	    	
	    	for (j = 0; j < size; ++j) {
	    		if (j+1==urutan){
	    			printf("-=-=-=-=-=-=-=-=-=-=- Data Mahasiswa #%d -=-=-=-=-=-=-=-=-=-=-\n", j + 1);
	    			printf("Nama: %s\n", nama[j]);
	    			printf("Nilai: %d\n", nilai[j]);
				}
			}
		system("pause");
		}
		else if (choice == 3) {
			loop = -1;
		}
	}while (loop != -1);
	return 0;
}

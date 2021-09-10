#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// Kemas Rafly Omar Thoriq
// 2006577422

int main(){
	int num, tid, i, j, count = 0, n,temp;
	double hasil;
	
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
	printf("Program untuk mencari bilangan kuadratik dengan multithreading.\n");
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
	
	printf("Silahkan masukkan sampai angka (ke-n) berapa ingin dicari = ");
	scanf("%d", &n);
	if(n>100000){
		printf("\nMaaf jumlah batas anda terlalu besar sehingga harap diulang.\n");
		return 0;
	}
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
	
	temp = sqrt(n);
	
	printf("\n\nAngka kuadratik 1 kehitung pada program ini.\n\n");
	
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		tid = omp_get_thread_num();
		printf("\nThread %d : ", tid);
		#pragma omp for schedule(static)
		for(i=1; i<=temp; i++){
			hasil = pow(i,2);
			printf("%.2lf, ", hasil);
            count++;    
		}  
	}

printf("\n\nBanyak bilangan kuadratik adalah : %d", count);
return 0;
}

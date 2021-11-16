#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// Kemas Rafly Omar Thoriq
// 2006577422

int findprime(int num);

int main(){
	int num, tid, i, j, count = 0, n, hasil, total=0, numt, start, finish;
	double t1, t2;
	double totalwaktu[100];
	
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
	printf("Program untuk mencari bilangan prima menggunakan parallel programming.\n");
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
	
	printf("Silahkan masukkan sampai angka (ke-n) berapa ingin dicari = ");
	scanf("%d", &n);
	if(n>100000){
		printf("\nMaaf jumlah batas anda terlalu besar sehingga harap diulang.\n");
		return 0;
	}
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
	
	omp_set_num_threads(4);
	#pragma omp parallel private (i, tid, start, finish, t1, t2, count)
	{
		t1 = omp_get_wtime();
		tid = omp_get_thread_num();
		numt = omp_get_num_threads();
		printf("\n\nThread %d : ", tid);
		start = (n/numt)*tid; 
  		finish = (n/numt)*(tid+1)-1;
  		
  		if(tid == numt-1){
   			finish = n-1;
  		}
		for(i=start; i<=finish; i++){
			hasil = findprime(i);
			if(hasil == 1){
				count++;
				printf("%d, ", i);
			}else{
				continue;
			}    
		}
		#pragma omp critical
		total += count;
		t2 = omp_get_wtime();
		
		totalwaktu[tid] = (t2-t1);
	}
	printf("\n\nBanyak bilangan prima adalah : %d \n", total);
	printf("Durasi: \n");
	for(i=0;i<4;i++){
		printf("Range %d - %d: %lf \n",((n/4)*i),((n/4)*(i+1)), totalwaktu[i]);
	}
	return 0;

}

int findprime(int n){
	int i, cek = 1;
	for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cek = 0;
            break;
        }
    }
    if (n <= 1)
        cek = 0;
 
    if (cek == 1) {
        return 1;  //prima
    }
    else {
        return 0;  //bukan prima
    }
}

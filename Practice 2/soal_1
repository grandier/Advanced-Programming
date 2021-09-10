#include <stdio.h>

// Kemas Rafly Omar Thoriq
// 2006577422

int faktorial(int n);

int main(){
	int n;
	
	printf("Masukkan angka yang ingin dijadikan faktorial versi zufar: ");
	scanf("%d", &n);
	
	printf("Nilai Faktorial versi zufar dari %d adalah: %d", n, faktorial(n));
	return 0;
}

int faktorial(int n){
	if (n == 0) {
		return 1;
	} 
	else if(n%2==0){
		return n/2 * faktorial(n-1);
	}
	else {
		return n*faktorial(n-1);
	}
}

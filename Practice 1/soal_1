#include <stdio.h>

// Kemas Rafly Omar Thoriq
// 2006577422

int main() {
	
  int matriks1[10][10], matriks2[10][10], hasil[10][10];
  int i, j, k, a, b,  jumlah = 0;
  printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
  printf("Masukkan Barisnya: ");
  scanf("%d",&a);
  printf("Masukkan Kolomnya ");
  scanf("%d",&b);


    printf("Masukkan elemen matriks pertama: \n");
    for(i = 0; i < a; i++){
      for(j = 0; j < b; j++){
        scanf("%d", &matriks1[i][j]);
      }
    }
  	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
  	for(i = 0; i < a; i++){
      for(j = 0; j < b; j++){
        matriks2[i][j] = matriks1[i][j]+0;
      }
    }
  	
    for(i = 0; i < a; i++){
      for(j = 0; j < b; j++){
      	for(k = 0; k < b; k++){
          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
        hasil[i][j] = jumlah;
        jumlah = 0;
      }
    }
    
    printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
    printf("Hasil kuadrat matriksnya: \n");
    for(i = 0; i < a; i++){
      for(j = 0; j < b; j++){
        printf("%d\t", hasil[i][j]);
      }
      printf("\n");
    }
	printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=");
  
  return 0;
}

#include <stdio.h>

// Kemas Rafly Omar Thoriq
// 2006577422

int main(){
    int m,n,i,j;   
	int matriks1[10][10], matriks2[10][10];
	
	printf("Masukkan Barisnya: ");
  	scanf("%d",&m);
  	printf("Masukkan Kolomnya: ");
  	scanf("%d",&n);
  	
  	printf("Masukkan elemen matriks: \n");
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        scanf("%d", &matriks1[i][j]);
      }
    }
  	printf("\n");
  	
    printf("Matriks setelah diputar melawan arah jarum jam \n");
    for(i=2; i>=0;i--){
    	for(j=0; j<=1;j++){
    		printf("%d ", matriks1[j][i]);
		}
		printf("\n");
	}
	return 0;
}

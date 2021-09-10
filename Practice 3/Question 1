#include <stdio.h>
#include <string.h>

// Kemas Rafly Omar Thoriq
// 2006577422

int main (void) {
	   	char temp;
	   	char karakter[100][2];
	   	int n, i, j;
   
   	printf("Masukkan jumlah karakternya: ");
    scanf("%d", &n);
    
    char s[n + 5];
    int list[35][3];
    
    printf("Masukkan isi karakter yang ingin di urutkan: ");
    scanf("%s", s);
   	
   	for (i = 0; i < 26; ++i) {
        list[i][1] = 0;
        list[i][2] = i;
    }
    
    for (i = 0; i < n; ++i) {
        int x = s[i] - 'A';
        list[x][1]++;
    }
    
    for (i = 0; i < 26; ++i) {
        int j, max, hmax, posmax, temp, htemp;
        max = list[i][1];
        hmax = list[i][2];
        posmax = i;
        
        for (j = i + 1; j < 26; ++j) {
        	if (list[j][1] == max) {
                if (list[j][2] < hmax) {
                    max = list[j][1];
                    hmax = list[j][2];
                    posmax = j;
                }
        	}
            else if (list[j][1] > max) {
                max = list[j][1];
                hmax = list[j][2];
                posmax = j;
            } 
			
        }
        temp = list[i][1];
        list[i][1] = max;
        list[posmax][1] = temp;
        
        htemp = list[i][2];
        list[i][2] = hmax;
        list[posmax][2] = htemp;
    }

    i = 0;
    while (list[i][1] > 0) {
        char c = list[i][2] + 'A';
        for (j = 0; j < list[i][1]; ++j) {
            printf("%c", c);
        }
        i++;
    }
    return 0;
}

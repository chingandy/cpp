#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int b[3][3] = {2,4,6,8,10,12,14,16,18};
	int c[3][3]= {0};
	int i , j ,k;

	/*printf("�x�} a\n");
	for(i = 0 ; i < 3 ; i ++){
		for(j = 0 ; j < 3 ; j++){
			printf("%-5d", a[i][j]);
		}
		printf("\n");
	}
	printf("�x�} b\n");
	for(i = 0 ; i < 3 ; i ++){
		for(j = 0 ; j < 3 ; j++){
			printf("%-5d", b[i][j]);
		}
		printf("\n");
	}*/

	for(i = 0 ; i < 3 ; i++){
		for(j = 0 ; j < 3 ; j ++){
			for(k = 0 ; k < 3 ; k ++){
				c[i][j] += a[i][k] * b[k][j];
			}

		}
	}
	//printf("�x�} c\n");
	for(i = 0 ; i < 3 ; i ++){
		for(j = 0 ; j < 3 ; j++){
			printf("%-5d", c[i][j]);
		}
		printf("\n");
	}
	return 0 ;
}

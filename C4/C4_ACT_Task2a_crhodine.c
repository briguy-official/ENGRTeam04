
#include <stdio.h>

int main(void){
	double numRows = 0.0;
	double numColumns = 0.0;
	int i = 0;
	int j = 0;
	
	printf("Number of rows: ");
	scanf("%lf", &numRows);
	printf("Number of columns: ");
	scanf("%lf", &numColumns);
	
	for (i = 1; i <= numRows; ++i){
		printf("%d", i);
		for(j = i; j < i + numColumns-1;){
			printf(" %d", ++j);
		}
	    printf("\n");
	}
	return 0;
}
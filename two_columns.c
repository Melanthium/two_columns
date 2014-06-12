#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void main(){
	FILE *file1, *file2;
	char fileName1[] = "text1.txt";
	char fileName2[] = "text2.txt";
	char c1, c2;
	char str1[40], str2[40];

	int i;

	file1 = fopen(fileName1, "r");
	file2 = fopen(fileName2, "r");

	fseek(file1,0,SEEK_SET);
	fseek(file2,0,SEEK_SET);
	

	while ((fgets(str1,sizeof(str1),file1)) && (fgets(str2,sizeof(str2),file2))){
		str1[strlen(str1)-1] = '\0';

		for (i=0; i < strlen(str1) || i < strlen(str2); i++){
			if (str1[i] != str2[i]){
				str1[i] = toupper(str1[i]);
				str2[i] = toupper(str2[i]);
			}
		}
		

		printf("%-40s", str1);
		printf("%s", str2);
	}

	fclose(file1);
	fclose(file2);

	getch();
}

#include <stdio.h>
#include <string.h>	
int main()
{
	int i,l;
	char str[128];
	char abc[128];
		
		printf("\n文字列を入力=");	
		scanf("%s",str); 
		strcpy(abc,str);
		l=strlen(str);
			
	for (i=0;i<l;i++) {
		 if (97<=abc[i] && abc[i]<=122) abc[i]-=32;
	}		
		printf("今入力した文字列%s\n\n",str);
		printf("大文字に直すと%s\n\n",abc);
		printf("文字列の長さ:%d\n\n",l);
		
		
		

		
		
	return 0;
}

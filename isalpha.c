#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE *fp;
    FILE *fp2;
    int c;
    
    fp = fopen("text.txt", "r");
    fp2 = fopen("newtext.txt", "w");
    
     while ((c = getc(fp)) != EOF){
          
        if ( isalpha(c)) {
        fprintf(fp2,"%c",c);
    	}else if ( c=='\n') {
        fprintf(fp2,"\n");
    	} else {
        fprintf(fp2," ");
    	}
     }
      
   printf("newtext.txtに挿入\n");
	 
    fclose(fp);
    fclose(fp2);           
 }

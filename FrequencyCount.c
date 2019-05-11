#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>    /* exit(  ) で必要 */
#include <string.h>

#define BYTE 256
int alpha[BYTE];       /* 関数の外で宣言 */

void Count(FILE *fp);
void Result(FILE *fp2) ;
void main(void);

  /* ファイル中の英文字の出現頻度を調べる */
void Count(FILE *fp)
{
    int c;
      /* ファイルの終わりに達するまで１文字読み込む */
    while ((c = getc(fp)) != EOF)
    {
          /* c がアルファベットの小文字か大文字なら */
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') 
            alpha[c]++;        /* カウントする */
    }
}

void Result(FILE *fp2)
{
    int c;

    for (c = 'a'; c <= 'z'; c++)       /* 小文字+大文字の出現頻度を */
        fprintf(fp2,"%c:%d\n",  c, alpha[c]+alpha[c-32]);    /* 表示 */
    fprintf(fp2,"\n");
   
}

void main(void)
{
    FILE *fp;
    FILE *fp2;
    
    fp = fopen("text.txt", "r");
    fp2 = fopen("count.txt", "w");
    
    printf("アルファベットの出現頻度をcount.txtに挿入\n");
    Count(fp) ;        /* 文字の出現頻度を調べて */
    Result(fp2);       /* 表示する */
	 
    fclose(fp);
    fclose(fp2);            /* ファイルを閉じる */
 }

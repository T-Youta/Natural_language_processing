#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main ()
{
FILE* fp;
char c;
char buf[1024];
char word[2048][1024];
int bWord = 0;
fp = fopen("newtext.txt", "r");
int n=0;
/* 初期化 */
buf[0] = '\0';

while ((c = fgetc(fp)) != EOF)
{
	if (isalnum(c))
	{
		/* アルファベットまたは数字 
		単語領域に追加する */
		int n = strlen(buf);
		buf[n++] = c;
		buf[n] = '\0';

		/* 単語フラグを立てる */
		bWord = 1;

		}
	else if (c == ' ' || c == '.')
	{
		/* 空白文字若しくは'.'の場合
		以前が単語で有った場合は、単語の終了
		単語を出力する */
		if (bWord)
		{
			printf("%s\n", buf);
			
			
			
			/* 単語領域を再度初期化 */
			buf[0] = '\0';
			bWord = 0;

		}
	}
}
fclose(fp);
return 0;
} 

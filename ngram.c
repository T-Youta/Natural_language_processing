#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 32
void setlastch(int n, char chr, char lastch[]);
void printngram(int n, char lastch[]);

int main(int argc, char *argv[])
{
int i;
int n;
char lastch[N] = {' '};
char chr;
if(argc != 2){
fprintf(stderr, "使い方 $./ngram (N の値) "
" < (入力ファイル名) > (出力ファイル名)\n");
exit(1);
}
if(((n = atoi (argv [1])) < 1) || (n >= N)){
fprintf(stderr, "N の値が不適切です。\n");
exit(1);
}


while((chr = getchar()) != EOF){
if(chr != '\n'){
setlastch(n, chr, lastch);
printngram(n, lastch);
}
}
return 0;
}
void setlastch(int n, char chr, char lastch[])
{
int i;
for(i = n - 2; i >= 0; --i){
lastch[i + 1] = lastch[i];
}
lastch[0] = chr;
}
void printngram(int n, char lastch[])
{
int i;
for(i = n - 1; i >= 0; --i){
printf("%c", lastch[i]);
}
printf("\n");
}

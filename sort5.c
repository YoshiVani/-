#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct kamoku{
char mei[20];
char kana[10];
int ei;
int koku;
int su;
int sha;
int ri;
int goukei;
};
#define SIZE 30
int main(){
	struct kamoku seiseki[SIZE],min;
	int i,j,n,m;
	FILE*input,*output;
	char infname[16],outfname[16];
	printf("input file name：");
	scanf("%s",infname);
	printf("output file name：");
	scanf("%s",outfname);
	if((input=fopen(infname,"r"))==NULL){
		printf("flie not found\n");
		exit(1);
	}
	if((output=fopen(outfname,"w"))==NULL){
		printf("cannot found\n");
		exit(1);
	}
	n=SIZE-1;
	for(i=0;i<SIZE;i++){
		if(fscanf(input,"%s%s%d%d%d%d%d",
		seiseki[i].mei,seiseki[i].kana,&seiseki[i].ei,&seiseki[i].koku,
		&seiseki[i].su,&seiseki[i].sha,&seiseki[i].ri)==EOF){
			n=i-1;
			break;
		}
			seiseki[i].goukei=seiseki[i].ei+seiseki[i].koku+seiseki[i].su
			+seiseki[i].sha+seiseki[i].ri;
			if(seiseki[i].goukei<=300){
				i=i-1;
			}
	}
	for(i=0;i<=n-1;i++){
		min = seiseki[i];
		m = i;
		for(j=i+1;j<=n;j++){
			if( strcmp(min.kana,seiseki[j].kana)>0){
				min = seiseki[j];
				m=j;
			}
		}
		seiseki[m]=seiseki[i];
		seiseki[i]=min;
	}
	printf("\tname\t\tkana\tGoukei\tEnglish\tNat.\tMath\tSociety\tScience\n");
	for(i=0;i<=n;i++){
		printf("\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n",
		seiseki[i].mei,seiseki[i].kana,seiseki[i].goukei,seiseki[i].ei,seiseki[i].koku,
		seiseki[i].su,seiseki[i].sha,seiseki[i].ri);
	}
	for(i=0;i<=n;i++){
		fprintf(output,"\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n",
		seiseki[i].mei,seiseki[i].kana,seiseki[i].goukei,seiseki[i].ei,seiseki[i].koku,
		seiseki[i].su,seiseki[i].sha,seiseki[i].ri);
	}
	fclose(input);
	fclose(output);
	return 0;
}

/*
追記：
テスト用のファイルとして、以下の情報をテキストファイルに保存し、このファイルをプログラムに入力すると正しい結果が得られます。

赤井    アカイ    78 65 87 92 70
伊藤    イトウ    56 57 63 87 45
鈴木    スズキ    93 92 89 67 75
藤原    フジハラ  72 82 71 63 82
田中    タナカ    88 66 91 74 79
山田    ヤマダ    45 54 62 86 90
奥村    オクムラ  32 78 63 82 46
高野    タカノ    93 78 65 88 96
松本    マツモト  85 67 79 57 87
相田    アイダ    69 42 52 63 56

*/
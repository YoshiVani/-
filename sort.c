/*
 * 実行方法（Windows のコマンドプロンプトの場合）：
 *   gcc sort.c -o 任意の実行ファイル名.exe 
 *   任意の実行ファイル名.exe 
 *
 * ※ 詳細な環境や補足情報は README.md をご参照ください。 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct kamoku{
char mei[20]; // 名前
char kana[10]; // カナ表記
int ei; // 英語の点数
int koku; // 国語の点数
int su;　//数学の点数
int sha;　//社会の点数
int ri;　//理科の点数
int goukei;　　//合計点
};

#define SIZE 30　  // 成績データの最大件数
int main(){
	struct kamoku seiseki[SIZE],min;　 // 成績配列と一時的な最小データ用変数
	int i,j,n,m;
	FILE*input,*output; // 入出力ファイルポインタ
	char infname[16],outfname[16];　 // 入出力ファイル名格納用
	printf("input file name：");　
	scanf("%s",infname);　 // 入力ファイル名の入力
	printf("output file name：");
	scanf("%s",outfname);　 // 出力ファイル名の入力

	/* 入力ファイルを開く。失敗時は終了 */
	if((input=fopen(infname,"r"))==NULL){
		printf("flie not found\n");
		exit(1);
	}

	/* 出力ファイルを開く。失敗時は終了 */
	if((output=fopen(outfname,"w"))==NULL){
		printf("cannot found\n");
		exit(1);
	}
	n=SIZE-1;　  // 最大読み込みインデックス

	/* ファイルから成績データを読み込み */
	for(i=0;i<SIZE;i++){
		if(fscanf(input,"%s%s%d%d%d%d%d",
		seiseki[i].mei,seiseki[i].kana,&seiseki[i].ei,&seiseki[i].koku,
		&seiseki[i].su,&seiseki[i].sha,&seiseki[i].ri)==EOF){
			n=i-1;
			break;   // EOFに達したら実データ数を設定しループ終了
		}
	/* 合計点を計算 */
			seiseki[i].goukei=seiseki[i].ei+seiseki[i].koku+seiseki[i].su
			+seiseki[i].sha+seiseki[i].ri;

	/* 合計点が300以下の場合は読み込んだカウントを戻す（読み飛ばし） */
			if(seiseki[i].goukei<=300){
				i=i-1;
			}
	}
	/* かな文字絵r津を基準に成績でデータを昇順ソート */
	for(i=0;i<=n-1;i++){
		min = seiseki[i]; //最小値候補を設定
		m = i;　//最小値候補のインデックス
		
	/* 未ソート部分から最小値を探索 */
		for(j=i+1;j<=n;j++){
			if( strcmp(min.kana,seiseki[j].kana)>0){
				min = seiseki[j];
				m=j;
			}
		}
		
	/* 最小値と現在のi番目の要素を交換 */
		seiseki[m]=seiseki[i];
		seiseki[i]=min;
	}
	printf("\tname\t\tkana\tGoukei\tEnglish\tNat.\tMath\tSociety\tScience\n");　//ヘッダー表示

	/* 成績データを画面に表示 */
	for(i=0;i<=n;i++){
		printf("\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n",
		seiseki[i].mei,seiseki[i].kana,seiseki[i].goukei,seiseki[i].ei,seiseki[i].koku,
		seiseki[i].su,seiseki[i].sha,seiseki[i].ri);
	}

	/* 成績データをファイルに書き込み */
	for(i=0;i<=n;i++){
		fprintf(output,"\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n",
		seiseki[i].mei,seiseki[i].kana,seiseki[i].goukei,seiseki[i].ei,seiseki[i].koku,
		seiseki[i].su,seiseki[i].sha,seiseki[i].ri);
	}

	/* ファイルを閉じる */
	fclose(input);
	fclose(output);

	return 0;
}

/*
テスト用のファイルとして以下の情報をテキストファイルに保存し、プログラムに入力すると正しい結果が得られます。

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

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<Windows.h>
///////////////////////////////////////////////////////////
//         PARKING SYSTEM V.1.0				           ////
//This is logical for parking system i hope you like this/////
//*This source is free for education                       ///
////////////////////////////////////////////////////////////
//			BUILD ON C++ 2010                              ////
//          Created By Nando on 01/02/2018              ////
////////////////////////////////////////////////////////////
int index=0;
int index1=0;
struct data {
	int jam;
	int menit;
	int detik;
	int jamkeluar;
	int menitkeluar;
	int detikkeluar;
	char platmotor[100];
}call[100];
void time(){
	time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );


	call[index].jam= localTime->tm_hour;
	call[index].menit= localTime->tm_min;
	call[index].detik= localTime->tm_sec;

};
void keluar() {
	time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );


	call[index1].jamkeluar= localTime->tm_hour;
	call[index1].menitkeluar= localTime->tm_min;
	call[index1].detikkeluar= localTime->tm_sec;
}
int main ()
{
	int ready=0;
	int choose=0;
	char plat[100];
	int totaljam,totalmenit,totaldetik;
	while(choose!=3){
	do{
	system("cls");
	printf("1.Enter The Parking Area\n");
	printf("2.Exit The Parking Area\n");
	printf("3.Exit\n");
	printf("choose your choice:");
	scanf("%d",&choose);fflush(stdin);
	}while(choose>2);
	if(choose==1){
	system("cls");
	printf("please input plat number :");
	scanf("%s",plat);fflush(stdin);
	for(int i=0;i<index;i++){
		if(strcmp(plat,call[i].platmotor)==0){
			printf("Already Input!!");
			ready=1;
			getchar();
			break;
		}
	}
	if(ready==0){
		strcpy(call[index].platmotor,plat);
		time();
		index++;
	}
		ready=0;
	}
	if(choose==2){
	system("cls");
	printf("Please input Plat number :");
	scanf("%s",plat);fflush(stdin);
	for(int i=0;i<index;i++){
		if(strcmp(plat,call[i].platmotor)==0){
			printf("time of entry:");
			printf(" %d:%d:%d\n",call[i].jam,call[i].menit,call[i].detik);
			keluar();
			printf("time of exit:");
			printf(" %d:%d:%d\n",call[index1].jamkeluar,call[index1].menitkeluar,call[index1].detikkeluar);
			totaljam=(call[index1].jamkeluar-call[i].jam)*3600;
			totalmenit=(call[index1].menitkeluar+call[i].menit)*60;
			totaldetik=(call[index1].detikkeluar+call[i].detik)*1;
			if(totaljam<1){
				totaljam*-1;
			}
			if(totalmenit<1){
				totalmenit*-1;
			}
			if(totaldetik<1){
				totaldetik*-1;
			}
			int result=totaljam+totalmenit+totaldetik;
			int result2=result%60;
			int harga;
			if(result2!=0){
				harga=(result/3600)+1;
			}
			if(result2==0){
				harga=(result/3600);
			}
			if(totaljam==0){
				harga=1;
			}
			printf("TOTAL PARKING COST %d",harga*2000);
			for(int x = i; x<=index;x++){
				
			call[x]=call[x+1];
			
			}
			index--;
			break;
			getchar();
			break;
		}
		if(i==index-1){
			printf("Nothing Found!!");
			getchar();
		}
	}
	}
	}
	return 0;
	getchar();
}
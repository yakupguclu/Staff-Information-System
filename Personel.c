#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> 
#include<conio.h>
//FONKSÝYON PROTOTÝPLERÝ
void Kayit_Sil();
void tc_bul();
void Kayit_Ekle();
void Personel_Listele();
void isimle_bul();
void kayitGuncelle();
//STRUCT TANIMLAMASI
typedef struct {
	char isim[100];
	char TCKimlikNo[100];
    char telefon[100];
	char eposta[100];
	char adres[100];
}personel;
personel person;
//MENÜ
int main () {
	setlocale(LC_ALL, "Turkish");

	printf("				-----> PERSONEL BÝLGÝ SÝSTEMÝ <-----\n"); 
	int islem;
	printf("		ÝÞLEMLER\n\n");
		printf("1. Kayýt Ekle\n2. Personel Listele\n3. Kaydý Düzenle\n4. TC Kimlik No ile Kayýt Bul\n5. Ýsim ile Kayýt Bul\n6. Kayýt Sil\n0. Çýkýþ\n");	
			printf("Yapmak Ýstediðiniz Ýþlem Numarasýný Giriniz :  ");
			scanf("%d",&islem);
			printf("\n");
		switch(islem){
			case 1: Kayit_Ekle();          break;
			case 2: Personel_Listele();    break;
			case 3:	kayitGuncelle();	   break;
			case 4: tc_bul();		       break;
			case 5: isimle_bul();		   break;
			case 6: Kayit_Sil();  	       break;
			case 0: printf("Baþarýyla Çýkýþ Yapýldý !!"); break;
			default: printf("Hatalý Tuþlama Yapýldý Ana Menüye Yönlendiriliyorsunuz !!\n"); main();
		}
	return 0;
}
// KAYIT EKLEME 
void Kayit_Ekle(){
	FILE *fp;
	fp=fopen("Personel.txt","a");
	if(fp==NULL){
		printf("Dosya Oluþturalamadý...");
	}
	printf("Ýsim :  ");
	scanf("%s",&person.isim);
		printf("T.C. Kimlik No : ");
		scanf("%s",&person.TCKimlikNo);
			printf("Telefon : ");
			scanf("%s",&person.telefon);
				printf("E-posta : ");
				scanf("%s",&person.eposta);
					printf("Adres : ");
					scanf("%s",&person.adres);
					fwrite(&person,sizeof(person),1,fp);	
							printf("Kayýt Baþarýyla Tamamlandý...\n");							
fclose(fp);
main();
}
//PERSONEL LÝSTELEME
void Personel_Listele() {
	FILE *fp;
	fp=fopen("Personel.txt","r");
	if(fp==NULL){
		printf("HATA");
		exit(1);
	}
	while(fread(&person,sizeof(person),1,fp)==1){
					printf("Ýsim : %s\n",person.isim);
					printf("TC Kimlik No : %s\n",person.TCKimlikNo);
					printf("Telefon : %s\n",person.telefon);
					printf("E-posta : %s\n",person.eposta);
					printf("Adres : %s\n\n",person.adres);
	}	
	printf("Kayýt Listelenmiþtir\n");
	fclose(fp);	
	main();
}
//ÝSÝMLE KAYIT BULMA
void isimle_bul() {
		FILE *fp;
		fp=fopen("Personel.txt","rb+");
		char search[100];
		int x;
		printf("Bulmak Ýstediðiniz Ýsimi Giriniz :  ");
		scanf("%s",&search);
			while(fread(&person,sizeof(person),1,fp)==1){
				if(strcmp(search,person.isim)==0){
					printf("Ýsim : %s\n",person.isim);
					printf("TC Kimlik No : %s\n",person.TCKimlikNo);
					printf("Telefon : %s\n",person.telefon);
					printf("E-posta : %s\n",person.eposta);
					printf("Adres : %s\n",person.adres);
					printf("Kayýt Listelenmiþtir");
					x++;
				}
			}		
			if(x==0){
				printf("Kayýt Bulunamadý\n");
				main();
			}
	fclose(fp);
	main();
}
//KAYIT GÜNCELLEME
void kayitGuncelle(){
	FILE *fp;
	fp=fopen("Personel.txt","rb+");
	char search[100];
	int x=0;
	int y=0;
	int z=0;
	
	printf("Ýsimi Giriniz : \n");
	scanf("%s",&search);
	
	while (fread(&person,sizeof(person),1,fp)==1){
		if(strcmp(search,person.isim)==0){
			printf("Ýsim: %s\n",person.isim);
			printf("TC Kimlik No : %s\n",person.TCKimlikNo);
			printf("Telefon : %s\n",person.telefon);
			printf("E-posta : %s\n",person.eposta);
			printf("Adres : %s\n",person.adres);
			printf("\nKayýt Listelenmiþtir\n");
			x++;
		}
		z++;
			if(x==1){
				y+=z;
				x=2;
			}
	}	
	if(x==0){
		printf("Kayit Bulunamadi..");
		fclose(fp);
		main();
	}
	printf("Yeni Ýsim Giriniz : ");
	scanf("%s",&person.isim);
		printf("Yeni Tc Kimlik No : ");
		scanf("%s",&person.TCKimlikNo);
			printf("Yeni Telefon Numarasýný Giriniz : ");
			scanf("%s",&person.telefon);
				printf("Yeni E-posta Adresini Giriniz : ");
				scanf("%s",&person.eposta);
					printf("Yeni Adres Giriniz : ");
					scanf("%s",person.adres);
					printf("\n");
					fseek(fp,(y-1)*sizeof(person),SEEK_SET);
					fwrite(&person,sizeof(person),1,fp);
					
					fclose(fp);
					printf("Ýþlem Baþarýlý\n\n");
					main();
					
}
//TC ÝLE KAYIT BULMA
void tc_bul(){
	FILE *fp;
	fp=fopen("Personel.txt","rb+");
	
	if(fp==NULL){
		printf("HATA");
		exit(1);
	}
	char number[100];
	int x=0;
		printf("TC Kimlik No : ");
		scanf("%s",number);
			while(fread(&person,sizeof(person),1,fp)==1){
				if(strcmp(number,person.TCKimlikNo)==0){
					printf("Ýsim : %s\n",person.isim);
					printf("TC Kimlik No : %s\n",person.TCKimlikNo);
					printf("Telefon : %s\n",person.telefon);
					printf("E-posta : %s\n",person.eposta);
					printf("Adres : %s\n",person.adres);
					printf("Kayýt Listelenmiþtir");
					x++;
				}
			}
			if(x==0){
				printf("Kayýt Bulunamadý\n");
			}
			fclose(fp);
			main();
}
//KAYIT SÝLME
void Kayit_Sil() {
	FILE *fp;
	fp=fopen("Personel.txt","rb+");
	FILE *fptr;
	fptr=fopen("temp.txt","wb+");
		if(fp==NULL){
			printf("HATA");
			exit(1);
		}
		if(fptr==NULL){
			printf("HATA");
			exit(1);
		}
		char number[100];
		int x=0;
		printf("TC Kimlik No : ");
		scanf("%s",&number);
		
			while(fread(&person,sizeof(person),1,fp)==1){
				if(strcmp(number,person.TCKimlikNo)!=0){
					fwrite(&person,sizeof(person),1,fptr);
				}
				else {
					x++;
				}
			}
			if(x==0){
				printf("BULUNAMADI HATA");
			}
			fclose(fp);
			fclose(fptr);
			remove("Personel.txt");
			rename("temp.txt","personel.txt");
				printf("Ýþlem Baþarýlý...\n");
				main();
}

















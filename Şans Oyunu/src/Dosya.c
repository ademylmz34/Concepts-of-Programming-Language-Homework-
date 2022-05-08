/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Dosyadan verilerin okunup dizilere aktarıldığı sınıf
* </p>
*/


#include "Dosya.h"

Dosya DosyaOlustur(){
	Dosya this;
	this = (Dosya)malloc(sizeof(struct DOSYA));
	this->adSoyad=NULL;
	this->bakiye=0;
	this->yatirilanBakiyeOrani=0;
	this->sansliSayi=0;
	this->sayi=0;
	this->kisileriAktar = &KisileriAktar;
	this->sayilariAktar=&SayilariAktar;
	this->yoket = &DosyaYokEt;
	return this;
}
void KisileriAktar(const Dosya this){
	char* fileName="doc/Kisiler.txt";
	FILE *fp= fopen(fileName,"r");
	
	this->toplamKisiSayisi=GetSatirSayisi(fileName);
	int uzunluk=this->toplamKisiSayisi;
	
	this->kisilerDizisi= (struct KISI**)malloc(sizeof(struct KISI) * uzunluk);
	
	if(fp==NULL){
		perror("Unable to open the file");
		exit(1);
	}
	else{
	
		char* str;
		int satir=0;
		char *kisiBilgileri[4];
		char line[1000];
        while(fgets(line, 255, fp)){
			if(line!=" "){
				str = strtok (line, "#");
				kisiBilgileri[0]=str;
				int sayac=1;
				while (str != NULL)  {
				str = strtok (NULL, "#");
				kisiBilgileri[sayac]=str;
				sayac++;
			}
			
		
			this->adSoyad=kisiBilgileri[0];
			this->bakiye=atof(kisiBilgileri[1]);
			this->yatirilanBakiyeOrani=atof(kisiBilgileri[2]);
			this->sansliSayi = atoi(kisiBilgileri[3]);
	
			this->kisilerDizisi[satir]=kisiOlustur(strdup(this->adSoyad),this->bakiye,this->yatirilanBakiyeOrani,this->sansliSayi);
			satir++;
			}
			
	  }
	
	}
	fclose(fp);
}
void SayilariAktar(const Dosya this){
	FILE *fp= fopen("doc/Sayilar.txt","r");
	this->sayilarDizisiUzunlugu=GetSatirSayisi("doc/Sayilar.txt");
	int uzunluk=this->sayilarDizisiUzunlugu;
	int SayilarArray[uzunluk];
	if(fp==NULL){
		perror("Unable to open the file");
		exit(1);
	}
	int satir=0;
	char line[5];
	int numberArray[uzunluk];
    int i;
    for (i = 0; i < uzunluk; i++)
    {
        fscanf(fp, "%d", &numberArray[i]);
    }

	this->sayilarDizisi=numberArray;
	fclose(fp);
}
int GetSatirSayisi(char* fileName){
	FILE *fp= fopen(fileName,"r");
	int lines=0;
	char line[200];

	while(fgets(line, 200, fp) != NULL) {
		if(strlen(line) > 1) {
			lines++;
		}
	}
	
    fclose(fp);
	
    return lines;
}

void DosyaYokEt(Dosya this){
	if(this == NULL) return;
	int i;
	for(i=0;i<this->toplamKisiSayisi;i++){
		this->kisilerDizisi[i]->yoket(this->kisilerDizisi[i]);
	}
	free(this->kisilerDizisi);
	free(this->sayilarDizisi);
	free(this);
}
/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Oyun'un başlatıldığı sınıf
* </p>
*/


#include "Oyun.h"

Oyun OyunOlustur(){
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->dosya=DosyaOlustur();
	this->masaBakiye=0;
	this->elenenKisiSayisi=0;
	this->dosya->kisileriAktar(this->dosya);
	this->toplamKisiSayisi=this->dosya->toplamKisiSayisi;
	this->dosya->sayilariAktar(this->dosya);
	this->sayilarDizisiUzunlugu=this->dosya->sayilarDizisiUzunlugu;
	this->sayilar=this->dosya->sayilarDizisi;
	this->yoket=&OyunYokEt;
	this->basla=&Basla;
	return this;
}
void Basla(const Oyun this){
		
	int sayilarrr[this->sayilarDizisiUzunlugu];
	int k;
	for(k=0;k<this->sayilarDizisiUzunlugu;k++){
		sayilarrr[k]=this->sayilar[k];
	}
	int tur=1;
	int i=0;
	while(i<this->sayilarDizisiUzunlugu){
		int j;
		for(j=0;j<this->toplamKisiSayisi;j++){
			this->kisiYatirilanBakiye = this->dosya->kisilerDizisi[j]->bakiye * this->dosya->kisilerDizisi[j]->yatirilanBakiyeOrani;
			this->kisisanslisayi = this->dosya->kisilerDizisi[j]->sayi;
			if(this->dosya->kisilerDizisi[j]->bakiye <= 1000){
				this->elenenKisiSayisi++;
				continue;
			}
			else if(this->kisisanslisayi == sayilarrr[i]){
				this->dosya->kisilerDizisi[j]->bakiye -= this->kisiYatirilanBakiye;
				this->masaBakiye += this->kisiYatirilanBakiye;
				this->dosya->kisilerDizisi[j]->bakiye += 10*this->kisiYatirilanBakiye;
				this->masaBakiye -= 10*this->kisiYatirilanBakiye;
			}
			else{
				this->dosya->kisilerDizisi[j]->bakiye -= this->kisiYatirilanBakiye;
				this->masaBakiye += this->kisiYatirilanBakiye;
			}
					
		}
				
		if(this->elenenKisiSayisi != this->toplamKisiSayisi-1){
			this->zenginKisi = enZenginKisiBul(this);
		}
		yazdir(this->elenenKisiSayisi,this->zenginKisi->adSoyad,this->zenginKisi->bakiye,this->masaBakiye,tur,sayilarrr[i],this->toplamKisiSayisi);
		//if(tur==65) break; //duraklatma kontrol noktası
		if(this->elenenKisiSayisi == this->toplamKisiSayisi){
			break;
		}
		if(i == this->sayilarDizisiUzunlugu-1){
			i=0;
		}
		else{
			i++;
		}
		this->elenenKisiSayisi=0;
		tur++;
	}
			
}


Kisi enZenginKisiBul(Oyun this){
	Kisi enZenginKisi = this->dosya->kisilerDizisi[0];
	int i;
	for(i=0; i<this->toplamKisiSayisi; i++){
		if(this->dosya->kisilerDizisi[i]->bakiye > enZenginKisi->bakiye){
			enZenginKisi = this->dosya->kisilerDizisi[i];
		}
	}
	return enZenginKisi;
}

int intUzunlukAlma(int deger){
	char str[50];
	sprintf(str,"%d",deger);
	int uzunluk = strlen(str);
	return uzunluk;
}

void yazdir(int toplamElenenSayisi,char* adisoyadi,double bakiyesi,double masaBakiye,int tur,int sayi,int toplamkisisayisi){
	Sleep(75);
	system("cls");
	int a;
	printf("\n\n\n\n\n");
	printf("                                   ");
	printf("#############################################\n");
	
	if(toplamElenenSayisi!=toplamkisisayisi){
		printf("                                   ");
		printf("##");
	printf("             ");
	printf("Sansli Sayi: ");
	printf("%d",sayi);
	int sayiUzunluk=intUzunlukAlma(sayi);
	
	for(a=0;a<15-sayiUzunluk;a++){
		printf(" ");
	}
	printf("##\n");
	printf("                                   ");
	printf("#############################################\n");
	printf("                                   ");
	printf("#############################################\n");
	//
	}
	
	printf("                                   ");
	printf("##");
	printf("             ");
	printf("Tur: ");
	if(toplamElenenSayisi!=toplamkisisayisi){
		printf("%d",tur);
	}
	else{
		printf("%d",tur-1);
	}
	
	int turUzunluk=intUzunlukAlma(tur);
	for(a=0;a<23-turUzunluk;a++){
		printf(" ");
	}
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("       ");
	printf("Masa Bakiye: ");
	printf("%.0lf TL",masaBakiye);
	int masaBakiyeUzunluk=intUzunlukAlma(masaBakiye);
	for(a=0;a<18-masaBakiyeUzunluk;a++){
		printf(" ");
	}
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("                                         ");
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("-----------------------------------------");
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("             ");
	if(toplamElenenSayisi!=toplamkisisayisi){
	printf("En Zengin Kisi ");
	printf("             ");
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("             ");
	printf("%s",adisoyadi);
	int adSoyadUzunluk=strlen(adisoyadi);
	for(a=0;a<28-adSoyadUzunluk;a++){
		printf(" ");
	}
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("       ");
	printf("Bakiyesi: ");
	printf("%.0lf",bakiyesi);
	int bakiyeUzunluk=intUzunlukAlma(bakiyesi);
	for(a=0;a<24-bakiyeUzunluk;a++){
		printf(" ");
	}
	printf("##\n");
	
	}
	else{
	printf("OYUN BITTI");
	printf("                  ");
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("                                         ");
	printf("##\n");
	printf("                                   ");
	printf("##");
	printf("                                         ");
	printf("##\n");
	
	}
	printf("                                   ");
	printf("##");
	printf("                                         ");
	printf("##\n");
	printf("                                   ");
	printf("#############################################\n");
}
void OyunYokEt(const Oyun this){
	if(this == NULL) return;
	this->dosya->yoket(this->dosya);
	free(this->sayilar);
	free(this);
}
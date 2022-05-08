/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Kişi sınıfının oluşturulmasi
* </p>
*/

#include "Kisi.h"

Kisi kisiOlustur(char* adSoyad,double bakiye,double yatirilanBakiyeOrani,int sayi){
	Kisi this;
	this = (Kisi)malloc(sizeof(struct KISI));
	this->adSoyad=adSoyad;
	this->bakiye=bakiye;
	this->yatirilanBakiyeOrani=yatirilanBakiyeOrani;
	this->sayi=sayi;
	this->yoket=&KisiYokEt;
	return this;
}
void KisiYokEt(Kisi this){
	if(this==NULL) return;
	free(this);
}
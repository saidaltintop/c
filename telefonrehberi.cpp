#include<stdio.h>//printf icin bu kutuphaneyi kullandik
#include<conio.h>//getche icin bu kutuphaneyi kullandik
#include<stdlib.h>//system icin bu kutuphaneyi kullandik
#include<windows.h>//sleep icin bu kutuphaneyi kullandik
void kisiekle();
void goruntule();
void guncelle();
void sil();
void arama();
int cikis();
char fonksiyonmenu(char);
void islemyapiliyor();

struct rehber
{
char ad[50],soyad[50],dogumtarihi[50],tc[50],istel[50],ceptel[50],mail[50];
}kisi,yedek[BUFSIZ],yedek2[BUFSIZ];
FILE *dosyam;
FILE *yeni;
void main()
{
system("color 3b");
char sec,menu;
while(true)	
{
printf("\t\t\t*******************\n\t\t\t*  1-> Kisi ekle  *\n\t\t\t*-----------------* \n\t\t\t*  2-> Goruntule  *\n\t\t\t*-----------------* \n\t\t\t*  3-> Guncelle   *\n\t\t\t*-----------------* \n\t\t\t*  4-> Sil        *\n\t\t\t*-----------------* \n\t\t\t*  5-> Arama      *\n\t\t\t*-----------------* \n\t\t\t*  6-> Cikis      *\n\t\t\t*******************");
sec=getch();
switch (sec)
{
case '1':
islemyapiliyor();
system("cls");
kisiekle();
islemyapiliyor();
break;
case '2':
islemyapiliyor();
system("cls");
goruntule();
printf("\n\nMenuye Donmek Icin => M ");
menu=getch();
fonksiyonmenu(menu);
islemyapiliyor();
break;
case '3':
islemyapiliyor();
system("cls");
guncelle();
system("cls");
islemyapiliyor();
break;
case '4':
islemyapiliyor();
system("cls");
sil();
printf("\n\nMenuye Donmek Icin => M ");
menu=getch();
fonksiyonmenu(menu);
islemyapiliyor();
break;
case '5':
islemyapiliyor();
system("cls");
arama();
printf("\n\nMenuye Donmek Icin => M ");
menu=getch();
fonksiyonmenu(menu);
islemyapiliyor();
break;
case '6':
islemyapiliyor();
exit(cikis());
break;
default:
islemyapiliyor();
system("cls");
system("color 3A"); 
printf("YANLIS SECIM YAPTINIZ!! LUTFEN TEKRAR DENEYINIZ ");
Sleep(750);
system("color 3B"); 
break;
}
system("cls");
}
}

void kisiekle()
{
dosyam=fopen("rehberdosyam.txt","a");//dosyayi yazma işlemi icin ac
if(dosyam==NULL)//eger ulasamiyorsak
printf("dosyaya ulasilamadi\n");
char tekrar='m';
do
{
system("cls");
printf("\n\nAdi => ");
scanf("%s",kisi.ad);
for(int i=0;i<50;i++)
{
if(('0'<=kisi.ad[i] && kisi.ad[i]<='9'))
{
printf("HATA HARF GIRMEDINIZ!!!");
Sleep(500);
system("cls");
main();
}

}
printf("\n\nSoyadi => ");
scanf("%s",kisi.soyad);
for(int i=0;i<50;i++)
{
if(('0'<=kisi.soyad[i] && kisi.soyad[i]<='9'))
{
printf("HATA HARF GIRMEDINIZ!!!");
Sleep(500);
system("cls");
main();
}

}
printf("\n\nDogum Tarihi => ");
scanf("%s",kisi.dogumtarihi);
printf("\n\nTc => ");
scanf("%s",kisi.tc);
for(int i=0;i<50;i++)
{
if(('a'<=kisi.tc[i] && kisi.tc[i]<='z') || ('A'<=kisi.tc[i] && kisi.tc[i]<='Z'))
{
printf("HATA SAYI GIRMEDINIZ!!!");
Sleep(500);
system("cls");
main();
}

}
printf("\n\nIs Tel => ");
scanf("%s",kisi.istel);
for(int i=0;i<50;i++)
{
if(('a'<=kisi.istel[i] && kisi.istel[i]<='z') || ('A'<=kisi.istel[i] && kisi.istel[i]<='Z'))
{
printf("HATA SAYI GIRMEDINIZ!!!");
Sleep(500);
system("cls");
main();
}

}
printf("\n\nCep Tel => ");
scanf("%s",kisi.ceptel);
for(int i=0;i<50;i++)
{
if(('a'<=kisi.ceptel[i] && kisi.ceptel[i]<='z') || ('A'<=kisi.ceptel[i] && kisi.ceptel[i]<='Z'))
{
printf("HATA SAYI GIRMEDINIZ!!!");
Sleep(500);
system("cls");
main();
}

}
printf("\n\nMail Adresi => ");
scanf("%s",kisi.mail);
fprintf(dosyam,"\n%s\t",kisi.ad);//dosyam icin isaret ettgi yere yazdir
fprintf(dosyam,"%s\t",kisi.soyad);//dosyamin isaret ettgi yere yazdir	
fprintf(dosyam,"%s\t",kisi.dogumtarihi);//dosyamin isaret ettgi yere yazdır
fprintf(dosyam,"%s\t",kisi.tc);//dosyamin isaret ettgi yere yazdır
fprintf(dosyam,"%s\t",kisi.istel);//dosyamın isaret ettgi yere yazdır
fprintf(dosyam,"%s\t",kisi.ceptel);//dosyamin isaret ettgi yere yazdır
fprintf(dosyam,"%s",kisi.mail);//dosyamin isaret ettgi yere yazdır
printf("\nYeni Bir Kisi Daha Eklemek Icin => 'E' Menuye Donmek Icin => 'M'");
tekrar=getch();

} while (tekrar=='e');
fclose(dosyam);
}
void goruntule()
{int m=0;
char okunan[BUFSIZ];
dosyam=fopen("rehberdosyam.txt","r");
if(dosyam==NULL)//eger ulasamıyorsak
printf("dosyaya ulasilamadi\n");

while(!feof(dosyam))
{
fscanf(dosyam,"%s%s%s%s%s%s%s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);
m++;
strcpy(yedek[m].ad,kisi.ad);
strcpy(yedek[m].soyad,kisi.soyad);
strcpy(yedek[m].dogumtarihi,kisi.dogumtarihi);
strcpy(yedek[m].tc,kisi.tc);
strcpy(yedek[m].istel,kisi.istel);
strcpy(yedek[m].ceptel,kisi.ceptel);
strcpy(yedek[m].mail,kisi.mail);

strcpy(yedek2[m].ad,kisi.ad);
strcpy(yedek2[m].soyad,kisi.soyad);
strcpy(yedek2[m].dogumtarihi,kisi.dogumtarihi);
strcpy(yedek2[m].tc,kisi.tc);
strcpy(yedek2[m].istel,kisi.istel);
strcpy(yedek2[m].ceptel,kisi.ceptel);
strcpy(yedek2[m].mail,kisi.mail);
}

for(int j=0;j<=m;j++)
{
for(int i=0;i<=m-j-1;i++)
{
//strcmp fonksyonu string degerlerine gore 3 farkli durumu vardir.
if(strcmp(yedek2[i].ad,yedek2[i+1].ad)>0)
{
//memcpy string kutuphanesinde tanimli struct kopyalama fonksyonudur.
memcpy(&yedek[i],&yedek2[i],sizeof(rehber));
memcpy(&yedek2[i],&yedek2[i+1],sizeof(rehber));
memcpy(&yedek2[i+1],&yedek[i],sizeof(rehber));
}
}
}

for(int i=1;i<m+1;i++)	 //Isim alfabe sirasina gore gosterim
{
printf("\nAdi => %s\n\nSoyadi => %s\n\nDogum Tarihi => %s\n\nTc => %s\n\nIs Tel => %s\n\nCep Tel => %s\n\nMail Adresi => %s",yedek2[i].ad,yedek2[i].soyad,yedek2[i].dogumtarihi,yedek2[i].tc,yedek2[i].istel,yedek2[i].ceptel,yedek2[i].mail);
printf("\n*****************************************************************************\n");
}

fclose(dosyam);
}
void guncelle()
{
char arananad[50],aranansoyad[50],eminmisin;
int say=0;
printf("\nGuncellemek Istediginiz Kisinin Adi => ");
scanf("%s",&arananad);
printf("\nGuncellemek Istediginiz Kisinin Soyadi => ");
scanf("%s",&aranansoyad);
printf("\nKisiyi guncellestirmek istediginize emin misiniz?(evet = e) (hayir = h) => ");//duzenleme yap hayır icin
eminmisin=getch();
if(eminmisin=='e'|| eminmisin=='E')
{
dosyam=fopen("rehberdosyam.txt","r"); //bilgiler dosyadan okunacak.
yeni=fopen("rehberdosyam1.txt","w"); //yeni bilgiler bu dosyaya yazılacak.
while(!feof(dosyam))
{
fscanf(dosyam,"%s%s%s%s%s%s%s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);
if((strcmp(kisi.ad,arananad)==0) && (strcmp(kisi.soyad,aranansoyad)==0))
{
printf("\n\nAdi => ");
scanf("%s",kisi.ad);
printf("\n\nSoyadi => ");
scanf("%s",kisi.soyad);
printf("\n\nDogum Tarihi => ");
scanf("%s",kisi.dogumtarihi);
printf("\n\nTc => ");
scanf("%s",kisi.tc);
printf("\n\nis Tel => ");
scanf("%s",kisi.istel);
printf("\n\nCep Tel => ");
scanf("%s",kisi.ceptel);
printf("\n\nMail Adresi => ");
scanf("%s",kisi.mail);
fprintf(yeni,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);
say++;
}
else
fprintf(yeni,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);//dosyamın isaret ettgi yere yazdır
}
if(say==0)
{	
system("cls");
system("Color 3a");
printf("\n\nEslesme Rehberde bulunamadi!! ");
Sleep(500);
system("Color 3b");
}
fclose(dosyam);
fclose(yeni);

remove("rehberdosyam.txt");//txt i siler
rename("rehberdosyam1.txt","rehberdosyam.txt");//txt ismini degistirir
}
else if(eminmisin=='h' || eminmisin=='H')
islemyapiliyor();
else
{
printf("e veya h harflerinden birisini tuslamadiniz menuye aktariliyorsunuz!!");
islemyapiliyor();
}

}
void sil()
{
char eminmisin,arananad[50],aranansoyad[50];
printf("Silinecek kisinin adi => ");
scanf("%s",&arananad);
printf("Silinecek kisinin soyadi => ");
scanf("%s",&aranansoyad);

printf("Kisiyi Silmek istediginize emin misiniz?(evet = e) (hayir = h) => ");//duzenleme yap hayir için
eminmisin=getch();
if(eminmisin=='e' || eminmisin=='E')
{
dosyam=fopen("rehberdosyam.txt","r"); //bilgiler dosyadan okunacak.
yeni=fopen("rehberdosyam1.txt","w"); //yeni bilgiler bu dosyaya yazilacak.

while(!feof(dosyam))
{

fscanf(dosyam,"%s %s %s %s %s %s %s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);

if((strcmp(kisi.ad,arananad)==0) && (strcmp(kisi.soyad,aranansoyad)==0)){//Silinecek ad bulununca dosyadan 1 kayit daha okunur ve silinedek kayit atlanmiş olur.

fscanf(dosyam,"%s %s %s %s %s %s %s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);

}//silinecek ad bulunana kadar alt satirdaki fprintf okunan veriyi yeni dosyaya yazar.
if(!feof(dosyam))
fprintf(yeni,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s",kisi.ad,kisi.soyad,kisi.dogumtarihi,kisi.tc,kisi.istel,kisi.ceptel,kisi.mail);

}

fclose(dosyam);
fclose(yeni);

remove("rehberdosyam.txt");
rename("rehberdosyam1.txt","rehberdosyam.txt");
printf("\n\nIsleminiz Tamamlandi!!");

}
else if(eminmisin=='h' || eminmisin=='H')
islemyapiliyor();
else
{
printf("e veya h harflerinden birisini tuslamadiniz menuye aktariliyorsunuz!!");
islemyapiliyor();
}


}
void arama()
{
char aranan[20];
printf("Aramak Istediginiz Kisinin Adi => ");
scanf("%s",&aranan);
dosyam=fopen("rehberdosyam.txt","r");
while(!feof(dosyam))
{
fscanf(dosyam,"%s",kisi.ad);
if(strcmp(aranan,kisi.ad)==0)
{
printf("\nAdi => %s",kisi.ad);
fscanf(dosyam,"%s",kisi.soyad);
printf("\n\nSoyadi => %s",kisi.soyad);
fscanf(dosyam,"%s",kisi.dogumtarihi);
printf("\n\nDogum Tarihi => %s",kisi.dogumtarihi);
fscanf(dosyam,"%s",kisi.tc);
printf("\n\nTc => %s",kisi.tc);
fscanf(dosyam,"%s",kisi.istel);
printf("\n\nIs Tel => %s",kisi.istel);
fscanf(dosyam,"%s",kisi.ceptel);
printf("\n\nCep Tel => %s",kisi.ceptel);
fscanf(dosyam,"%s",kisi.mail);
printf("\n\nMail Adresi => %s",kisi.mail);
printf("\n*****************************************************************************\n");
}
}
fclose(dosyam);
}

int cikis()
{
return 1;
}
char fonksiyonmenu(char x)
{
while (true)
{


if(x=='m' || x=='M')
break;
else
{
return printf("\n\nYanlis Giris Yaptiniz Tekrar Deneyiniz");
}
}
}
void islemyapiliyor()
{
printf("\n\n\nIsleminiz Yapiliyor...");
Sleep(500);
}

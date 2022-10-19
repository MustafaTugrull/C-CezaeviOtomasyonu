#include<stdio.h>
#include<stdlib.h>
#include<string.h>


                    struct mahkum{                          // ilaclari tanimlar: olusumlari;
                           char *mahkumadi;
                           char *sucturu;
                           char *mahkumsoyadi;
                           char *tcno;
                           int kogusno;
                           };
                           
                           
                           


void mahkum_kayit_func(int kogus_num)  {

	mahkum girdi;  // mahkum tipinde bir degisken tanimi
	girdi.kogusno=kogus_num;
                            
							girdi.mahkumadi=(char *)malloc(sizeof(char)*300);
                            printf("Mahkum Adi Giriniz:");
                            scanf("%s",girdi.mahkumadi);
                              
                            girdi.mahkumsoyadi=(char *)malloc(sizeof(char)*300);
                            printf("Mahkum Soyadi Giriniz:");
                            scanf("%s",girdi.mahkumsoyadi);
                              
							girdi.sucturu=(char *)malloc(sizeof(char)*300);
                            printf("Suc Turu Giriniz:");
                            scanf("%s",girdi.sucturu);
                              
                            girdi.tcno=(char *)malloc(sizeof(char)*300);
                            printf("Tc Numarasi:");
                            scanf("%s",girdi.tcno);
                            
                            
                            FILE *fp=fopen("ceza.txt","a");   // append modunda acar dosyaya ekleme yapar
                              fprintf(fp,"%s %s %s %s %d \n",girdi.mahkumadi,girdi.mahkumsoyadi,girdi.sucturu,girdi.tcno,girdi.kogusno); // ve dosyadan yazdirir
                              printf("--Kayit Basari Ile Gerceklestirilmistir--\n");
                              fclose(fp); // islem bittiginde dosyayi kapatir
}   
                           
                           
                           
int  kogus_mevcudu_getir (int kogus_no){

	int mevcut=0;
	FILE *fp=fopen("ceza.txt","r");
	mahkum girdi[50];  // listedeki 'mahkum girdi' tipi
	int artis=0;
	while(!feof(fp)){                                                       

		girdi[artis].mahkumadi=(char *)malloc(sizeof(char)*300);  // artis parametresi,mahkum tiplerinin icinde artar ve bunu tanimlar
		girdi[artis].mahkumsoyadi=(char *)malloc(sizeof(char)*300);
		girdi[artis].sucturu=(char *)malloc(sizeof(char)*300);
		girdi[artis].tcno=(char *)malloc(sizeof(char)*300);
										    
		fscanf(fp,"%s %s %s %s %d \n",girdi[artis].mahkumadi,girdi[artis].mahkumsoyadi,girdi[artis].sucturu,girdi[artis].tcno,&girdi[artis].kogusno); // dosyadan okur
		
		if(girdi[artis].kogusno==kogus_no){
			mevcut++;
		}
		
		artis++;  // 'artis' arttirir..
	}
	fclose(fp);	
	return mevcut;
}                       
    
	
	
void kogus_bilgileri_getir(int kogus_num){
	
	int mevcut=0;
	FILE *fp=fopen("ceza.txt","r");
	mahkum girdi[50];  // listedeki 'mahkum girdi' tipi
	int artis=0;
	while(!feof(fp)){                                                       

		girdi[artis].mahkumadi=(char *)malloc(sizeof(char)*300);  // artis parametresi,mahkum tiplerinin icinde artar ve bunu tanimlar
		girdi[artis].mahkumsoyadi=(char *)malloc(sizeof(char)*300);
		girdi[artis].sucturu=(char *)malloc(sizeof(char)*300);
		girdi[artis].tcno=(char *)malloc(sizeof(char)*300);
										    
		fscanf(fp,"%s %s %s %s %d \n",girdi[artis].mahkumadi,girdi[artis].mahkumsoyadi,girdi[artis].sucturu,girdi[artis].tcno,&girdi[artis].kogusno); // dosyadan okur
		
		if(girdi[artis].kogusno==kogus_num){

			printf("\nAdi:%s - Soyadi:%s - Suc Turu:%s -Kimlik Numarasi:%s\n",girdi[artis].mahkumadi,girdi[artis].mahkumsoyadi,girdi[artis].sucturu,girdi[artis].tcno);

			mevcut++;
		}	
		artis++;  // 'artis' arttirir..
	}
	
	printf("\nKogus Numarasi: %d \n",kogus_num);
	printf("Kogus Mevcudu: %d \n",mevcut);
	if(mevcut==0){
		printf("Bu kogusta mahkum bulunmamaktadir.\n\n\n");
	}
	
	if(mevcut>0 && mevcut<5 ){
		int kalan_mevcut=5-mevcut;
		printf("Kogus musait yatak sayisi= %d\n\n\n", (kalan_mevcut));
	}
	
	if(mevcut==5){
		printf("Bu kogus doludur.\n\n\n");
	} 
	fclose(fp);	

}                       
                                              
int main(){
    while(1){ // Ana menunun surekli donmesini saglar
    typedef mahkum cezaevi;  // tipini belirler
      int secim;
         printf("\n* * * * * * MENU * * * * * *\n");
         printf("1.Mahkum Kaydi:\n");
		 printf("2.Mahkum Arama:\n");
         printf("3.Mahkum Listesi:\n");
         printf("4.Mahkum Kayit Silme:\n");
         printf("5.Kogus Bilgileri Getir:\n");
         printf("6.Dolu Koguslari Listele:\n");
         printf("7.Dolu Olmayan Koguslari Listele:\n");
         printf("8.Reset:\n");
         printf("0.Otomasyon Cikis:\n");
                 for(int i=1;i<15;i++){  // menu yildizlari icin 15 e kadar donen bir 'i' dongusu 
                         printf("* ",i);
                         }
                         printf("\n\nLutfen Seciminizi Giriniz=");
                         scanf("%d",&secim);                       // asagidaki secenekler icin secim yaptirir 
 
     if(secim==1){     // mahkum kaydet bolum 1
     						

							int gecici=0;
							
							while(!(gecici>=1 && gecici<=10)){
							printf("Lutfen 1-10 arasinda kogus numarasi giriniz:\n");
                            scanf("%d",&gecici);
                            
                            
                            	while(kogus_mevcudu_getir(gecici)>=5){
                            		printf("%d nolu kogus doludur.\n",gecici);
                            		gecici=0;
								}
                            
                            }
                            
                            mahkum_kayit_func(gecici); 

                              }
                              
                              
     if(secim==2){  // mahkum arama bolum 4
                              printf("Aradiginiz Mahkum Adi Giriniz:");
                              char arananadi[30];  // istedigimiz mahkuma ulasmak icin char turunde bir aranan olan kullandigimiz bir arac
                              char aranansoyadi[30];

                              scanf("%s",&arananadi);
                              printf("Aradiginiz Mahkum Soyadi Giriniz:");
                              scanf("%s",&aranansoyadi);

                              
                              int bayrak=0;
                              FILE *fp=fopen("ceza.txt","r");  // read modun da okuma islemi
                              
                              cezaevi girdi; // cezaevi tipinde klasik degiskenimiz
                              girdi.mahkumadi=(char *)malloc(sizeof(char)*300);
                              girdi.mahkumsoyadi=(char *)malloc(sizeof(char)*300);
                              girdi.sucturu=(char *)malloc(sizeof(char)*300);
                              girdi.tcno=(char *)malloc(sizeof(char)*300);
                                                    
                              while(!feof(fp)){
                                               fscanf(fp,"%s %s %s %s %d \n",girdi.mahkumadi,girdi.mahkumsoyadi,girdi.sucturu,girdi.tcno,&girdi.kogusno);
                                                
                                                 if(strcmp(girdi.mahkumadi,arananadi)==0 && strcmp(girdi.mahkumsoyadi,aranansoyadi)==0){  // dosyada ki kayitli bir mahkum ile aranan isim ayni ise alttaki printf ile yazdir..
                                                                                     bayrak=1;  
                                                 printf(" Mahkum Adi :%s\n Mahkum Soyadi:%s\n Suc Turu:%s\n Kimlik Numarasi:%s\n Kogus numarasi:%d\n",girdi.mahkumadi,girdi.mahkumsoyadi,girdi.sucturu,girdi.tcno,girdi.kogusno);                          
                              }
                              }
                              if(bayrak==0)
                              printf("Aradiginiz Mahkum Bulunmamaktadir..!");
                              fclose(fp);  // ve dosyayi kapatir
                              }
                              
     if(secim==3){   // Mahkum Listesi bolum 5
                                           printf("Cezaevi Mahkum Listesi:\n");
                                           FILE *fp=fopen("ceza.txt","r");
                                           cezaevi girdi;
                              girdi.mahkumsoyadi=(char *)malloc(sizeof(char)*300);    //  olusumlarin tipini tekrardan belirt
                              girdi.mahkumadi=(char *)malloc(sizeof(char)*300);
                              girdi.sucturu=(char *)malloc(sizeof(char)*300);  
                              girdi.tcno=(char *)malloc(sizeof(char)*300);
                               while(!feof(fp)){  // Dosya sonuna kadar okur
                                               fscanf(fp,"%s %s %s %s %d \n",girdi.mahkumadi,girdi.mahkumsoyadi,girdi.sucturu,&girdi.tcno,&girdi.kogusno);
                                               printf("\nAdi:%s - Soyadi:%s - Suc Turu:%s - Kogus Numarasi:%d \n",girdi.mahkumadi,girdi.mahkumsoyadi,girdi.sucturu,girdi.kogusno);
                                               }
                                               fclose(fp); // dosyayi kapatir..
                                               } 
                              
     if(secim==4){  // kayit kaldirma bolum 6
                               FILE *fp=fopen("ceza.txt","r");
                                            char isim[30];  // silme islemi icin,char isim[100] turunde bir degisken
                                                   printf("Silmek Istediginiz Mahkum Adi:");               
                                            scanf("%s",isim);
                                            char soyisim[30];
                                            	   printf("Silmek Istediginiz Mahkum Soyadi:");
                                            scanf("%s",soyisim);
                                              int artis=0;  // islem devam ettikce icinde kullanilan parametre
                                                mahkum girdi[200];  // listedeki 'mahkum girdi' tipi
                                            while(!feof(fp)){                                                       
                                            girdi[artis].mahkumadi=(char *)malloc(sizeof(char)*300);  // artis parametresi,mahkum tiplerinin icinde artar ve bunu tanimlar
                                            girdi[artis].mahkumsoyadi=(char *)malloc(sizeof(char)*300);
                                            girdi[artis].sucturu=(char *)malloc(sizeof(char)*300);
											girdi[artis].tcno=(char *)malloc(sizeof(char)*300);         
                                            fscanf(fp,"%s %s %s %s %d \n",girdi[artis].mahkumadi,girdi[artis].mahkumsoyadi,girdi[artis].sucturu,girdi[artis].tcno,&girdi[artis].kogusno); // dosyadan okur
                                            artis++;  // 'artis' arttirir..
                                            }
                                            fclose(fp); 
                                            FILE *fp2=fopen("ceza.txt","w");
                                            
                                              for(int i=0;i<=artis-1;i++){
                                                                                                        
                                                                                                                                                                  
                               						if(strcmp(girdi[i].mahkumadi,isim) != 0 || strcmp(girdi[i].mahkumsoyadi,soyisim) != 0 )// girilen mahkum ismi ile kayittaki mahkum ismi ayni degil ise,
		
													  	fprintf(fp2,"%s %s %s %s %d \n",girdi[i].mahkumadi,girdi[i].mahkumsoyadi,girdi[i].sucturu,girdi[i].tcno,girdi[i].kogusno);   // dosyadan yazdir..     
													    
                          }
                              printf("Kayit Kaldirilmistir...");
                              fprintf(fp2,'\0');  // dosya sonuna kadar..                               
                              fclose(fp2);  // dosyayi kapatir..
                              }
      if(secim==5){     // mahkum kaydet bolum 1  
	  						int gecici=-1;
							
							while(!(gecici>=1 && gecici<=10)){
							printf("Lutfen 1-10 arasinda kogus numarasi giriniz:");
                            scanf("%d",&gecici);
                            
	                            if(gecici>=1 && gecici<=10){
	                            	kogus_bilgileri_getir(gecici);
								}
	                            else {
	                            gecici=-1;	
								}
	
                            }
                              
    				}
      if(secim==6){
      		for( int i=1;i<=10;i++){
      		if(kogus_mevcudu_getir(i)==5){
      			printf("%d numarali kogus doludur.\n",i);
			  }
      		
		  }
      }
       if(secim==7){
      		for( int i=1;i<=10;i++){
      		if(kogus_mevcudu_getir(i)<5){
      			printf("%d numarali kogus dolu degildir.\n",i);
			  }
      		
		  }
      }
      if(secim==8){ // reset dugmesi bolum 10
                                           system("CLS");   // ekran temizlemek icin bir komut olan = system("CLS")
                                           }
                              
                              
     if(secim==0)     /* son olarak cikis butonu
                              secim '0' oldugu takdirde               
                              break komuduyla islemi kirar..*/
                              break;           
                          }
                      }

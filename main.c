#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct HavaVerisi {
    char tarih[12];
    int hava_durumu;
    float sicaklik;
    int nem_yuzdesi;
    float basinc;
    float ruzgar;
    float gorus_mesafesi;
    int UV_indeksi;
};

char hava_durumlari[21][40] = {"Acik", "Az Bulutlu", "Parcali Bulutlu", "Cok Bulutlu", "Sisli",
                               "Hafif Yagmurlu", "Yagmurlu", "Kuvvetli Yagmurlu", "Hafif Saganak Yagisli",
                               "Saganak Yagisli", "Kuvvetli Saganak Yagisli", "Hafif Kar Yagisli",
                               "Kar Yagisli", "Yogun Kar Yagisli", "Yer Yer Saganak Yagisli", "Dolu",
                               "Gok Gurultulu Saganak Yagisli", "Karla Karisik Yagmurlu", "Ruzgarli",
                               "Toz veya Kum Firtinasi", "Kuvvetli Gok Gurultulu Saganak Yagisli"};

void veri_girisi();
bool isValid(char tarih[12]);
void veri_goruntule();
void analiz(int gunSayisi);
void sıralama(int gunSayisi);
void menu();

int main(){
    menu();
}

void menu(){
    printf("-------------------------------------------------------------");
    printf("\n-----------------------MENU----------------------------------");
    printf("\n(1) Veri Girisi"
           "\n(2) Girilen Verileri Goruntuleme"
           "\n(3) Belirli Deger Araliklarindaki Verileri Goruntuleme"
           "\n(4) Verilerin Siralanmasi");
    printf("\nLutfen yapmak istediginiz islemi secin:");
}

bool isValid(char tarih[12]){
    int gun,ay,yil;
    sscanf(tarih, "%d.%d.%d", &gun, &ay, &yil);
    switch(ay){
        case 4:
        case 6:
        case 9:
        case 11:
            if(gun < 31)
                return true;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(gun < 31)
                return true;
            break;
        case 2:
            if(gun < 29)
                return true;
            break;
    }
    return false;
}

void veri_girisi() {
    int gunSayisi;
    printf("Lutfen meteorolojik kayit girmek istediginiz gun sayisini giriniz:");
    scanf("%d", &gunSayisi);
    struct HavaVerisi veri[gunSayisi];
    for (int i = 0; i < gunSayisi; i++) {
        printf("--------------------------------------------------------------------------");
        printf("\n Tarih (GG.AA.YYYY): ");
        char dateInput[12];
        scanf("%s", &dateInput);
        while(isValid(dateInput) == false){
            printf("\n Tarih (GG.AA.YYYY): ");
            scanf("%s", &dateInput);
        }

        printf("-------------------------------------------------------------");
        printf("\n -- Hava Durumu --");
        printf("\n Lutfen secmek istediginiz hava durumunun sayisal degerini giriniz: \n" );
        for(int j=0; j<21; j++){
            for(int k=0; k<40; k++){
                if(hava_durumlari[j][k] != NULL)
                    printf("%c",hava_durumlari[j][k]);
            }
            printf(" (%d) \n", j+1);
        }

        scanf("%d", &veri[i].hava_durumu);


        printf("\n -------------------------------------------------------------");
        printf("\n Sicaklik Degeri: ");
        scanf("%f", &veri[i].sicaklik);

        printf("-------------------------------------------------------------");
        printf("\n Nem Yuzdesi: ");
        scanf("%d", &veri[i].nem_yuzdesi);

        printf("-------------------------------------------------------------");
        printf("\n Basinc Degeri:", veri[i].basinc);
        scanf("%f", &veri[i].basinc);

        printf("-------------------------------------------------------------");
        printf("\n Ruzgar Hizi: ", veri[i].ruzgar);
        scanf("%f", &veri[i].ruzgar);

        printf("-------------------------------------------------------------");
        printf("\n Gorus Mesafesi: ", veri[i].gorus_mesafesi);
        scanf("%f", &veri[i].gorus_mesafesi);

        printf("-------------------------------------------------------------");
        printf("\n UV Indeksi: ", veri[i].UV_indeksi);
        scanf("%d", &veri[i].UV_indeksi);

        //Verileri dosyaya yazdırma
        FILE *file;
        file = fopen("../WeatherSystem/veriler","a");
        fprintf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                      "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d}\n",
                veri[i].tarih,veri[i].hava_durumu,veri[i].sicaklik,veri[i].nem_yuzdesi,veri[i].basinc,
                veri[i].ruzgar, veri[i].gorus_mesafesi, veri[i].UV_indeksi);
        fclose(file);

    }
}

void veri_goruntule() {
    int gunsayisi;
    printf("Görüntülemek istediğiniz gün sayısını girin: ");
    scanf("%d", &gunsayisi);

    for (int i = 0; i < gunsayisi; i++) {
        char dateInput[12];

        printf("Görüntülemek istediğiniz %d.günün tarihini girin: ", i + 1);
        scanf("%s", dateInput);

        while (!isValid(dateInput)) {
            printf("Girilen tarih geçersiz. Tekrar girin: ");
            scanf("%s", dateInput);
        }

        FILE *file = fopen("../WeatherSystem/veriler", "r");
        if (file == NULL) {
            printf("Dosya açma hatası\n");
            return;
        }

        struct HavaVerisi veri;
        int tarihBulundu = 0;

        while (fscanf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %f\nNem Yuzdesi: %d\n"
                            "Basinc Degeri: %f\nRuzgar Hizi: %f\nGorus Mesafesi: %f\nUV Indeksi: %d}\n",
                      veri.tarih, &veri.hava_durumu, &veri.sicaklik, &veri.nem_yuzdesi, &veri.basinc,
                      &veri.ruzgar, &veri.gorus_mesafesi, &veri.UV_indeksi) == 8) {
            if (strcmp(veri.tarih, dateInput) == 0) {
                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);

                fclose(file);
                tarihBulundu = 1;
                break;
            }
        }
        if (!tarihBulundu) {
            printf("Bu tarihe ait girili veri bulunamadı\n");
        }

        fclose(file);
    }
}

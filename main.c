#include <stdio.h>
#include <stdlib.h>

struct HavaVerisi {
    char tarih[20];
    char hava_durumu[20];
    float sicaklik;
    int nem_yuzdesi;
    float basinc;
    float ruzgar;
    float gorus_mesafesi;
    int UV_indeksi;
};

void veri_girisi(int gunSayisi);
void veri_goruntule(struct HavaVerisi veri [], int gunSayisi);
void analiz(struct HavaVerisi veri [], int gunSayisi);
void sıralama(struct HavaVerisi veri [], int gunSayisi);
void menu();

int main(){

    int gunSayisi;
    printf("Lutfen meteorolojik kayit girmek istediginiz gun sayisini giriniz:");
    scanf("%d", &gunSayisi);
    veri_girisi(gunSayisi);

}
void veri_girisi(int gunSayisi) {
    struct HavaVerisi veri[gunSayisi];
    for (int i = 0; i < gunSayisi; i++) {

        printf("--------------------------------------------------------------------------");
        printf("\n Tarih (GG.AA.YYYY): ");
        scanf("%s", veri[i].tarih);

        printf("-------------------------------------------------------------");
        printf("\n -- Hava Durumu --");
        printf("\n Lutfen secmek istediginiz hava durumunun sayisal degerini giriniz:"
               "\n - Acik (1)"
               "\n - Az Bulutlu (2)"
               "\n - Parcali Bulutlu (3)"
               "\n - Cok Bulutlu (4)"
               "\n - Sisli (5)"
               "\n - Hafif Yagmurlu (6)"
               "\n - Yagmurlu (7) "
               "\n - Kuvvetli Yagmurlu (8)"
               "\n - Hafif Saganak Yagisli (9)"
               "\n - Saganak Yagisli (10)"
               "\n - Kuvvetli Saganak Yagisli (11)"
               "\n - Hafif Kar Yagisli (12)"
               "\n - Kar Yagisli (13)"
               "\n - Yogun Kar Yagisli (14)"
               "\n - Yer Yer Saganak Yagisli (15)"
               "\n - Dolu (16)"
               "\n - Gok Gurultulu Saganak Yagisli (17)"
               "\n - Karla Karisik Yagmurlu (18)"
               "\n - Ruzgarli (19)"
               "\n - Toz veya Kum Firtinasi (20)"
               "\n - Kuvvetli Gok Gurultulu Saganak Yagisli (21) \n");

        int secenek;
        scanf("%d", &secenek);
        switch(secenek){
            case 1: printf("Hava durumu: Acik");
            case 2: printf("Hava durumu: Az Bulutlu");
            case 3: printf("Hava durumu: Parcali Bulutlu");
            case 4: printf("Hava durumu: Cok Bulutlu");
            case 5: printf("Hava durumu: Sisli");
            case 6: printf("Hava durumu: Hafif Yagmurlu");
            case 7: printf("Hava durumu: Yagmurlu");
            case 8: printf("Hava durumu: Kuvvetli Yagmurlu");
            case 9: printf("Hava durumu: Hafif Saganak Yagisli");
            case 10: printf("Hava durumu: Saganak Yagisli");
            case 11: printf("Hava durumu: Kuvvetli Saganak Yagisli");
            case 12: printf("Hava durumu: Hafif Kar Yagisli");
            case 13: printf("Hava durumu: Kar Yagisli");
            case 14: printf("Hava durumu: Yogun Kar Yagisli");
            case 15: printf("Hava durumu: Yer Yer Saganak Yagisli");
            case 16: printf("Hava durumu: Dolu");
            case 17: printf("Hava durumu: Gok Gurultulu Saganak Yagisli");
            case 18: printf("Hava durumu: Karla Karisik Yagmurlu");
            case 19: printf("Hava durumu: Ruzgarli");
            case 20: printf("Hava durumu: Toz veya Kum Firtinasi");
            case 21: printf("Hava durumu: Kuvvetli Gok Gurultulu Saganak Yagisli");
        }


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

    }
}

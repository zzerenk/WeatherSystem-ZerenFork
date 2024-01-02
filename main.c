#include <stdio.h>

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
void menu(){
    printf("-------------------------------------------------------------");
    printf("\n-----------------------MENU----------------------------------");
    printf("\n(1) Veri Goruntuleme"
           "\n(2) Girilen Verileri Goruntuleme"
           "\n(3) Girilen Araliktaki Verileri Goruntuleme"
           "\n(4) Verilerin Siralanmasi");
    printf("\nLutfen yapmak istediginiz islemi secin:");
}

void veri_girisi(int gunSayisi) {
    struct HavaVerisi veri[gunSayisi];
    for (int i = 0; i < gunSayisi; i++) {

        printf("--------------------------------------------------------------------------");
        printf("\n Tarih (GG.AA.YYYY): ");
        scanf("%s", veri[i].tarih);

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
        file = fopen("../veriler","a");
        fprintf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                      "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d}\n",
                veri[i].tarih,veri[i].hava_durumu,veri[i].sicaklik,veri[i].nem_yuzdesi,veri[i].basinc,
                veri[i].ruzgar, veri[i].gorus_mesafesi, veri[i].UV_indeksi);
        fclose(file);

    }
}

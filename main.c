#include <stdio.h>
#include <stdlib.h>

int veri(int veriler[28],float kazanc)
{
    FILE *f = fopen("Gelir.txt", "a");
    fprintf(f, "%d. Musteri %.2f'lik harcama yapti.\n",veriler[28],kazanc);
}

int giris(int veriler[],float kazanc) {
    printf("***** HOSGELDINIZ *****\n");
    printf("1) Musteri Girisi\n2) Admin Girisi\n");
    scanf("%d", &veriler[4]);

    if (veriler[4] == 2) {
        printf("Admin girisi icin sifreyi giriniz.\n");
        scanf("%d", &veriler[5]);

        if (veriler[5] == veriler[6]) {
            printf("Sifre dogru!\nTekrardan Hosgeldiniz!\n");
            printf("Ne islem yapmak istersiniz?:\n1) Bugun icindeki toplam kazanci gor.\n2) Benzinligi kapat.\n");
            scanf("%d", &veriler[9]);

            switch (veriler[9]) {
                case 1:
                    printf("Kazanciniz %.2f dir.\n", kazanc);
                break;
                case 2:
                    printf("Benzinlik kapatilmistir.\n");
                exit(0) ;
                default:
                    printf("Gecersiz bir islem sectiniz.\n");
                break;
            }
        } else {
            printf("Sifre yanlis!\n");
            exit(0) ;
        }
    } else if (veriler[4] == 1) {
        printf("Hosgeldiniz benzinligimize. Uye misiniz?\n1) Evet\n2) Hayir\n");
        scanf("%d", &veriler[10]);

        if (veriler[10] == 1) {
            printf("Lutfen telefon numaranizi girer misiniz?:\n");
            scanf("%d", &veriler[11]);
        } else if (veriler[10] == 2) {
            printf("Uye olmak icin lutfen telefon numaranizi giriniz:\n");
            scanf("%d", &veriler[12]);
            printf("Basariyla uye olunmustur. Aramiza hosgeldiniz!\n");
            printf("Lutfen giris yapmak icin bir daha numaranizi giriniz:\n");
            scanf("%d", &veriler[13]);

            if (veriler[13] != veriler[12]) {
                printf("Girdiginiz telefon numaralari eslesmemektedir.\n");
            } else {
                printf("Basarili bir sekilde giris yapilmistir!\n");
            }
        } else {
            printf("Gecersiz bir secim yaptiniz.\n");
        }

    }else {
        printf("Gecersiz bir giris yaptiniz.\n");
    }
}
int main(void) {
    float kazanc = 0;
    float fiyatlar[7] = {42.84, 43.80, 25.98, 0, 0, 0.9, 0};
    int veriler[29] = {450, 300, 700, 100, 0, 0, 12345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};

    while (1) {
        veriler[28]++;
        giris(veriler, kazanc);

        while (1) {
            printf("Hangi islemi yapmak istersiniz?:\n1) Yakit Almak\n2) Lastik Sisirmek\n3) Araba Yikama\n");
            scanf("%d", &veriler[14]);

            switch (veriler[14]) {
                case 1:
                    printf("Hangi yakit turunden almak istersiniz?:\n1) Benzin\n2) Motorin\n3) LPG\n");
                scanf("%d", &veriler[15]);

                printf("Kac litre almak istersiniz?:\n");
                int litre;
                scanf("%d", &litre);

                if (veriler[15] >= 1 && veriler[15] <= 3) {
                    fiyatlar[3] = litre * fiyatlar[veriler[15] - 1];
                    printf("Tutar: %.2f\n", fiyatlar[3]);
                    fiyatlar[4] += fiyatlar[3];
                } else {
                    printf("Gecersiz bir secim yaptiniz.\n");
                }
                break;
                case 2:
                    printf("Kac lastik sisirmek istersiniz?:\n");
                int lastik;
                scanf("%d", &lastik);
                fiyatlar[3] = lastik * veriler[3];
                printf("Tutar: %.2f\n", fiyatlar[3]);
                fiyatlar[4] += fiyatlar[3];
                break;
                case 3:
                    printf("Hangi bolgeyi yikamak istersiniz?\n1) Ic\n2) Dis\n3) Ic ve Dis\n");
                int yikama;
                scanf("%d", &yikama);

                if (yikama >= 1 && yikama <= 3) {
                    fiyatlar[3] = veriler[yikama - 1];
                    printf("Tutar: %d\n", veriler[yikama - 1]);
                    fiyatlar[4] += fiyatlar[3];
                } else {
                    printf("Gecersiz bir secim yaptiniz.\n");
                }
                break;
                default:
                    printf("Gecersiz bir islem girdiniz.\n");
            }

            printf("Baska bir islem yapmak ister misiniz?\n1) Evet\n2) Hayir\n");
            int devam;
            scanf("%d", &devam);
            if (devam != 1) {
                break;
            }
        }

        printf("Toplam tutar: %.2f\n", fiyatlar[4]);
        printf("Ilk defa mi benzinligimizi kullandiniz?\n1) Evet\n2) Hayir\n");
        int ilk_kullanim;
        scanf("%d", &ilk_kullanim);

        if (ilk_kullanim == 1) {
            fiyatlar[6] = fiyatlar[4] * fiyatlar[5];
            printf("Indirimli tutar: %.2f\n", fiyatlar[6]);
            kazanc += fiyatlar[6];
        } else {
            kazanc += fiyatlar[4];
        }
        veri(veriler,kazanc);
        printf("Odeme yontemi nedir?\n1) Nakit\n2) Kredi Karti\n");
        int odeme_yontemi;
        scanf("%d", &odeme_yontemi);

        if (odeme_yontemi == 1) {
            printf("Nakit odeme alindi. Iyi gunler dileriz.\n");
        } else {
            printf("Kart bilgilerinizi giriniz.\n");
            int kart_numarasi, son_tarih, cvv, bakiye;
            printf("Kart numarasi: ");
            scanf("%d", &kart_numarasi);
            printf("Son kullanma tarihi : ");
            scanf("%d", &son_tarih);
            printf("CVV: ");
            scanf("%d", &cvv);
            printf("Bakiye: ");
            scanf("%d", &bakiye);

            if (bakiye >= fiyatlar[4]) {
                printf("Odeme basarili. Bizi tercih ettiginiz icin tesekkur ederiz!\n");

            } else {
                printf("Yetersiz bakiye!\n");
            }
        }
    }
}


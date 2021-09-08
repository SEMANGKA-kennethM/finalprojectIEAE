#include <stdio.h>
#include <string.h>

struct Makanan{
    char name[254];
};

void tambahBrMakanan(){
    struct Makanan mkn;
    scanf("%s", mkn.name);
    FILE *fp = fopen("brmakanan.txt", "a");
    fprintf(fp, "%s\n", mkn.name);
    fclose(fp);
}

void tambahLncMakanan(){
    struct Makanan mkn;
    scanf("%s", mkn.name);
    FILE *fp = fopen("lncmakanan.txt", "a");
    fprintf(fp, "%s\n", mkn.name);
    fclose(fp);
}

void tambahDrMakanan(){
    struct Makanan mkn;
    scanf("%s", mkn.name);
    FILE *fp = fopen("drmakanan.txt", "a");
    fprintf(fp, "%s\n", mkn.name);
    fclose(fp);
}

void lihatMakanan(){
    FILE *fp = fopen("./brmakanan.txt", "r");
    struct Makanan mkn;
    while(fscanf(fp, "%[^#]\n", 
            mkn.name) != EOF){
        printf("Name: %s\n", mkn.name);
    }
}

struct Makanan cariMakanan(){
    char nama[254];
    scanf("%s", nama);
    FILE *fp = fopen("./brmakanan.txt", "r");
    struct Makanan mkn;
    while(fscanf(fp, "%[^#]\n", 
            mkn.name) != EOF){
        if(strcmp(nama, mkn.name) == 0){
            return mkn;
        }
    }
    struct Makanan temp;
    return temp;
}

// Menu Makanan
int main(){
    int choice;
    do{
    	printf("----------------------------\n");
        printf("SELAMAT DATANG DI FOOD GENERATOR");
        puts("\n\n1. Cari Makanan");
        puts("2. Input Makanan");
        puts("3. Random Generator Makanan");
        puts("4. Lihat Semua Makanan");
        puts("5. Exit\n");
        printf("----------------------------\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                struct Makanan temp = cariMakanan();
                printf("%s dicari\n", temp.name);
                break;
            }
            case 2:{
                int pilih;
                do
                {
                    printf("----------------------------\n");
                    puts("\n\nPILIH JENIS METODE MAKAN");
                    puts("1. Breakfast");
                    puts("2. Lunch");
                    puts("3. Dinner");
                    puts("4. Exit\n");
                    printf("----------------------------\n");
                    scanf("%d", &pilih);
                    switch (pilih){
                    case 1:{
                        tambahBrMakanan();
                        break;
                    }
                    case 2 : {
                        tambahLncMakanan();
                        break;
                    }
                    case 3:{
                        tambahDrMakanan();
                        break;
                    }
                }
            } while(pilih != 4);
            return 0;
            }
            case 3:{
                break;
            }
            case 4:{
                lihatMakanan();
                break;
            }
        }
    }while(choice != 5);
    return 0;
}


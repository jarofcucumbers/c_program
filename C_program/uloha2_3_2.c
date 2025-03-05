//tento kod pracuje z struct FILE otvara dva file jeden na citane a druhy na zapis, tuto on robi xor z kazdy znakom 

#include <stdio.h>

int main() {
    FILE *fwrite, *fread;
    unsigned c;
    unsigned c_27;

    fread = fopen("text232.txt", "r");
    if (fread == NULL) {
        printf("Subor na citanie sa nepodarilo otvorit\n");
        return 1;
    }

    fwrite = fopen("XOR_text", "wb");
    if (fwrite == NULL) {
        printf("Subor na zapis sa nepodarilo otvorit\n");
        fclose(fread);
        return 1;
    }

    while ((c = fgetc(fread)) != EOF) {
        c_27 = (unsigned char)(c ^ 27);
        fputc(c_27, fwrite);
    }

    fclose(fwrite);
    fclose(fread);

    printf("Sifrovanie uspesne dokoncene!\n");
    return 0;
}
      

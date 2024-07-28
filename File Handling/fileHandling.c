#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[50];
    char str1[50];
    FILE *fp = fopen("strings.txt", "w");
    printf("\nWrite some stuff idk: ");
    if(fp != NULL) {
        fgets(str, sizeof(str), stdin);
        fputs(str, fp);
    } else {
        printf("\nDidn't open file.");
    }
    fclose(fp);

    fp = fopen("strings.txt", "r");
    if(fp != NULL) {
        /*
        char ch;
        while((ch = (char)fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
        printf("\n");
        */
        fgets(str1, sizeof(str1), fp);
        puts(str1);
    } else {
        printf("Didn't open file successfully");
    }
    fclose(fp);
    return 0;
}

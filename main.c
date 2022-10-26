#include <stdio.h>

void lecture_fichier(){
    FILE* fichier = NULL;
    fichier = fopen("C:\\Users\\Edvan\\CLionProjects\\ProjetC\\fichier.txt", "r");
    if (fichier != NULL){
        char caractereActuel = fgetc(fichier);
        while (caractereActuel != EOF){
            printf("%c", caractereActuel);
            caractereActuel = fgetc(fichier);
        }
        fclose(fichier);
    }
}
int main() {
    lecture_fichier();
    return 0;
}

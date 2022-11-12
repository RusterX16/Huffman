#include <stdio.h>

struct Noeud {
    char char_value;
    unsigned frequence;
    struct Arbre *haut, *bas;
};



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
// FILE *out = fopen("output.txt", "w");
// fclose(out);



int main() {
    lecture_fichier();
    return 0;
}

// Récupération du fichier donné par l'utilisateur

// Extraction des octets du fichier

// Création d'une liste avec tous les caractères différents

// Pour chacun de ces charactères
    // Compter le nombre d'occurence

// Associer chaque charactère avec son nombre d'occurences

// Création d'un arbre binaire pour chaque duo Valeur / Fréquence

// Tant qu'il ni a pas de noeud final
    // On fusionne les arbres binaire avec les plus petites fréquences

// On créer un code de Huffman pour réécrire le fichier de façon compréssé

// On retourne le code de Huffman
// On retourne le fichier compressé

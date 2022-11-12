#include <stdio.h>

// Structure représentant un nœud de l'arbre
// l'arbre sera une accumulation de nœuds
struct Noeud {
    char char_value;
    unsigned frequence;
    struct Noeud *haut, *bas;
};

// Récupération du fichier donné par l'utilisateur

void lecture_fichier() {
    FILE *fichier = NULL;
    fichier = fopen("../fichier.txt", "r");

    if (fichier != NULL) {
        char caractereActuel = fgetc(fichier);

        while (caractereActuel != EOF) {
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

// Extraction des octets du fichier

// Création d'une liste avec tous les caractères différents

// Pour chacun de ces caractères
// Compter le nombre d'occurrences

// Associer chaque caractère avec son nombre d'occurrences

// Création d'un arbre binaire pour chaque duo Valeur / Fréquence

// Tant qu'il n'a pas de nœud final
// On fusionne les arbres binaires avec les plus petites fréquences

// On crée un code de Huffman pour réécrire le fichier de façon compressé

// On retourne le code de Huffman
// On retourne le fichier compressé
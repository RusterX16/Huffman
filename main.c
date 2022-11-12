#include <stdio.h>

// Structure représentant un noeud de l'arbre
// l'arbre sera une accumulation de noeuds
struct Noeud {
    char charValue;
    unsigned frequence;
    struct Noeud *haut, *bas;
};

void lectureFichier(){
    FILE* fichier = NULL;
    int caractereActuel = 0;
    fichier = fopen("test.txt", "r");
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichier);
    }
}
// FILE *out = fopen("output.txt", "w");
// fclose(out);



int main() {
    lectureFichier();
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

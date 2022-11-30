// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

// ---------------------------------------------------------------------------

// STRUCTS

// Structure représentant un couple caractère / nombre d'occurrences
typedef struct {
    char charValue;
    unsigned frequence;
} Couple;

// Structure représentant un nœud de l'arbre
// l'arbre sera une accumulation de nœuds
typedef struct {
    Couple * couple;
    struct Noeud * haut, * bas;
} Noeud;

// ---------------------------------------------------------------------------

// FUNCTIONS DECLARATIONS

void lecture_fichier();

char * get_char_list(FILE * file);

unsigned * get_char_frequency(char * char_list);

Couple * get_couple_list(const char * char_list, unsigned * char_frequency);

Noeud * get_noeud_list(Couple * couple_list);

int count_noeud(Noeud * noeud_list);

// ---------------------------------------------------------------------------

// FUNCTIONS

// Récupération du fichier donné par l'utilisateur
void lecture_fichier() {
    FILE * fichier = NULL;
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

// Fonction qui récupère la liste des caractères dans un fichier
char * get_char_list(FILE * file) {
    char * char_list = malloc(sizeof(char));
    int i = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        char_list[i] = c;
        i++;
        char_list = realloc(char_list, sizeof(char) * (i + 1));
    }
    char_list[i] = '\0';
    return char_list;
}

// Fonction qui récupère la liste des fréquences des caractères dans une liste de caractères
unsigned * get_char_frequency(char * char_list) {
    int size = 256;
    unsigned * char_frequency = malloc(sizeof(unsigned) * size);
    for (int i = 0; i < size; i++) {
        char_frequency[i] = 0;
    }
    int i = 0;
    while (char_list[i] != '\0') {
        char_frequency[(int) char_list[i]]++;
        i++;
    }
    return char_frequency;
}

// Fonction that create a list of couple using char_list and char_frequency
Couple * get_couple_list(const char * char_list, unsigned * char_frequency) {
    Couple * couple_list = malloc(sizeof(Couple));
    int i = 0;
    int j = 0;

    while (char_list[i] != '\0') {
        if (char_frequency[(int) char_list[i]] != 0) {
            couple_list[j] . charValue = char_list[i];
            couple_list[j] . frequence = char_frequency[(int) char_list[i]];
            char_frequency[(int) char_list[i]] = 0;
            j++;
            couple_list = realloc(couple_list, sizeof(Couple) * (j + 1));
        }
        i++;
    }
    couple_list[j] . charValue = '\0';
    couple_list[j] . frequence = 0;
    return couple_list;
}

// Fonction qui créer une liste de Nœud à partir d'une liste de couple
Noeud * get_noeud_list(Couple * couple_list) {
    Noeud * noeud_list = malloc(sizeof(Noeud));
    int i = 0;
    while (couple_list[i] . charValue != '\0') {
        noeud_list[i] . couple = & couple_list[i];
        noeud_list[i] . haut = NULL;
        noeud_list[i] . bas = NULL;
        i++;
        noeud_list = realloc(noeud_list, sizeof(Noeud) * (i + 1));
    }
    noeud_list[i] . couple = NULL;
    noeud_list[i] . haut = NULL;
    noeud_list[i] . bas = NULL;
    return noeud_list;
}

// fonction qui compte le nombre de nœuds dans une liste de nœud
int count_noeud(Noeud * noeud_list) {
    int i = 0;
    while (noeud_list[i] . couple != NULL) {
        i++;
    }
    return i;
}

// ---------------------------------------------------------------------------

// MAIN

int main() {
    lecture_fichier();

    // use get_char_list and get_char_frequency to get the list of characters and their frequencies
    FILE * file = fopen("../fichier.txt", "r");
    char * char_list = get_char_list(file);
    unsigned * char_frequency = get_char_frequency(char_list);
    fclose(file);

    printf("char_list : \"%s\"", char_list);

    int i = 0;
    while (char_list[i] != '\0') {
        if (char_frequency[(int) char_list[i]] != 0) {
            printf("\n%c : %d", char_list[i], char_frequency[(int) char_list[i]]);
            char_frequency[(int) char_list[i]] = 0;
        }
        i++;
    }

    // use get_couple_list to get the list of couples
    Couple * couple_list = get_couple_list(char_list, char_frequency);

    // use get_noeud_list to get the list of noeuds
    Noeud * noeud_list = get_noeud_list(couple_list);

    // get the number of noeuds
    int nb_noeud = count_noeud(noeud_list);
    printf("\n\nnb noeud : %d", nb_noeud);
    printf("\nAinsi, on doit faire %d fusions", nb_noeud - 1);

    if (nb_noeud > 1) {
        noeud_list = node_fusion(noeud_list, nb_noeud);
    }
    printf("\n\nNoeud Racine: %c : %d", noeud_list[0] . couple -> charValue, noeud_list[0] . couple -> frequence);

    // free the memory
    free(char_list);
    free(char_frequency);
    free(couple_list);
    free(noeud_list);

    return 0;
}

// Extraction des octets du fichier : DONE

// Création d'une liste avec tous les caractères différents : DONE

// Pour chacun de ces caractères : DONE
// Compter le nombre d'occurrences : DONE

// Associer chaque caractère avec son nombre d'occurrences : DONE

// Création d'un arbre binaire pour chaque duo Valeur / Fréquence : DONE

// Tant qu'il n'a pas de nœud final : DONE
// On fusionne les arbres binaires avec les plus petites fréquences : DONE

// On crée un code de Huffman pour réécrire le fichier de façon compressé

// On retourne le code de Huffman
// On retourne le fichier compressé

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

Noeud * fusion_noeud(Noeud * noeud_list, unsigned noeud_list_length);

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

Noeud * node_fusion(Noeud * noeud_list, unsigned noeud_list_length) {
    // Return if the size is less or equals than 1
    if (noeud_list_length <= 1) {
        return noeud_list;
    }

    // Find the two lowest nodes
    Noeud * lowest_node_1 = noeud_list;
    Noeud * lowest_node_2 = noeud_list + 1;
    if (lowest_node_1 -> couple -> frequence > lowest_node_2 -> couple -> frequence) {
        lowest_node_1 = noeud_list + 1;
        lowest_node_2 = noeud_list;
    }

    // Instantiate the new node couple
    Couple * new_couple = malloc(sizeof(Couple));
    new_couple -> charValue = '\0';
    new_couple -> frequence = lowest_node_1 -> couple -> frequence + lowest_node_2 -> couple -> frequence;

    // Instantiate the new node
    Noeud * new_node = malloc(sizeof(Noeud));
    new_node -> couple = new_couple;
    new_node -> haut = (struct Noeud *) lowest_node_1;
    new_node -> bas = (struct Noeud *) lowest_node_2;

    // Delete the two lowest nodes couples
    free(lowest_node_1 -> couple);
    free(lowest_node_2 -> couple);

    // Delete the two lowest nodes
    free(lowest_node_1);
    free(lowest_node_2);

    // Create a new list of nodes
    Noeud * new_noeud_list = malloc(sizeof(Noeud) * (noeud_list_length - 1));
    int i = 0;
    int j = 0;
    while (i < noeud_list_length) {
        if (noeud_list != lowest_node_1 && noeud_list != lowest_node_2) {
            new_noeud_list[j] = noeud_list[i];
            j++;
        }
        i++;
    }
    new_noeud_list[j] = * new_node;
    j++;
    new_noeud_list[j] . couple = NULL;
    new_noeud_list[j] . haut = NULL;
    new_noeud_list[j] . bas = NULL;

    // Recursion call
    return node_fusion(new_node, noeud_list_length - 1);
}

Noeud * fusion_noeud(Noeud * noeud_list, unsigned noeud_list_length) {
    // verification de la taille de la liste
    if (noeud_list_length <= 1) {
        return noeud_list;
    }
    // recherche des deux couples de nœud avec les plus petites fréquences
    int min1 = 0;
    int min2 = 1;
    if (noeud_list[min1] . couple -> frequence > noeud_list[min2] . couple -> frequence) {
        int tmp = min1;
        min1 = min2;
        min2 = tmp;
    }
    for (int i = 2; i < noeud_list_length; i++) {
        if (noeud_list[i] . couple -> frequence < noeud_list[min1] . couple -> frequence) {
            min2 = min1;
            min1 = i;
        } else if (noeud_list[i] . couple -> frequence < noeud_list[min2] . couple -> frequence) {
            min2 = i;
        }
    }
    // creation du nouveau couple
    Couple * new_couple = malloc(sizeof(Couple));
    new_couple -> charValue = '\0';
    new_couple -> frequence = noeud_list[min1] . couple -> frequence + noeud_list[min2] . couple -> frequence;
    // creation du nouveau nœud
    Noeud * new_noeud = malloc(sizeof(Noeud));
    new_noeud -> couple = new_couple;
    new_noeud -> haut = (struct Noeud *) & noeud_list[min1];
    new_noeud -> bas = (struct Noeud *) & noeud_list[min2];
    // suppression des deux couples de nœud les plus petits
    for (int i = min2; i < noeud_list_length - 1; i++) {
        noeud_list[i] = noeud_list[i + 1];
    }
    for (int i = min1; i < noeud_list_length - 2; i++) {
        noeud_list[i] = noeud_list[i + 1];
    }
    // ajout du nouveau nœud
    noeud_list[noeud_list_length - 2] = * new_noeud;
    noeud_list[noeud_list_length - 1] . couple = NULL;
    noeud_list[noeud_list_length - 1] . haut = NULL;
    noeud_list[noeud_list_length - 1] . bas = NULL;
    // appel récursif
    return fusion_noeud(noeud_list, noeud_list_length - 1);
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
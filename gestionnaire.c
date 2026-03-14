#include "gestionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Fonction pour créer un gestionnaire d'étudiants
GestionnaireEtudiants creer_gestionnaire() {
GestionnaireEtudiants g;
g.taille = 0;
return g;
}
// Fonction pour ajouter un étudiant
GestionnaireEtudiants ajouter_etudiant(GestionnaireEtudiants g, Etudiant e) {
if (est_plein(g)) {
printf("Erreur : Le gestionnaire est plein.\n");
return g;
}
for (int i = 0; i < g.taille; i++) {
if (strcmp(g.etudiants[i].nom, e.nom) == 0) {
printf("Erreur : L'étudiant %s existe déjà.\n", e.nom);
return g;
}
}
g.etudiants[g.taille] = e;
g.taille++;
return g;
}
// Fonction pour supprimer un étudiant
GestionnaireEtudiants supprimer_etudiant(GestionnaireEtudiants g, char* nom) {
if (est_vide(g)) {
printf("Erreur : Le gestionnaire est vide.\n");

return g;
}
for (int i = 0; i < g.taille; i++) {
if (strcmp(g.etudiants[i].nom, nom) == 0) {
for (int j = i; j < g.taille - 1; j++) {
g.etudiants[j] = g.etudiants[j + 1];
}
g.taille--;
return g;
}
}
printf("Erreur : L'étudiant %s n'a pas été trouvé.\n", nom);
return g;
}
// Fonction pour chercher un étudiant
Etudiant chercher_etudiant(GestionnaireEtudiants g, char* nom) {
for (int i = 0; i < g.taille; i++) {
if (strcmp(g.etudiants[i].nom, nom) == 0) {
return g.etudiants[i];
}
}
printf("Erreur : L'étudiant %s n'a pas été trouvé.\n", nom);
Etudiant e = {"", 0, ""};
return e; // Retourner un étudiant vide
}

// Fonction pour obtenir l'étudiant à la position i
Etudiant ieme_etudiant(GestionnaireEtudiants g, int i) {
if (i < 0 || i >= g.taille) {
printf("Erreur : Index hors limites.\n");
Etudiant e = {"", 0, ""};

return e; // Retourner un étudiant vide
}
return g.etudiants[i];
}

// Fonction pour vérifier si le gestionnaire est vide
int est_vide(GestionnaireEtudiants g) {
return g.taille == 0;
}
// Fonction pour vérifier si le gestionnaire est plein
int est_plein(GestionnaireEtudiants g) {
return g.taille >= MAX_ETUDIANTS;
}
// Fonction pour obtenir la taille du gestionnaire
int taille(GestionnaireEtudiants g) {
return g.taille;
}
// Fonction pour modifier les informations d'un étudiant
GestionnaireEtudiants modifier_etudiant(GestionnaireEtudiants g, char* nom, Etudiant e) {
for (int i = 0; i < g.taille; i++) {
if (strcmp(g.etudiants[i].nom, nom) == 0) {
g.etudiants[i] = e;
return g;
}
}
printf("Erreur : L'étudiant %s n'a pas été trouvé.\n", nom);
return g;
}
// Fonction pour trier les étudiants par nom
GestionnaireEtudiants trier_par_nom(GestionnaireEtudiants g) {
for (int i = 0; i < g.taille - 1; i++) {

for (int j = i + 1; j < g.taille; j++) {
if (strcmp(g.etudiants[i].nom, g.etudiants[j].nom) > 0) {
Etudiant temp = g.etudiants[i];
g.etudiants[i] = g.etudiants[j];
g.etudiants[j] = temp;
}
}
}
return g;
}
// Fonction pour compter le nombre d'étudiants dans une filière
int compter_filiere(GestionnaireEtudiants g, char* filiere) {
int count = 0;
for (int i = 0; i < g.taille; i++) {
if (strcmp(g.etudiants[i].filiere, filiere) == 0) {
count++;
}
}
return count;
}
// Fonction pour obtenir l'étudiant le plus âgé
Etudiant etudiant_le_plus_age(GestionnaireEtudiants g) {
if (est_vide(g)) {
printf("Erreur : Le gestionnaire est vide.\n");
Etudiant e = {"", 0, ""};
return e; // Retourner un étudiant vide
}
Etudiant maxAgeEtudiant = g.etudiants[0];
for (int i = 1; i < g.taille; i++) {
if (g.etudiants[i].age > maxAgeEtudiant.age) {
maxAgeEtudiant = g.etudiants[i];

}
}
return maxAgeEtudiant;
}
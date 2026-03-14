#include <stdio.h>
#include <stdlib.h>
#include "gestionnaire.h"
void afficher_menu() {
printf("\n--- Gestionnaire d'Étudiants ---\n");
printf("1. Ajouter un étudiant\n");
printf("2. Supprimer un étudiant\n");
printf("3. Modifier un étudiant\n");
printf("4. Afficher tous les étudiants\n");
printf("5. Chercher un étudiant\n");
printf("6. Trier par nom\n");
printf("7. Compter les étudiants dans une filière\n");
printf("8. Trouver l'étudiant le plus âgé\n");
printf("9. Quitter\n");
printf("Choisissez une option : ");
}

int main() {
GestionnaireEtudiants g = creer_gestionnaire();
int choix;
do {
afficher_menu();
scanf("%d", &choix);
getchar(); // Pour consommer le caractère de nouvelle ligne
switch (choix) {
case 1: {

Etudiant e;
printf("Nom : ");
fgets(e.nom, 50, stdin);
e.nom[strcspn(e.nom, "\n")] = 0; // Retirer le saut de ligne
printf("Âge : ");
scanf("%d", &e.age);
getchar(); // Consommer le saut de ligne
printf("Filière : ");
fgets(e.filiere, 50, stdin);
e.filiere[strcspn(e.filiere, "\n")] = 0; // Retirer le saut de ligne
g = ajouter_etudiant(g, e);
break;
}
case 2: {
char nom[50];
printf("Nom de l'étudiant à supprimer : ");
fgets(nom, 50, stdin);
nom[strcspn(nom, "\n")] = 0; // Retirer le saut de ligne
g = supprimer_etudiant(g, nom);
break;
}
case 3: {
char nom[50];
printf("Nom de l'étudiant à modifier : ");
fgets(nom, 50, stdin);
nom[strcspn(nom, "\n")] = 0; // Retirer le saut de ligne
Etudiant e;
printf("Nouveau nom : ");
fgets(e.nom, 50, stdin);
e.nom[strcspn(e.nom, "\n")] = 0; // Retirer le saut de ligne
printf("Nouvel âge : ");

scanf("%d", &e.age);
getchar(); // Consommer le saut de ligne
printf("Nouvelle filière : ");
fgets(e.filiere, 50, stdin);
e.filiere[strcspn(e.filiere, "\n")] = 0; // Retirer le saut de ligne
g = modifier_etudiant(g, nom, e);
break;
}
case 4: {
afficher_etudiants(g);
break;
}
case 5: {
char nom[50];
printf("Nom de l'étudiant à chercher : ");
fgets(nom, 50, stdin);
nom[strcspn(nom, "\n")] = 0; // Retirer le saut de ligne
Etudiant e = chercher_etudiant(g, nom);
if (strlen(e.nom) > 0) {
printf("Étudiant trouvé : %s, %d ans, Filière : %s\n", e.nom, e.age, e.filiere);
}
break;
}
case 6: {
g = trier_par_nom(g);
printf("Étudiants triés par nom.\n");
break;
}
case 7: {
char filiere[50];
printf("Filière : ");

fgets(filiere, 50, stdin);
filiere[strcspn(filiere, "\n")] = 0; // Retirer le saut de ligne
int count = compter_filiere(g, filiere);
printf("Nombre d'étudiants dans la filière %s : %d\n", filiere, count);
break;
}
case 8: {
Etudiant e = etudiant_le_plus_age(g);
if (strlen(e.nom) > 0) {
printf("L'étudiant le plus âgé : %s, %d ans, Filière : %s\n", e.nom, e.age, e.filiere);
}
break;
}
case 9:
printf("Au revoir !\n");
break;
default:
printf("Choix invalide. Veuillez réessayer.\n");
break;
}
} while (choix != 9);

return 0;
}
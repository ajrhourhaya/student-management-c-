#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#define MAX_ETUDIANTS 100 // Capacité maximale du gestionnaire
// Définition du type Étudiant
typedef struct {
char nom[50]; // Nom de l'étudiant
int age; // Âge de l'étudiant
char filiere[50]; // Filière de l'étudiant
} Etudiant;

// Définition du type GestionnaireEtudiants
typedef struct {
Etudiant etudiants[MAX_ETUDIANTS]; // Tableau d'étudiants
int taille; // Nombre actuel d'étudiants
} GestionnaireEtudiants;

// Opérations sur le Gestionnaire d'Étudiants
GestionnaireEtudiants creer_gestionnaire();
GestionnaireEtudiants ajouter_etudiant(GestionnaireEtudiants g, Etudiant e);
GestionnaireEtudiants supprimer_etudiant(GestionnaireEtudiants g, char* nom);
Etudiant chercher_etudiant(GestionnaireEtudiants g, char* nom);
Etudiant ieme_etudiant(GestionnaireEtudiants g, int i);
int est_vide(GestionnaireEtudiants g);
int est_plein(GestionnaireEtudiants g);
int taille(GestionnaireEtudiants g);
GestionnaireEtudiants modifier_etudiant(GestionnaireEtudiants g, char* nom, Etudiant e);
GestionnaireEtudiants trier_par_nom(GestionnaireEtudiants g);
int compter_filiere(GestionnaireEtudiants g, char* filiere);
Etudiant etudiant_le_plus_age(GestionnaireEtudiants g);
#endif // GESTIONNAIRE_H
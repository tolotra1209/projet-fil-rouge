# projet-fil-rouge
#declaration des variables 
Type1 
    parametre = Enregistrement
                    langue:chaine de caractere
                    couleur:couleur
                    preference:chaine de caractere
                Finenreg
Type2
    couleur = Enregistrement
                    choix1:chaine de caractere
                    choix2:chaine de caractere
                    choix3:chaine de caractere
              Finenreg
              
variable
parametreUtilisateur: parametre
langueParDefaut='Anglais'
couleurParDefaut='Rouge','Bleue','Verte'
choix1ParDefaut='Rouge'
choix2ParDefaut='Bleue'
choix3ParDefaut='Verte'
preferenceParDefaut='Preference'       

#corps du programme
Debut
    Ecrire("Veuillez entrer une langue:")
    Lire(parametre.langue)
    Ecrire("Veuillez entrer le premier choix de couleur:")
    Lire(couleur.choix1)
    Ecrire("Veuillez entrer le deuxieme choix de couleur:")
    Lire(couleur.choix2)
    Ecrire("Veuillez entrer le troisieme choix de couleur:")
    Lire(couleur.choix3)
    Ecrire(parametre.couleur)
Fin

Procedure configLangue()
si langueSaisie != langueParDefaut faire
    parametre.langue=langueSaisie
sinon si langueSaisie = langueParDefaut faire
    parametre.langue='Anglais'
sinon
    ecrire("la langue saisie est invalide")

Procedure configCouleur()
si couleurSaisie != couleurParDefaut faire
    parametre.couleur=couleurSaisie
sinon si couleurSaisie = couleurParDefaut faire
    parametre.couleur='Rouge'
sinon
    ecrire("la couleur saisie est invalide")

Procedure configPreference()
si preferenceSaisie != preferenceParDefaut faire
    parametre.preference=preferenceSaisie
sinon si preferenceSaisie = preferenceParDefaut faire
    parametre.preference='Preference'
sinon
    ecrire("la preference saisie est invalide")      
        

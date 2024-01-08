from tkinter import *
import tkinter
import tkinter.font as font
from tkinter import messagebox
fenetre = Tk()

fenetre.title("Accueil")
fenetre.geometry("300x200")

#choix de la langue

liste=Listbox(fenetre,height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")
liste.insert(3, "Allemand")
liste.insert(4, "Espagnol")

liste.pack()

label=Label(fenetre, text="Veuillez saisir une langue : ")
label.pack()
langue_choisie=Entry(fenetre)
langue_choisie.pack()    

#choix de l'action

def recup_langue():
    recup_langue=langue_choisie.get()
    #Anglais
    if recup_langue == "Anglais":
        fenetre = Tk()

        fenetre.title("Anglais")
        fenetre.geometry("200x450")

        #choix de la couleur
        liste=Listbox(fenetre,height=3)
        liste.insert(1, "Red")
        liste.insert(2, "Green")
        liste.insert(3, "Blue")
        liste.pack()

        label=Label(fenetre, text="Please enter a color: ")
        label.pack()
        couleur_choisie=Entry(fenetre)
        couleur_choisie.pack()

        #création d'une liste/réinitialiser la liste
        couleur_phrase=[]
        def get_color():
            get_color=couleur_choisie.get()
            if get_color == "Red":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Green":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Blue":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            else:
                messagebox.showerror("ERROR", "Invalid color")
            print(couleur_phrase)

        bouton=Button(fenetre, text="Validate",command=get_color)
        bouton.pack()

        
        #choix nom
        liste=Listbox(fenetre,height=2)
        liste.insert(1, "Ball")
        liste.insert(2, "Cube")
        liste.pack()

        label=Label(fenetre, text="Please enter an obstacle : ")
        label.pack()
        nom_choisi=Entry(fenetre)
        nom_choisi.pack()

        #création d'une liste/réinitialiser la liste
        nom_phrase=[]
        def get_nom():
            get_nom=nom_choisi.get()
            if get_nom == "Ball":
                nom_phrase.clear()
                nom_phrase.append(get_nom)
            elif get_nom == "Cube":
                nom_phrase.clear()
                nom_phrase.append(get_nom)
            else:
                messagebox.showerror("ERROR", "Invalid noun")

            print(nom_phrase)   

        bouton=Button(fenetre, text="Validate",command=get_nom)
        bouton.pack()

        #choix verbe
        liste=Listbox(fenetre,height=3)
        liste.insert(2, "Moves")
        liste.insert(3, "Turns")
        liste.pack()

        label=Label(fenetre, text="Please enter an action : ")
        label.pack()
        action_choisie=Entry(fenetre)
        action_choisie.pack()

    #création d'une liste/réinitialiser la liste
        action_phrase=[]
        def get_action():
            get_action=action_choisie.get()
            if get_action == "Moves":
                action_phrase.clear()
                action_phrase.append(get_action)
            elif get_action == "Turns":
                action_phrase.clear()
                action_phrase.append(get_action)
            else:
                messagebox.showerror("ERROR", "Invalid noun")

            print(action_phrase)   

        bouton=Button(fenetre, text="Validate",command=get_action)
        bouton.pack()

        label=Label(fenetre, text="Sentence")
        label.pack()
        def afficher_phrase():
            label.config(text = action_phrase[0]+" towards the "+couleur_phrase[0]+" "+nom_phrase[0])
            

        bouton=Button(fenetre, text="Valid",command=afficher_phrase)
        bouton.pack()
            
        fenetre.mainloop()
        
    #français
    elif recup_langue == "Français":   
        fenetre = Tk()

        fenetre.title("Français")
        fenetre.geometry("200x450")

        #choix de la couleur
        liste=Listbox(fenetre,height=3)
        liste.insert(1, "Rouge")
        liste.insert(2, "Vert")
        liste.insert(3, "Bleu")
        liste.pack()

        label=Label(fenetre, text="Saisissez une couleur : ")
        label.pack()
        couleur_choisie=Entry(fenetre)
        couleur_choisie.pack()

        #création d'une liste/réinitialiser la liste
        couleur_phrase=[]
        def get_color():
            get_color=couleur_choisie.get()
            if get_color == "Rouge":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Vert":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Bleu":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            else:
                messagebox.showerror("ERREUR", "Couleur invalide")
            print(couleur_phrase)

        bouton=Button(fenetre, text="Valider",command=get_color)
        bouton.pack()

        #choix nom
        liste=Listbox(fenetre,height=2)
        liste.insert(1, "Balle")
        liste.insert(2, "Cube")
        liste.pack()

        label=Label(fenetre, text="Saisissez un obstacle : ")
        label.pack()
        nom_choisi=Entry(fenetre)
        nom_choisi.pack()

        #création d'une liste/réinitialiser la liste
        nom_phrase=[]
        def get_nom():
            get_nom=nom_choisi.get()
            if get_nom == "Balle":
                nom_phrase.clear()
                nom_phrase.append("la Balle")
            elif get_nom == "Cube":
                nom_phrase.clear()
                nom_phrase.append("le Cube")
            else:
                messagebox.showerror("ERREUR", "Nom invalide")

            print(nom_phrase)   

        bouton=Button(fenetre, text="Valider",command=get_nom)
        bouton.pack()

        #choix verbe
        liste=Listbox(fenetre,height=3)
        liste.insert(2, "Avance")
        liste.insert(3, "Tourne")
        liste.pack()

        label=Label(fenetre, text="Saisissez une action : ")
        label.pack()
        action_choisie=Entry(fenetre)
        action_choisie.pack()

    #création d'une liste/réinitialiser la liste
        action_phrase=[]
        def get_action():
            get_action=action_choisie.get()
            if get_action == "Avance":
                action_phrase.clear()
                action_phrase.append(get_action)
            elif get_action == "Tourne":
                action_phrase.clear()
                action_phrase.append(get_action)
            else:
                messagebox.showerror("ERREUR", "Action invalide")

            print(action_phrase)   

        bouton=Button(fenetre, text="Valider",command=get_action)
        bouton.pack()

        label=Label(fenetre, text="Phrase")
        label.pack()
        def afficher_phrase():
            label.config(text = action_phrase[0]+" vers "+nom_phrase[0]+" "+couleur_phrase[0])
            
        bouton=Button(fenetre, text="Valider",command=afficher_phrase)
        bouton.pack()
            
        fenetre.mainloop()

     #Allemand
    elif recup_langue == "Allemand":   
        fenetre = Tk()

        fenetre.title("Allemand")
        fenetre.geometry("200x450")

        #choix de la couleur
        liste=Listbox(fenetre,height=3)
        liste.insert(1, "Rot")
        liste.insert(2, "Grün")
        liste.insert(3, "Blau")
        liste.pack()

        label=Label(fenetre, text="Geben Sie eine Farbe ein : ")
        label.pack()
        couleur_choisie=Entry(fenetre)
        couleur_choisie.pack()

        #création d'une liste/réinitialiser la liste
        couleur_phrase=[]
        def get_color():
            get_color=couleur_choisie.get()
            if get_color == "Rot":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Grün":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Blau":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            else:
                messagebox.showerror("ERROR", "Ungültige Farbe")
            print(couleur_phrase)

        bouton=Button(fenetre, text="Bestätigen",command=get_color)
        bouton.pack()

        
        #choix nom
        liste=Listbox(fenetre,height=2)
        liste.insert(1, "Ball")
        liste.insert(2, "Würfel")
        liste.pack()

        label=Label(fenetre, text="Geben Sie ein Hindernis ein : ")
        label.pack()
        nom_choisi=Entry(fenetre)
        nom_choisi.pack()

        #création d'une liste/réinitialiser la liste
        nom_phrase=[]
        def get_nom():
            get_nom=nom_choisi.get()
            if get_nom == "Ball":
                nom_phrase.clear()
                nom_phrase.append("der Ball")
            elif get_nom == "Würfel":
                nom_phrase.clear()
                nom_phrase.append("der Würfel")
            else:
                messagebox.showerror("ERROR", "Ungültiger Name")

            print(nom_phrase)   

        bouton=Button(fenetre, text="Bestätigen",command=get_nom)
        bouton.pack()


        
        #choix verbe
        liste=Listbox(fenetre,height=3)
        liste.insert(2, "Vorschuss")
        liste.insert(3, "Drehe")
        liste.pack()

        label=Label(fenetre, text="Geben Sie eine Aktion ein : ")
        label.pack()
        action_choisie=Entry(fenetre)
        action_choisie.pack()

    #création d'une liste/réinitialiser la liste
        action_phrase=[]
        def get_action():
            get_action=action_choisie.get()
            if get_action == "Vorschuss":
                action_phrase.clear()
                action_phrase.append(get_action)
            elif get_action == "Drehe":
                action_phrase.clear()
                action_phrase.append(get_action)
            else:
                messagebox.showerror("ERROR", "Ungültiger Aktion")

            print(action_phrase)   

        bouton=Button(fenetre, text="Bestätigen",command=get_action)
        bouton.pack()

        label=Label(fenetre, text="Phrase")
        label.pack()
        def afficher_phrase():
            label.config(text = action_phrase[0]+" zu "+couleur_phrase[0]+" "+nom_phrase[0])
            
        bouton=Button(fenetre, text="Valider",command=afficher_phrase)
        bouton.pack()
            
        fenetre.mainloop()

    #Espagnol
    elif recup_langue == "Espagnol":   
        fenetre = Tk()

        fenetre.title("Espagnol")
        fenetre.geometry("200x450")

        #choix de la couleur
        liste=Listbox(fenetre,height=3)
        liste.insert(1, "Rojo")
        liste.insert(2, "Verde")
        liste.insert(3, "Azul")
        liste.pack()

        label=Label(fenetre, text="Introduzca un color : ")
        label.pack()
        couleur_choisie=Entry(fenetre)
        couleur_choisie.pack()

        #création d'une liste/réinitialiser la liste
        couleur_phrase=[]
        def get_color():
            get_color=couleur_choisie.get()
            if get_color == "Rojo":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Verde":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            elif get_color == "Azul":
                couleur_phrase.clear()
                couleur_phrase.append(get_color)
            else:
                messagebox.showerror("ERROR", "Color no válido")
            print(couleur_phrase)

        bouton=Button(fenetre, text="Confirme",command=get_color)
        bouton.pack()

        
        #choix nom
        liste=Listbox(fenetre,height=2)
        liste.insert(1, "Bola")
        liste.insert(2, "Cubo")
        liste.pack()

        label=Label(fenetre, text="Introduzca un obstáculo : ")
        label.pack()
        nom_choisi=Entry(fenetre)
        nom_choisi.pack()

        #création d'une liste/réinitialiser la liste
        nom_phrase=[]
        def get_nom():
            get_nom=nom_choisi.get()
            if get_nom == "Bola":
                nom_phrase.clear()
                nom_phrase.append("la Bola")
            elif get_nom == "Cubo":
                nom_phrase.clear()
                nom_phrase.append("el Cubo")
            else:
                messagebox.showerror("ERROR", "Nombre no válido")

            print(nom_phrase)   

        bouton=Button(fenetre, text="Confirme",command=get_nom)
        bouton.pack()

        #choix verbe
        liste=Listbox(fenetre,height=3)
        liste.insert(2, "Avanzar")
        liste.insert(3, "Gire")
        liste.pack()

        label=Label(fenetre, text="Introducir una acción : ")
        label.pack()
        action_choisie=Entry(fenetre)
        action_choisie.pack()

    #création d'une liste/réinitialiser la liste
        action_phrase=[]
        def get_action():
            get_action=action_choisie.get()
            if get_action == "Avanzar":
                action_phrase.clear()
                action_phrase.append(get_action)
            elif get_action == "Gire":
                action_phrase.clear()
                action_phrase.append(get_action)
            else:
                messagebox.showerror("ERROR", "Acción no válida")

            print(action_phrase)   

        bouton=Button(fenetre, text="Confirme",command=get_action)
        bouton.pack()

        label=Label(fenetre, text="Phrase")
        label.pack()
        def afficher_phrase():
            label.config(text = action_phrase[0]+" hacia "+nom_phrase[0]+" "+couleur_phrase[0])
            

        bouton=Button(fenetre, text="Valider",command=afficher_phrase)
        bouton.pack()
            
        fenetre.mainloop()

    #ERROR
    else:
        messagebox.showerror("ERROR", "Invalid language")
        
bouton1=Button(fenetre, text="Valider", command=recup_langue)
bouton1.pack()

fenetre.mainloop()

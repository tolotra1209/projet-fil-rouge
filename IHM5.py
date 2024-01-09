from tkinter import *
import tkinter
from tkinter import messagebox

fenetre = Tk()

fenetre.title("Accueil")
fenetre.geometry("300x200")

#choix de la langue

liste=Listbox(fenetre,height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")

liste.pack()

label=Label(fenetre, text="Please enter a language : ")
label.pack()
langue_choisie = Entry(fenetre)
langue_choisie.pack()
    

#choix de l'action suivant la langue choisie

def recup_langue():
    recup_langue = langue_choisie.get()

    #Anglais

    if recup_langue == "Anglais":
        fenetre = Tk()

        fenetre.title("English")
        fenetre.geometry("200x450")

        #choix de l'action

        liste=Listbox(fenetre,height=3)
        liste.insert(1, "Moves forward")
        liste.insert(2, "Moves forward to the (Color) (Obstacle)")
        liste.pack()

        label=Label(fenetre, text="Please enter an action : ")
        label.pack()
        phrase_entree = Entry(fenetre)
        phrase_entree.pack()

        #création d'une liste/réinitialiser la liste

        phrase = []
        def get_phrase():
            get_phrase = phrase_entree.get()
            phrase = phrase.append(get_phrase)

        bouton = Button(fenetre, text="Validate",command=get_phrase)
        bouton.pack()

        def modif_txt():
            label_modif.config(text="The sentence has been saved")
            file = open("fichier.txt","r") #le fichier doit déjà exister
            lignes = file.readlines()
            file.close()
            lignes[0] = phrase
            file=open("fichier.txt","w")
            file.writelines(lignes)
            file.close()

        bouton = Button(fenetre, text="Validate sentence",command=modif_txt)
        bouton.pack()

        fenetre.mainloop()
        
    #Français
        
    elif recup_langue == "Français":
        fenetre = Tk()

        fenetre.title("Français")
        fenetre.geometry("200x450")

        #choix de l'action

        liste=Listbox(fenetre,height=3)
        liste.insert(1, "Avance")
        liste.insert(2, "Avance vers (le/la Obstacle) (Couleur)")
        liste.pack()

        label=Label(fenetre, text="Saisissez une action : ")
        label.pack()
        phrase_entree = Entry(fenetre)
        phrase_entree.pack()

        #création d'une liste/réinitialiser la liste

        phrase = []
        def get_phrase():
            get_phrase = phrase_entree.get()
            phrase = phrase.append(get_phrase)

        bouton = Button(fenetre, text="Valider",command=get_phrase)
        bouton.pack()
            
        def modif_txt():
            label_modif.config(text="La phrase a été enregistrée")
            file = open("fichier.txt","r") #le fichier doit déjà exister
            lignes = file.readlines()
            file.close()
            lignes[0] = phrase
            file=open("fichier.txt","w")
            file.writelines(lignes)
            file.close()

        bouton = Button(fenetre, text="Valider la phrase",command=modif_txt)
        bouton.pack()

        fenetre.mainloop()
        
    else:
        messagebox.showerror("ERROR", "Invalid language")
                    
bouton = Button(fenetre, text="Validate", command=recup_langue)
bouton.pack()

fenetre.mainloop()

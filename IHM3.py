from tkinter import *
import tkinter
import tkinter.font as font
from tkinter import messagebox
fenetre = Tk()

fenetre.title("Accueil")
fenetre.geometry("300x200")

#choix de Langue
liste=Listbox(fenetre,height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")
liste.insert(3, "Allemand")
liste.insert(4, "Espagnol")

liste.pack()

label=Label(fenetre, text="Veuillez saisir une langue: ")
label.pack()
langue_choisie=Entry(fenetre)
langue_choisie.pack()

#fonction couleur
def anglais_couleur():
    fenetre = Tk()

    fenetre.title("Colors")
    fenetre.geometry("200x300")

    #choix de la couleur
    liste=Listbox(fenetre)
    liste.insert(1, "Red")
    liste.insert(2, "Green")
    liste.insert(3, "Blue")
    liste.pack()

    label=Label(fenetre, text="Please enter a color: ")
    label.pack()
    couleur_choisie=Entry(fenetre)
    couleur_choisie.pack()

    fenetre.mainloop()    

#fonction lexique
def anglais_lexique():
    fenetre = Tk()

    fenetre.title("Lexicon")
    fenetre.geometry("200x300")
    
    #choix nom
    liste=Listbox(fenetre)
    liste.insert(1, "Ball")
    liste.insert(2, "Cube")
    liste.pack()

    label=Label(fenetre, text="Please enter an obstacle : ")
    label.pack()
    nom_choisi=Entry(fenetre)
    nom_choisi.pack()

    #choix verbe
    liste=Listbox(fenetre)
    liste.insert(1, "Moves towards")
    liste.insert(2, "Moves")
    liste.insert(3, "Turns")
    liste.pack()

    label=Label(fenetre, text="Please enter an action : ")
    label.pack()
    action_choisie=Entry(fenetre)
    action_choisie.pack()

    fenetre.mainloop()
    
def recup_langue():
    recup_langue=langue_choisie.get()
    #anglais
    if recup_langue == "Anglais":
        fenetre = Tk()

        fenetre.title("Anglais")
        fenetre.geometry("200x300")
        #bouton couleur
        f=font.Font(size=18)
        bouton=Button(fenetre, text="COULEUR", command=anglais_couleur,width=10,height=2)
        bouton["font"]=f
        bouton.pack()

        #bouton lexique
        f=font.Font(size=18)
        bouton=Button(fenetre, text="LEXIQUE", command=anglais_lexique,width=10,height=2)
        bouton["font"]=f
        bouton.pack()
        
        fenetre.mainloop()
    
    #français
    elif recup_langue == "Français":
        fenetre = Tk()

        fenetre.title("Français")
        fenetre.geometry("200x300")

        fenetre.mainloop()

    #allemand
    elif recup_langue == "Allemand":
        fenetre = Tk()

        fenetre.title("Allemand")
        fenetre.geometry("200x300")

        fenetre.mainloop()


    #Espagnol
    elif recup_langue == "Espagnol":
        fenetre = Tk()

        fenetre.title("Espagnol")
        fenetre.geometry("200x300")

        fenetre.mainloop()

    #ERROR
    else:
        messagebox.showerror("ERROR", "Invalid language")
        
    


bouton1=Button(fenetre, text="Valider", command=recup_langue)
bouton1.pack()



fenetre.mainloop()

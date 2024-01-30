#BASTIDE Guillaume RANDRIAMAROVELO Tolotra	

from tkinter import *
import tkinter
import tkinter.font as font
from tkinter import messagebox
fenetre= Tk()

fenetre.title("Parametres de configuration")
fenetre.geometry("300x200")

#choix de Langue
liste=Listbox(fenetre,height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")
liste.insert(3, "Allemand")
liste.insert(4, "Espagnol")

liste.pack()

label=Label(fenetre, text="Veuillez entrer une langue: ")
label.pack()
entree=Entry(fenetre)
entree.pack()

#fonction couleur
def afficher2():
    fenetre= Tk()

    fenetre.title("Parametres de configuration")
    fenetre.geometry("200x300")

    #menu
    #Creer la barre de menu
    menu_pfr = tkinter.Menu(fenetre)

    #Creer menu en cascade
    menu_aides = tkinter.Menu(menu_pfr, tearoff = 0)
    menu_quitter = tkinter.Menu(menu_pfr, tearoff = 0)
    menu_pfr.add_cascade(label = "Aides", menu = menu_aides)
    menu_pfr.add_cascade(label = "Quitter", menu = menu_quitter)

    #Mettre les éléments dans la cascade
    menu_aides.add_command(label = "Manuel")
    menu_quitter.add_command(label = "Quitter", command = exit)

    #Emplacement du menu
    fenetre.config(menu = menu_pfr)

    liste=Listbox(fenetre)
    liste.insert(1, "Rouge")
    liste.insert(2, "Bleu")
    liste.insert(3, "Vert")
    liste.pack()

    fenetre.mainloop()    

#fonction lexique
def afficher3():
    fenetre= Tk()

    fenetre.title("Parametres de configuration")
    fenetre.geometry("200x300")

    #menu
    #Creer la barre de menu
    menu_pfr = tkinter.Menu(fenetre)

    #Creer menu en cascade
    menu_aides = tkinter.Menu(menu_pfr, tearoff = 0)
    menu_quitter = tkinter.Menu(menu_pfr, tearoff = 0)
    menu_pfr.add_cascade(label = "Aides", menu = menu_aides)
    menu_pfr.add_cascade(label = "Quitter", menu = menu_quitter)

    #Mettre les éléments dans la cascade
    menu_aides.add_command(label = "Manuel")
    menu_quitter.add_command(label = "Quitter", command = exit)

    #Emplacement du menu
    fenetre.config(menu = menu_pfr)

    #bouton nom
    f=font.Font(size=18)
    bouton=Button(fenetre, text="NOM")
    bouton["font"]=f
    bouton.pack()

    #bouton verbe
    f=font.Font(size=18)
    bouton=Button(fenetre, text="VERBE")
    bouton["font"]=f
    bouton.pack()

    #bouton adjectif
    f=font.Font(size=18)
    bouton=Button(fenetre, text="ADJECTIF")
    bouton["font"]=f
    bouton.pack()
    


    fenetre.mainloop()    
def entree1():
    recup=entree.get()
    #anglais
    if recup == "Anglais":
        fenetre = Tk()

        fenetre.title("Anglais")
        fenetre.geometry("200x300")
        #bouton couleur
        f=font.Font(size=18)
        bouton=Button(fenetre, text="COULEUR", command=afficher2,width=10,height=2)
        bouton["font"]=f
        bouton.pack()

        #bouton lexique
        f=font.Font(size=18)
        bouton=Button(fenetre, text="LEXIQUE", command=afficher3,width=10,height=2)
        bouton["font"]=f
        bouton.pack()


        fenetre.mainloop()
    
    #français
    elif recup == "Français":
        fenetre = Tk()

        fenetre.title("Français")
        fenetre.geometry("200x300")

        fenetre.mainloop()

    #allemand
    elif recup == "Allemand":
        fenetre = Tk()

        fenetre.title("Allemand")
        fenetre.geometry("200x300")

        fenetre.mainloop()


    #Espagnol
    elif recup == "Espagnol":
        fenetre = Tk()

        fenetre.title("Espagnol")
        fenetre.geometry("200x300")

        fenetre.mainloop()

    #ERROR
    else:
        messagebox.showerror("ERROR", "Invalid language")
        
    


bouton1=Button(fenetre, text="Valider", command=entree1)
bouton1.pack()



fenetre.mainloop()

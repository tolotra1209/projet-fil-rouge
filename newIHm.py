#BASTIDE Guillaume RANDRIAMAROVELO Tolotra	

from tkinter import *
import tkinter
import tkinter.font as font
fenetre= Tk()

fenetre.title("Parametres de configuration")
fenetre.geometry("300x300")

#menu
#Creer la barre de menu
menu_pfr = tkinter.Menu(fenetre)

#Creer menu en cascade
menu_langues = tkinter.Menu(menu_pfr, tearoff = 0)
menu_aides = tkinter.Menu(menu_pfr, tearoff = 0)
menu_quitter = tkinter.Menu(menu_pfr, tearoff = 0)
menu_pfr.add_cascade(label = "Langues", menu = menu_langues)
menu_pfr.add_cascade(label = "Aides", menu = menu_aides)
menu_pfr.add_cascade(label = "Quitter", menu = menu_quitter)

#Mettre les éléments dans la cascade
menu_aides.add_command(label = "Manuel")
menu_quitter.add_command(label = "Quitter", command = exit)
menu_langues.add_command(label = "French")
menu_langues.add_command(label = "English")
menu_langues.add_command(label = "German")

#Emplacement du menu
fenetre.config(menu = menu_pfr)

#fonction langue
def afficher1():
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
    
    #bouton
    bouton=Button(fenetre, text="Français")
    bouton.pack()
    bouton=Button(fenetre, text="")
    bouton.pack()
    bouton=Button(fenetre, text="Français")
    bouton.pack()
    bouton=Button(fenetre, text="Initialiser")
    bouton.pack()

    fenetre.mainloop()

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
    bouton=Button(fenetre, text="NOM", command=afficherNom,width=10,height=2)
    bouton["font"]=f
    bouton.pack()

    #bouton verbe
    f=font.Font(size=18)
    bouton=Button(fenetre, text="VERBE", command=afficherVerbe,width=10,height=2)
    bouton["font"]=f
    bouton.pack()

    #bouton adjectif
    f=font.Font(size=18)
    bouton=Button(fenetre, text="ADJECTIF", command=afficherAdjectif,width=10,height=2)
    bouton["font"]=f
    bouton.pack()
    


    fenetre.mainloop()

#fonction nom
def afficherNom():
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
    #Liste de noms
    liste2=Listbox(fenetre, height=3)
    liste2.insert(1, "balle")
    liste2.insert(2, "obstacle")
    liste2.insert(3, "image")

    liste2.pack()


#fonction verbe
def afficherVerbe():
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

    #Liste de verbes
    liste3=Listbox(fenetre, height=3)
    liste3.insert(1, "avance")
    liste3.insert(2, "tourne")
    liste3.insert(3, "positionne")

    liste3.pack()

#fonction adjectif
def afficherAdjectif():
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

    #Liste de adjectifs
    liste4=Listbox(fenetre, height=3)
    liste4.insert(1, "rouge")
    liste4.insert(2, "bleu")
    liste4.insert(3, "vert")

    liste4.pack()

#bouton langue
f=font.Font(size=18)
bouton=Button(fenetre, text="LANGUE", command=afficher1,width=10,height=2)
bouton["font"]=f
bouton.pack()

fenetre.mainloop()

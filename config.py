#RANDRIAMAROVELO Tolotra	

from tkinter import *
import tkinter
fenetre= Tk()

fenetre.title("Parametres de configuration")
fenetre.geometry("590x310")

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


#label
label=Label(fenetre, text="Langue")
label.place(x=10)

#Liste de langues
liste=Listbox(fenetre,height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")
liste.insert(3, "Allemand")
liste.insert(4, "Espagnol")
liste.place(x=10,y=25)

#bouton
def afficher():
    print(groupe.get())

bouton=Button(fenetre, text="Appliquer", command=afficher)
bouton.place(x=40,y=100)

#input
label2=Label(fenetre, text="Couleur")
label2.place(x=200)

val= StringVar()
val.set("Valeur par défaut")
champ= Entry(fenetre, textvariable=val)
champ.place(x=200,y=25)
bouton2=Button(fenetre, text="Valider", command=afficher)
bouton2.place(x=330,y=20)

#checkbox
checkbox=Checkbutton(fenetre, text="cocher si OK")
checkbox.place(x=200,y=50)

#boutons radio
groupe = StringVar()
bouton3= Radiobutton(fenetre, text="oui", variable=groupe,value="O")
bouton4= Radiobutton(fenetre, text="non", variable=groupe,value="N")
bouton3.place(x=200,y=75)
bouton4.place(x=200,y=100)
bouton3.invoke()

label3=Label(fenetre, text="Lexique")
label3.place(x=10,y=130)

#label nom
label=Label(fenetre, text="nom")
label.place(x=10,y=150)
val= StringVar()
val.set("défaut")
champ= Entry(fenetre, textvariable=val)
champ.place(x=10,y=175)
bouton2=Button(fenetre, text="Ajouter", command=afficher)
bouton2.place(x=140,y=170)

#Liste de noms
liste2=Listbox(fenetre, height=3)
liste2.insert(1, "balle")
liste2.insert(2, "obstacle")
liste2.insert(3, "image")

liste2.place(x=10,y=200)

#label verbe
label=Label(fenetre, text="verbe")
label.place(x=200,y=150)
val= StringVar()
val.set("défaut")
champ= Entry(fenetre, textvariable=val)
champ.place(x=200,y=175)
bouton2=Button(fenetre, text="Ajouter", command=afficher)
bouton2.place(x=330,y=170)

#Liste de verbes
liste3=Listbox(fenetre, height=3)
liste3.insert(1, "avance")
liste3.insert(2, "tourne")
liste3.insert(3, "positionne")

liste3.place(x=200,y=200)

#label adjectif
label=Label(fenetre, text="adjectif")
label.place(x=400,y=150)
val= StringVar()
val.set("défaut")
champ= Entry(fenetre, textvariable=val)
champ.place(x=400,y=175)
bouton2=Button(fenetre, text="Ajouter")
bouton2.place(x=530,y=170)

#Liste de adjectifs
liste4=Listbox(fenetre, height=3)
liste4.insert(1, "rouge")
liste4.insert(2, "bleu")
liste4.insert(3, "vert")

liste4.place(x=400,y=200)

bouton5=Button(fenetre, text="Annuler")
bouton5.place(x=425,y=275)
bouton6=Button(fenetre, text="Appliquer")
bouton6.place(x=500,y=275)

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

liste=Listbox(fenetre)
liste.insert(1, "Anglais")
liste.insert(2, "Français")
liste.insert(3, "Allemand")
liste.insert(4, "Espagnol")

liste.pack()

fenetre.mainloop()

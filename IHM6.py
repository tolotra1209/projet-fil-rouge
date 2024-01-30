#BASTIDE Guillaume RANDRIAMAROVELO Tolotra	

from tkinter import *
from tkinter import messagebox

def recup_langue():
    recup_langue = langue_choisie.get()

    def enregistrer_phrase(phrase):
        with open("C:/Users/tolot/Desktop/test/zoo.txt", "w") as filout:
            for i in phrase:
                filout.write(i)

    if recup_langue == "Anglais":
        fenetre_anglais = Tk()
        fenetre_anglais.title("English")
        fenetre_anglais.geometry("300x450")

        def save_phrase():
            phrase = phrase_entree.get()
            enregistrer_phrase(phrase)
            label_modif.config(text="The sentence has been saved")

        liste_actions = Listbox(fenetre_anglais, height=3, width=40)
        liste_actions.insert(1, "Moves forward")
        liste_actions.insert(2, "Moves forward to the Color Obstacle")
        liste_actions.insert(3, "Turn")
        liste_actions.pack()

        label = Label(fenetre_anglais, text="Please enter an action : ")
        label.pack()
        phrase_entree = Entry(fenetre_anglais)
        phrase_entree.pack()

        bouton_save = Button(fenetre_anglais, text="Save sentence", command=save_phrase)
        bouton_save.pack()

        label_modif = Label(fenetre_anglais, text="")
        label_modif.pack()

        fenetre_anglais.mainloop()

    elif recup_langue == "Français":
        fenetre_francais = Tk()
        fenetre_francais.title("Français")
        fenetre_francais.geometry("200x450")

        def save_phrase():
            phrase = phrase_entree.get()
            enregistrer_phrase(phrase)
            label_modif.config(text="La phrase a été enregistrée")

        liste_actions = Listbox(fenetre_francais, height=3)
        liste_actions.insert(1, "Avance")
        liste_actions.insert(2, "Avance vers le/la Obstacle Couleur")
        liste_actions.insert(3, "Tourne")
        liste_actions.pack()

        label = Label(fenetre_francais, text="Saisissez une action : ")
        label.pack()
        phrase_entree = Entry(fenetre_francais)
        phrase_entree.pack()

        bouton_save = Button(fenetre_francais, text="Enregistrer la phrase", command=save_phrase)
        bouton_save.pack()

        label_modif = Label(fenetre_francais, text="")
        label_modif.pack()

        fenetre_francais.mainloop()

    else:
        messagebox.showerror("ERROR", "Invalid language")

fenetre = Tk()
fenetre.title("Accueil")
fenetre.geometry("300x200")

liste = Listbox(fenetre, height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")
liste.pack()

label = Label(fenetre, text="Please enter a language : ")
label.pack()

langue_choisie = Entry(fenetre)
langue_choisie.pack()

bouton = Button(fenetre, text="Validate", command=recup_langue)
bouton.pack()

fenetre.mainloop()

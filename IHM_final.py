#BASTIDE Guillaume RANDRIAMAROVELO Tolotra	

import tkinter
from tkinter import *
from tkinter import messagebox

fenetre = Tk()

fenetre.title("Accueil")
fenetre.geometry("200x100")

#choix de la langue
label_modif=Label(fenetre, text="Select a language")
label_modif.pack()
liste=Listbox(fenetre,height=4)
liste.insert(1, "Anglais")
liste.insert(2, "Français")

liste.pack()

    
def on_langue_select(event):
    selected_language_index = liste.curselection()
    if selected_language_index:
        selected_language = liste.get(selected_language_index)
        recup_langue(selected_language)
#choix de l'action suivant la langue choisie

def recup_langue(langue):
    

    #Anglais

    if langue == "Anglais":
        fenetre = Tk()

        fenetre.title("English")
        fenetre.geometry("300x250")

        #choix de l'action

        liste=Listbox(fenetre,height=3, width=40)
        liste.insert(1, "Moves forward")
        liste.insert(2, "Moves forward to the Color Obstacle")
        liste.insert(3, "Turn")
        liste.pack()

        label=Label(fenetre, text="Please enter an action : ")
        label.pack()
        phrase_entree = Entry(fenetre)
        phrase_entree.pack()

        #création d'une liste/réinitialiser la liste

        phrase = []
        def get_phrase():
            get_phrase = phrase_entree.get()
            phrase.append(get_phrase)
            print(phrase)

        def modif_txt():
            with open("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/fichier.txt", "w") as filout:
                for i in phrase:
                    filout.write(f"{i}\n")
            label_modif.config(text="The sentence has been saved")

        label_modif=Label(fenetre, text="Waiting for validation")
        label_modif.pack()
        def appel_text():
            return [get_phrase(),modif_txt()]
            

        bouton = Button(fenetre, text="Validate sentence",command=appel_text)
        bouton.pack()

        fenetre.mainloop()
        
    #Français
        
    elif langue == "Français":
        fenetre = Tk()

        fenetre.title("Français")
        fenetre.geometry("300x250")

        #choix de l'action

        liste=Listbox(fenetre,height=3,width=40)
        liste.insert(1, "Avance")
        liste.insert(2, "Avance vers le/la Obstacle Couleur")
        liste.insert(3, "Tourne")
        liste.pack()

        label=Label(fenetre, text="Saisissez une action : ")
        label.pack()
        phrase_entree = Entry(fenetre)
        phrase_entree.pack()

        #création d'une liste/réinitialiser la liste

        phrase = []
        def get_phrase():
            get_phrase = phrase_entree.get()
            phrase.append(get_phrase)
            
        def modif_txt():
            with open("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/fichier.txt", "w") as filout:
                for i in phrase:
                    filout.write(f"{i}\n")
            label_modif.config(text="La phrase a été enregistrée")

        label_modif=Label(fenetre, text="Attente de validation")
        label_modif.pack()
        def appel_text():
            return [get_phrase(),modif_txt()]

        bouton = Button(fenetre, text="Valider la phrase",command=appel_text)
        bouton.pack()

        fenetre.mainloop()
        
    else:
        messagebox.showerror("ERROR", "Invalid language")
                    
liste.bind("<<ListboxSelect>>", on_langue_select)


fenetre.mainloop()

import tkinter
from tkinter import *
from tkinter import messagebox

fenetre = Tk()

fenetre.title("Accueil")
fenetre.geometry("200x100")

#choix de la langue
label_modif=Label(fenetre, text="Select a language",font=("Helvetica",12,"bold"),bg="light blue")
label_modif.pack()
liste=Listbox(fenetre,height=4)
liste.insert(1, "English")
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

    if langue == "English":
        fenetre = Tk()

        fenetre.title("English")
        fenetre.geometry("300x250")

        #choix de l'action

        liste=Listbox(fenetre,height=3, width=40)
        liste.insert(1, "Moves forward")
        liste.insert(2, "Moves forward to the Color Obstacle")
        liste.insert(3, "Turn")
        liste.pack()

        label=Label(fenetre, text="Please enter an action :",font=("Helvetica",8,"bold"),bg="light blue")
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
            label_modif.config(text="The sentence has been saved",font=("Helvetica",8,"bold"),bg="light green")

        label_modif=Label(fenetre, text="Waiting for validation",font=("Helvetica",8,"bold"),bg="red")
        label_modif.pack()
        def appel_text():
            return [get_phrase(),modif_txt(),phrase_entree.delete(0,"end")]
            

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

        label=Label(fenetre, text="Saisissez une action :",font=("Helvetica",8,"bold"),bg="light blue")
        label.pack()
        phrase_entree = Entry(fenetre)
        phrase_entree.pack()
        phrase_entree.delete(0,"end")

        #création d'une liste/réinitialiser la liste

        phrase = []
        def get_phrase():
            get_phrase = phrase_entree.get()
            phrase.append(get_phrase)
            
        def modif_txt():
            with open("C:/Users/tolot/Desktop/PFR/GIT/projet-fil-rouge/fichier.txt", "w") as filout:
                for i in phrase:
                    filout.write(f"{i}\n")
            label_modif.config(text="La phrase a été enregistrée",font=("Helvetica",8,"bold"),bg="light green")

        label_modif=Label(fenetre, text="En attente de validation",font=("Helvetica",8,"bold"),bg="red")
        label_modif.pack()
        def appel_text():
            return [get_phrase(),modif_txt(),phrase_entree.delete(0,"end")]

        bouton = Button(fenetre, text="Valider la phrase",command=appel_text)
        bouton.pack()

        fenetre.mainloop()
        
    else:
        messagebox.showerror("ERROR", "Invalid language")
                    
liste.bind("<<ListboxSelect>>", on_langue_select)


fenetre.mainloop()

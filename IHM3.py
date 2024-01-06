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

        print(phrase)
    
    bouton=Button(fenetre, text="Validate",command=get_color)
    bouton.pack()

    fenetre.mainloop()    

#fonction lexique
def anglais_lexique():
    fenetre = Tk()

    fenetre.title("Lexicon")
    fenetre.geometry("200x300")
    
    #choix nom
    liste=Listbox(fenetre,height=2)
    liste.insert(1, "Ball")
    liste.insert(2, "Cube")
    liste.pack()

    label=Label(fenetre, text="Please enter an obstacle : ")
    label.pack()
    nom_choisi=Entry(fenetre)
    nom_choisi.pack()

    #choix verbe
    liste=Listbox(fenetre,height=3)
    liste.insert(1, "Moves towards")
    liste.insert(2, "Moves")
    liste.insert(3, "Turns")
    liste.pack()

    label=Label(fenetre, text="Please enter an action : ")
    label.pack()
    action_choisie=Entry(fenetre)
    action_choisie.pack()

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
    
    fenetre.mainloop()

#création d'une liste/réinitialiser la liste
    action_phrase=[]
    def get_action():
        get_action=action_choisie.get()
        if get_action == "Moves towards":
            action_phrase.clear()
            action_phrase.append(get_action)
        elif get_action == "Moves":
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
    
    fenetre.mainloop()

#Afficher la phrase complète

print(action_phrase[0] "vers la/le" nom_phrase[0] couleur_phrase[0])

#fonction couleur
def francais_couleur():
    fenetre = Tk()

    fenetre.title("Couleurs")
    fenetre.geometry("200x300")

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

    fenetre.mainloop()    

#fonction lexique
def francais_lexique():
    fenetre = Tk()

    fenetre.title("Lexique")
    fenetre.geometry("200x300")
    
    #choix nom
    liste=Listbox(fenetre,height=2)
    liste.insert(1, "Balle")
    liste.insert(2, "Cube")
    liste.pack()

    label=Label(fenetre, text="Saisissez un obstacle : ")
    label.pack()
    nom_choisi=Entry(fenetre)
    nom_choisi.pack()

    #choix verbe
    liste=Listbox(fenetre,height=3)
    liste.insert(1, "Avance vers")
    liste.insert(2, "Avance")
    liste.insert(3, "Tourne")
    liste.pack()

    label=Label(fenetre, text="Saisissez une action : ")
    label.pack()
    action_choisie=Entry(fenetre)
    action_choisie.pack()

    fenetre.mainloop()

#fonction couleur
def allemand_couleur():
    fenetre = Tk()

    fenetre.title("Farben")
    fenetre.geometry("200x300")

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

    fenetre.mainloop()    

#fonction lexique
def allemand_lexique():
    fenetre = Tk()

    fenetre.title("Lexikon")
    fenetre.geometry("200x300")
    
    #choix nom
    liste=Listbox(fenetre,height=2)
    liste.insert(1, "Ball")
    liste.insert(2, "Würfel")
    liste.pack()

    label=Label(fenetre, text="Ein hindernis ergreifen : ")
    label.pack()
    nom_choisi=Entry(fenetre)
    nom_choisi.pack()

    #choix verbe
    liste=Listbox(fenetre,height=3)
    liste.insert(1, "Vorwärts nach")
    liste.insert(2, "Vorschuss")
    liste.insert(3, "Drehe")
    liste.pack()

    label=Label(fenetre, text="Geben Sie eine Aktion ein : ")
    label.pack()
    action_choisie=Entry(fenetre)
    action_choisie.pack()

    fenetre.mainloop()

#fonction couleur
def espagnol_couleur():
    fenetre = Tk()

    fenetre.title("Colores")
    fenetre.geometry("200x300")

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

    fenetre.mainloop()    

#fonction lexique
def espagnol_lexique():
    fenetre = Tk()

    fenetre.title("Léxico")
    fenetre.geometry("200x300")
    
    #choix nom
    liste=Listbox(fenetre,height=2)
    liste.insert(1, "Bola")
    liste.insert(2, "Cubo")
    liste.pack()

    label=Label(fenetre, text="Introduzca un obstáculo : ")
    label.pack()
    nom_choisi=Entry(fenetre)
    nom_choisi.pack()

    #choix verbe
    liste=Listbox(fenetre,height=3)
    liste.insert(1, "Avanzar a")
    liste.insert(2, "Avanzar")
    liste.insert(3, "Gire")
    liste.pack()

    label=Label(fenetre, text="Introducir una acción : ")
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
        bouton=Button(fenetre, text="COLORS", command=anglais_couleur,width=10,height=2)
        bouton["font"]=f
        bouton.pack()

        #bouton lexique
        f=font.Font(size=18)
        bouton=Button(fenetre, text="LEXICON", command=anglais_lexique,width=10,height=2)
        bouton["font"]=f
        bouton.pack()
        
        fenetre.mainloop()
    
    #français
    elif recup_langue == "Français":
        fenetre = Tk()

        fenetre.title("Français")
        fenetre.geometry("200x300")
        
        #bouton couleur
        f=font.Font(size=18)
        bouton=Button(fenetre, text="COULEURS", command=francais_couleur,width=10,height=2)
        bouton["font"]=f
        bouton.pack()

        #bouton lexique
        f=font.Font(size=18)
        bouton=Button(fenetre, text="LEXIQUE", command=francais_lexique,width=10,height=2)
        bouton["font"]=f
        bouton.pack()
        
        fenetre.mainloop()

    #allemand
    elif recup_langue == "Allemand":
        fenetre = Tk()

        fenetre.title("Allemand")
        fenetre.geometry("200x300")

        #bouton couleur
        f=font.Font(size=18)
        bouton=Button(fenetre, text="FARBEN", command=allemand_couleur,width=10,height=2)
        bouton["font"]=f
        bouton.pack()

        #bouton lexique
        f=font.Font(size=18)
        bouton=Button(fenetre, text="LEXIKON", command=allemand_lexique,width=10,height=2)
        bouton["font"]=f
        bouton.pack()
        
        fenetre.mainloop()


    #Espagnol
    elif recup_langue == "Espagnol":
        fenetre = Tk()

        fenetre.title("Espagnol")
        fenetre.geometry("200x300")

        #bouton couleur
        f=font.Font(size=18)
        bouton=Button(fenetre, text="COLORES", command=espagnol_couleur,width=10,height=2)
        bouton["font"]=f
        bouton.pack()

        #bouton lexique
        f=font.Font(size=18)
        bouton=Button(fenetre, text="LEXICO", command=espagnol_lexique,width=10,height=2)
        bouton["font"]=f
        bouton.pack()
        
        fenetre.mainloop()

    #ERROR
    else:
        messagebox.showerror("ERROR", "Invalid language")
        
    


bouton1=Button(fenetre, text="Valider", command=recup_langue)
bouton1.pack()



fenetre.mainloop()

import tkinter
fenetre = tkinter.Tk()
fenetre.geometry("400x250")

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

#Creer bouton
quitter = tkinter.Button(fenetre, text="Cliquez ici pour quitter", command=fenetre.destroy)

#Afficher bouton
quitter.pack()

#Afficher la fenetre
fenetre.mainloop()

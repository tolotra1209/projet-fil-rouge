#Création d'un fichier et écriture
#print('1. creation du fichier')
#nom='fichier1.txt'      #on crée une variable de type string
#fichier=open(nom,'w')   #ouverture du fichier en écriture : 'w' pour write
#for i in range(1,4):    #si le fichier n'existe pas, il est créé, sinon son contenu est écrasé
#    fichier.write('ceci est la ligne {}\n'.format(i))
#fichier.close()

#Modifier un txt compris dans le même répertoire que le programme
file = open("fichier.txt","r") #à vérifier si ça créer un fichier sans passer par le code au dessus
lignes = file.readlines()
file.close()
lignes[0]="phrase\n"
file=open("fichier.txt","w")
file.writelines(lignes)
file.close()

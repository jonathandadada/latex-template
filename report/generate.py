#!/usr/bin/python3
#encoding:utf-8
'''
@author: jonathan aubriet
'''
if __name__ == "__main__":

    backup = open("template.tex.bak", "w")

    with open("template.tex", "r+") as template:
        #macro pour remplir rapidement la template
        NOMAUTEURDOC = "Nom"
        PRENOMAUTEURDOC = "Prénom"
        ADRESSEEMAILDOC = "adresse.email@etudiant.univ-reims.fr"
        NOMMATIERE = "Nom matière" #exemple : Info0101
        NUMEROTP = "Numéro du tp ou cm" #exemple : Tp1, Cm1  
        INTITULEMATIERE = "Intulé de la matière" #exemple : Programmation Orientée Objet (POO)
        
        contenu = template.read()
        backup.write(contenu)

        contenu = contenu.replace("PRENOMAUTEURDOC", PRENOMAUTEURDOC)
        contenu = contenu.replace("NOMAUTEURDOC", NOMAUTEURDOC)
        contenu = contenu.replace("ADRESSEEMAILDOC", ADRESSEEMAILDOC)
        contenu = contenu.replace("NOMMATIERE", NOMMATIERE)
        contenu = contenu.replace("NUMEROTP", NUMEROTP)
        contenu = contenu.replace("INTITULEMATIERE", INTITULEMATIERE)

        template.seek(0) #retour au debut du fichier
        template.write(contenu) #ecriture de la template modifie

        print("template prête à être utilisée")

    backup.close()

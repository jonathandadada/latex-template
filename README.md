# Template Latex - Report

## completion des macros
Avant de lancer le script python, vous devez modifier les macros suivantes dans le code (exemple) :  
NOMAUTEURDOC = "nom"  
PRENOMAUTEURDOC = "prénom"  
ADRESSEEMAILDOC = "adresse email"  
NOMMATIERE = "nom de la matière" %exemple : Info0101  
NUMEROTP = "numero du tp" %exemple tp1 ou cm1 au besoin si la template sert à enregistrer un cours  
INTITULEMATIERE = "intitule de la matière" %exemple : Programmation Orientée Objet (POO)  

## completion de la template
Pour compléter cette template avec vos informations, vous devez entrez dans la console :  
./generate.py  
python3 generate.py  

## en cas d'erreur
ensuite, le fichier template.tex est modifie avec vos macros.  
en cas d'erreur sur les macros, veuillez copier puis renommer la copie de template.tex.bak en template.tex (c'est une backup)  


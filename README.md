# Rapport : Implementation métier 

    Dans le cadre du cours de développement IV (Dev 4), il nous a été demandé de réaliser le jeu
“Baba is you”, qui est un jeu de type puzzle. Dans ce jeu, à chaque niveau, le joueur, qui a le contrôle
d’un élément sur le plateau, doit atteindre un objectif. La plupart du temps, cet élément est le
personnage « Baba », et il doit le déplacer sur un drapeau.
La particularité de ce jeu est que les règles du jeu sont littéralement des éléments placés sur
le plateau de jeu. Par exemple, sur le plateau illustré à la figure 1, le joueur contrôle Baba parce que
trois blocs « Baba », « is » et « you » sont placés côte à côte, et implémentent donc la règle « le
joueur contrôle Baba ». L’objectif à atteindre est le drapeau parce que trois blocs « Flag », « is » et «
win » sont placés côte à côte, etc.[^1]

L'implémentation de ce projet est divisée en 3 parties : une modélisation logicielle, une implémentation métier avec une interface console et enfin une interface graphique. À ce stade du projet et dans ce rapport, nous allons nous concentrer sur la partie "implémentation métier avec interface console" en nous basant sur la "modélisation métier" mise à jour. Ce rapport de modélisation a pour but de décrire le fonctionnement global de nos classes implémentées.

Voici donc le working directory : i-mohamedchairikahloun-s-kulakula\baba_is_you

# Implémentation de l'interface console

Nous allons expliquer ci-dessous la fonction des classes principales du projet, ainsi que les modifications apportées sur certaines d'entre elles par rapport à la première version modélisée lors de notre premier diagramme de classes.

## Element :
La classe Element représente les éléments qui composent la table du jeu. Elle possède actuellement 3 constructeurs : l'un prend en paramètre un état et un type, l'autre prend en paramètre un type et le dernier c'est par défaut. Elle possède également des méthodes qui ne font que ce qui est à la résponsabilité de la classe Element (converti le type en int, voir le type text il fait référence à quoi ex: TBABA fait référence à BABA ...)

## Position :
La classe Position représente la position de Box. Le "Box" est une case dans le plateau de jeu qui contient les éléments.

## Box :
La classe Box représente une case dans le plateau de jeu qui contient les éléments du jeu. Par défaut, elle contient l'élément de type "EARTH" représenté par "Element{}".
Grace au Box, on peut accéder à un élément mais on donne pas l'élément à une classe car ça fait partie de l'encapsulation .

## Level : 
L'un des fonction principale de la classe Level est de lire le fichier text qui reprend les différents niveau du jeu. De plus, elle permet de mettre les élément dans le Board grace à la methode "put_the_world(Board &board) et aussi sauvegarder une partie en cours".

## Rules
La classes Rules a pour fonction principales "l'application des règles" du jeu.

## Game
La classe Game est la classe qui représente la façade, et pocède les méthodes de model qui permet de jouer.

## CommandManager
La classe CommandManager gère les commandes qui permettent d'executer et de unexécuter les commandes pour éviter que le façade fait plus que son boulot.

## MoveCommand
La classe MoveCommand est la classe qui a pour but de deplacer et disparaitre les éléments. Tous les cas de mouvement sont géré dans cette classe. Elle permet aussi la mise à jour des règles du jeu.

## Board
La classe Board est l'une des classes principales. Elle est responsable de entre autre de toutes les positions(position d'éléments, position d'élément type, position d'un état, ...). Ainsi grace à cette classe on peut par exemple:
- changer tous les Element d'un type
- changer un ElementType par un autre
- ...

# Conclusion 
En conclusion, le jeu "Baba is You" est un jeu de type puzzle où le joueur doit atteindre un objectif en contrôlant un élément sur le plateau. La particularité de ce jeu est que les règles du jeu sont littéralement des éléments placés sur le plateau de jeu. Le projet de développement de ce jeu a été divisé en 3 parties : une modélisation logicielle, une implémentation métier avec une interface console et enfin une interface graphique. Dans ce rapport, nous avons décrit le fonctionnement global des classes implémentées, telles que la classe Element, la classe Box, la classe Level, la classe Rules, la classe Game, la classe CommandManager, la classe MoveCommand, et la classe Board. Ce projet nous a permis de mieux comprendre les principes de la programmation orientée objet et la modélisation de jeux vidéo.

[^1] :Cfr. Enoné sur poesi
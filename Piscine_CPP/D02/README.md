# Day 02

Score: 0
Status: in_progress

# The concept

- Polymorphisme ad-hoc
- Surcharge d’opérateurs
- Forme canonique

---

# Notes taking

[Notes Taking ](https://www.notion.so/dec818683d8949e291931225e5a20786)

# Subject

[https://cdn.intra.42.fr/pdf/pdf/41373/en.subject.pdf](https://cdn.intra.42.fr/pdf/pdf/41373/en.subject.pdf)

PDF in English

[PDF en français](Day%2002%204436c/CPP_00.fr.pdf)

PDF en français

AJOUTER LE PDF D’EVALUATION 

## Exercice 00 : My first class in orthodox canonical form

### Objectives:

- Découvrir la représentations des nombres à virgules fixes.
- Ajouter la représentation des nombres à virgules fixes dans le C++

### Notes

Suite à l’article “Understanding et using float point numbers”, nous avons compris les différence entre les floats et les integers. Cependant il existe une alternative qui fixe un équilibre entre performance, exactitude, portée et précision. 

Enfaite la class des entiers constant statique comprend deux int. Le premier qui prend le chiffre sans virgule, et le second qui dit après quel bytes se placera la virgule.

```bash
//exemple en base 10

pour écrire 25.6

int nb = 256
int comma = 1;
```

### Encountered problems

<aside>
💡 J’avais pas compris que l’attribut _comma devait être static const

</aside>

## Exercice 01 : Toward a more useful fixed-point number class

### Objectives

- Améliorer la class Fixed mi en avant dans l’exercice 00.
- Comprendre la conversion de float to fixed et inversement.

### Notes

Résumé sur le point fixed:

Un point fixed c’est un integer, dans cet exemple si ca sera en 24/8, dont les 24 premiers bytes s’occupe des nombres devant la virgule et les 8  bytes suivant s’occupe des chiffres derrières la virgule. 

```bash
//fixed point 4 / 4
1 0 1 0 | 0 0 1 0 == 10,125

1010 = 2^3 + 2^1 = 8 + 2 = 10
0010 = 2^-3 = 1/2^3 = 0.125 

Si on regroupe les deux :
10 + 0.125 = 10.125 
```

<aside>
☝ les bytes s’occupant des nombres derrières la virgule sont en exposant négatif car c’est diviser. Et un exposant diviser équivaut à : x^-4 = 1/x^4

</aside>

Lorsqu’on reçoit un float, et qu’on veut le transformer en int, il faut donc faire attention. Si on caste juste le float on perdra a jamais les décimales. 

```bash
fixed point 24 / 8

(int)188.5 = 188

188.5 * 256 = 48256
```

<aside>
☝ On voit ici que si on déplace les bytes de 8 (valeur de 256) on gardera une trace des décimales qu’on pourra retrouver plus tard.

</aside>

Il nous reste donc pus qu’à arrondir la valeur (au cas ou il y aurait du reste). 

### Rappel

| int | 4 bytes | 32 bits |
| --- | --- | --- |
| char  | 1 bytes | 8 bits |
| float | 4 bytes | 32 bits |

Comme on peut le voir ci dessus, un integer est composé de 4 bytes qui est lui même composé de 32 bits. Un bits représente soit un “1” soit un “0”, vu que l’on fonctionne dans un système binaire. 

- Entier
    
    Pour ce qui est du nombre a virgule fixe, c’est simple on va diviser un integer (32 bits) pour donner une fonction a certains bits et une autre aux autres bits. Dans cet exercice ci, les 24 premiers bits représenteront les entiers et les 8 bits suivant représenteront les valeurs fractionnées. 
    
    Donc si on prend par exemple le chiffre 10 il sera représenté sous se forma la dans l’ordinateur. (sachant que 10 en binary équivaut 1010 ).
    
    ![Screen Shot 2022-03-02 at 11.01.04 AM.png](Day%2002%204436c/Screen_Shot_2022-03-02_at_11.01.04_AM.png)
    
    Sauf qu’il faut se rappeler qu’enfaite cet entier 10 est est lui même sauvegardé dans un int. ce qui fait qu’on a dut l’avancer de 8 bytes, qui sont les valeurs fractionné pour le mettre dans les nombres entiers. cela devient donc 1010 0000 0000 ce qui équivaut à 2560 car on a enfaite fait :
    
    ```bash
    2^9 + 2^11 = 2560
    ```
    
    Alors d’où sort on ce 9 et ce 11. car en avançant l’entier de 8bites pour qu’il se retrouve du côté entier, on a augmenter sa valeur. Sur les 32 bits de l’integer total on en a rajouter 8 vides avant ce qui fait que le premier 1 ne se retrouve pas a l’index 1 mais bien à l’index 9 et donc par conséquence le 1 qui se retrouvait avant à l’index 3se retrouve à l’index 11.
    
- Partie fractionné
    
    Si on reprend la logique des entiers on se demande comment on va faire pour les parties fractionnées. 
    
- 

### Encountered problems

- problem 1
- problem 2

<aside>
💡 tips pour les autres evaluations

</aside>

## Exercice 02 :

### Objectives

- objectifs 1
- objectifs 2

### Encountered problems

- problem 1
- problem 2

<aside>
💡 tips pour les autres evaluations

</aside>
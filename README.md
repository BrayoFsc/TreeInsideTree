# TreeInsideTree

_Para começarmos temos a Arvore Binária B, que é uma simples arvore binária dada pelo usuario com o comando i (arvore), utilizando de parenteses aninhados. Logo em seguida temos a Arvore Binária A, uma Arvore composta de várias arvores Binária B's._
_O programa Basicamente lê várias arvores binárias Bs, dadas pelo usuario, e as armazena na arvore Binaria A, também contendo comando para Remoção dado por **r + (arvore binaria B)**, esse comando soma todos os elementos da arvore binaria B dada e remove qualquer arvore Binaria B, que tenha a mesma soma, de dentro da Arvore Binária A;; Logo depois temos o comando de busca, dado por **b + (arvore binaria B)**, que faz a mesma coisa que o comando **r**, porém ao invés de remover, ele busca a Arvore B dentro da Arvore A e imprime o percurso_




### _Tree *initTree(tNo *no);_

###### inicia a arvore A que contem as arvores binárias B

##

### void printTree(Tree \*arvore);

###### imprime a Arvore A

###

### Tree *insertBranch(Tree *arvore, tNo \*no);

###### coloca um nodo/ arvore binaria B, dentro da Arvore A

###

### tNo \*init(int key);

###### inicia um nodo/ Arvore binaria B

###

### tNo *buildBranch(char *input, int \*i);

###### a partir da entrada constrói uma arvore binaria B

###

### int sumBranch(tNo \*no);

###### soma todos os componentes da arvore binária B

###

### void printBranch(tNo \*no);

###### imprime uma arvore binária B

###

### Tree *searchBranch(Tree *arvore, int no, bool verbose);

###### procura uma Arvore Binaria B especifica dentro da Arvore Binaria A

###

### Tree *min(Tree *arvore);

###### retorna o menor Nodo/Arvore Binaria B, dentro da Arvore Binaria A, a partir do nodo dado como parametro

###

### Tree *sucessor(Tree *no);

###### retorna o nodo/Arvore Binaria B sucessor do nodo dado como parametro

###

### void adjustNode(Tree \*no, Tree \*novo);

###### ajusta um nodo/Arvore Binária B removido, tornando o pai desse nodo/Arvore Binária B pai do outro nodo/Arvore Binária B dado e também tornando o outro

###### nodo/Arvore Binária B dado filho do pai do primeiro nodo

###

### Tree \*removeBranch(Tree \*arvore, Tree \*remove);

###### remove um nodo/Arvore Binária B da arvore arrumando seus nodos para que não hajam conflitos

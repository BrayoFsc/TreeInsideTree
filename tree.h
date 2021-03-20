#pragma once

struct tNo {
   int key;
   tNo *esq, *dir, *pai;
};

struct Tree {
   tNo *ramo;
   Tree *esq, *dir, *pai;
};

// inicia a arvore A que contem as arvores binárias B
Tree *initTree(tNo *no);
// imprime a Arvore A
void printTree(Tree *arvore);
// coloca um nodo/ arvore binaria B, dentro da Arvore A
Tree *insertBranch(Tree *arvore, tNo *no);
//
//
// inicia um nodo/ Arvore binaria B
tNo *init(int key);
// a partir da entrada constrói uma arvore binaria B
tNo *buildBranch(char *input, int *i);
// soma todos os componentes da arvore binária B
int sumBranch(tNo *no);
// imprime uma arvore binária B
void printBranch(tNo *no);
// procura uma Arvore Binaria B especifica dentro da Arvore Binaria A
Tree *searchBranch(Tree *arvore, int no, bool verbose);
//
//
// retorna o menor Nodo/Arvore Binaria B, dentro da Arvore Binaria A, a partir do nodo dado como parametro
Tree *min(Tree *arvore);
// retorna o nodo/Arvore Binaria B sucessor do nodo dado como parametro
Tree *sucessor(Tree *no);
// ajusta um nodo/Arvore Binária B removido, tornando o pai desse nodo/Arvore Binária B pai do outro nodo/Arvore Binária B dado e também tornando o outro
// nodo/Arvore Binária B dado filho do pai do primeiro nodo
void adjustNode(Tree *no, Tree *novo);
// remove um nodo/Arvore Binária B da arvore arrumando seus nodos para que não hajam conflitos
Tree *removeBranch(Tree *arvore, Tree *remove);

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct tNo {
   int key;
   tNo *esq, *dir, *pai;
};

struct Tree {
   tNo *ramo;
   Tree *esq, *dir, *pai;
};

tNo *init(int key)
{
   tNo *no = (tNo *)malloc(sizeof(tNo));
   no->key = key;
   no->esq = NULL;
   no->dir = NULL;
   no->pai = NULL;
   return no;
}

Tree *initTree(tNo *no)
{
   Tree *arvore = (Tree *)malloc(sizeof(Tree));
   arvore->dir = NULL;
   arvore->esq = NULL;
   arvore->pai = NULL;
   arvore->ramo = no;
   return arvore;
}

tNo *buildBranch(char *input, int *i)
{
   tNo *no = NULL;
   if (input[*i] == '(')
   {
      (*i)++;
      char *str;
      str = (char *)malloc(30 * sizeof(char));
      int num = 0;
      for (; (input[*i] != ')') && (input[*i] != '('); (*i)++)
      {
         str[num] = input[*i];
         num++;
      }
      int number;
      number = atoi(str);
      no = init(number);
      no->esq = buildBranch(input, i);
      no->dir = buildBranch(input, i);
      (*i)++;
      free(str);
      str = NULL;
   }
   return no;
}

int sumBranch(tNo *no)
{
   if (no == NULL)
      return 0;
   if ((no->esq == NULL) && (no->dir == NULL))
      return no->key;
   else if ((no->esq != NULL) && (no->dir != NULL))
      return sumBranch(no->esq) + sumBranch(no->dir) + no->key;
   else if ((no->esq != NULL) && (no->dir == NULL))
      return sumBranch(no->esq) + no->key;
   else
      return sumBranch(no->dir) + no->key;
}

Tree *insertBranch(Tree *arvore, tNo *no)
{
   if (arvore == NULL)
      return initTree(no);
   int soma = sumBranch(no);
   if (soma < sumBranch(arvore->ramo))
   {
      arvore->esq = insertBranch(arvore->esq, no);
      arvore->esq->pai = arvore;
   } else
   {
      arvore->dir = insertBranch(arvore->dir, no);
      arvore->dir->pai = arvore;
   }
   return arvore;
}

int main()
{
   Tree *arvore = NULL;
   tNo *no = NULL;
   char *input;
   input = (char *)malloc(200 * sizeof(char));
   while (fgets(input, 200, stdin))
   {
      int i = 2;
      switch (input[0])
      {
      case 'i':
         no = buildBranch(input, &i);
         arvore = insertBranch(arvore, no);
         break;
      case 'b':
         cout << "\naaaaaaaaaa";
         break;
      default:
         cout << "\noloko";
         break;
      }
   }
}
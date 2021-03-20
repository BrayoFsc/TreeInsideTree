#include "tree.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;

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

void printBranch(tNo *no)
{

   if (no == NULL)
      cout << "()";
   else if (no->esq == NULL && no->dir == NULL)
      cout << "(" << no->key << ") ";
   else
   {
      cout << "(" << no->key;
      printBranch(no->esq);
      printBranch(no->dir);
      cout << ")";
   }
}

void printTree(Tree *arvore)
{
   if (arvore == NULL)
      cout << " []";
   else if (arvore->esq == NULL && arvore->dir == NULL)
   {
      cout << " [";
      printBranch(arvore->ramo);
      cout << "]" << endl;
   } else
   {
      cout << " [";
      printBranch(arvore->ramo);
      printTree(arvore->esq);
      printTree(arvore->dir);
      cout << "]" << endl;
   }
}

Tree *searchBranch(Tree *arvore, int no, bool verbose)
{

   if (arvore == NULL)
      return 0;

   if (verbose)
   {
      printBranch(arvore->ramo);
      cout << ": " << sumBranch(arvore->ramo) << "\n";
   }
   int branch = sumBranch(arvore->ramo);
   if (no == branch)
      return arvore;
   if (no < branch)
      return searchBranch(arvore->esq, no, verbose);
   else
      return searchBranch(arvore->dir, no, verbose);
}

void adjustNode(Tree *no, Tree *novo)
{
   if (no->pai != NULL)
   {
      if (no->pai->esq == no)
         no->pai->esq = novo;
      else
         no->pai->dir = novo;
   }
   if (novo != NULL)
      novo->pai = no->pai;
}

Tree *min(Tree *arvore)
{
   if (arvore->esq == NULL)
      return arvore;
   return min(arvore->esq);
}

Tree *sucessor(Tree *no)
{
   Tree *next = NULL;
   if (no->dir != NULL)
      return min(no->dir);
   else
   {
      next = no->pai;
      while (next != NULL && no == next->dir)
      {
         no = next;
         next = next->pai;
      }
   }
   return next;
}

Tree *removeBranch(Tree *arvore, Tree *remove)
{
   Tree *next, *novaraiz = arvore;
   if (remove->esq == NULL)
   {
      adjustNode(remove, remove->dir);
      free(remove);
      remove = NULL;

   } else if (remove->dir == NULL)
   {
      adjustNode(remove, remove->esq);
      free(remove);
      remove = NULL;

   } else
   {
      next = sucessor(remove);
      adjustNode(remove, next);
      next->esq = remove->esq;
      remove->esq->pai = next;
      if (remove == arvore)
         novaraiz = next;
      free(remove);
      remove = NULL;
   }
   return novaraiz;
}
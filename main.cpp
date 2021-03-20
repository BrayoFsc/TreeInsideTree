#include "tree.cpp"

int main()
{
   Tree *arvore = NULL;
   tNo *no = NULL;
   char *input;
   input = (char *)malloc(500 * sizeof(char));
   while (fgets(input, 500, stdin))
   {
      input[strcspn(input, "\n")] = 0;
      if (input == NULL)
      {
         free(input);
         exit(2);
      }
      int i = 2;
      switch (input[0])
      {
      case 'i':
         no = buildBranch(input, &i);
         if (searchBranch(arvore, sumBranch(no), false) == NULL)
            arvore = insertBranch(arvore, no);
         printTree(arvore);
         break;
      case 'b':
         no = buildBranch(input, &i);
         searchBranch(arvore, sumBranch(no), true);
         break;
      case 'r': {
         Tree *remove = NULL;
         no = buildBranch(input, &i);
         remove = searchBranch(arvore, sumBranch(no), false);
         if (remove != NULL)
            arvore = removeBranch(arvore, remove);
         remove = NULL;
         printTree(arvore);
         break;
      }
      default:
         cout << "\noloko";
         break;
      }
   }
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <string.h>


#include "users\menu_user.c"

void clearScream(){
  printf("\33c");
}

// Main Menu
int showMainMenu()
{ 
  int optionSelected = 0;
  printf("-----------------------          Main Menu          -----------------------\n\n");
  printf("[1] User menus\n");
  printf("[0] Exit\n");
  scanf("%d", &optionSelected);
  return optionSelected;
}

int main()
{
  printf("####################### Welcome to the HelloTeams! #######################\n");
  int optionSelected;
  do
  {
    optionSelected = showMainMenu();
    switch (optionSelected)
    {
    case 1:
      userMain();
      clearScream();
      break;
    case 0:
      clearScream();
      break;
    default:
      printf("Chose %d is not available\n", optionSelected);
      system("pause");
      clearScream();
      break;
    }
  } while (optionSelected != 0);

  return 0;
}
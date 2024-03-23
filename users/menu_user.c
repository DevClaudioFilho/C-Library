
// User Interface
int showUserMenu()
{
  int optionUserSelected = 0;
  printf("-----------------------          User Menu          -----------------------\n\n");
  printf("[1] Create a new user\n");
  printf("[2] Update a user\n");
  printf("[3] Load all user\n");
  printf("[4] Search a user\n");
  printf("[5] Delete a user\n");
  printf("[6] Create List User\n");
  printf("[0] Exit\n");
  scanf("%d", &optionUserSelected);
  return optionUserSelected;
}

int userMain()
{
  int optionSelectedUser;
  do
  {
    optionSelectedUser = showUserMenu();
    switch (optionSelectedUser)
    {
    case 1:
      printf("TESTE INCRIVEL DE MENU \n\n");
      system("pause");
      clearScream();
      break;
    case 2:
      printf("[2] Update a user\n");
      system("pause");
      clearScream();
      break;
    case 3:
      printf("[3] Load all user\n");
      system("pause");
      clearScream();
      break;
    case 4:
      printf("[4] Search a user\n");
      system("pause");
      clearScream();
      break;
    case 5:
      printf("[5] Delete a user\n");
      system("pause");
      clearScream();
      break;
    case 6:
      printf("[5] Delete a user\n");
      system("pause");
      clearScream();
      break;
    default:
      printf("Chose %d is not available\n", optionSelectedUser);
      system("pause");
      clearScream();
      break;
    }
  } while (optionSelectedUser != 0);
  return 0;
}

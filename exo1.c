#include <stdio.h>

int main() {

    int playerHealth = 100;
    int playerAttack = 20;
    int playerDefense = 10;
    int treasureCount = 0;
    char playerName[20];
    int i;

    printf("Bienvenue dans Fable !\n");
    printf("Entrez votre nom : ");
    scanf("%s", playerName);
    

    while (playerHealth > 0) {
        printf("\n %s, Que voulez-vous faire ? \n", playerName);
        printf("\n 1. Explorer \n");
        printf("\n 2. Attaquer \n");
        printf("\n 3. Quitter \n");
        
        int choice;
        printf("Choix : ");
        scanf("%d", &choice);
        

        if (choice == 1) {
            printf("\n Vous explorez les environs... \n");
            

            for (i = 0; i < 3; i++) {
                int treasure = rand() % 2;
                
                if (treasure) {
                    printf("\n Vous avez trouvé un trésor ! \n");
                    treasureCount++;
                } else {
                    printf("\n Vous ne trouvez rien... \n");
                }
            }
        }

        else if (choice == 2) {
            printf("\n Vous attaquez un ennemi... \n");
            
            int enemyHealth = 50;
            int enemyAttack = 15;
            int enemyDefense = 15;
            
            while (enemyHealth > 0 && playerHealth > 0) {
                enemyHealth -= playerAttack - enemyDefense;
                playerHealth -= enemyAttack - playerDefense;
            }
            
            if (playerHealth > 0) {
                printf("\n Vous avez vaincu l'ennemi ! \n");
            } else {
                printf("\n Vous avez été vaincu par l'ennemi... \n");
                break;
            }
        }
        
        else if (choice == 3) {
            printf("\n Merci d'avoir joué ! Au revoir %s ! \n", playerName);
            break;
        }
    }
    
    printf("\n Votre aventure est terminée. Vous avez trouvé %d trésor. \n", treasureCount);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100;
    int playerAttack = 20;
    int playerDefense = 10;
    int treasureCount = 0;
    char playerName[20];
    int i;

    int enemyHealth = 50;
    int enemyAttack = 15;
    int enemyDefense = 15;

    char treasures[3][20] = {
        "Sceptre d'Avo",
        "Potion de volonté",
        "Armure du Héros"
    };

    srand(time(NULL));

    printf("Bienvenue dans Fable: The Lost Chapters !\n");
    printf("Entrez votre nom de héros : ");
    scanf("%s", playerName);

    while (playerHealth > 0) {
        printf("\n%s, Que voulez-vous faire ?\n", playerName);
        printf("1. Explorer les ruines\n");
        printf("2. Combattre les bandits\n");
        printf("3. Quitter le jeu\n");

        int choice;
        printf("Choix : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nVous explorez les ruines anciennes...\n");

            for (i = 0; i < 3; i++) {
                int treasure = rand() % 2;

                if (treasure) {
                    printf("Vous avez trouvé un trésor rare : %s !\n", treasures[i]);
                    treasureCount++;
                } else {
                    printf("Vous ne trouvez rien d'intéressant...\n");
                }
            }
        } else if (choice == 2) {
            printf("\nVous affrontez un groupe de bandits...\n");

            while (enemyHealth > 0 && playerHealth > 0) {
                enemyHealth -= playerAttack - enemyDefense;
                playerHealth -= enemyAttack - playerDefense;
            }

            if (playerHealth > 0) {
                printf("Vous avez vaincu les bandits !\n");
            } else {
                printf("Vous avez été vaincu par les bandits...\n");
                break;
            }
        } else if (choice == 3) {
            printf("\nMerci d'avoir joué à Fable: The Lost Chapters ! Au revoir, %s !\n", playerName);
            break;
        }
    }

    char inventory[5][40] = {
        "Épée de l'Élu",
        "Arc de Skorm",
        "Bouclier de l'Ombre",
        "Casque de l'Ancien",
        "Potion de résurrection"
    };

    printf("\nVotre aventure est terminée. Vous avez trouvé %d trésor(s).\n", treasureCount);
    printf("Voici votre inventaire de héros :\n");

    for (i = 0; i < 5; i++) {
        printf("- %s\n", inventory[i]);
    }

    return 0;
}

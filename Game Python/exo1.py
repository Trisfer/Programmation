import random

player_health = 100
player_attack = 20
player_defense = 10
treasure_count = 0

enemy_health = 50
enemy_attack = 15
enemy_defense = 15

treasures = [
    "Sceptre d'Avo",
    "Potion de volonté",
    "Armure du Héros"
]

print("Bienvenue dans Fable: The Lost Chapters !")
player_name = input("Entrez votre nom de héros : ")

while player_health > 0:
    print("\n" + player_name + ", Que voulez-vous faire ?")
    print("1. Explorer les ruines")
    print("2. Combattre les bandits")
    print("3. Quitter le jeu")

    choice = int(input("Choix : "))

    if choice == 1:
        print("\nVous explorez les ruines anciennes...")

        for _ in range(3):
            treasure = random.randint(0, 1)

            if treasure:
                found_treasure = random.choice(treasures)
                print("Vous avez trouvé un trésor rare : " + found_treasure + " !")
                treasure_count += 1
            else:
                print("Vous ne trouvez rien d'intéressant...")
    elif choice == 2:
        print("\nVous affrontez un groupe de bandits...")

        while enemy_health > 0 and player_health > 0:
            enemy_health -= player_attack - enemy_defense
            player_health -= enemy_attack - player_defense

        if player_health > 0:
            print("Vous avez vaincu les bandits !")
        else:
            print("Vous avez été vaincu par les bandits...")
            break
    elif choice == 3:
        print("\nMerci d'avoir joué à Fable: The Lost Chapters ! Au revoir, " + player_name + " !")
        break

inventory = [
    "Épée de l'Élu",
    "Arc de Skorm",
    "Bouclier de l'Ombre",
    "Casque de l'Ancien",
    "Potion de résurrection"
]

print("\nVotre aventure est terminée. Vous avez trouvé", treasure_count, "trésor(s).")
print("Voici votre inventaire de héros :")

for item in inventory:
    print("-", item)

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int playerHealth = 10;
int playerStrength = 5;
int playerAgility = 5;
std::string playerAction;
int enemyHealth = 5;
int enemyStrength = 3;
int enemyAgility = 8;
int glassesOfWater = 0;
int glassesOfBeer = 0;
int exercise = 0;
int bullets = 0;
int bowlingFrame = 1;
int bowlingScore = 0;
int remainingPins = 10;
int pinKnockdown = rand() % (remainingPins + 1);
int frameScore = 0;
double fistDam = playerStrength * 0.5;
double knifeDam = playerStrength * 0.75;
double gunDam = playerStrength;
double blasterDam = playerStrength * 1.2;
double playerDam = fistDam;
double enemyDam = enemyStrength * 1.2;
int fistAcc = 85;
int knifeAcc = 65;
int gunAcc = 50;
int blasterAcc = 40;
int playerAcc = 85;
int attackHit = rand() % 100;
int enemyHit = rand() % 100;
int alienNumber = 1;
bool playerHigh = false;
bool playerAware = false;
bool playerDressed = false;
bool playerHungry = true;
bool handsClean = true;
bool bodyClean = true;
bool teethClean = false;
bool needToilet = true;
bool TVon = false;
bool playerRested = true;
bool fridgeOpen = false;
bool toastMade = false;
bool toastButtered = false;
bool hasKnife = false;
bool hasGun = false;
bool hasBlaster = false;
bool trashOut = false;
bool shoesRented = false;
bool playerBuzzed = false;
bool playerDrunk = false;
bool alienFound = false;
std::string TVchannel = "Bonanza";
std::string playerLoc = "Bedroom";
std::string lastFrame = "0";
std::string lastFrame2 = "0";
std::string playerWeapon = "Fists";
void Bathroom();
void Bedroom();
void LivingRoom();
void Kitchen();
void OutsideHome();
void FranksHouse();
void BowlingAlley();
void AlienCraft();
void Bowl();
void DreamWorld();
void Combat();


void Bathroom() {
    std::cout << "\n\nWhat would you like to do?\n\n";
    // Present bathroom action selections
    if (needToilet == false) {
        std::cout << "\n";
    }
    else {
        std::cout << "1) Go pee\n";
    }
    if (teethClean == false) {
        std::cout << "2) Brush your teeth\n";
    }
    else {
        std::cout << "\n";
    }
    if (handsClean == false) {
        std::cout << "3) Wash your hands\n";
    }
    else {
        std::cout << "\n";
    }
    if (bodyClean == false) {
        std::cout << "4) Take a bath\n";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "5) Return to the Bedroom\n";
    // Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\nYou use the toilet like a human being." << "\nYour hands are now dirty.";
        handsClean = false;
        needToilet = false;
        Bathroom();
    }
    else if (playerAction == "2") {
        std::cout << "\nYou brush your teeth." << "\nYour teeth are now clean.";
        teethClean = true;
        Bathroom();
    }
    else if (playerAction == "3") {
        std::cout << "\nYou wash your hands for 20 seconds." << "\nYour hands are now clean.";
        handsClean = true;
        Bathroom();
    }
    else if (playerAction == "4") {
        std::cout << "\nYou take a hot bath with epsom salts." << "\nYour body is now clean.";
        bodyClean = true;
        Bathroom();
    }
    else if (playerAction == "5") {
        std::cout << "\nYou return to the Bedroom.";
        playerLoc = "Bedroom";
        Bedroom();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
    }
}


void Bedroom() {
    std::cout << "\n\nWhat would you like to do?\n\n";
    //This section is for printing the possible actions in the Bedroom
    if (playerDressed == false) {
        std::cout << "1) Get dressed\n";
    }
    else {
        std::cout << "1) Undress\n";
    }
    std::cout << "2) Look out the window.\n";
    if (needToilet == true) {
        std::cout << "3) Go pee\n";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "4) Move to another room\n";
    if (playerRested == false) {
        std::cout << "5) Go to sleep\n";
    }
    else {
        std::cout << "\n";
    }
    if (TVon == false) {
        std::cout << "6) Turn on the TV\n";
    }
    else {
        std::cout << "6) Turn off the TV\n";
    }
    if (TVon == true && TVchannel == "Bonanza") {
        std::cout << "7) Watch Bonanza\n";
        std::cout << "8) Switch to the news\n";
    }
    else if (TVon == true && TVchannel == "News") {
        std::cout << "7) Watch the news\n";
        std::cout << "8) Switch to Bonanza\n";
    }
    else {
        std::cout << "\n";
    }

    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    //Ask player for selection
    std::cin >> playerAction;

    if (playerAction == "1" && playerDressed == false) {
        std::cout << "\nYou get fully dressed. Shoes and all.";
        playerDressed = true;
        Bedroom();
    }
    else if (playerAction == "1" && playerDressed == true) {
        std::cout << "\nYou undress.";
        playerDressed = false;
        Bedroom();
    }
    else if (playerAction == "2" && playerAware == false) {
        std::cout << "\nYou look out the window and notice that the world appears to\n be under attack by an alien race. \"Oh good.\" You say to\n yourself, \"this is just what I need on a Monday.\"";
        playerAware = true;
        Bedroom();
    }
    else if (playerAction == "2" && playerAware == true) {
        std::cout << "\nYou look out the window at the terror of the outside\n world. Alien ships with laser beams vaporize people\n and animals alike. The world is doomed.";
        Bedroom();
    }
    else if (playerAction == "3" && playerDressed == false) {
        std::cout << "\nYou urinate on your bedroom floor like an animal." << "\nYour hands are now dirty.";
        handsClean = false;
        needToilet = false;
        Bedroom();
    }
    else if (playerAction == "3" && playerDressed == true) {
        std::cout << "\nYou pee your pants. Just like Miles Davis." << "\nYou are now dirty.";
        bodyClean = false;
        needToilet = false;
        Bedroom();
    }
    else if (playerAction == "4") {
        std::cout << "\nWhere are you going?\n";
        std::cout << "\n1) Bathroom\n2) Living Room\n";
        std::cout << "\nMake a selection: ";
        std::cin >> playerAction;
        if (playerAction == "1") {
            std::cout << "\nYou enter the bathroom.\n";
            playerLoc = "Bathroom";
            Bathroom();
        }
        else if (playerAction == "2") {
            std::cout << "\nYou enter the Living Room.\n";
            playerLoc = "Living Room";
            LivingRoom();
        }
        else {
            std::cout << "\nInvalid Entry. Please enter action number only.\n:";
            Bedroom();
        }
    }
    else if (playerAction == "5" && playerRested == false) {
        std::cout << "\nYou get into bed and fall asleep into a dream state.\n";
        std::cout << "\nIn your dream you see an anthropomorhic hamburger signing Tina Turner songs for nickels.";
        std::cout << "\nAfter giving the burger a few nickels you get bored.";
        playerLoc = "Dream World";
        DreamWorld();
    }
    else if (playerAction == "5" && playerRested == true) {
        std::cout << "\nYou are not tired yet.\n";
        Bedroom();
    }
    else if (playerAction == "6" && TVon == false && TVchannel == "Bonanza") {
        std::cout << "\nYou switch on the television. An episode of Bonanza is playing.\n";
        TVon = true;
        Bedroom();
    }
    else if (playerAction == "6" && TVon == false && TVchannel == "News") {
        std::cout << "\nYou switch on the television. The news is playing.\n";
        TVon = true;
        Bedroom();
    }
    else if (playerAction == "6" && TVon == true) {
        std::cout << "\nYou switch off the television.\n";
        TVon = false;
        Bedroom();
    }
    else if (playerAction == "7" && TVon == false) {
        std::cout << "\nInvalid entry. Please enter action number only.\n";
        Bedroom();
    }
    else if (playerAction == "7" && TVon == true && TVchannel == "Bonanza") {
        std::cout << "\nGriff's friend, widowed farmer Jonathan May, wants to adopt two young orphans,\n one of whom is unable to talk. When Jonathan is told he cannot adopt the boys,\n Griff decides to set the adoption agency folks straight on what a loving father is.\n";
        Bedroom();
    }
    else if (playerAction == "7" && TVon == true && TVchannel == "News") {
        std::cout << "\nThe news shows live footage from all various parts of the world. Aliens are\n attacking every major populated city in the world. Nobody knows how to stop the\n attacks. It appears the human race is doomed.\n";
        playerAware = true;
        Bedroom();
    }
    else if (playerAction == "8" && TVon == false) {
        std::cout << "\nInvalid Entry.  Please enter action number only.\n";
        Bedroom();
    }
    else if (playerAction == "8" && TVon == true && TVchannel == "Bonanza") {
        std::cout << "You switch channels to the BBC World News.\n";
        TVchannel = "News";
        Bedroom();
    }
    else if (playerAction == "8" && TVon == true && TVchannel == "News") {
        std::cout << "You switch channels to Bonanza.\n";
        TVchannel = "Bonanza";
        Bedroom();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "Invalid Entry. Please enter action number only.";
        Bedroom();
    }
}


void LivingRoom() {
    std::cout << "\n\nWhat would you like to do?\n\n";
    // Present Living room action selections
    if (needToilet == true) {
        std::cout << "1) Go pee\n";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "2) Use exercise bike\n" << "3) Sit in recliner\n" << "4) Smoke weed\n" << "5) Move to another room\n";
    // Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1" && playerDressed == false) {
        std::cout << "\nYou urinate in the living room like an animal." << "\nYour hands are now dirty.";
        handsClean = false;
        needToilet = false;
        LivingRoom();
    }
    else if (playerAction == "1" && playerDressed == true) {
        std::cout << "\nYou pee your pants in the living room." << "\nYour body is now dirty.";
        needToilet = false;
        bodyClean = false;
        LivingRoom();
    }
    else if (playerAction == "2") {
        std::cout << "\nYou use the exercise bike." << "\nYour body is now dirty.";
        bodyClean = false;
        for (int t = 0; t < 5; t++) {
            std::cout << "\nRiding";
	    std::this_thread::sleep_for(2000ms);
        }
        while (playerStrength <= 5) {
            std::cout << "\nYour strength has increased";
            playerStrength++;
        }
        if (exercise >= 5) {
            std::cout << "\nYou're tired.";
            playerRested = false;
        }
        else {
            std::cout << "\n";
        }
        exercise++;
        LivingRoom();
    }
    else if (playerAction == "3") {
        std::cout << "\nYou take a seat and recline.";
        LivingRoom();
    }
    else if (playerAction == "4" && playerHigh == false) {
        std::cout << "\nYou pack a bowl of weed and smoke it in your bong." << "\nYou are now high.";
        playerHigh = true;
        playerAgility = playerAgility - 1;
        LivingRoom();
    }
    else if (playerAction == "4" && playerHigh == true) {
        std::cout << "\nYou are already high.";
        LivingRoom();
    }
    else if (playerAction == "5") {
        std::cout << "\nWhere are you going?";
        std::cout << "\n\n1) Bedroom" << "\n2) Kitchen" << "\n3) Go outside";
        std::cout << "\n Make a selection: ";
        std::cin >> playerAction;
        if (playerAction == "1") {
            std::cout << "\nYou move to the Bedroom";
            playerLoc = "Bedroom";
            Bedroom();
        }
        else if (playerAction == "2") {
            std::cout << "\nYou move to the Kitchen";
            playerLoc = "Kitchen";
            Kitchen();
        }
        else if (playerAction == "3" && bodyClean == true && handsClean == true && teethClean == true && needToilet == false && playerDressed == true && playerHungry == false && playerAware == false) {
            std::cout << "\nYou head outside to find that the world is currently being invaded by an alien race.\n This looks very bad for humans.";
            playerAware = true;
            playerLoc = "Outside Home";
            OutsideHome();
        }
        else if (playerAction == "3" && bodyClean == true && handsClean == true && teethClean == true && needToilet == false && playerDressed == true && playerHungry == false && playerAware == true) {
            std::cout << "\nYou leave the house feeling ready to face the alien invasion. Upon exiting\n you notice the alien ship vaporizing things here and there.";
            playerLoc = "Outside Home";
            OutsideHome();
        }
        else if (playerAction == "3" && bodyClean == false) {
            std::cout << "\nYou stink. You should take a bath before going out.";
            LivingRoom();
        }
        else if (playerAction == "3" && handsClean == false) {
            std::cout << "\nYour hands are dirty. You should wash them before going out.";
            LivingRoom();
        }
        else if (playerAction == "3" && teethClean == false) {
            std::cout << "\nYou should brush your teeth before going out.";
            LivingRoom();
        }
        else if (playerAction == "3" && needToilet == true) {
            std::cout << "\nYou still need to pee.";
            LivingRoom();
        }
        else if (playerAction == "3" && playerDressed == false) {
            std::cout << "\nYou are naked. You should get dressed first.";
            LivingRoom();
        }
        else if (playerAction == "3" && playerHungry == true) {
            std::cout << "\nYou haven't eaten breakfast yet.";
            LivingRoom();
        }
        else if (playerAction == "exit") {
            exit(0);
        }
        else {
            std::cout << "\nInvalid entry. Please enter action number only.";
            LivingRoom();
        }
    }
}


void Kitchen() {
    std::cout << "\n\nWhat would you like to do?\n\n";
    //Print Kitchen Actions
    if (fridgeOpen == false) {
        std::cout << "\n1) Open the fridge";
    }
    else {
        std::cout << "\n1) Close the fridge";
    }
    if (hasKnife == false) {
        std::cout << "\n2) Pick up kitchen knife";
    }
    else {
        std::cout << "\n";
    }
    if (handsClean == false) {
        std::cout << "\n3) Wash hands in sink";
    }
    else {
        std::cout << "\n";
    }
    if (trashOut == false) {
        std::cout << "\n4) Take out the trash";
    }
    else {
        std::cout << "\n";
    }
    if (toastMade == false) {
        std::cout << "\n5) Make toast";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "\n6) Return to the Living Room";
    if (fridgeOpen == true && toastMade == true) {
        std::cout << "\n7) Butter the toast";
    }
    else {
        std::cout << "\n";
    }
    if (toastButtered == true) {
        std::cout << "\n8) Eat the toast";
    }
    else {
        std::cout << "\n";
    }
    if (needToilet == true) {
        std::cout << "\n9) Go pee";
    }
    else {
        std::cout << "\n";
    }

    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    //Kitchen action results.
    if (playerAction == "1" && fridgeOpen == false) {
        std::cout << "\nYou open the fridge. You are out of eggs";
        fridgeOpen = true;
        Kitchen();
    }
    else if (playerAction == "1" && fridgeOpen == true) {
        std::cout << "\nYou close the fridge";
        fridgeOpen = false;
        Kitchen();
    }
    else if (playerAction == "2" && hasKnife == false) {
        std::cout << "\nYou pick up the knife and put it in your pocket.";
        hasKnife = true;
        playerWeapon = "Knife";
        playerAcc = 65;
        playerDam = knifeDam;
        Kitchen();
    }
    else if (playerAction == "3" && handsClean == false) {
        std::cout << "\nYou wash your hands in the sink for 20 seconds.";
        handsClean = true;
        Kitchen();
    }
    else if (playerAction == "4" && trashOut == false) {
        std::cout << "\nYou take the trash out to the big can in the garage." << "\nYour hands are now dirty";
        handsClean = false;
        trashOut = true;
        Kitchen();
    }
    else if (playerAction == "5" && toastMade == false) {
        std::cout << "\nYou pop two slices of bread in the toaster and wait for them to toast.";
        for (int t = 0; t < 5; t++) {
            std::cout << "\nToasting";
	    std::this_thread::sleep_for(2000ms);
        }
        std::cout << "\nToast ready";
        toastMade = true;
        Kitchen();
    }
    else if (playerAction == "6") {
        std::cout << "\nYou return to the Living Room";
        playerLoc = "Living Room";
        LivingRoom();
    }
    else if (playerAction == "7" && fridgeOpen == true && toastMade == true) {
        std::cout << "\nYou butter your toast. Now it's ready for eating.";
        toastButtered = true;
        Kitchen();
    }
    else if (playerAction == "8" && toastButtered == true && handsClean == false) {
        std::cout << "\nYou eat the buttered toast with your filthy hands." << "\nYou have lost 1 health." << "\nYou are no longer hungry.";
        playerHealth = playerHealth - 1;
        toastMade = false;
        toastButtered = false;
        playerHungry = false;
        Kitchen();
    }
    else if (playerAction == "8" && toastButtered == true && handsClean == true) {
        std::cout << "\nYou eat the buttered toast." << "\nYou are no longer hungry.";
        toastMade = false;
        toastButtered = false;
        playerHungry = false;
        Kitchen();
    }
    else if (playerAction == "9" && needToilet == true && playerDressed == false) {
        std::cout << "\nYou pee in the kitchen sink like a savage beast." << "\nYour hands are now dirty.";
        handsClean = false;
        needToilet = false;
        Kitchen();
    }
    else if (playerAction == "9" && needToilet == true && playerDressed == true) {
        std::cout << "\nYou pee your pants in the kitchen." << "\nYour body is now dirty.";
        bodyClean = false;
        needToilet = false;
        Kitchen();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        Kitchen();
    }
}


void OutsideHome() {
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1) Go see your neighbor Frank." << "\n2) Go to the bowling alley." << "\n3) Head towards the alien spacecraft." << "\n4) Go into your house.";
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\nYou walk to Frank's house. Frank invites you in.";
        playerLoc = "Frank's House";
        FranksHouse();
    }
    else if (playerAction == "2") {
        std::cout << "\nYou drive to the bowling alley.";
        playerLoc = "Bowling Alley";
        BowlingAlley();
    }
    else if (playerAction == "3") {
        std::cout << "\nYou get in your car and start driving towards the alien spacecraft. You get \na bad feeling in the pit of your stomach and you're pretty sure it's not the toast.";
        playerLoc = "Alien Craft";
        AlienCraft();
    }
    else if (playerAction == "4") {
        std::cout << "You wipe your feet and enter the Living Room.";
        playerLoc = "Living Room";
        LivingRoom();
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        OutsideHome();
    }
}


void FranksHouse() {
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1) Talk to Frank about the aliens." << "\n2) Ask Frank for some water." << "\n3) Talk to Frank about gun control." << "\n4) Talk to Frank about religion." << "\n5) Say goodbye to Frank and go home.";
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1" && playerHigh == false) {
        std::cout << "\"Have you seen the news or looked outside? We are under alien attack.\n We have to do something about it.\" You ask Frank with a concerned tone of voice.";
        std::cout << "\n\nFrank looks at you with a grinand says, \"I told you there were aliens!";
        std::cout << "\nNow its too late to do anything! The earth is doomed!\"";
        FranksHouse();
    }
    else if (playerAction == "1" && playerHigh == true) {
        std::cout << "\nYou stare at Frank for a moment and ask, \"Dude, have you seen the aliens yet?\"";
        std::cout << "\n\nFrank looks at you and replies mockingly, \"Have you seen the aliens yet?\n Yes! Of course I have! Haven't I been telling you there are aliens for years?\n We're too late now. The world is doomed.\"";
        FranksHouse();
    }
    else if (playerAction == "2" && playerHigh == false) {
        std::cout << "\nYou ask Frank for a glass of water. He brings you a glass of water from the kitchen.\n \"Thanks.\" you say as you drink the water down.";
        glassesOfWater = glassesOfWater + 1;
        if (glassesOfWater >= 3) {
            std::cout << "\nYou need to go pee.";
            needToilet = true;
        }
        else {
            std::cout << "\n";
        }
        FranksHouse();
    }
    else if (playerAction == "2" && playerHigh == true) {
        std::cout << "\nYou ask Frank for a glass of water. He brings you a glass of water from the kitchen.\n \"Awesome duder. You're like totally the best.\" you say as you drink the water down.";
        glassesOfWater = glassesOfWater + 1;
        if (glassesOfWater >= 3) {
            std::cout << "\nYou need to go pee.";
            needToilet = true;
        }
        else {
            std::cout << "\n";
        }
        FranksHouse();
    }
    else if (playerAction == "3" && playerHigh == false) {
        std::cout << "\n\"Well this certainly changes a few viewpoints on gun control, doesn't it?\" You ask frank. \"Not mine!\" says Frank, \"I've been preparing for this for years!\"";
        std::cout << "\nFrank opens a large gun safe and shows you his guns. \"Here, have a pistol.\" Frank says as he hands you a .357 Magnum revolver and a box of 25 bullets.";
        std::cout << "\n\"That ought to help you stay safe out there.\"";
        hasGun = true;
        bullets = 25;
        playerWeapon = "Gun";
        playerAcc = 50;
        playerDam = gunDam;
        FranksHouse();
    }
    else if (playerAction == "3" && playerHigh == true) {
        std::cout << "\n\"Brah, this like totally changes my mind on gun control.\" You say to frank. \"Not mine!\" says Frank, \"I've been preparing for this for years!";
        std::cout << "\n I'd offer you one of my guns but you smell like weed and you just called me \"Brah\" so I'm not about to endanger your life by giving you a gun.";
        FranksHouse();
    }
    else if (playerAction == "4" && playerHigh == false) {
        std::cout << "\n\"What do you know about life after death?\" You ask. Frank looks at you, raises an eyebrow and replies,";
        std::cout << "\n\"That all depends, are we talking existentialism, or anthropomorphic deity?\"";
        std::cout << "\nConfused by this question, you decide to it's probably time to go.";
        FranksHouse();
    }
    else if (playerAction == "4" && playerHigh == true) {
        std::cout << "\n\"Have you ever wondered what it would be like to be Jesus in modern times?\" You ask. Frank looks at you, raises an eyebrow and replies,";
        std::cout << "\n\"No.\"";
        FranksHouse();
    }
    else if (playerAction == "5" && playerHigh == false) {
        std::cout << "\n\"Well Frank thank you for the hospitality, I've got to be going now.\" You say as you head for the front door.";
        std::cout << "\n\"Come back any time!\" Frank says, \"Have a nice time killing the aliens.\"";
        playerLoc = "Outside Home";
        OutsideHome();
    }
    else if (playerAction == "5" && playerHigh == true) {
        std::cout << "\n\"I'm Audi 5000. Later dude!\" You say as you head for the front door.";
        std::cout << "\n\"Come back any time!\" Frank says, \"Have a nice time killing the aliens.\"";
        playerLoc = "Outside Home";
        OutsideHome();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        FranksHouse();
    }
}


void BowlingAlley() {
    std::cout << "\nWhat would you like to do?\n";
    if (shoesRented == false) {
        std::cout << "\n1) Rent shoes";
    }
    else {
        std::cout << "\n1) Return shoes";
    }
    std::cout << "\n2) Order a beer" << "\n3) Bowl" << "\n4) Go back home";
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1" && shoesRented == false) {
        std::cout << "\nYou rent the appropriate shoes for bowling.";
        shoesRented = true;
        BowlingAlley();
    }
    else if (playerAction == "1" && shoesRented == true) {
        std::cout << "\nYou return the bowling shoes.";
        shoesRented = false;
        BowlingAlley();
    }
    else if (playerAction == "2" && glassesOfBeer <= 5) {
        std::cout << "\nYou order a beer and slug it down. Mmm refreshing.";
        glassesOfBeer = glassesOfBeer + 1;
        if (glassesOfBeer == 3) {
            std::cout << "\nYou are buzzed.";
            playerBuzzed = true;
        }
        else if (glassesOfBeer == 5) {
            std::cout << "\nYou are drunk.";
            playerDrunk = true;
        }
        else {
            std::cout << "\n";
        }
        BowlingAlley();
    }
    else if (playerAction == "2" && glassesOfBeer >= 6) {
        std::cout << "\nThe bartender cuts you off because you are clearly drunk.";
        BowlingAlley();
    }
    else if (playerAction == "3" && shoesRented == false) {
        std::cout << "\nYou need to rent the shoes first.";
        BowlingAlley();
    }
    else if (playerAction == "3" && shoesRented == true) {
        std::cout << "\nYou pick out a ball and head for the lanes.";
        Bowl();
    }
    else if (playerAction == "4" && playerDrunk == false) {
        std::cout << "\nYou drive back home.";
        playerLoc = "Outside Home";
        OutsideHome();
    }
    else if (playerAction == "4" && playerDrunk == true) {
        std::cout << "\nYou take an Uber home becuase you are drunk.";
        playerLoc = "Outside Home";
        OutsideHome();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        BowlingAlley();
    }
}

void Bowl() {
    std::cout << "\nFrame: " << bowlingFrame << " Score: " << bowlingScore << " Pins remaining: " << remainingPins;
    std::cout << "\n\n1) Bowl frame" << "\n2) Quit Bowling";
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1" && bowlingFrame <= 9) {
        std::cout << "You roll a ball down the lane and knock down " << pinKnockdown << " pins.";
        remainingPins = remainingPins - pinKnockdown;
        lastFrame2 = lastFrame;
        if (remainingPins == 0) {
            bowlingFrame = bowlingFrame + 1;
            if (lastFrame == "X" || lastFrame == "/" && lastFrame2 != "X") {
                frameScore = pinKnockdown * 2;
            }
            else if (lastFrame == "X" || lastFrame == "/" && lastFrame2 == "X") {
                frameScore = pinKnockdown * 3;
            }
            else if (lastFrame != "X" && lastFrame != "/" && lastFrame2 != "X") {
                frameScore = pinKnockdown;
            }
            else if (lastFrame != "X" && lastFrame != "/" && lastFrame2 == "X") {
                frameScore = pinKnockdown * 2;
            }
            lastFrame = "X";
            bowlingScore = bowlingScore + frameScore;
            remainingPins = 10;
            frameScore = 0;
            Bowl();
        }
        else if (remainingPins != 0) {
            std::cout << "\nThere are " << remainingPins << " still standing.";
            std::cout << "\nRoll again?" << "\n\n1) Roll again" << "\n2) Quit bowling";
            std::cout << "\n\n Make a selection:";
            std::cin >> playerAction;

            if (lastFrame == "X" || lastFrame == "/" && lastFrame2 != "X") {
                frameScore = pinKnockdown * 2;
            }
            else if (lastFrame == "X" || lastFrame == "/" && lastFrame2 == "X") {
                frameScore = pinKnockdown * 3;
            }
            else if (lastFrame != "X" && lastFrame != "/" && lastFrame2 != "X") {
                frameScore = pinKnockdown;
            }
            else if (lastFrame != "X" && lastFrame != "/" && lastFrame2 == "X") {
                frameScore = pinKnockdown * 2;
            }
            else {
                std::cout << "\nError";
                BowlingAlley();
            }

            if (playerAction == "1") {
                pinKnockdown = rand() % (remainingPins + 1);
                std::cout << "You roll a ball down the lane and knock down " << pinKnockdown << " pins.";
                remainingPins = remainingPins - pinKnockdown;
                if (remainingPins == 0) {
                    bowlingFrame = bowlingFrame + 1;
                    if (lastFrame == "X") {
                        frameScore = frameScore + pinKnockdown * 2;
                    }
                    else if (lastFrame == "/") {
                        frameScore = frameScore + pinKnockdown;
                    }
                    else if (lastFrame != "X" && lastFrame != "/") {
                        frameScore = frameScore + pinKnockdown;
                    }
                    else {
                        std::cout << "\nError";
                        BowlingAlley();
                    }
                    lastFrame = "/";
                    bowlingScore = bowlingScore + frameScore;
                    remainingPins = 10;
                    frameScore = 0;
                    Bowl();
                }
                else if (remainingPins != 0) {
                    bowlingFrame = bowlingFrame + 1;
                    if (lastFrame == "X") {
                        frameScore = frameScore + pinKnockdown * 2;
                    }
                    else if (lastFrame == "/") {
                        frameScore = frameScore + pinKnockdown;
                    }
                    else if (lastFrame != "X" && lastFrame != "/") {
                        frameScore = frameScore + pinKnockdown;
                    }
                    else {
                        std::cout << "\nError";
                        BowlingAlley();
                    }
                    lastFrame = 10 - remainingPins;
                    bowlingScore = bowlingScore + frameScore;
                    remainingPins = 10;
                    frameScore = 0;
                    Bowl();
                }
            }
            else if (playerAction == "2") {
                std::cout << "\nYou quit bowling.";
                BowlingAlley();
            }
            else if (playerAction == "exit") {
                exit(0);
            }
            else {
                std::cout << "\nInvalid Entry. Please enter action number only.";
                Bowl();
            }
        }
    }
    else if (playerAction == "2") {
        std::cout << "\nYou quit bowling.";
        BowlingAlley();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
    }
}


void AlienCraft() {
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1) Investigate the alien spacecraft." << "\n2) Find an alien." << "\n3) Return home.";
    if (alienFound == false) {
        std::cout << "\n";
    }
    else if (alienFound == true && hasKnife == false && hasGun == false) {
        std::cout << "\n4) Attack aliens with fists";
    }
    else if (alienFound == true && hasKnife == true && hasGun == false) {
        std::cout << "\n4) Attack aliens with knife";
    }
    else if (alienFound == true && hasGun == true) {
        std::cout << "\n4) Attack aliens with gun";
    }
    else {
        std::cout << "\n";
    }
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\nYou move in closer to the alien ship and find that it has a large opening on the bottom to facilitate docking with smaller craft." << "\nYou can also see what appears to be alien lifeforms being transported to the ground.";
        AlienCraft();
    }
    else if (playerAction == "2") {
        std::cout << "\nAfter some searching you find the alien landing site. You can currently see 6 aliens. They are tall, fuzzy, and sound like an upset turkey when they talk.";
        alienFound = true;
        AlienCraft();
    }
    else if (playerAction == "3") {
        std::cout << "\nYou return to your house.";
        playerLoc = "Outside Home";
        OutsideHome();
    }
    else if (playerAction == "4") {
        Combat();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
    }
}


void Combat() {
    attackHit = rand() % 100;
    enemyHit = rand() % 100;
    if (playerHealth <= 0) {
        std::cout << "\nYou have died.\n\n GAME OVER.";
        exit(0);
    }
    else {
        std::cout << "\n";
    }
    std::cout << "\n\n========== Combat Mode ==========";
    std::cout << "\nWeapon: " << playerWeapon << " Hit chance: ";
    if (playerWeapon == "Fists") {
        std::cout << fistAcc;
    }
    else if (playerWeapon == "Knife") {
        std::cout << knifeAcc;
    }
    else if (playerWeapon == "Gun") {
        std::cout << gunAcc;
    }
    else if (playerWeapon == "Blaster") {
        std::cout << blasterAcc;
    }
    else {
        std::cout << "Error";
    }
    std::cout << " Damage: ";
    if (playerWeapon == "Fists") {
        std::cout << fistDam;
    }
    else if (playerWeapon == "Knife") {
        std::cout << knifeDam;
    }
    else if (playerWeapon == "Gun") {
        std::cout << gunDam;
    }
    else if (playerWeapon == "Blaster") {
        std::cout << blasterDam;
    }
    else {
        std::cout << "Error";
    }
    std::cout << " Enemy HP: " << enemyHealth;
    std::cout << "\n\n1) Attack enemy" << "\n2) Change weapon" << "\n3) Quit combat.\n";
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1") {
        if (playerWeapon == "Fists") {
            playerDam = fistDam;
        }
        else if (playerWeapon == "Knife") {
            playerDam = knifeDam;
        }
        else if (playerWeapon == "Gun") {
            playerDam = gunDam;
        }
        else {

        }
        std::cout << "\nYou attack the alien with your " << playerWeapon << ". The attack ";
        if (playerWeapon == "Gun") {
            bullets = bullets - 1;
        }
        else {

        }
        if (attackHit > playerAcc) {
            std::cout << "Misses";
            playerDam = 0;
        }
        else if (attackHit <= playerAcc) {
            std::cout << "Hits";
        }
        else {
            std::cout << "Error";
        }
        std::cout << " and deals " << playerDam << " damage.\n\n";
        enemyHealth = enemyHealth - playerDam;
        enemyDam = enemyStrength * 1.2;
        if (enemyHealth <= 0) {
            std::cout << "You have killed the alien. Prepare for the next challenge.\n";
            alienNumber++;
            enemyHealth = alienNumber * 5;
            enemyStrength = enemyStrength + 1;
            Combat();
        }
        else if (enemyHealth != 0 && enemyHealth > 0) {
            std::cout << "The alien has " << enemyHealth << " health remaining.\n";
            std::cout << "The alien counter attacks. The attack ";
            if (enemyHit > blasterAcc) {
                std::cout << "Misses";
                enemyDam = 0;
            }
            else if (enemyHit <= blasterAcc) {
                std::cout << "Hits";
            }
            std::cout << " and deals " << enemyDam << " damage.\n\n";
            playerHealth = playerHealth - enemyDam;
            Combat();
        }

    }
    else if (playerAction == "2") {
        std::cout << "\n1) Fists";
        if (hasKnife == true) {
            std::cout << "\n2) Knife";
        }
        else {
            std::cout << "\n";
        }
        if (hasGun == true) {
            std::cout << "\n3) Gun";
        }
        else {
            std::cout << "\n";
        }
        std::cout << "\nSelect a weapon:";

        std::cin >> playerAction;

        if (playerAction == "1") {
            playerDam = fistDam;
            playerAcc = fistAcc;
            playerWeapon = "Fists";
            Combat();
        }
        else if (playerAction == "2" && hasKnife == true) {
            playerDam = knifeDam;
            playerAcc = knifeAcc;
            playerWeapon = "Knife";
            Combat();
        }
        else if (playerAction == "3" && hasGun == true) {
            playerDam = gunDam;
            playerAcc = gunAcc;
            playerWeapon = "Gun";
            Combat();
        }
        else {
            std::cout << "\nInvalid Entry. Please enter action number only.";
            Combat();
        }

    }
    else if (playerAction == "3") {
        std::cout << "\nYou quit fighting.";
        AlienCraft();
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        Combat();
    }
}


void DreamWorld() {
    std::cout << "\n\nWhat would you like to do?";
    std::cout << "\n\n1) Try to eat the hamburger." << "\n2) Ask the hamburger a question";
    //Print player stats
    std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
    std::cout << "\n\n Make a selection:";

    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\n\nYou pick up the hamburger. It immediately starts screaming and kicking. It appears the hamburger is not keen on the idea of being eaten.";
        std::cout << "\n\n1) Continue eating" << "\n2) Put the hamburger back";
        //Print player stats
        std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
        std::cout << "\n\n Make a selection:";

        std::cin >> playerAction;

        if (playerAction == "1") {
            std::cout << "\n\nYou eat Gary the Hamburger like a complete fucking savage. Now you dont even have a hamburger to entertain you.";
            std::cout << "\nThe Mona Lisa with legs comes in and asks, \"Where is Gary?\"";
            std::cout << "\n\n1) Tell the truth." << "\n2) Lie.";
            //Print player stats
            std::cout << "\nLocation: " << playerLoc << " || Health: " << playerHealth << " || Agility: " << playerAgility << " || Strength: " << playerStrength;
            std::cout << "\n\n Make a selection:";

            std::cin >> playerAction;

            if (playerAction == "1") {
                std::cout << "\n\nYou tell the Mona Lisa that you ate Gary. The Mona Lisa begins weeping uncontrollably. You comfort the painting and wipe the tears from her face.";
                std::cout << "\nYou turn around and notice a bright red light in the distance. It comes closer and closer until its right over your head. Then is crushes you.";
                std::cout << "\nYou wake up in your bed, naked, like any other day.";
                playerDrunk = false;
                playerBuzzed = false;
                playerRested = true;
                needToilet = true;
                playerHungry = true;
                playerHigh = false;
                playerHealth = 10;
                Bedroom();
            }
            else if (playerAction == "2") {
                std::cout << "\n\nYou tell the Mona Lisa that Gary the Hamburger went to the store to buy some tap shoes and should be back shortly. The Mona Lisa says, \"Tap shoes? Well okay I guess.";
                std::cout << "\nHe is supposed to be giving me a foot massage right now. But since he isnt here I'll just have to stab you.\"\n\nThe Mona Lisa stabs you in the chest with a screwdriver.";
                std::cout << "\nYou wake up in your bed, naked, like any other day.";
                playerDrunk = false;
                playerBuzzed = false;
                playerRested = true;
                needToilet = true;
                playerHungry = true;
                playerHigh = false;
                playerHealth = 10;
                Bedroom();
            }
            else {
                std::cout << "\nInvalid Entry. Please enter action number only.";
                DreamWorld();
            }

        }
        else if (playerAction == "2") {
            std::cout << "\n\nYou put the hamburger back. \"The name's Gary,\" Says the hamburger, \"Thanks for thinking twice about eating me.\"";
            std::cout << "\n\"No problem little dude! Keep on dancing.\" You say with a grin. You turn around and find that Gary is being pursued by the Russian Mafia.";
            std::cout << "\nThe goons beat Gary senseless and tie you to a roasting spit. They throw you over a fire to get a good char going.";
            std::cout << "\nYou wake up in your bed, naked, like any other day.";
            playerDrunk = false;
            playerBuzzed = false;
            playerRested = true;
            needToilet = true;
            playerHungry = true;
            playerHigh = false;
            playerHealth = 10;
            Bedroom();
        }
        else {
            std::cout << "\nInvalid Entry. Please enter action number only.";
            DreamWorld();
        }

    }
    if (playerAction == "2") {
        std::cout << "\n\nYou ask the hamburger, \"How does a handsome burger like you end up in place like this?\" The hamburger looks at you confused and says, \"Becuase you're dreaming, dummy.\" says Gary the hamburger.";
        std::cout << "\nThis of course reminds you that you can do anything. Including shooting a hamburger out of a cannon.You launch Gary the Hamburger high into the sky. You can hear him screaming the whole way.";
            std::cout << "\nYou wake up in your bed, naked, like any other day.";
        playerDrunk = false;
        playerBuzzed = false;
        playerRested = true;
        needToilet = true;
        playerHungry = true;
        playerHigh = false;
        playerHealth = 10;
        Bedroom();
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        DreamWorld();
    }
}


int main() {
    srand(time(NULL));
    std::cout << "\nThe Great Big Adventure\n";
    std::cout << "\nYou wake up in your bed, naked, like any other day.\n";
    Bedroom();
}

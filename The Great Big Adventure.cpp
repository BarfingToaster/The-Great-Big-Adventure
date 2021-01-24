#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

constexpr int PLAYER_MAX_STRENGTH = 5;

constexpr double DAMAGE_NULL = 0;
constexpr double DAMAGE_FIST = PLAYER_MAX_STRENGTH * 0.5;
constexpr double DAMAGE_KNIFE = PLAYER_MAX_STRENGTH * 0.75;
constexpr double DAMAGE_GUN = PLAYER_MAX_STRENGTH;
constexpr double DAMAGE_BLASTER = PLAYER_MAX_STRENGTH * 1.2;

constexpr int ACC_FIST = 85;
constexpr int ACC_KNIFE = 65;
constexpr int ACC_GUN = 50;
constexpr int ACC_BLASTER = 40;

struct PlayerData {
    std::string playerLoc = "Bedroom";
    std::string playerWeapon = "Fists";
    int playerHealth = 10;
    int playerStrength = PLAYER_MAX_STRENGTH;
    int playerAgility = 5;
    double playerDam = DAMAGE_FIST;
    int playerAcc = ACC_FIST;

    int glassesOfWater = 0;
    int glassesOfBeer = 0;
    int exercise = 0;
    int bullets = 0;

    bool playerHigh = false;
    bool playerAware = false;
    bool playerDressed = false;
    bool playerHungry = true;
    bool handsClean = true;
    bool bodyClean = true;
    bool teethClean = false;
    bool needToilet = true;
    bool playerRested = true;
    bool hasKnife = false;
    bool hasGun = false;
    bool hasBlaster = false;
    bool playerBuzzed = false;
    bool playerDrunk = false;
};

struct EnemyData {
    int enemyHealth = 5;
    int enemyStrength = 3;
    int enemyAgility = 8;

    double currentDamage() const {
	return enemyStrength * 1.2;
    }
};

struct GameState {
    PlayerData player;
    EnemyData enemy;

    std::string TVchannel = "Bonanza";
    int bowlingFrame = 1;
    int bowlingScore = 0;
    int remainingPins = 10;
    int pinKnockdown = rand() % (remainingPins + 1);
    int frameScore = 0;
    int alienNumber = 1;

    bool TVon = false;
    bool fridgeOpen = false;
    bool toastMade = false;
    bool toastButtered = false;
    bool trashOut = false;
    bool shoesRented = false;
    bool alienFound = false;

    std::string lastFrame = "0";
    std::string lastFrame2 = "0";
};

void Bathroom( GameState& state );
void Bedroom( GameState& state );
void LivingRoom( GameState& state );
void Kitchen( GameState& state );
void OutsideHome( GameState& state );
void FranksHouse( GameState& state );
void BowlingAlley( GameState& state );
void AlienCraft( GameState& state );
void Bowl( GameState& state );
void DreamWorld( GameState& state );
void Combat( GameState& state );


void printPlayerStats(const PlayerData& player) {
    std::cout << "\nLocation: " << player.playerLoc
	      << " || Health: " << player.playerHealth
	      << " || Agility: " << player.playerAgility
	      << " || Strength: " << player.playerStrength;
}


void Bathroom(GameState& state) {
    std::cout << "\n\nWhat would you like to do?\n\n";
    // Present bathroom action selections
    if (state.player.needToilet == false) {
        std::cout << "\n";
    }
    else {
        std::cout << "1) Go pee\n";
    }
    if (state.player.teethClean == false) {
        std::cout << "2) Brush your teeth\n";
    }
    else {
        std::cout << "\n";
    }
    if (state.player.handsClean == false) {
        std::cout << "3) Wash your hands\n";
    }
    else {
        std::cout << "\n";
    }
    if (state.player.bodyClean == false) {
        std::cout << "4) Take a bath\n";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "5) Return to the Bedroom\n";
    // Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\nYou use the toilet like a human being." << "\nYour hands are now dirty.";
        state.player.handsClean = false;
        state.player.needToilet = false;
        Bathroom( state );
    }
    else if (playerAction == "2") {
        std::cout << "\nYou brush your teeth." << "\nYour teeth are now clean.";
        state.player.teethClean = true;
        Bathroom( state );
    }
    else if (playerAction == "3") {
        std::cout << "\nYou wash your hands for 20 seconds." << "\nYour hands are now clean.";
        state.player.handsClean = true;
        Bathroom( state );
    }
    else if (playerAction == "4") {
        std::cout << "\nYou take a hot bath with epsom salts." << "\nYour body is now clean.";
        state.player.bodyClean = true;
        Bathroom( state );
    }
    else if (playerAction == "5") {
        std::cout << "\nYou return to the Bedroom.";
        state.player.playerLoc = "Bedroom";
        Bedroom( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
    }
}


void Bedroom(GameState& state) {
    std::cout << "\n\nWhat would you like to do?\n\n";
    //This section is for printing the possible actions in the Bedroom
    if (state.player.playerDressed == false) {
        std::cout << "1) Get dressed\n";
    }
    else {
        std::cout << "1) Undress\n";
    }
    std::cout << "2) Look out the window.\n";
    if (state.player.needToilet == true) {
        std::cout << "3) Go pee\n";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "4) Move to another room\n";
    if (state.player.playerRested == false) {
        std::cout << "5) Go to sleep\n";
    }
    else {
        std::cout << "\n";
    }
    if (state.TVon == false) {
        std::cout << "6) Turn on the TV\n";
    }
    else {
        std::cout << "6) Turn off the TV\n";
    }
    if (state.TVon == true && state.TVchannel == "Bonanza") {
        std::cout << "7) Watch Bonanza\n";
        std::cout << "8) Switch to the news\n";
    }
    else if (state.TVon == true && state.TVchannel == "News") {
        std::cout << "7) Watch the news\n";
        std::cout << "8) Switch to Bonanza\n";
    }
    else {
        std::cout << "\n";
    }

    //Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    //Ask player for selection
    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1" && state.player.playerDressed == false) {
        std::cout << "\nYou get fully dressed. Shoes and all.";
        state.player.playerDressed = true;
        Bedroom( state );
    }
    else if (playerAction == "1" && state.player.playerDressed == true) {
        std::cout << "\nYou undress.";
        state.player.playerDressed = false;
        Bedroom( state );
    }
    else if (playerAction == "2" && state.player.playerAware == false) {
        std::cout << "\nYou look out the window and notice that the world appears to\n be under attack by an alien race. \"Oh good.\" You say to\n yourself, \"this is just what I need on a Monday.\"";
        state.player.playerAware = true;
        Bedroom( state );
    }
    else if (playerAction == "2" && state.player.playerAware == true) {
        std::cout << "\nYou look out the window at the terror of the outside\n world. Alien ships with laser beams vaporize people\n and animals alike. The world is doomed.";
        Bedroom( state );
    }
    else if (playerAction == "3" && state.player.playerDressed == false) {
        std::cout << "\nYou urinate on your bedroom floor like an animal." << "\nYour hands are now dirty.";
        state.player.handsClean = false;
        state.player.needToilet = false;
        Bedroom( state );
    }
    else if (playerAction == "3" && state.player.playerDressed == true) {
        std::cout << "\nYou pee your pants. Just like Miles Davis." << "\nYou are now dirty.";
        state.player.bodyClean = false;
        state.player.needToilet = false;
        Bedroom( state );
    }
    else if (playerAction == "4") {
        std::cout << "\nWhere are you going?\n";
        std::cout << "\n1) Bathroom\n2) Living Room\n";
        std::cout << "\nMake a selection: ";
        std::cin >> playerAction;
        if (playerAction == "1") {
            std::cout << "\nYou enter the bathroom.\n";
            state.player.playerLoc = "Bathroom";
            Bathroom( state );
        }
        else if (playerAction == "2") {
            std::cout << "\nYou enter the Living Room.\n";
            state.player.playerLoc = "Living Room";
            LivingRoom( state );
        }
        else {
            std::cout << "\nInvalid Entry. Please enter action number only.\n:";
            Bedroom( state );
        }
    }
    else if (playerAction == "5" && state.player.playerRested == false) {
        std::cout << "\nYou get into bed and fall asleep into a dream state.\n";
        std::cout << "\nIn your dream you see an anthropomorhic hamburger signing Tina Turner songs for nickels.";
        std::cout << "\nAfter giving the burger a few nickels you get bored.";
        state.player.playerLoc = "Dream World";
        DreamWorld( state );
    }
    else if (playerAction == "5" && state.player.playerRested == true) {
        std::cout << "\nYou are not tired yet.\n";
        Bedroom( state );
    }
    else if (playerAction == "6" && state.TVon == false && state.TVchannel == "Bonanza") {
        std::cout << "\nYou switch on the television. An episode of Bonanza is playing.\n";
        state.TVon = true;
        Bedroom( state );
    }
    else if (playerAction == "6" && state.TVon == false && state.TVchannel == "News") {
        std::cout << "\nYou switch on the television. The news is playing.\n";
        state.TVon = true;
        Bedroom( state );
    }
    else if (playerAction == "6" && state.TVon == true) {
        std::cout << "\nYou switch off the television.\n";
        state.TVon = false;
        Bedroom( state );
    }
    else if (playerAction == "7" && state.TVon == false) {
        std::cout << "\nInvalid entry. Please enter action number only.\n";
        Bedroom( state );
    }
    else if (playerAction == "7" && state.TVon == true && state.TVchannel == "Bonanza") {
        std::cout << "\nGriff's friend, widowed farmer Jonathan May, wants to adopt two young orphans,\n one of whom is unable to talk. When Jonathan is told he cannot adopt the boys,\n Griff decides to set the adoption agency folks straight on what a loving father is.\n";
        Bedroom( state );
    }
    else if (playerAction == "7" && state.TVon == true && state.TVchannel == "News") {
        std::cout << "\nThe news shows live footage from all various parts of the world. Aliens are\n attacking every major populated city in the world. Nobody knows how to stop the\n attacks. It appears the human race is doomed.\n";
        state.player.playerAware = true;
        Bedroom( state );
    }
    else if (playerAction == "8" && state.TVon == false) {
        std::cout << "\nInvalid Entry.  Please enter action number only.\n";
        Bedroom( state );
    }
    else if (playerAction == "8" && state.TVon == true && state.TVchannel == "Bonanza") {
        std::cout << "You switch channels to the BBC World News.\n";
        state.TVchannel = "News";
        Bedroom( state );
    }
    else if (playerAction == "8" && state.TVon == true && state.TVchannel == "News") {
        std::cout << "You switch channels to Bonanza.\n";
        state.TVchannel = "Bonanza";
        Bedroom( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "Invalid Entry. Please enter action number only.";
        Bedroom( state );
    }
}


void LivingRoom(GameState& state) {
    std::cout << "\n\nWhat would you like to do?\n\n";
    // Present Living room action selections
    if (state.player.needToilet == true) {
        std::cout << "1) Go pee\n";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "2) Use exercise bike\n" << "3) Sit in recliner\n" << "4) Smoke weed\n" << "5) Move to another room\n";
    // Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1" && state.player.playerDressed == false) {
        std::cout << "\nYou urinate in the living room like an animal." << "\nYour hands are now dirty.";
        state.player.handsClean = false;
        state.player.needToilet = false;
        LivingRoom( state );
    }
    else if (playerAction == "1" && state.player.playerDressed == true) {
        std::cout << "\nYou pee your pants in the living room." << "\nYour body is now dirty.";
        state.player.needToilet = false;
        state.player.bodyClean = false;
        LivingRoom( state );
    }
    else if (playerAction == "2") {
        std::cout << "\nYou use the exercise bike." << "\nYour body is now dirty.";
        state.player.bodyClean = false;
        for (int t = 0; t < 5; t++) {
            std::cout << "\nRiding";
	    std::this_thread::sleep_for(2000ms);
        }
        while (state.player.playerStrength <= PLAYER_MAX_STRENGTH) {
            std::cout << "\nYour strength has increased";
            state.player.playerStrength++;
        }
        if (state.player.exercise >= 5) {
            std::cout << "\nYou're tired.";
            state.player.playerRested = false;
        }
        else {
            std::cout << "\n";
        }
        state.player.exercise++;
        LivingRoom( state );
    }
    else if (playerAction == "3") {
        std::cout << "\nYou take a seat and recline.";
        LivingRoom( state );
    }
    else if (playerAction == "4" && state.player.playerHigh == false) {
        std::cout << "\nYou pack a bowl of weed and smoke it in your bong." << "\nYou are now high.";
        state.player.playerHigh = true;
        state.player.playerAgility = state.player.playerAgility - 1;
        LivingRoom( state );
    }
    else if (playerAction == "4" && state.player.playerHigh == true) {
        std::cout << "\nYou are already high.";
        LivingRoom( state );
    }
    else if (playerAction == "5") {
        std::cout << "\nWhere are you going?";
        std::cout << "\n\n1) Bedroom" << "\n2) Kitchen" << "\n3) Go outside";
        std::cout << "\n Make a selection: ";
        std::cin >> playerAction;
        if (playerAction == "1") {
            std::cout << "\nYou move to the Bedroom";
            state.player.playerLoc = "Bedroom";
            Bedroom( state );
        }
        else if (playerAction == "2") {
            std::cout << "\nYou move to the Kitchen";
            state.player.playerLoc = "Kitchen";
            Kitchen( state );
        }
        else if (playerAction == "3" && state.player.bodyClean == true && state.player.handsClean == true && state.player.teethClean == true && state.player.needToilet == false && state.player.playerDressed == true && state.player.playerHungry == false && state.player.playerAware == false) {
            std::cout << "\nYou head outside to find that the world is currently being invaded by an alien race.\n This looks very bad for humans.";
            state.player.playerAware = true;
            state.player.playerLoc = "Outside Home";
            OutsideHome( state );
        }
        else if (playerAction == "3" && state.player.bodyClean == true && state.player.handsClean == true && state.player.teethClean == true && state.player.needToilet == false && state.player.playerDressed == true && state.player.playerHungry == false && state.player.playerAware == true) {
            std::cout << "\nYou leave the house feeling ready to face the alien invasion. Upon exiting\n you notice the alien ship vaporizing things here and there.";
            state.player.playerLoc = "Outside Home";
            OutsideHome( state );
        }
        else if (playerAction == "3" && state.player.bodyClean == false) {
            std::cout << "\nYou stink. You should take a bath before going out.";
            LivingRoom( state );
        }
        else if (playerAction == "3" && state.player.handsClean == false) {
            std::cout << "\nYour hands are dirty. You should wash them before going out.";
            LivingRoom( state );
        }
        else if (playerAction == "3" && state.player.teethClean == false) {
            std::cout << "\nYou should brush your teeth before going out.";
            LivingRoom( state );
        }
        else if (playerAction == "3" && state.player.needToilet == true) {
            std::cout << "\nYou still need to pee.";
            LivingRoom( state );
        }
        else if (playerAction == "3" && state.player.playerDressed == false) {
            std::cout << "\nYou are naked. You should get dressed first.";
            LivingRoom( state );
        }
        else if (playerAction == "3" && state.player.playerHungry == true) {
            std::cout << "\nYou haven't eaten breakfast yet.";
            LivingRoom( state );
        }
        else if (playerAction == "exit") {
            exit(0);
        }
        else {
            std::cout << "\nInvalid entry. Please enter action number only.";
            LivingRoom( state );
        }
    }
}


void Kitchen(GameState& state) {
    std::cout << "\n\nWhat would you like to do?\n\n";
    //Print Kitchen Actions
    if (state.fridgeOpen == false) {
        std::cout << "\n1) Open the fridge";
    }
    else {
        std::cout << "\n1) Close the fridge";
    }
    if (state.player.hasKnife == false) {
        std::cout << "\n2) Pick up kitchen knife";
    }
    else {
        std::cout << "\n";
    }
    if (state.player.handsClean == false) {
        std::cout << "\n3) Wash hands in sink";
    }
    else {
        std::cout << "\n";
    }
    if (state.trashOut == false) {
        std::cout << "\n4) Take out the trash";
    }
    else {
        std::cout << "\n";
    }
    if (state.toastMade == false) {
        std::cout << "\n5) Make toast";
    }
    else {
        std::cout << "\n";
    }
    std::cout << "\n6) Return to the Living Room";
    if (state.fridgeOpen == true && state.toastMade == true) {
        std::cout << "\n7) Butter the toast";
    }
    else {
        std::cout << "\n";
    }
    if (state.toastButtered == true) {
        std::cout << "\n8) Eat the toast";
    }
    else {
        std::cout << "\n";
    }
    if (state.player.needToilet == true) {
        std::cout << "\n9) Go pee";
    }
    else {
        std::cout << "\n";
    }

    //Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    //Kitchen action results.
    if (playerAction == "1" && state.fridgeOpen == false) {
        std::cout << "\nYou open the fridge. You are out of eggs";
        state.fridgeOpen = true;
        Kitchen( state );
    }
    else if (playerAction == "1" && state.fridgeOpen == true) {
        std::cout << "\nYou close the fridge";
        state.fridgeOpen = false;
        Kitchen( state );
    }
    else if (playerAction == "2" && state.player.hasKnife == false) {
        std::cout << "\nYou pick up the knife and put it in your pocket.";
        state.player.hasKnife = true;
        state.player.playerWeapon = "Knife";
        state.player.playerAcc = ACC_KNIFE;
        state.player.playerDam = DAMAGE_KNIFE;
        Kitchen( state );
    }
    else if (playerAction == "3" && state.player.handsClean == false) {
        std::cout << "\nYou wash your hands in the sink for 20 seconds.";
        state.player.handsClean = true;
        Kitchen( state );
    }
    else if (playerAction == "4" && state.trashOut == false) {
        std::cout << "\nYou take the trash out to the big can in the garage." << "\nYour hands are now dirty";
        state.player.handsClean = false;
        state.trashOut = true;
        Kitchen( state );
    }
    else if (playerAction == "5" && state.toastMade == false) {
        std::cout << "\nYou pop two slices of bread in the toaster and wait for them to toast.";
        for (int t = 0; t < 5; t++) {
            std::cout << "\nToasting";
	    std::this_thread::sleep_for(2000ms);
        }
        std::cout << "\nToast ready";
        state.toastMade = true;
        Kitchen( state );
    }
    else if (playerAction == "6") {
        std::cout << "\nYou return to the Living Room";
        state.player.playerLoc = "Living Room";
        LivingRoom( state );
    }
    else if (playerAction == "7" && state.fridgeOpen == true && state.toastMade == true) {
        std::cout << "\nYou butter your toast. Now it's ready for eating.";
        state.toastButtered = true;
        Kitchen( state );
    }
    else if (playerAction == "8" && state.toastButtered == true && state.player.handsClean == false) {
        std::cout << "\nYou eat the buttered toast with your filthy hands." << "\nYou have lost 1 health." << "\nYou are no longer hungry.";
        state.player.playerHealth = state.player.playerHealth - 1;
        state.toastMade = false;
        state.toastButtered = false;
        state.player.playerHungry = false;
        Kitchen( state );
    }
    else if (playerAction == "8" && state.toastButtered == true && state.player.handsClean == true) {
        std::cout << "\nYou eat the buttered toast." << "\nYou are no longer hungry.";
        state.toastMade = false;
        state.toastButtered = false;
        state.player.playerHungry = false;
        Kitchen( state );
    }
    else if (playerAction == "9" && state.player.needToilet == true && state.player.playerDressed == false) {
        std::cout << "\nYou pee in the kitchen sink like a savage beast." << "\nYour hands are now dirty.";
        state.player.handsClean = false;
        state.player.needToilet = false;
        Kitchen( state );
    }
    else if (playerAction == "9" && state.player.needToilet == true && state.player.playerDressed == true) {
        std::cout << "\nYou pee your pants in the kitchen." << "\nYour body is now dirty.";
        state.player.bodyClean = false;
        state.player.needToilet = false;
        Kitchen( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        Kitchen( state );
    }
}


void OutsideHome(GameState& state) {
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1) Go see your neighbor Frank." << "\n2) Go to the bowling alley." << "\n3) Head towards the alien spacecraft." << "\n4) Go into your house.";
    //Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\nYou walk to Frank's house. Frank invites you in.";
        state.player.playerLoc = "Frank's House";
        FranksHouse( state );
    }
    else if (playerAction == "2") {
        std::cout << "\nYou drive to the bowling alley.";
        state.player.playerLoc = "Bowling Alley";
        BowlingAlley( state );
    }
    else if (playerAction == "3") {
        std::cout << "\nYou get in your car and start driving towards the alien spacecraft. You get \na bad feeling in the pit of your stomach and you're pretty sure it's not the toast.";
        state.player.playerLoc = "Alien Craft";
        AlienCraft( state );
    }
    else if (playerAction == "4") {
        std::cout << "You wipe your feet and enter the Living Room.";
        state.player.playerLoc = "Living Room";
        LivingRoom( state );
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        OutsideHome( state );
    }
}


void FranksHouse(GameState& state) {
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1) Talk to Frank about the aliens." << "\n2) Ask Frank for some water." << "\n3) Talk to Frank about gun control." << "\n4) Talk to Frank about religion." << "\n5) Say goodbye to Frank and go home.";
    //Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1" && state.player.playerHigh == false) {
        std::cout << "\"Have you seen the news or looked outside? We are under alien attack.\n We have to do something about it.\" You ask Frank with a concerned tone of voice.";
        std::cout << "\n\nFrank looks at you with a grinand says, \"I told you there were aliens!";
        std::cout << "\nNow its too late to do anything! The earth is doomed!\"";
        FranksHouse( state );
    }
    else if (playerAction == "1" && state.player.playerHigh == true) {
        std::cout << "\nYou stare at Frank for a moment and ask, \"Dude, have you seen the aliens yet?\"";
        std::cout << "\n\nFrank looks at you and replies mockingly, \"Have you seen the aliens yet?\n Yes! Of course I have! Haven't I been telling you there are aliens for years?\n We're too late now. The world is doomed.\"";
        FranksHouse( state );
    }
    else if (playerAction == "2" && state.player.playerHigh == false) {
        std::cout << "\nYou ask Frank for a glass of water. He brings you a glass of water from the kitchen.\n \"Thanks.\" you say as you drink the water down.";
        state.player.glassesOfWater = state.player.glassesOfWater + 1;
        if (state.player.glassesOfWater >= 3) {
            std::cout << "\nYou need to go pee.";
            state.player.needToilet = true;
        }
        else {
            std::cout << "\n";
        }
        FranksHouse( state );
    }
    else if (playerAction == "2" && state.player.playerHigh == true) {
        std::cout << "\nYou ask Frank for a glass of water. He brings you a glass of water from the kitchen.\n \"Awesome duder. You're like totally the best.\" you say as you drink the water down.";
        state.player.glassesOfWater = state.player.glassesOfWater + 1;
        if (state.player.glassesOfWater >= 3) {
            std::cout << "\nYou need to go pee.";
            state.player.needToilet = true;
        }
        else {
            std::cout << "\n";
        }
        FranksHouse( state );
    }
    else if (playerAction == "3" && state.player.playerHigh == false) {
        std::cout << "\n\"Well this certainly changes a few viewpoints on gun control, doesn't it?\" You ask frank. \"Not mine!\" says Frank, \"I've been preparing for this for years!\"";
        std::cout << "\nFrank opens a large gun safe and shows you his guns. \"Here, have a pistol.\" Frank says as he hands you a .357 Magnum revolver and a box of 25 bullets.";
        std::cout << "\n\"That ought to help you stay safe out there.\"";
        state.player.hasGun = true;
        state.player.bullets = 25;
        state.player.playerWeapon = "Gun";
        state.player.playerAcc = 50;
        state.player.playerDam = DAMAGE_GUN;
        FranksHouse( state );
    }
    else if (playerAction == "3" && state.player.playerHigh == true) {
        std::cout << "\n\"Brah, this like totally changes my mind on gun control.\" You say to frank. \"Not mine!\" says Frank, \"I've been preparing for this for years!";
        std::cout << "\n I'd offer you one of my guns but you smell like weed and you just called me \"Brah\" so I'm not about to endanger your life by giving you a gun.";
        FranksHouse( state );
    }
    else if (playerAction == "4" && state.player.playerHigh == false) {
        std::cout << "\n\"What do you know about life after death?\" You ask. Frank looks at you, raises an eyebrow and replies,";
        std::cout << "\n\"That all depends, are we talking existentialism, or anthropomorphic deity?\"";
        std::cout << "\nConfused by this question, you decide to it's probably time to go.";
        FranksHouse( state );
    }
    else if (playerAction == "4" && state.player.playerHigh == true) {
        std::cout << "\n\"Have you ever wondered what it would be like to be Jesus in modern times?\" You ask. Frank looks at you, raises an eyebrow and replies,";
        std::cout << "\n\"No.\"";
        FranksHouse( state );
    }
    else if (playerAction == "5" && state.player.playerHigh == false) {
        std::cout << "\n\"Well Frank thank you for the hospitality, I've got to be going now.\" You say as you head for the front door.";
        std::cout << "\n\"Come back any time!\" Frank says, \"Have a nice time killing the aliens.\"";
        state.player.playerLoc = "Outside Home";
        OutsideHome( state );
    }
    else if (playerAction == "5" && state.player.playerHigh == true) {
        std::cout << "\n\"I'm Audi 5000. Later dude!\" You say as you head for the front door.";
        std::cout << "\n\"Come back any time!\" Frank says, \"Have a nice time killing the aliens.\"";
        state.player.playerLoc = "Outside Home";
        OutsideHome( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        FranksHouse( state );
    }
}


void BowlingAlley(GameState& state) {
    std::cout << "\nWhat would you like to do?\n";
    if (state.shoesRented == false) {
        std::cout << "\n1) Rent shoes";
    }
    else {
        std::cout << "\n1) Return shoes";
    }
    std::cout << "\n2) Order a beer" << "\n3) Bowl" << "\n4) Go back home";
    //Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1" && state.shoesRented == false) {
        std::cout << "\nYou rent the appropriate shoes for bowling.";
        state.shoesRented = true;
        BowlingAlley( state );
    }
    else if (playerAction == "1" && state.shoesRented == true) {
        std::cout << "\nYou return the bowling shoes.";
        state.shoesRented = false;
        BowlingAlley( state );
    }
    else if (playerAction == "2" && state.player.glassesOfBeer <= 5) {
        std::cout << "\nYou order a beer and slug it down. Mmm refreshing.";
        state.player.glassesOfBeer = state.player.glassesOfBeer + 1;
        if (state.player.glassesOfBeer == 3) {
            std::cout << "\nYou are buzzed.";
            state.player.playerBuzzed = true;
        }
        else if (state.player.glassesOfBeer == 5) {
            std::cout << "\nYou are drunk.";
            state.player.playerDrunk = true;
        }
        else {
            std::cout << "\n";
        }
        BowlingAlley( state );
    }
    else if (playerAction == "2" && state.player.glassesOfBeer >= 6) {
        std::cout << "\nThe bartender cuts you off because you are clearly drunk.";
        BowlingAlley( state );
    }
    else if (playerAction == "3" && state.shoesRented == false) {
        std::cout << "\nYou need to rent the shoes first.";
        BowlingAlley( state );
    }
    else if (playerAction == "3" && state.shoesRented == true) {
        std::cout << "\nYou pick out a ball and head for the lanes.";
        Bowl( state );
    }
    else if (playerAction == "4" && state.player.playerDrunk == false) {
        std::cout << "\nYou drive back home.";
        state.player.playerLoc = "Outside Home";
        OutsideHome( state );
    }
    else if (playerAction == "4" && state.player.playerDrunk == true) {
        std::cout << "\nYou take an Uber home becuase you are drunk.";
        state.player.playerLoc = "Outside Home";
        OutsideHome( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        BowlingAlley( state );
    }
}

void Bowl(GameState& state) {
    std::cout << "\nFrame: " << state.bowlingFrame << " Score: " << state.bowlingScore << " Pins remaining: " << state.remainingPins;
    std::cout << "\n\n1) Bowl frame" << "\n2) Quit Bowling";
    //Print player stats
    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1" && state.bowlingFrame <= 9) {
        std::cout << "You roll a ball down the lane and knock down " << state.pinKnockdown << " pins.";
        state.remainingPins = state.remainingPins - state.pinKnockdown;
        state.lastFrame2 = state.lastFrame;
        if (state.remainingPins == 0) {
            state.bowlingFrame = state.bowlingFrame + 1;
            if (state.lastFrame == "X" || state.lastFrame == "/" && state.lastFrame2 != "X") {
                state.frameScore = state.pinKnockdown * 2;
            }
            else if (state.lastFrame == "X" || state.lastFrame == "/" && state.lastFrame2 == "X") {
                state.frameScore = state.pinKnockdown * 3;
            }
            else if (state.lastFrame != "X" && state.lastFrame != "/" && state.lastFrame2 != "X") {
                state.frameScore = state.pinKnockdown;
            }
            else if (state.lastFrame != "X" && state.lastFrame != "/" && state.lastFrame2 == "X") {
                state.frameScore = state.pinKnockdown * 2;
            }
            state.lastFrame = "X";
            state.bowlingScore = state.bowlingScore + state.frameScore;
            state.remainingPins = 10;
            state.frameScore = 0;
            Bowl( state );
        }
        else {
            std::cout << "\nThere are " << state.remainingPins << " still standing.";
            std::cout << "\nRoll again?" << "\n\n1) Roll again" << "\n2) Quit bowling";
            std::cout << "\n\n Make a selection:";
            std::cin >> playerAction;

            if (state.lastFrame == "X" || state.lastFrame == "/" && state.lastFrame2 != "X") {
                state.frameScore = state.pinKnockdown * 2;
            }
            else if (state.lastFrame == "X" || state.lastFrame == "/" && state.lastFrame2 == "X") {
                state.frameScore = state.pinKnockdown * 3;
            }
            else if (state.lastFrame != "X" && state.lastFrame != "/" && state.lastFrame2 != "X") {
                state.frameScore = state.pinKnockdown;
            }
            else if (state.lastFrame != "X" && state.lastFrame != "/" && state.lastFrame2 == "X") {
                state.frameScore = state.pinKnockdown * 2;
            }
            else {
                std::cout << "\nError";
                BowlingAlley( state );
            }

            if (playerAction == "1") {
                state.pinKnockdown = rand() % (state.remainingPins + 1);
                std::cout << "You roll a ball down the lane and knock down " << state.pinKnockdown << " pins.";
                state.remainingPins = state.remainingPins - state.pinKnockdown;
                if (state.remainingPins == 0) {
                    state.bowlingFrame = state.bowlingFrame + 1;
                    if (state.lastFrame == "X") {
                        state.frameScore = state.frameScore + state.pinKnockdown * 2;
                    }
                    else if (state.lastFrame == "/") {
                        state.frameScore = state.frameScore + state.pinKnockdown;
                    }
                    else if (state.lastFrame != "X" && state.lastFrame != "/") {
                        state.frameScore = state.frameScore + state.pinKnockdown;
                    }
                    else {
                        std::cout << "\nError";
                        BowlingAlley( state );
                    }
                    state.lastFrame = "/";
                    state.bowlingScore = state.bowlingScore + state.frameScore;
                    state.remainingPins = 10;
                    state.frameScore = 0;
                    Bowl( state );
                }
                else {
                    state.bowlingFrame = state.bowlingFrame + 1;
                    if (state.lastFrame == "X") {
                        state.frameScore = state.frameScore + state.pinKnockdown * 2;
                    }
                    else if (state.lastFrame == "/") {
                        state.frameScore = state.frameScore + state.pinKnockdown;
                    }
                    else if (state.lastFrame != "X" && state.lastFrame != "/") {
                        state.frameScore = state.frameScore + state.pinKnockdown;
                    }
                    else {
                        std::cout << "\nError";
                        BowlingAlley( state );
                    }
                    state.lastFrame = 10 - state.remainingPins;
                    state.bowlingScore = state.bowlingScore + state.frameScore;
                    state.remainingPins = 10;
                    state.frameScore = 0;
                    Bowl( state );
                }
            }
            else if (playerAction == "2") {
                std::cout << "\nYou quit bowling.";
                BowlingAlley( state );
            }
            else if (playerAction == "exit") {
                exit(0);
            }
            else {
                std::cout << "\nInvalid Entry. Please enter action number only.";
                Bowl( state );
            }
        }
    }
    else if (playerAction == "2") {
        std::cout << "\nYou quit bowling.";
        BowlingAlley( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
    }
}


void AlienCraft(GameState& state) {
    std::cout << "\nWhat would you like to do?\n";
    std::cout << "\n1) Investigate the alien spacecraft." << "\n2) Find an alien." << "\n3) Return home.";
    if (state.alienFound == false) {
        std::cout << "\n";
    }
    else if (state.alienFound == true && state.player.hasKnife == false && state.player.hasGun == false) {
        std::cout << "\n4) Attack aliens with fists";
    }
    else if (state.alienFound == true && state.player.hasKnife == true && state.player.hasGun == false) {
        std::cout << "\n4) Attack aliens with knife";
    }
    else if (state.alienFound == true && state.player.hasGun == true) {
        std::cout << "\n4) Attack aliens with gun";
    }
    else {
        std::cout << "\n";
    }

    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\nYou move in closer to the alien ship and find that it has a large opening on the bottom to facilitate docking with smaller craft." << "\nYou can also see what appears to be alien lifeforms being transported to the ground.";
        AlienCraft( state );
    }
    else if (playerAction == "2") {
        std::cout << "\nAfter some searching you find the alien landing site. You can currently see 6 aliens. They are tall, fuzzy, and sound like an upset turkey when they talk.";
        state.alienFound = true;
        AlienCraft( state );
    }
    else if (playerAction == "3") {
        std::cout << "\nYou return to your house.";
        state.player.playerLoc = "Outside Home";
        OutsideHome( state );
    }
    else if (playerAction == "4") {
        Combat( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
    }
}


void Combat(GameState& state) {
    const int attackHit = rand() % 100;
    const int enemyHit = rand() % 100;
    if (state.player.playerHealth <= 0) {
        std::cout << "\nYou have died.\n\n GAME OVER.";
        exit(0);
    }
    else {
        std::cout << "\n";
    }
    std::cout << "\n\n========== Combat Mode ==========";
    std::cout << "\nWeapon: " << state.player.playerWeapon << " Hit chance: ";
    if (state.player.playerWeapon == "Fists") {
        std::cout << ACC_FIST;
    }
    else if (state.player.playerWeapon == "Knife") {
        std::cout << ACC_KNIFE;
    }
    else if (state.player.playerWeapon == "Gun") {
        std::cout << ACC_GUN;
    }
    else if (state.player.playerWeapon == "Blaster") {
        std::cout << ACC_BLASTER;
    }
    else {
        std::cout << "Error";
    }
    std::cout << " Damage: ";
    if (state.player.playerWeapon == "Fists") {
        std::cout << DAMAGE_FIST;
    }
    else if (state.player.playerWeapon == "Knife") {
        std::cout << DAMAGE_KNIFE;
    }
    else if (state.player.playerWeapon == "Gun") {
        std::cout << DAMAGE_GUN;
    }
    else if (state.player.playerWeapon == "Blaster") {
        std::cout << DAMAGE_BLASTER;
    }
    else {
        std::cout << "Error";
    }
    std::cout << " Enemy HP: " << state.enemy.enemyHealth;
    std::cout << "\n\n1) Attack enemy" << "\n2) Change weapon" << "\n3) Quit combat.\n";

    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1") {
        if (state.player.playerWeapon == "Fists") {
            state.player.playerDam = DAMAGE_FIST;
        }
        else if (state.player.playerWeapon == "Knife") {
            state.player.playerDam = DAMAGE_KNIFE;
        }
        else if (state.player.playerWeapon == "Gun") {
            state.player.playerDam = DAMAGE_GUN;
        }
        else {

        }
        std::cout << "\nYou attack the alien with your " << state.player.playerWeapon << ". The attack ";
        if (state.player.playerWeapon == "Gun") {
            state.player.bullets = state.player.bullets - 1;
        }
        else {

        }
        if (attackHit > state.player.playerAcc) {
            std::cout << "Misses";
            state.player.playerDam = DAMAGE_NULL;
        }
        else {
            std::cout << "Hits";
        }
        std::cout << " and deals " << state.player.playerDam << " damage.\n\n";
        state.enemy.enemyHealth = state.enemy.enemyHealth - state.player.playerDam;
        auto enemyDam = state.enemy.currentDamage();
        if (state.enemy.enemyHealth <= 0) {
            std::cout << "You have killed the alien. Prepare for the next challenge.\n";
            state.alienNumber++;
            state.enemy.enemyHealth = state.alienNumber * 5;
            state.enemy.enemyStrength = state.enemy.enemyStrength + 1;
            Combat( state );
        }
        else {
            std::cout << "The alien has " << state.enemy.enemyHealth << " health remaining.\n";
            std::cout << "The alien counter attacks. The attack ";
            if (enemyHit > ACC_BLASTER) {
                std::cout << "Misses";
                enemyDam = DAMAGE_NULL;
            }
            else {
                std::cout << "Hits";
            }
            std::cout << " and deals " << enemyDam << " damage.\n\n";
            state.player.playerHealth = state.player.playerHealth - enemyDam;
            Combat( state );
        }

    }
    else if (playerAction == "2") {
        std::cout << "\n1) Fists";
        if (state.player.hasKnife == true) {
            std::cout << "\n2) Knife";
        }
        else {
            std::cout << "\n";
        }
        if (state.player.hasGun == true) {
            std::cout << "\n3) Gun";
        }
        else {
            std::cout << "\n";
        }
        std::cout << "\nSelect a weapon:";

        std::cin >> playerAction;

        if (playerAction == "1") {
            state.player.playerDam = DAMAGE_FIST;
            state.player.playerAcc = ACC_FIST;
            state.player.playerWeapon = "Fists";
            Combat( state );
        }
        else if (playerAction == "2" && state.player.hasKnife == true) {
            state.player.playerDam = DAMAGE_KNIFE;
            state.player.playerAcc = ACC_KNIFE;
            state.player.playerWeapon = "Knife";
            Combat( state );
        }
        else if (playerAction == "3" && state.player.hasGun == true) {
            state.player.playerDam = DAMAGE_GUN;
            state.player.playerAcc = ACC_GUN;
            state.player.playerWeapon = "Gun";
            Combat( state );
        }
        else {
            std::cout << "\nInvalid Entry. Please enter action number only.";
            Combat( state );
        }

    }
    else if (playerAction == "3") {
        std::cout << "\nYou quit fighting.";
        AlienCraft( state );
    }
    else if (playerAction == "exit") {
        exit(0);
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        Combat( state );
    }
}


void DreamWorld(GameState& state) {
    std::cout << "\n\nWhat would you like to do?";
    std::cout << "\n\n1) Try to eat the hamburger." << "\n2) Ask the hamburger a question";

    printPlayerStats( state.player );
    std::cout << "\n\n Make a selection:";

    std::string playerAction;
    std::cin >> playerAction;

    if (playerAction == "1") {
        std::cout << "\n\nYou pick up the hamburger. It immediately starts screaming and kicking. It appears the hamburger is not keen on the idea of being eaten.";
        std::cout << "\n\n1) Continue eating" << "\n2) Put the hamburger back";

	printPlayerStats( state.player );
        std::cout << "\n\n Make a selection:";

        std::cin >> playerAction;

        if (playerAction == "1") {
            std::cout << "\n\nYou eat Gary the Hamburger like a complete fucking savage. Now you dont even have a hamburger to entertain you.";
            std::cout << "\nThe Mona Lisa with legs comes in and asks, \"Where is Gary?\"";
            std::cout << "\n\n1) Tell the truth." << "\n2) Lie.";

	    printPlayerStats( state.player );
            std::cout << "\n\n Make a selection:";

            std::cin >> playerAction;

            if (playerAction == "1") {
                std::cout << "\n\nYou tell the Mona Lisa that you ate Gary. The Mona Lisa begins weeping uncontrollably. You comfort the painting and wipe the tears from her face.";
                std::cout << "\nYou turn around and notice a bright red light in the distance. It comes closer and closer until its right over your head. Then is crushes you.";
                std::cout << "\nYou wake up in your bed, naked, like any other day.";
                state.player.playerDrunk = false;
                state.player.playerBuzzed = false;
                state.player.playerRested = true;
                state.player.needToilet = true;
                state.player.playerHungry = true;
                state.player.playerHigh = false;
                state.player.playerHealth = 10;
                Bedroom( state );
            }
            else if (playerAction == "2") {
                std::cout << "\n\nYou tell the Mona Lisa that Gary the Hamburger went to the store to buy some tap shoes and should be back shortly. The Mona Lisa says, \"Tap shoes? Well okay I guess.";
                std::cout << "\nHe is supposed to be giving me a foot massage right now. But since he isnt here I'll just have to stab you.\"\n\nThe Mona Lisa stabs you in the chest with a screwdriver.";
                std::cout << "\nYou wake up in your bed, naked, like any other day.";
                state.player.playerDrunk = false;
                state.player.playerBuzzed = false;
                state.player.playerRested = true;
                state.player.needToilet = true;
                state.player.playerHungry = true;
                state.player.playerHigh = false;
                state.player.playerHealth = 10;
                Bedroom( state );
            }
            else {
                std::cout << "\nInvalid Entry. Please enter action number only.";
                DreamWorld( state );
            }

        }
        else if (playerAction == "2") {
            std::cout << "\n\nYou put the hamburger back. \"The name's Gary,\" Says the hamburger, \"Thanks for thinking twice about eating me.\"";
            std::cout << "\n\"No problem little dude! Keep on dancing.\" You say with a grin. You turn around and find that Gary is being pursued by the Russian Mafia.";
            std::cout << "\nThe goons beat Gary senseless and tie you to a roasting spit. They throw you over a fire to get a good char going.";
            std::cout << "\nYou wake up in your bed, naked, like any other day.";
            state.player.playerDrunk = false;
            state.player.playerBuzzed = false;
            state.player.playerRested = true;
            state.player.needToilet = true;
            state.player.playerHungry = true;
            state.player.playerHigh = false;
            state.player.playerHealth = 10;
            Bedroom( state );
        }
        else {
            std::cout << "\nInvalid Entry. Please enter action number only.";
            DreamWorld( state );
        }

    }
    if (playerAction == "2") {
        std::cout << "\n\nYou ask the hamburger, \"How does a handsome burger like you end up in place like this?\" The hamburger looks at you confused and says, \"Becuase you're dreaming, dummy.\" says Gary the hamburger.";
        std::cout << "\nThis of course reminds you that you can do anything. Including shooting a hamburger out of a cannon.You launch Gary the Hamburger high into the sky. You can hear him screaming the whole way.";
            std::cout << "\nYou wake up in your bed, naked, like any other day.";
        state.player.playerDrunk = false;
        state.player.playerBuzzed = false;
        state.player.playerRested = true;
        state.player.needToilet = true;
        state.player.playerHungry = true;
        state.player.playerHigh = false;
        state.player.playerHealth = 10;
        Bedroom( state );
    }
    else {
        std::cout << "\nInvalid Entry. Please enter action number only.";
        DreamWorld( state );
    }
}


int main() {
    srand(time(NULL));
    std::cout << "\nThe Great Big Adventure\n";
    std::cout << "\nYou wake up in your bed, naked, like any other day.\n";

    GameState state;
    Bedroom( state );
}

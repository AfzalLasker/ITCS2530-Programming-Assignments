#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_MEALS = 10;

enum GoalStatus
{
    BelowGoal,
    ReachedGoal,
    AboveGoal
};

class NutritionTracker
{
private:
    struct DailyMeal
    {
        string mealName;
        string mealTime;
        double calories;
        double proteinGrams;
    };

    string userName;
    int dailyMealGoal;
    double dailyCalorieGoal;
    int totalMeals;

    DailyMeal foodEntries[MAX_MEALS];

    double totalCalories;
    double averageCalories;
    double totalProtein;

    string calorieMessage;
    string nutritionMessage;

public:
    NutritionTracker();
    void run();

private:
    void displayBanner();
    void changeConsoleColor(string colorCode);
    void askUserName();
    void collectGoals();
    void collectFoodEntries();

    void calculateTotals();
    void calculateAverage();

    GoalStatus getGoalStatus(double goalValue, double actualValue);
    string goalStatusText(GoalStatus status);
    void displayGoalMessage();
    void createStatusMessages();
    void displayConfirmationMessage();

    void displayMenu();
    void displayFoodEntries();
    void displaySummary();
    void createTextFile();
    void programEndMessage();
};

int main()
{
    NutritionTracker tracker;
    tracker.run();

    return 0;
}

NutritionTracker::NutritionTracker()
{
    userName = "";
    dailyMealGoal = 0;
    dailyCalorieGoal = 0;
    totalMeals = 0;

    totalCalories = 0;
    averageCalories = 0;
    totalProtein = 0;

    calorieMessage = "";
    nutritionMessage = "";
}

void NutritionTracker::run()
{
    displayBanner();
    askUserName();
    collectGoals();
    displayGoalMessage();
    collectFoodEntries();
    calculateTotals();
    calculateAverage();
    displayConfirmationMessage();
    createStatusMessages();
    displayMenu();

    // Save the final report even if the user did not select it in the menu.
    createTextFile();

    programEndMessage();
}
void NutritionTracker::changeConsoleColor(string colorCode)
{
    cout << colorCode;
}

void NutritionTracker::displayBanner()
{
    cout << endl;
    cout << "======================================================================" << endl;

    changeConsoleColor("\x1b[1;39;48;5;14m");
    cout << "                     Welcome to Nutrition Tracker!                    ";
    changeConsoleColor("\x1b[0m");
    cout << endl;

    cout << "======================================================================" << endl;
    cout << endl;

    changeConsoleColor("\x1b[1;38;5;73;49m");
    cout << "This application helps keep track of your daily nutrition information.";
    changeConsoleColor("\x1b[0m");

    cout << endl << endl;
}

void NutritionTracker::askUserName()
{
    changeConsoleColor("\x1b[0;38;5;54;49m");
    cout << "Please enter your name: ";
    changeConsoleColor("\x1b[0m");

    getline(cin, userName);

    while (userName == "")
    {
        changeConsoleColor("\x1b[1;39;48;5;196m");
        cout << "Name cannot be empty. Please enter your name: ";
        changeConsoleColor("\x1b[0m");

        getline(cin, userName);
    }

    cout << endl;
}

void NutritionTracker::collectGoals()
{
    cout << "-----------------------------" << endl;

    changeConsoleColor("\x1b[1;38;5;0;48;5;216m");
    cout << "Let's set some nutrition goals!";
    changeConsoleColor("\x1b[0m");

    cout << endl;
    cout << "-----------------------------" << endl;

    changeConsoleColor("\x1b[0;38;5;54;49m");
    cout << "Enter your daily food entry goal: ";
    changeConsoleColor("\x1b[0m");

    cin >> dailyMealGoal;

    while (cin.fail() || dailyMealGoal < 1 || dailyMealGoal > MAX_MEALS)
    {
        cin.clear();
        cin.ignore(100, '\n');

        changeConsoleColor("\x1b[1;39;48;5;196m");
        cout << "Invalid input! Enter a food entry goal from 1 to "
            << MAX_MEALS << ".";
        changeConsoleColor("\x1b[0m");

        cout << endl << endl;

        cout << "Enter your daily food entry goal: ";
        cin >> dailyMealGoal;
    }

    cout << endl;

    changeConsoleColor("\x1b[0;38;5;54;49m");
    cout << "Enter your daily calorie goal: ";
    changeConsoleColor("\x1b[0m");

    cin >> dailyCalorieGoal;

    while (cin.fail() || dailyCalorieGoal < 1)
    {
        cin.clear();
        cin.ignore(100, '\n');

        changeConsoleColor("\x1b[1;39;48;5;196m");
        cout << "Invalid input! Enter a calorie goal greater than 0.";
        changeConsoleColor("\x1b[0m");

        cout << endl << endl;

        cout << "Enter your daily calorie goal: ";
        cin >> dailyCalorieGoal;
    }

    cout << endl;

    changeConsoleColor("\x1b[0;38;5;54;49m");
    cout << "Enter the number of food entries you had today (1-"
        << MAX_MEALS << "): ";
    changeConsoleColor("\x1b[0m");

    cin >> totalMeals;

    while (cin.fail() || totalMeals < 1 || totalMeals > MAX_MEALS)
    {
        cin.clear();
        cin.ignore(100, '\n');

        changeConsoleColor("\x1b[1;39;48;5;196m");
        cout << "Invalid input! Enter a number from 1 to "
            << MAX_MEALS << ".";
        changeConsoleColor("\x1b[0m");

        cout << endl << endl;

        cout << "Enter the number of food entries you had today (1-"
            << MAX_MEALS << "): ";

        cin >> totalMeals;
    }

    cout << endl;
}
void NutritionTracker::displayGoalMessage()
{
    if (dailyMealGoal >= 1 && dailyCalorieGoal >= 1)
    {
        changeConsoleColor("\x1b[1;38;5;54;48;5;10m");
        cout << "# Food entry and calorie goals set successfully.";
        changeConsoleColor("\x1b[0m");
    }
    else
    {
        changeConsoleColor("\x1b[1;39;48;5;196m");
        cout << "# Food entry and calorie goals were not fully set.";
        changeConsoleColor("\x1b[0m");
    }

    cout << endl << endl;
}

void NutritionTracker::collectFoodEntries()
{
    cin.ignore(100, '\n');

    // This for loop fills the array of DailyMeal structs.
    for (int i = 0; i < totalMeals; i++)
    {
        changeConsoleColor("\x1b[1;38;5;167;49m");
        cout << "* Enter the name for food entry " << (i + 1) << ": ";
        changeConsoleColor("\x1b[0m");

        getline(cin, foodEntries[i].mealName);

        while (foodEntries[i].mealName == "")
        {
            changeConsoleColor("\x1b[1;39;48;5;196m");
            cout << "Invalid input! Food entry name cannot be empty.";
            changeConsoleColor("\x1b[0m");

            cout << endl;

            cout << "Enter the name for food entry " << (i + 1) << ": ";
            getline(cin, foodEntries[i].mealName);
        }

        changeConsoleColor("\x1b[1;38;5;167;49m");
        cout << "* Enter the meal time for "
            << foodEntries[i].mealName
            << " (breakfast, lunch, dinner, or snack): ";
        changeConsoleColor("\x1b[0m");

        getline(cin, foodEntries[i].mealTime);

        while (foodEntries[i].mealTime == "")
        {
            changeConsoleColor("\x1b[1;39;48;5;196m");
            cout << "Invalid input! Meal time cannot be empty.";
            changeConsoleColor("\x1b[0m");

            cout << endl;

            cout << "Enter the meal time: ";
            getline(cin, foodEntries[i].mealTime);
        }

        changeConsoleColor("\x1b[1;38;5;167;49m");
        cout << "* Enter the calories consumed for "
            << foodEntries[i].mealName << ": ";
        changeConsoleColor("\x1b[0m");

        cin >> foodEntries[i].calories;

        while (cin.fail() || foodEntries[i].calories < 0)
        {
            cin.clear();
            cin.ignore(100, '\n');

            changeConsoleColor("\x1b[1;39;48;5;196m");
            cout << "Invalid input! Enter a calorie amount of 0 or greater.";
            changeConsoleColor("\x1b[0m");

            cout << endl;

            cout << "Enter the calories consumed for "
                << foodEntries[i].mealName << ": ";

            cin >> foodEntries[i].calories;
        }

        changeConsoleColor("\x1b[1;38;5;167;49m");
        cout << "* Enter the protein grams for "
            << foodEntries[i].mealName << ": ";
        changeConsoleColor("\x1b[0m");

        cin >> foodEntries[i].proteinGrams;

        while (cin.fail() || foodEntries[i].proteinGrams < 0)
        {
            cin.clear();
            cin.ignore(100, '\n');

            changeConsoleColor("\x1b[1;39;48;5;196m");
            cout << "Invalid input! Enter protein grams of 0 or greater.";
            changeConsoleColor("\x1b[0m");

            cout << endl;

            cout << "Enter the protein grams for "
                << foodEntries[i].mealName << ": ";

            cin >> foodEntries[i].proteinGrams;
        }

        cin.ignore(100, '\n');
        cout << endl;
    }
}
void NutritionTracker::calculateTotals()
{
    totalCalories = 0;
    totalProtein = 0;

    for (int i = 0; i < totalMeals; i++)
    {
        totalCalories += foodEntries[i].calories;
        totalProtein += foodEntries[i].proteinGrams;
    }

    changeConsoleColor("\x1b[1;38;5;167;49m");
    cout << "Your total calorie intake today is ";
    changeConsoleColor("\x1b[0m");

    cout << fixed << setprecision(2) << totalCalories << endl;

    changeConsoleColor("\x1b[1;38;5;167;49m");
    cout << "Your total protein intake today is ";
    changeConsoleColor("\x1b[0m");

    cout << fixed << setprecision(2) << totalProtein << " grams" << endl << endl;
}

void NutritionTracker::calculateAverage()
{
    averageCalories = 0;

    if (totalMeals > 0)
    {
        averageCalories = totalCalories / totalMeals;
    }
}

void NutritionTracker::displayConfirmationMessage()
{
    if (totalMeals >= 1 && totalCalories >= 1)
    {
        changeConsoleColor("\x1b[1;38;5;54;48;5;10m");
        cout << "# Today's nutrition information recorded successfully.";
        changeConsoleColor("\x1b[0m");
    }
    else if (totalMeals >= 1 && totalCalories < 1)
    {
        changeConsoleColor("\x1b[1;38;5;54;48;5;10m");
        cout << "# Food entries were recorded, but no calories were recorded.";
        changeConsoleColor("\x1b[0m");
    }
    else
    {
        changeConsoleColor("\x1b[1;39;48;5;196m");
        cout << "# Nutrition information was not fully recorded.";
        changeConsoleColor("\x1b[0m");
    }

    cout << endl << endl;
}

GoalStatus NutritionTracker::getGoalStatus(double goalValue, double actualValue)
{
    if (actualValue < goalValue)
    {
        return BelowGoal;
    }
    else if (actualValue > goalValue)
    {
        return AboveGoal;
    }
    else
    {
        return ReachedGoal;
    }
}

string NutritionTracker::goalStatusText(GoalStatus status)
{
    string statusText;

    switch (status)
    {
    case BelowGoal:
        statusText = "Below Goal";
        break;

    case ReachedGoal:
        statusText = "Reached Goal";
        break;

    case AboveGoal:
        statusText = "Above Goal";
        break;

    default:
        statusText = "Unknown";
        break;
    }

    return statusText;
}
void NutritionTracker::createStatusMessages()
{
    GoalStatus calorieGoalStatus;
    GoalStatus foodEntryGoalStatus;

    calorieGoalStatus = getGoalStatus(dailyCalorieGoal, totalCalories);
    foodEntryGoalStatus = getGoalStatus(dailyMealGoal, totalMeals);

    switch (calorieGoalStatus)
    {
    case BelowGoal:
        calorieMessage =
            "# You are below your calorie goal. Status: "
            + goalStatusText(calorieGoalStatus);
        break;

    case ReachedGoal:
        calorieMessage =
            "# You reached your calorie goal. Status: "
            + goalStatusText(calorieGoalStatus);
        break;

    case AboveGoal:
        calorieMessage =
            "# You are above your calorie goal. Status: "
            + goalStatusText(calorieGoalStatus);
        break;
    }

    switch (foodEntryGoalStatus)
    {
    case BelowGoal:
        nutritionMessage =
            "# You are below your food entry goal. Status: "
            + goalStatusText(foodEntryGoalStatus);
        break;

    case ReachedGoal:
        nutritionMessage =
            "# You reached your food entry goal. Status: "
            + goalStatusText(foodEntryGoalStatus);
        break;

    case AboveGoal:
        nutritionMessage =
            "# You are above your food entry goal. Status: "
            + goalStatusText(foodEntryGoalStatus);
        break;
    }
}

void NutritionTracker::displayMenu()
{
    int choice = 0;

    do
    {
        changeConsoleColor("\x1b[0;38;5;54;49m");
        cout << "Menu:";
        changeConsoleColor("\x1b[0m");

        cout << endl;
        cout << "1. View calorie status" << endl;
        cout << "2. View food entry status" << endl;
        cout << "3. View today's food entries" << endl;
        cout << "4. View full nutrition summary" << endl;
        cout << "5. Save report" << endl;
        cout << "6. Quit" << endl << endl;

        cout << "Enter your menu choice (1-6): ";
        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');

            changeConsoleColor("\x1b[1;39;48;5;196m");
            cout << "Invalid input! Enter a number between 1 and 6.";
            changeConsoleColor("\x1b[0m");

            cout << endl << endl;
        }
        else if (choice < 1 || choice > 6)
        {
            changeConsoleColor("\x1b[1;39;48;5;196m");
            cout << "Invalid menu choice! Enter a number from 1 to 6.";
            changeConsoleColor("\x1b[0m");

            cout << endl << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                cout << calorieMessage << endl << endl;
                break;

            case 2:
                cout << nutritionMessage << endl << endl;
                break;

            case 3:
                displayFoodEntries();
                break;

            case 4:
                displaySummary();
                break;

            case 5:
                createTextFile();
                break;

            case 6:
                cout << "Exiting menu..." << endl << endl;
                break;
            }
        }
    } while (choice != 6);
}
void NutritionTracker::displayFoodEntries()
{
    changeConsoleColor("\x1b[1;38;5;0;48;5;216m");
    cout << "---------------------- Food Entry List ----------------------";
    changeConsoleColor("\x1b[0m");

    cout << endl << endl;

    cout << left << setw(20) << "Food Entry"
        << left << setw(18) << "Meal Time"
        << right << setw(15) << "Calories"
        << right << setw(15) << "Protein (g)" << endl;

    cout << "--------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < totalMeals; i++)
    {
        cout << left << setw(20) << foodEntries[i].mealName
            << left << setw(18) << foodEntries[i].mealTime
            << right << setw(15) << fixed << setprecision(2)
            << foodEntries[i].calories
            << right << setw(15)
            << foodEntries[i].proteinGrams << endl;
    }

    cout << endl;
}

void NutritionTracker::displaySummary()
{
    changeConsoleColor("\x1b[1;38;5;0;48;5;216m");
    cout << "-------------------- Nutrition Summary --------------------";
    changeConsoleColor("\x1b[0m");

    cout << endl << endl;

    cout << left << setw(32) << "User Name:"
        << right << setw(20) << userName << endl;

    cout << left << setw(32) << "Daily Food Entry Goal:"
        << right << setw(20) << dailyMealGoal << endl;

    cout << left << setw(32) << "Daily Calorie Goal:"
        << right << setw(20) << fixed << setprecision(2)
        << dailyCalorieGoal << endl;

    cout << left << setw(32) << "Food Entries Today:"
        << right << setw(20) << totalMeals << endl;

    cout << left << setw(32) << "Today's Calorie Intake:"
        << right << setw(20) << totalCalories << endl;

    cout << left << setw(32) << "Average Calories Per Entry:"
        << right << setw(20) << averageCalories << endl;

    cout << left << setw(32) << "Total Protein:"
        << right << setw(20) << totalProtein << endl;

    cout << endl;

    displayFoodEntries();

    changeConsoleColor("\x1b[1;38;5;0;48;5;216m");
    cout << "---------------- Nutrition Assessment ----------------";
    changeConsoleColor("\x1b[0m");

    cout << endl << endl;
    cout << calorieMessage << endl;
    cout << nutritionMessage << endl << endl;
}
void NutritionTracker::createTextFile()
{
    ofstream report("report.txt");

    if (!report)
    {
        cout << "The report file could not be opened." << endl << endl;
        return;
    }

    report << "============================================================" << endl;
    report << "                    Nutrition Summary                       " << endl;
    report << "============================================================" << endl;

    report << left << setw(32) << "User Name:"
        << right << setw(20) << userName << endl;

    report << left << setw(32) << "Daily Food Entry Goal:"
        << right << setw(20) << dailyMealGoal << endl;

    report << left << setw(32) << "Daily Calorie Goal:"
        << right << setw(20) << fixed << setprecision(2)
        << dailyCalorieGoal << endl;

    report << left << setw(32) << "Food Entries Today:"
        << right << setw(20) << totalMeals << endl;

    report << left << setw(32) << "Today's Calorie Intake:"
        << right << setw(20) << totalCalories << endl;

    report << left << setw(32) << "Average Calories Per Entry:"
        << right << setw(20) << averageCalories << endl;

    report << left << setw(32) << "Total Protein:"
        << right << setw(20) << totalProtein << endl;

    report << endl;

    report << "----------------------- Food Entries -----------------------"
        << endl;

    report << left << setw(20) << "Food Entry"
        << left << setw(18) << "Meal Time"
        << right << setw(15) << "Calories"
        << right << setw(15) << "Protein (g)" << endl;

    report << "--------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < totalMeals; i++)
    {
        report << left << setw(20) << foodEntries[i].mealName
            << left << setw(18) << foodEntries[i].mealTime
            << right << setw(15) << fixed << setprecision(2)
            << foodEntries[i].calories
            << right << setw(15)
            << foodEntries[i].proteinGrams << endl;
    }

    report << endl;
    report << "---------------- Nutrition Assessment ----------------" << endl;
    report << calorieMessage << endl;
    report << nutritionMessage << endl;

    report.close();

    cout << "Nutrition summary saved to report.txt" << endl << endl;
}

void NutritionTracker::programEndMessage()
{
    cout << "* -- ";

    changeConsoleColor("\x1b[1;38;5;73;49m");
    cout << "Thank you for using Nutrition Tracker!";
    changeConsoleColor("\x1b[0m");

    cout << " -- *" << endl << endl;
}
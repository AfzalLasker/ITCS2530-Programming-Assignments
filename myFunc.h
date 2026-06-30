#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "myFunc.h"

using namespace std;

void displayBanner()
{
    // Greeting
    cout << endl;
    cout << "======================================================================" << endl;
    cout << "\x1b[1;39;48;5;14m                     Welcome to Nutrition Tracker!                    \x1b[0m" << endl;
    cout << "======================================================================" << endl;
    cout << endl;
    cout << "\x1b[1;38;5;73;49mThis application helps keep track of your daily nutrition information.\x1b[0m" << endl;
    cout << endl << endl;
}


string askUserName()
{
    // Ask user name
    string userName;
    cout << "\x1b[0;38;5;54;49mPlease enter your name:\x1b[0m ";
    getline(cin, userName);

    // Validate that the name is not empty
    while (userName == "")
    {
        cout << "\x1b[1;39;48;5;196mName cannot be empty. Please enter your name:\x1b[0m ";
        getline(cin, userName);
    }

    cout << endl;

    return userName;
}


int mealGoal()
{
    // Variables
    int dailyMealGoal = 0;  // Store the user's daily meal goal

    cout << "-----------------------------" << endl;
    cout << "\x1b[1;38;5;0;48;5;216mLets set some nutration goal!\x1b[0m" << endl;
    cout << "-----------------------------" << endl;

    // Ask user daily meal goal
    cout << "\x1b[0;38;5;54;49mEnter your daily meal goal (number of meals):\x1b[0m ";
    cin >> dailyMealGoal;

    // Validate input to ensure a valid data type and value is entered
    while (cin.fail() || dailyMealGoal < 1 || dailyMealGoal > MAX_MEALS)
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "\x1b[1;39;48;5;196mInvalid input! Enter a meal goal from 1 to " << MAX_MEALS << ".\x1b[0m" << endl << endl;

        // Repeat: Ask user daily meal goal
        cout << "\x1b[0;38;5;54;49mEnter your daily meal goal (number of meals):\x1b[0m ";
        cin >> dailyMealGoal;
    }
    cout << endl;

    return dailyMealGoal;
}


int calorieGoal()
{
    // variable
    int dailyCalorieGoal = 0;   // Store the user's daily calorie goal

    // Ask user daily calorie goal 
    cout << "\x1b[0;38;5;54;49mEnter your daily calorie goal (in calories):\x1b[0m ";
    cin >> dailyCalorieGoal;

    // Validate input to ensure a valid data type is entered
    // while loop
    while (cin.fail() || dailyCalorieGoal < 1)
    {
        cin.clear();               // Clear the error
        cin.ignore(100, '\n');     // remove the invalid input from memory
        cout << "\x1b[1;39;48;5;196mInvalid input! Enter a calorie goal greater than 0.\x1b[0m" << endl << endl;

        // Repeat: Ask user daily calorie goal
        cout << "\x1b[0;38;5;54;49mEnter your daily calorie goal (in calories):\x1b[0m ";
        cin >> dailyCalorieGoal;
    }
    cout << endl;

    return dailyCalorieGoal;
}


string GoalMessage(int dailyMealGoal, double dailyCalorieGoal)
{
    // Variables
    string setGoalMessage;          // Store the goal setting status message
    int MIN_valid_Meals = 1;        // Minimum valid Meal value
    int MIN_valid_Calories = 1;     // Minimum valid calorie value

    // Display message based on whether goals were set or not
    // if/else
    if (dailyMealGoal < MIN_valid_Meals && dailyCalorieGoal < MIN_valid_Calories)
    {
        setGoalMessage = "#  \x1b[1;38;5;54;48;5;10mMeal and calorie goals were not fully set.\x1b[0m";
    }
    else if (dailyMealGoal >= MIN_valid_Meals && dailyCalorieGoal < MIN_valid_Calories)
    {
        setGoalMessage = "#  \x1b[1;38;5;54;48;5;10mMeal goal set but calorie goal not set.\x1b[0m";
    }
    else if (dailyMealGoal < MIN_valid_Meals && dailyCalorieGoal >= MIN_valid_Calories)
    {
        setGoalMessage = "#  \x1b[1;38;5;54;48;5;10mCalorie goal set but meal goal not set.\x1b[0m";
    }
    else
    {
        setGoalMessage = "# \x1b[1;38;5;54;48;5;10mMeal and calorie goals set successfully.\x1b[0m";
    }

    // Display the goal setting message
    cout << setGoalMessage << endl << endl;

    return setGoalMessage;
}


int dailyMeals(int maxMeals)
{
    // Variables
    int totalMeals = 0;     // Store the total meals eaten today

    cout << "----------------------------" << endl;
    cout << "\x1b[1;38;5;0;48;5;216mNow let's see your progress!\x1b[0m" << endl;
    cout << "----------------------------" << endl;

    // Ask the user for the number of meals eaten today
    cout << "\x1b[0;38;5;54;49mEnter the number of meals you ate today (1-" << maxMeals << "):\x1b[0m ";
    cin >> totalMeals;

    // Validate input to ensure a valid data type and range is entered
    // while loop
    while (cin.fail() || totalMeals < 1 || totalMeals > maxMeals)
    {
        cin.clear();               // Clear the error
        cin.ignore(100, '\n');     // remove the invalid input from memory
        cout << "\x1b[1;39;48;5;196mInvalid input! Enter a number from 1 to " << maxMeals << ".\x1b[0m" << endl << endl;

        // Prompt the user again until valid input is provided
        cout << "\x1b[0;38;5;54;49mEnter the number of meals you ate today (1-" << maxMeals << "):\x1b[0m ";
        cin >> totalMeals;
    }
    cout << endl;

    return totalMeals;
}


double calorieIntake(int totalMeals, string mealNames[], double mealCalories[])
{
    // Variables
    double todayCalories_totalSum = 0;      // Store the total calories consumed today
    int MIN_valid_Meals = 1;

    // Clear the newline before using getline for meal names
    cin.ignore(100, '\n');

    // Collect meal name and calorie intake for each meal
    // for loop with arrays
    for (int i = 0; i < totalMeals; i++)
    {
        cout << "*   \x1b[1;38;5;167;49mEnter the name for meal \x1b[0m" << (i + 1) << "\x1b[1;38;5;167;49m:\x1b[0m   ";
        getline(cin, mealNames[i]);

        // Validate meal name so the array does not store an empty string
        while (mealNames[i] == "")
        {
            cout << "    \x1b[1;39;48;5;196mInvalid input! Meal name cannot be empty.\x1b[0m" << endl << endl;
            cout << "*   \x1b[1;38;5;167;49mEnter the name for meal \x1b[0m" << (i + 1) << "\x1b[1;38;5;167;49m:\x1b[0m   ";
            getline(cin, mealNames[i]);
        }

        cout << "*   \x1b[1;38;5;167;49mEnter the calories consumed for \x1b[0m" << mealNames[i] << "\x1b[1;38;5;167;49m:\x1b[0m   ";
        cin >> mealCalories[i];

        // while loop validates every calorie value before it is added into the array total
        while (cin.fail() || mealCalories[i] < 0)
        {
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "    \x1b[1;39;48;5;196mInvalid input! Please enter a positive number.\x1b[0m" << endl << endl;

            // Repeat: Ask user calorie intake for each meal
            cout << "*   \x1b[1;38;5;167;49mEnter the calories consumed for \x1b[0m" << mealNames[i] << "\x1b[1;38;5;167;49m:\x1b[0m   ";
            cin >> mealCalories[i];
        }

        // Each array element is assigned above, then added into the total
        todayCalories_totalSum += mealCalories[i];
        cin.ignore(100, '\n');
    }
    cout << endl;

    // Calculate and display total calorie intake if meals were recorded
    // if/else
    if (totalMeals >= MIN_valid_Meals)
    {
        cout << "\x1b[1;38;5;167;49mYour today calorie total is\x1b[0m " << todayCalories_totalSum << endl;
    }
    else
    {
        cout << "\x1b[1;38;5;54;48;5;10mNo meals today, no calories to track!\x1b[0m" << endl << endl;
    }

    return todayCalories_totalSum;
}


double celculateCalorieAverage(double todayCalories_totalSum, int totalMeals)
{
    // Calculate average calories per meal
    double averageCalories = 0;

    if (totalMeals > 0)
    {
        averageCalories = todayCalories_totalSum / totalMeals;
    }
    cout << endl;

    return averageCalories;
}


string confirmationMassege(int totalMeals, double todayCalories_totalSum)
{
    // Variable
    string dataMessage;
    int MIN_valid_Meals = 1;
    int MIN_valid_Calories = 1;

    // Show messages whether any information was recorded or not
    //if/else
    if (totalMeals >= MIN_valid_Meals && todayCalories_totalSum >= MIN_valid_Calories)
    {
        dataMessage = "#  \x1b[1;38;5;54;48;5;10mToday's nutrition information recorded successfully.\x1b[0m";
    }
    else if (totalMeals >= MIN_valid_Meals && todayCalories_totalSum < MIN_valid_Calories)
    {
        dataMessage = "#  \x1b[1;38;5;54;48;5;10mToday's meals recorded but no calorie intake recorded today.\x1b[0m";
    }
    else if (totalMeals < MIN_valid_Meals && todayCalories_totalSum >= MIN_valid_Calories)
    {
        dataMessage = "#  \x1b[1;38;5;54;48;5;10mToday's calorie intake recorded but no meals recorded today.\x1b[0m";
    }
    else
    {
        dataMessage = "";
    }
    cout << endl;

    // Display the data message
    cout << dataMessage << endl << endl;

    return dataMessage;
}


GoalStatus getGoalStatus(double goalValue, double actualValue)
{
    // This enum function is used in decision structures for Week 6.
    if (actualValue < goalValue)
    {
        return UnderGoal;
    }
    else if (actualValue > goalValue)
    {
        return OverGoal;
    }
    else
    {
        return MetGoal;
    }
}


string goalStatusText(GoalStatus status)
{
    // Convert enum value into a readable word using switch
    string statusText;

    switch (status)
    {
        case UnderGoal:
            statusText = "Under Goal";
            break;
        case MetGoal:
            statusText = "Met Goal";
            break;
        case OverGoal:
            statusText = "Over Goal";
            break;
        default:
            statusText = "Unknown";
            break;
    }

    return statusText;
}


string calorieStatus(double dailyCalorieGoal, double todayCalories_totalSum)
{
    // Variables
    string calorieMessage;
    int MIN_valid_Calories = 1;
    GoalStatus calorieGoalStatus;

    // Assess calorie status based on the calorie goal and intake
    // if/else and enum decision structure
    if (dailyCalorieGoal >= MIN_valid_Calories && todayCalories_totalSum >= MIN_valid_Calories)
    {
        calorieGoalStatus = getGoalStatus(dailyCalorieGoal, todayCalories_totalSum);

        switch (calorieGoalStatus)
        {
            case UnderGoal:
                calorieMessage = "#  You are under your calorie goal for the day. Status: " + goalStatusText(calorieGoalStatus);
                break;
            case OverGoal:
                calorieMessage = "#  You are over your calorie goal for the day. Status: " + goalStatusText(calorieGoalStatus);
                break;
            case MetGoal:
                calorieMessage = "#  You have met your calorie goal for the day. Status: " + goalStatusText(calorieGoalStatus);
                break;
        }
    }
    else
    {
        calorieMessage = "#  Calorie goal or intake not fully recorded, cannot assess calorie status!";
    }

    return calorieMessage;
}


string mealStatus(int dailyMealGoal, int totalMeals)
{
    // Variables
    string nutritionMessage;
    int MIN_valid_Meals = 1;
    GoalStatus mealGoalStatus;

    // Display appropriate message based on the meal goal and meals eaten
    // if/else and enum decision structure
    if (dailyMealGoal >= MIN_valid_Meals && totalMeals >= MIN_valid_Meals)
    {
        mealGoalStatus = getGoalStatus(dailyMealGoal, totalMeals);

        switch (mealGoalStatus)
        {
            case UnderGoal:
                nutritionMessage = "#  You are under your meal goal for the day. Status: " + goalStatusText(mealGoalStatus);
                break;
            case OverGoal:
                nutritionMessage = "#  You are over your meal goal for the day. Status: " + goalStatusText(mealGoalStatus);
                break;
            case MetGoal:
                nutritionMessage = "#  You have met your meal goal for the day. Status: " + goalStatusText(mealGoalStatus);
                break;
        }
    }
    else
    {
        nutritionMessage = "#  \x1b[1;38;5;54;48;5;10mMeal goal or meals eaten not fully recorded, cannot assess meal status!";
    }

    return nutritionMessage;
}


void switchManu(string calorieMessage, string nutritionMessage, int totalMeals, string mealNames[], double mealCalories[])
{
    // Display a simple menu using switch to select specific nutrition information
    // do-while loop, if/else, switch
    int choice = 0;

    do
    {
        cout << "\x1b[0;38;5;54;49mMenu:\x1b[0m\n";
        cout << "1. \x1b[0;38;5;54;49mView calorie status\x1b[0m" << endl;
        cout << "2. \x1b[0;38;5;54;49mView meal status\x1b[0m" << endl;
        cout << "3. \x1b[0;38;5;54;49mView meal calorie list\x1b[0m" << endl;
        cout << "4. \x1b[0;38;5;54;49mQuit\x1b[0m" << endl << endl;
        cout << "\x1b[0;38;5;54;49mEnter your menu choice (1-4):\x1b[0m ";
        cin >> choice;
        cout << endl;

        if (cin.fail())             // Validate input to ensure a valid data type is entered
        {
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "\x1b[1;39;48;5;196mInvalid input! Please enter a number between 1 and 4\x1b[0m" << endl << endl;
        }
        else if (choice < 1 || choice > 4)
        {
            cout << "\x1b[1;39;48;5;196mInvalid menu choice! Please enter 1, 2, 3, or 4.\x1b[0m" << endl << endl;
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
                    displayMealList(totalMeals, mealNames, mealCalories);
                    break;
                case 4:
                    cout << "Exiting menu..." << endl << endl;
                    break;
            }
        }
    }
    while (choice != 4);
    cout << endl;
}


void displayMealList(int totalMeals, string mealNames[], double mealCalories[])
{
    // Display the arrays in a formatted table
    cout << "\x1b[1;38;5;0;48;5;216m--------------- Meal Calorie List ----------------\x1b[0m" << endl;
    cout << endl;
    cout << left << setw(25) << "Meal Name" << right << setw(15) << "Calories" << endl;
    cout << "----------------------------------------" << endl;

    // for loop displays each array element
    for (int i = 0; i < totalMeals; i++)
    {
        cout << left << setw(25) << mealNames[i]
             << right << setw(15) << fixed << setprecision(2) << mealCalories[i] << endl;
    }
    cout << endl;
}


void displaySummary(string userName, int dailyMealGoal, double dailyCalorieGoal, int totalMeals, double todayCalories_totalSum, double averageCalories, string calorieMessage, string nutritionMessage, string mealNames[], double mealCalories[])
{
    // Display nutrition summary

    cout << "\x1b[1;38;5;0;48;5;216m--------------- Nutrition Summary ----------------\x1b[0m" << endl;
    cout << endl;

    cout << left << setw(30) << "User Name: " << right << setw(20) << userName << endl << endl;
    cout << left << setw(30) << "Daily Meal Goal: " << right << setw(20) << dailyMealGoal << endl;
    cout << left << setw(30) << "Daily Calorie Goal: " << right << setw(20) << dailyCalorieGoal << endl;
    cout << endl;
    cout << left << setw(30) << "Meals Eaten Today: " << right << setw(20) << totalMeals << endl;
    cout << left << setw(30) << "Today's Calorie Intake: " << right << setw(20) << todayCalories_totalSum << endl;
    cout << left << setw(30) << "Average Calories Per Meal: " << right << setw(20) << fixed << setprecision(2) << averageCalories << endl;
    cout << endl;

    cout << "\x1b[1;38;5;0;48;5;216m---------------- Meals Entered -------------------\x1b[0m" << endl;
    cout << left << setw(25) << "Meal Name" << right << setw(15) << "Calories" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < totalMeals; i++)
    {
        cout << left << setw(25) << mealNames[i]
             << right << setw(15) << fixed << setprecision(2) << mealCalories[i] << endl;
    }
    cout << endl;

    cout << "\x1b[1;38;5;0;48;5;216m-------------- Nutrition Assessment --------------\x1b[0m" << endl << endl;
    cout << calorieMessage << endl;
    cout << endl;
    cout << nutritionMessage << endl;
    cout << endl;
}


void createTextFile(string userName, int dailyMealGoal, double dailyCalorieGoal, int totalMeals, double todayCalories_totalSum, double averageCalories, string calorieMessage, string nutritionMessage, string mealNames[], double mealCalories[])
{
    // Variable
    string textFile_1 = "report.txt";     // Text file name

    // Save nutrition summary to file
    ofstream report(textFile_1);

    report << "==================================================" << endl;
    report << "               Nutrition Summary                  " << endl;
    report << "==================================================" << endl;
    report << left << setw(30) << "User Name: " << right << setw(20) << userName << endl << endl;
    report << left << setw(30) << "Daily Meal Goal: " << right << setw(20) << dailyMealGoal << endl;
    report << left << setw(30) << "Daily Calorie Goal: " << right << setw(20) << dailyCalorieGoal << endl;
    report << endl;
    report << left << setw(30) << "Meals Eaten Today: " << right << setw(20) << totalMeals << endl;
    report << left << setw(30) << "Today's Calorie Intake: " << right << setw(20) << todayCalories_totalSum << endl;
    report << left << setw(30) << "Average Calories Per Meal: " << right << setw(20) << fixed << setprecision(2) << averageCalories << endl;
    report << endl;

    report << "---------------- Meals Entered -------------------" << endl;
    report << left << setw(25) << "Meal Name" << right << setw(15) << "Calories" << endl;
    report << "----------------------------------------" << endl;

    for (int i = 0; i < totalMeals; i++)
    {
        report << left << setw(25) << mealNames[i]
               << right << setw(15) << fixed << setprecision(2) << mealCalories[i] << endl;
    }
    report << endl;

    report << "-------------- Nutrition Assessment --------------" << endl;
    report << calorieMessage << endl;
    report << nutritionMessage << endl;
    report.close();

    // Notify user that the report has been saved
    cout << "Nutrition summary saved to report.txt" << endl;
    cout << endl;
}


void programEndMessage()
{
    // Program ending message
    cout << "* -- \x1b[1;38;5;73;49mThank you for using Nutrition Tracker! \x1b[0m -- *" << endl;
    cout << endl << endl;
}

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

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
    cout << "\x1b[0;38;5;54;49mPleas enter your name:\x1b[0m ";
    getline(cin, userName);
    cout << endl;

    return userName;
}


int mealGoal()
{
    // Veriables
    int dailyMealGoal = 0;  // Store the user's daily meal goal


    cout << "-----------------------------" << endl;
    cout << "\x1b[1;38;5;0;48;5;216mLets set some nutration goal!\x1b[0m" << endl;
    cout << "-----------------------------" << endl;

    // Ask user daily meal goal
    cout << "\x1b[0;38;5;54;49mEnter your daily meal goal (number of meals):\x1b[0m ";
    cin >> dailyMealGoal;
    // Validate input to ensure a valid data type is entered
    while (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "\x1b[1;39;48;5;196mInvalid input!\x1b[0m" << endl << endl;

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
    while (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();               // Clear the error
        cin.ignore(100, '\n');     // remove the invalid input from memory
        cout << "\x1b[1;39;48;5;196mInvalid input!\x1b[0m" << endl << endl;

        // Repeat: Ask user daily calorie goal
        cout << "\x1b[0;38;5;54;49mEnter your daily calorie goal (in calories):\x1b[0m ";
        cin >> dailyCalorieGoal;
    }
    cout << endl; 

    return dailyCalorieGoal;
}



string GoalMessage(int dailyMealGoal, double dailyCalorieGoal)
{
    // Veriables
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


int dailyMeals()
{
    // Veriables
    int totalMeals = 0;     // Store the total meals eaten today


    cout << "----------------------------" << endl; 
    cout << "\x1b[1;38;5;0;48;5;216mNow let's see your progress!\x1b[0m" << endl;
    cout << "----------------------------" << endl; 

    // Ask the user for the number of meals eaten today
    cout << "\x1b[0;38;5;54;49mEnter the number of meals you ate today:\x1b[0m ";
    cin >> totalMeals;
    // Validate input to ensure a valid data type is entered
    //while loop
    while (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();               // Clear the error
        cin.ignore(100, '\n');     // remove the invalid input from memory
        cout << "\x1b[1;39;48;5;196mInvalid input!\x1b[0m" << endl << endl;

        // Prompt the user again until valid input is provided
        cout << "\x1b[0;38;5;54;49mEnter the number of meals you ate today:\x1b[0m ";
        cin >> totalMeals;
    }
    cout << endl;

    return totalMeals;
}






double calorieIntake(int totalMeals)
{

    // Veriables
    double caloriePerMeals;
    double todayCalories_totalSum;
    int MIN_valid_Meals = 1;

    // Collect calorie intake for each meal
    //for loop
    int i;
    for (i = 1; i <= totalMeals; i++)
    {
        cout << "*   \x1b[1;38;5;167;49mEnter the calories consumed for meal \x1b[0m" << i << "\x1b[1;38;5;167;49m:\x1b[0m   ";
        cin >> caloriePerMeals;
        //while loop
        while (cin.fail())          // Check if user entered the wrong input type
        {
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "    \x1b[1;39;48;5;196mInvalid input! Pleas inter a number\x1b[0m" << endl << endl;

            // Repeat: Ask user calorie intake for each meal
            cout << "*   \x1b[1;38;5;167;49mEnter the calories consumed for meal \x1b[0m" << i << "\x1b[1;38;5;167;49m:\x1b[0m   ";
            cin >> caloriePerMeals;
        }
        todayCalories_totalSum += caloriePerMeals;
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
    double averageCalories;
    averageCalories = todayCalories_totalSum / totalMeals;
    cout << endl;

    return averageCalories;
}



string confirmationMassege(int totalMeals, double todayCalories_totalSum)
{
    // Veriable
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


string calorieStatus(double dailyCalorieGoal, double todayCalories_totalSum)
{
    // Veriables
    string calorieMessage;
    int MIN_valid_Calories = 1;

    // Assess calorie status based on the calorie goal and intake
    //if/else
    if (dailyCalorieGoal >= MIN_valid_Calories && todayCalories_totalSum >= MIN_valid_Calories)
    {
        if (todayCalories_totalSum < dailyCalorieGoal)
        {             
            calorieMessage = "#  You are under your calorie goal for the day.";
        }
        else if (todayCalories_totalSum > dailyCalorieGoal)
        {             
            calorieMessage = "#  You are over your calorie goal for the day.";
        }
        else        
        {             
            calorieMessage = "#  You have met your calorie goal for the day.";
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
    // Veriables
    string nutritionMessage;
    int MIN_valid_Meals = 1;

    //Dispplay appropriate message based on the meal goal and meals eaten
    //if/else
    if (dailyMealGoal >= MIN_valid_Meals && totalMeals >= MIN_valid_Meals)
    {
        if (totalMeals < dailyMealGoal)
        {
            nutritionMessage = "#  You are under your meal goal for the day.";
        }
        else if (totalMeals > dailyMealGoal)
        {
            nutritionMessage = "#  You are over your meal goal for the day.";
        }
        else        {
            nutritionMessage = "#  You have met your meal goal for the day.";
        }
    }
    else    {
        nutritionMessage = "#  \x1b[1;38;5;54;48;5;10mMeal goal or meals eaten not fully recorded, cannot assess meal status!";
    }
    
    return nutritionMessage;
}


void switchManu(string calorieMessage, string nutritionMessage)
{
    // Display a simple menu using switch to select specific nutrition information
    //do-while loop, if/else, switch
    int choice;
    do
    {
        cout << "\x1b[0;38;5;54;49mMenu:\x1b[0m\n";
        cout << "1. \x1b[0;38;5;54;49mView calorie status\x1b[0m" << endl;
        cout << "2. \x1b[0;38;5;54;49mView meal status\x1b[0m" << endl;
        cout << "3. \x1b[0;38;5;54;49mQuit\x1b[0m" << endl << endl;
        cout << "\x1b[0;38;5;54;49mEnter your menu choice (1-3):\x1b[0m ";
        cin >> choice;
        cout << endl;

        if (cin.fail())             // Validate input to ensure a valid data type is entered
        {        
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "\x1b[1;39;48;5;196mInvalid input! Please enter a number between 1 and 3\x1b[0m" << endl << endl;
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
            }
        }   
    }
    while (choice != 3);
    cout << endl;
}



void displaySummary(string userName, int dailyMealGoal, double dailyCalorieGoal, int totalMeals, double todayCalories_totalSum, double averageCalories, string calorieMessage, string nutritionMessage)
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

    cout << "\x1b[1;38;5;0;48;5;216m-------------- Nutrition Assessment --------------\x1b[0m" << endl << endl;
    cout << calorieMessage << endl;
    cout << endl;
    cout << nutritionMessage << endl;
    cout << endl;
}



void createTextFile(string userName, int dailyMealGoal, double dailyCalorieGoal, int totalMeals, double todayCalories_totalSum, double averageCalories, string calorieMessage, string nutritionMessage)
{
    // Veriable
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
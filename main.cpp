// Nutrition Tracker Application
// Afzal Lasker

// Week 4 Programming Assignment

// This program collects daily nutrition information from the user,
// including meal goals, meals eaten, and calorie intake.
// The program calculates total and average calorie intake,
// evaluates whether nutrition goals were met,
// and displays a formatted nutrition summary.


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // Declare variables
    string userName;                // Store the user's name

    int dailyMealGoal = 0;          // Store the user's daily meal goal
    double calorieGoal = 0;         // Store the user's daily calorie goal

    int totalMeals = 0;             // Store the total meals eaten today
    double caloriePerMeals;         // Store calories consumed per meal
    double todayCalories = 0;       // Store the total calories consumed today

    double averageCalories = 0;     // Store the average calories per meal

    string setGoalMessage;          // Store the goal setting status message
    string calorieMessage;          // Store the calorie assessment message
    string dataMessage;             // Store the data recording status message
    string nutritionMessage;        // Store the meal goal assessment message

    const double MIN_valid_Calories = 1;    // Minimum valid calorie value
    const int MIN_valid_Meals = 1;          // Minimum valid meal value

    string textFile_1 = "report.txt";     // Text file name



    // Greeting
    cout << endl;
    cout << "======================================================================" << endl;
    cout << "                     Welcome to Nutrition Tracker!                    " << endl;
    cout << "======================================================================" << endl;
    cout << endl;
    cout << "This application helps keep track of your daily nutrition information." << endl;
    cout << endl << endl;



    // Ask user name
    cout << "Pleas enter your name: ";
    getline(cin, userName);
    cout << endl;



    
    cout << "------------------------------" << endl;
    cout << "Let's set some nutration goal!" << endl;
    cout << "------------------------------" << endl;

    // Ask user daily meal goal
    cout << "Enter your daily meal goal (number of meals): ";
    cin >> dailyMealGoal;
    // Validate input to ensure a valid data type is entered
    while (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;

        // Repeat: Ask user daily meal goal
        cout << "Enter your daily meal goal: ";
        cin >> dailyMealGoal;
    }
    cout << endl;



    // Ask user daily calorie goal 
    cout << "Enter your daily calorie goal (in calories): ";
    cin >> calorieGoal;
    // Validate input to ensure a valid data type is entered
    // while loop
    while (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();               // Clear the error
        cin.ignore(100, '\n');     // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;

        // Repeat: Ask user daily calorie goal
        cout << "Enter your daily calorie goal (in calories): ";
        cin >> calorieGoal;
    }
    cout << endl; 



    // Display message based on whether goals were set or not
    // if/else
    if (dailyMealGoal < MIN_valid_Meals && calorieGoal < MIN_valid_Calories)
    {
        setGoalMessage = "#  Meal and calorie goals were not fully set.";
    }
    else if (dailyMealGoal >= MIN_valid_Meals && calorieGoal < MIN_valid_Calories)
    {
        setGoalMessage = "#  Meal goal set but calorie goal not set.";
    }
    else if (dailyMealGoal < MIN_valid_Meals && calorieGoal >= MIN_valid_Calories)
    {
        setGoalMessage = "#  Calorie goal set but meal goal not set.";
    }
    else
    {
        setGoalMessage = "# Meal and calorie goals set successfully.";
    }
    // Display the goal setting message
    cout << setGoalMessage << endl << endl;



    cout << "----------------------------" << endl; 
    cout << "Now let's see your progress!" << endl;
    cout << "----------------------------" << endl; 

    // Ask the user for the number of meals eaten today
    cout << "Enter the number of meals you ate today: ";
    cin >> totalMeals;
    // Validate input to ensure a valid data type is entered
    //while loop
    while (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();               // Clear the error
        cin.ignore(100, '\n');     // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;

        // Prompt the user again until valid input is provided
        cout << "Enter the number of meals you ate today: ";
        cin >> totalMeals;
    }
    cout << endl;

    

    // Collect calorie intake for each meal
    //for loop
    int i;
    for (i = 1; i <= totalMeals; i++)
    {
        cout << "*   Enter the calories consumed for meal " << i << ":   ";
        cin >> caloriePerMeals;
        //while loop
        while (cin.fail())          // Check if user entered the wrong input type
        {
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "    Invalid input! Pleas inter a number" << endl << endl;

            // Repeat: Ask user calorie intake for each meal
            cout << "*   Enter the calories consumed for meal " << i << ":   ";
            cin >> caloriePerMeals;
        }
        todayCalories += caloriePerMeals;
    }
    cout << endl;


    // Calculate and display total calorie intake if meals were recorded
    // if/else
    if (totalMeals >= MIN_valid_Meals)
    {
    cout << "Your today calorie total is " << todayCalories << endl;
    }
    else
    {
        cout << "No meals today, no calories to track!" << endl << endl;
    }



    // Calculate average calories per meal
    averageCalories = todayCalories / totalMeals;
    cout << endl;
 


    // Show messages whether any information was recorded or not
    //if/else
    if (totalMeals >= MIN_valid_Meals && todayCalories >= MIN_valid_Calories)
    {
        dataMessage = "#  Today's nutrition information recorded successfully.";
    }
    else if (totalMeals >= MIN_valid_Meals && todayCalories < MIN_valid_Calories)
    {
        dataMessage = "#  Today's meals recorded but no calorie intake recorded today.";
    }
    else if (totalMeals < MIN_valid_Meals && todayCalories >= MIN_valid_Calories)
    {
        dataMessage = "#  Today's calorie intake recorded but no meals recorded today.";
    }
    else
    {
        dataMessage = "";
    }
    cout << endl;
    // Display the data message
    cout << dataMessage << endl << endl;



    // Assess calorie status based on the calorie goal and intake
    //if/else
    if (calorieGoal >= MIN_valid_Calories && todayCalories >= MIN_valid_Calories)
    {
        if (todayCalories < calorieGoal)
        {             
            calorieMessage = "#  You are under your calorie goal for the day.";
        }
        else if (todayCalories > calorieGoal)
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
        nutritionMessage = "#  Meal goal or meals eaten not fully recorded, cannot assess meal status!";
    }   



    // Display a simple menu using switch to select specific nutrition information
    //do-while loop, if/else, switch
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. View calorie status" << endl;
        cout << "2. View meal status" << endl;
        cout << "3. Quit" << endl << endl;
        cout << "Enter your menu choice (1-3): ";
        cin >> choice;
        cout << endl;

        if (cin.fail())             // Validate input to ensure a valid data type is entered
        {        
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "Invalid input! Please enter a number between 1 and 3" << endl << endl;
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



    // Display nutrition summary

    cout << "--------------- Nutrition Summary ----------------" << endl;
    cout << endl;

    cout << left << setw(30) << "User Name: " << right << setw(20) << userName << endl << endl;
    cout << left << setw(30) << "Daily Meal Goal: " << right << setw(20) << dailyMealGoal << endl;
    cout << left << setw(30) << "Daily Calorie Goal: " << right << setw(20) << calorieGoal << endl;
    cout << endl;
    cout << left << setw(30) << "Meals Eaten Today: " << right << setw(20) << totalMeals << endl;
    cout << left << setw(30) << "Today's Calorie Intake: " << right << setw(20) << todayCalories << endl;
    cout << left << setw(30) << "Average Calories Per Meal: " << right << setw(20) << fixed << setprecision(2) << averageCalories << endl;
    cout << endl;

    cout << "-------------- Nutrition Assessment --------------" << endl;
    cout << calorieMessage << endl;
    cout << nutritionMessage << endl;
    cout << endl;


    
    // Save nutrition summary to file
    ofstream report(textFile_1);

    report << "==================================================" << endl;
    report << "               Nutrition Summary                  " << endl;
    report << "==================================================" << endl;
    report << left << setw(30) << "User Name: " << right << setw(20) << userName << endl << endl;
    report << left << setw(30) << "Daily Meal Goal: " << right << setw(20) << dailyMealGoal << endl;
    report << left << setw(30) << "Daily Calorie Goal: " << right << setw(20) << calorieGoal << endl;
    report << endl;
    report << left << setw(30) << "Meals Eaten Today: " << right << setw(20) << totalMeals << endl;
    report << left << setw(30) << "Today's Calorie Intake: " << right << setw(20) << todayCalories << endl;
    report << left << setw(30) << "Average Calories Per Meal: " << right << setw(20) << fixed << setprecision(2) << averageCalories << endl;
    report << endl;

    report << "-------------- Nutrition Assessment --------------" << endl;
    report << calorieMessage << endl;
    report << nutritionMessage << endl;
    report.close();

    // Notify user that the report has been saved
    cout << "Nutrition summary saved to report.txt" << endl;

    // Program ending message
    cout << "*--- Thank you for using Nutrition Tracker! ---*" << endl;
    cout << endl << endl;



    return 0;
}
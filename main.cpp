// Nutrition Tracker Application
// Afzal Lasker

// This program collects daily nutrition information from the user
// including name, date, meals eaten, and calorie intake.
// The program then displays a formatted nutrition summary as output.



#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // Declare variables
    string userName;
    int dailyMealGoal = 0;
    double calorieGoal = 0;
    int totalMeals = 0;
    double todayCalories = 0;
    double averageCalories = 0;
    string setGoalMessage;
    string calorieMessage;
    string dataMessage;
    string nutritionMessage;

    const double MIN_VALID_CALORIES = 1;
    const int MIN_VALID_MEALS = 1;



    // Greeting
    cout << "Welcome to Nutrition Tracker!" << endl;
    cout << "This application helps keep track of your daily nutrition information." << endl;
    cout << endl;



    // Ask user information
    cout << "Enter your name: ";
    getline(cin, userName);
    cout << endl;



    // Ask user daily meal goal
    cout << "Enter your daily meal goal: ";
    cin >> dailyMealGoal;
    // Input check for wrong data type
    if (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;
    }



    // Ask user daily calorie goal
    cout << "Enter your daily calorie goal: ";
    cin >> calorieGoal;
    // Input check for wrong data type
    if (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;
    }
    cout << endl; 



    // Display message based on whether goals were set or not
    if (dailyMealGoal < MIN_VALID_MEALS && calorieGoal < MIN_VALID_CALORIES)
    {
        setGoalMessage = "Meal and calorie goals were not fully set.";
    }
    else if (dailyMealGoal >= MIN_VALID_MEALS && calorieGoal < MIN_VALID_CALORIES)
    {
        setGoalMessage = "Meal goal set but calorie goal not set.";
    }
    else if (dailyMealGoal < MIN_VALID_MEALS && calorieGoal >= MIN_VALID_CALORIES)
    {
        setGoalMessage = "Calorie goal set but meal goal not set.";
    }
    else
    {
        setGoalMessage = "Meal and calorie goals set successfully.";
    }
    // Display the goal setting message
    cout << setGoalMessage << endl << endl;



    // Ask user for today's meals eaten
    cout << "How many meals did you eat today? ";
    cin >> totalMeals;
    // Input check for wrong data type
    if (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;
    }



    // Ask for calorie intake only if meals were recorded
    if (totalMeals >= MIN_VALID_MEALS)
    {
        cout << "Enter your total calorie intake for today: ";
        cin >> todayCalories;
        // Input check for wrong data type
        if (cin.fail())             // Check if user entered the wrong input type
        {
            cin.clear();            // Clear the error
            cin.ignore(100, '\n');  // remove the invalid input from memory
            cout << "Invalid input!" << endl << endl;
        }
    }
    else
    {
        cout << "No meals today, no calories to track!" << endl << endl;
    }



    // Calculate average calories per meal
    averageCalories = todayCalories / totalMeals;
    cout << endl;
 


    // Show messages whether any information was recorded or not
    if (totalMeals >= MIN_VALID_MEALS && todayCalories >= MIN_VALID_CALORIES)
    {
        dataMessage = "Today's nutrition information recorded successfully.";
    }
    else if (totalMeals >= MIN_VALID_MEALS && todayCalories < MIN_VALID_CALORIES)
    {
        dataMessage = "Today's meals recorded but no calorie intake recorded today.";
    }
    else if (totalMeals < MIN_VALID_MEALS && todayCalories >= MIN_VALID_CALORIES)
    {
        dataMessage = "Today's calorie intake recorded but no meals recorded today.";
    }
    else
    {
        dataMessage = "";
    }
    cout << endl;
    // Display the data message
    cout << dataMessage << endl << endl;



    // Assess calorie status based on the calorie goal and intake
    if (calorieGoal >= MIN_VALID_CALORIES && todayCalories >= MIN_VALID_CALORIES)
    {
        if (todayCalories < calorieGoal)
        {             
            calorieMessage = "You are under your calorie goal for the day.";
        }
        else if (todayCalories > calorieGoal)
        {             
            calorieMessage = "You are over your calorie goal for the day.";
        }
        else        
        {             
            calorieMessage = "You have met your calorie goal for the day.";
        }
    }
    else    
    {
        calorieMessage = "Calorie goal or intake not fully recorded, cannot assess calorie status.";
    }



    //Dispplay appropriate message based on the meal goal and meals eaten
    if (dailyMealGoal >= MIN_VALID_MEALS && totalMeals >= MIN_VALID_MEALS)
    {
        if (totalMeals < dailyMealGoal)
        {
            nutritionMessage = "You are under your meal goal for the day.";
        }
        else if (totalMeals > dailyMealGoal)
        {
            nutritionMessage = "You are over your meal goal for the day.";
        }
        else        {
            nutritionMessage = "You have met your meal goal for the day.";
        }
    }
    else    {
        nutritionMessage = "Meal goal or meals eaten not fully recorded, cannot assess meal status.";
    }   



    // Display a simple menu using switch to select specific nutrition information
    int choice;
    cout << "Menu:\n";
    cout << "1. View calorie status" << endl;
    cout << "2. View meal status" << endl;
    cout << "Enter your choice: ";
    cin >> choice;  

    switch (choice)
    {
        case 1:
            cout << calorieMessage << endl << endl;
            break;
        case 2:
            cout << nutritionMessage << endl << endl;
            break;
        default:
            cout <<"Invalid choice."<<endl<<endl;
            break;
    }



    // Display nutrition summary
    cout << "------ Nutrition Summary ------" << endl;
    cout << endl;

    cout << left << setw(30) << "User Name: " << userName << endl << endl;
    cout << left << setw(30) << "Daily Meal Goal: " << dailyMealGoal << endl;
    cout << left << setw(30) << "Daily Calorie Goal: " << calorieGoal << endl;
    cout << endl;
    cout << left << setw(30) << "Meals Eaten Today: " << totalMeals << endl;
    cout << left << setw(30) << "Today's Calorie Intake: " << todayCalories << endl;
    cout << left << setw(30) << "Average Calories Per Meal: " << fixed << setprecision(2) << averageCalories << endl;
    cout << endl;

    cout << "------ Nutrition Assessment ------" << endl;
    cout << calorieMessage << endl;
    cout << nutritionMessage << endl;
    cout << endl;
    // Program ending message
    cout << "Thank you for using Nutrition Tracker!" << endl << endl;


    
    // Save nutrition summary to file
    ofstream report("report.txt");

    report << "------ Nutrition Summary ------" << endl;
    report << left << setw(30) << "User Name: " << userName << endl << endl;
    report << left << setw(30) << "Daily Meal Goal: " << dailyMealGoal << endl;
    report << left << setw(30) << "Daily Calorie Goal: " << calorieGoal << endl;
    report << endl;
    report << left << setw(30) << "Meals Eaten Today: " << totalMeals << endl;
    report << left << setw(30) << "Today's Calorie Intake: " << todayCalories << " calories" << endl;
    report << left << setw(30) << "Average Calories Per Meal: " << fixed << setprecision(2) << averageCalories << " calories" << endl;
    report << endl;

    report << "------ Nutrition Assessment ------" << endl;
    report << calorieMessage << endl;
    report << nutritionMessage << endl;
    report.close();

    // Notify user that the report has been saved
    cout << "Nutrition summary saved to report.txt" << endl << endl;



    return 0;
}
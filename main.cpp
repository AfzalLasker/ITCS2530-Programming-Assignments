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

#include "myFunc.h"

using namespace std;

int main()
{
    // Declare variables
    string userName;                // Store the user's name

    int dailyMealGoal;              // Store the user's daily meal goal
    double dailyCalorieGoal = 0;    // Store the user's daily calorie goal

    int totalMeals = 0;             // Store the total meals eaten today
    double caloriePerMeals;         // Store calories consumed per meal
    double todayCalories_totalSum = 0;       // Store the total calories consumed today

    double averageCalories = 0;     // Store the average calories per meal

    string setGoalMessage;          // Store the goal setting status message
    string calorieMessage;          // Store the calorie assessment message
    string dataMessage;             // Store the data recording status message
    string nutritionMessage;        // Store the meal goal assessment message


    // Function: Greeting
    // Void
    displayBanner();

    // Function: Ask user name
    // Return user name (string)
    userName = askUserName();

    // Function: Ask user daily meal goal
    //Retun meal number (int)
    dailyMealGoal = mealGoal();

    // Function: Ask user daily calorie goal 
    // Return calorie number (double)
    dailyCalorieGoal = calorieGoal();


    // Function: Display message based on whether goals were set or not
    // Return setGoalMessage (string)
    setGoalMessage = GoalMessage(dailyMealGoal, dailyCalorieGoal);


    // Function: Ask the user for the number of meals eaten today
    // Return number of meals (int)
    totalMeals = dailyMeals();


    // Function: Collect calorie intake for each, Calculate
    // Return total calories (double) and display total calorie intake if meals were recorded
    todayCalories_totalSum = calorieIntake(totalMeals);
    

    // Function: Calculate average calories per meal
    // Return average number of calories (double)
    averageCalories = celculateCalorieAverage(todayCalories_totalSum, totalMeals);
 

    // Function: Show messages whether any information was recorded or not
    // Void
    dataMessage = confirmationMassege(totalMeals, todayCalories_totalSum);


    // Function: Assess calorie status based on the calorie goal and intake
    // Void
    calorieMessage = calorieStatus(dailyCalorieGoal, todayCalories_totalSum);


    // Function: Dispplay appropriate message based on the meal goal and meals eaten
    // Return text message (string)
    nutritionMessage = mealStatus(dailyMealGoal, totalMeals);


    // Function: Display a simple menu using switch to select specific nutrition information
    // Void
    switchManu(calorieMessage, nutritionMessage);


    // Function: Display nutrition summary
    // Void
    displaySummary(userName, dailyMealGoal, dailyCalorieGoal, totalMeals, todayCalories_totalSum, averageCalories, calorieMessage, nutritionMessage);


    // Function: Save nutrition summary to file
    // Void
    createTextFile(userName, dailyMealGoal, dailyCalorieGoal, totalMeals, todayCalories_totalSum, averageCalories, calorieMessage, nutritionMessage);



    // Program ending message
    // Void
    programEndMessage();


    return 0;
}
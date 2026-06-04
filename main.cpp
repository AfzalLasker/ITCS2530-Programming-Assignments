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
    int totalMeals;
    int todayCalories;
    double averageCalories;


    // Greeting
    cout << "Welcome to Nutrition Tracker!" << endl;
    cout << "This application helps keep track of your daily nutrition information." << endl;
    cout << endl;


    // Ask user information
    cout << "Enter your name: ";
    getline(cin, userName);


    // Ask for meals eaten
    cout << "How many meals did you eat today? ";
    cin >> totalMeals;
    // Input check for wrong data type
    if (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;
    }


    // Ask for calorie intake
    cout << "Enter your total calorie intake for today: ";
    cin >> todayCalories;
    // Input check for wrong data type
    if (cin.fail())             // Check if user entered the wrong input type
    {
        cin.clear();            // Clear the error
        cin.ignore(100, '\n');  // remove the invalid input from memory
        cout << "Invalid input!" << endl << endl;
    }


    // Calculate average calories per meal
    averageCalories = todayCalories / totalMeals;
    cout << endl;
 

    // Display nutrition summary
    cout << "------ Nutrition Summary ------" << endl;
    cout << endl;

    cout << left << setw(30) << "User Name: " << userName << endl;
    cout << left << setw(30) << "Meals Eaten Today: " << totalMeals << endl;
    cout << left << setw(30) << "Today's Calorie Intake: " << todayCalories << endl;
    cout << left << setw(30) << "Average Calories Per Meal: " << fixed << setprecision(2) << averageCalories << endl;
    cout << endl;

    cout << "Thank you for using Nutrition Tracker!" << endl << endl;

    
    // Save nutrition summary to file
    ofstream report("report.txt");

    report << "------ Nutrition Summary ------" << endl;
    report << left << setw(30) << "User Name: " << userName << endl;
    report << left << setw(30) << "Meals Eaten Today: " << totalMeals << endl;
    report << left << setw(30) << "Today's Calorie Intake: " << todayCalories << " calories" << endl;
    report << left << setw(30) << "Average Calories Per Meal: " << fixed << setprecision(2) << averageCalories << " calories" << endl;
    report.close();

    // Notify user that the report has been saved
    cout << "Nutrition summary saved to report.txt" << endl << endl;


    return 0;
}
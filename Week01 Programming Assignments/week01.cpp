// Nutrition Tracker Application
// Afzal Lasker

// This program collects daily nutrition information from the user
// including name, date, meals eaten, and calorie intake.
// The program then displays a formatted nutrition summary as output.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declare variables
    string userName;
    string currentDate;
    int totalMeals;
    int todayCalories;

    // Greeting
    cout << "Welcome to Nutrition Tracker!" << endl;
    cout << "This application helps keep track of your daily nutrition information." << endl;
    cout << endl;

    // Ask user information
    cout << "Enter your name: ";
    cin >> userName;

    cout << "Enter today's date (MM/DD/YYYY): ";
    cin >> currentDate;

    cout << "How many meals did you eat today? ";
    cin >> totalMeals;

    cout << "Enter your total calorie intake for today: ";
    cin >> todayCalories;

    cout << endl;

    // Display nutrition summary
    cout << "------ Nutrition Summary ------" << endl;

    cout << endl;

    cout << "User Name: " << userName << endl;
    cout << "Date: " << currentDate << endl;
    cout << "Meals Eaten Today: " << totalMeals << endl;
    cout << "Today's Calorie Intake: " << todayCalories << " calories" << endl;

    cout << endl;
    cout << "Thank you for using Nutrition Tracker!" << endl;

    return 0;
}

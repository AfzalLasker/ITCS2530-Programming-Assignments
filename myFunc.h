#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void displayBanner();


string askUserName();


int mealGoal();


int calorieGoal();


string GoalMessage(int dailyMealGoal, double dailyCalorieGoal);


int dailyMeals();


double calorieIntake(int totalMeals);


double celculateCalorieAverage(double todayCalories_totalSum, int totalMeals);


string confirmationMassege(int totalMeals, double todayCalories_totalSum);


string calorieStatus(double dailyCalorieGoal, double todayCalories_totalSum);


string mealStatus(int dailyMealGoal, int totalMeals);


void switchManu(string calorieMessage, string nutritionMessage);


void displaySummary(string userName, int dailyMealGoal, double dailyCalorieGoal, int totalMeals, double todayCalories_totalSum, double averageCalories, string calorieMessage, string nutritionMessage);


void createTextFile(string userName, int dailyMealGoal, double dailyCalorieGoal, int totalMeals, double todayCalories_totalSum, double averageCalories, string calorieMessage, string nutritionMessage);


void programEndMessage();
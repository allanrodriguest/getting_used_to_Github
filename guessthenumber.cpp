/******************************************
------------THE GUESSING GAME--------------
Student: Allan Rodrigues de Santana Torreao
Date: 04/14/2020
*******************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
   cout << "********************************************" << endl;
   cout << "* Welcome to the Guessing Game !!! *" << endl;
   cout << "********************************************" << endl;

   cout << "Select your Difficulty:" << endl;
   cout << "Easy (E) , Normal (N) or Hard (H)" << endl;

   char difficulty;
   cin >> difficulty;

   int number_of_attempts;

   if (difficulty == 'E') {
      number_of_attempts = 15;
   }
   else if (difficulty == 'N') {
      number_of_attempts = 10;
   }
   else {
      number_of_attempts = 5;
   }

   srand(time(NULL));
   const int SECRET_NUMBER = rand() % 100;

   bool wrong = true;
   int attempts = 0;

   double score = 1000.0;

   for (attempts = 1; attempts <= number_of_attempts; attempts++) {
      int shot = 0;

      cout << "Attempt " << attempts << endl;
      cout << "What's your shot? ";
      cin >> shot;

      double points_lost = abs(shot - SECRET_NUMBER) / 2.0;
      score -= points_lost;

      cout << "The number that you typed is: " << shot << endl;
      bool winner = shot == SECRET_NUMBER;
      bool bigger = shot > SECRET_NUMBER;

      if (winner) 
      {
         cout << "Congratulations! You guessed the Secret Number" << endl << endl;
         wrong = false;
         break;
      }
      else if (bigger) 
      {
         cout << "Your shot was bigger than the Secret Number" << endl << endl;
      }
      else {
         cout << "Your shot was lower than the Secret Number" << endl << endl;
      }

   }
   cout << "Good Game! " << endl;
   if (wrong) {
      cout << "You Lost! Please, try again!" << endl;
   }
   else {
      cout << "You've guessed the number in " << attempts << " attempts" << endl;
      cout.precision(2);
      cout << fixed;
      cout << "Your Score was " << score << " points!" << endl;
   }
}
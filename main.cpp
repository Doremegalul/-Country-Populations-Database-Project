#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "library.h"  //reference the struct definitions and function prototypes
using namespace std; 

int main() {
  cout << "Code test?\n";
  const int DECADES = 20; //To able to change, add, or remove country.
  Country countries[DECADES]; //To put the country infomation into an array to display.
  unsigned number_country;
  int size = 0; //To do comparison but not really?
  int user_answer, user_answer_sort, user_answer_remove, user_answer_filter,user_answer_analysis; //For the user response and prevent the user overlap the user response.
  string user_country; //For the user response in what country name.

  if (collect_data(countries, number_country) == false){
  //To make sure the collect data work right without issue.
    cout << "can't process input data properly.";
    return 1;
  }
  
  growth_rate_average_calculation(countries, number_country); //To set up the country average growth rate for future used.
  
  do{
    cout << "Here are the options: [1] Display all data, [2] Sort data, [3] Remove data. [4] Filter data, [5] Analyse data, [6] Quit all data. (Ex. Type 1 to display all data): ";
    cin >> user_answer;
    
    if (user_answer == 1){
      display_all(countries, number_country); //To display the current data
    }

    else if (user_answer == 2){
      cout << "Here are the options for sort data: [1] Sort by the growth rate, [2] Sort by the population. (Ex. Type 1 to sort by the growth rate): ";
      cin >> user_answer_sort;
      
      if (user_answer_sort == 1){
        sorting_growth_rate_country(countries, number_country); //To sort the growth rate based on user response
      }

      else if (user_answer_sort == 2){
        sorting_population_country(countries, number_country); //To sort the growth rate based on user response
      }
    }
    
    else if (user_answer == 3){
      cout << "Which country do you want to remove? [1] Australia, [2] Canada, [3] New Zealand, [4] United Kingdom, [5] United States, [6] Japan, [7] Hong Kong, [8] Ireland, [9] India, [10] Vietnam (Ex, Type 1 to remove some Aussie): ";
      cin >> user_answer_remove;
      if (user_answer_remove > 10){ //If user response higher number.
        cout << "Sorry, we only have 10 countries in total in this project. " << endl;
      }
    
      switch (user_answer_remove){ //To remove the country based on user response pick.
      case 1:
        remove_country(countries, number_country, "Australia");
        break;        
      case 2:
        remove_country(countries, number_country, "Canada");
        break;       
      case 3:
        remove_country(countries, number_country, "New Zealand");
        break;        
      case 4:
        remove_country(countries, number_country, "United_Kingdom");
        break;        
      case 5:
        remove_country(countries, number_country, "United_States");
        break;        
      case 6:
        remove_country(countries, number_country, "Japan");
        break;        
      case 7:
        remove_country(countries, number_country, "Hong_Kong");
        break;
      case 8:
        remove_country(countries, number_country, "Ireland");
        break;
      case 9:
        remove_country(countries, number_country, "India");
        break;
      case 10:
        remove_country(countries, number_country, "Vietnam");
        break;
      }
    }

    else if (user_answer == 4){
      cout << "What percentage of the growth rate do you want to insert? (Ex. Type 20.00 or 20 to see only country with it average growth rate at least 20% or above): ";
      cin >> user_answer_filter;
      filter_growth_rate(countries, number_country, user_answer_filter); //To filter out any country below the user response.
    }

    else if (user_answer == 5){
      cout << "What analysis do you want to choose? [1] Find the country average growth rate, [2] Find the highest growth rate of the country in year (Ex. Type 1 to find the country average growth rate): ";
      cin >> user_answer_analysis;

      if (user_answer_analysis == 1){
        cout << "What country do you find the average growth rate?: ";
        cin >> user_country;
        analysis_within(countries, number_country, user_country); //To find the country average growth rate based on user response.
      }

      else if(user_answer_analysis == 2){
        analysis_mutiple(countries, number_country); //To find the country highest growth rate based on user reponse on year.
      }
    }
  } while (user_answer != 6); //Until the user response 6, then it will continue.
  
  return 0;
 
}


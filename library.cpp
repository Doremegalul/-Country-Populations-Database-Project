#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "library.h"  //reference the struct definitions and function prototypes
using namespace std; 

bool collect_data(Country c[],unsigned& d){
  ifstream input("input.dat");
  if (!input.is_open()){
    cout << "can't open the file\n";
    return false;	//abnormal termination
  }
 
  string url;
  getline(input, url);
  d = 0;

  cout << "Hello, welcome to my final project!" << endl;
  cout << "My final project is about 10 different countries with its popoulation and growth rate. " << endl;
  cout << url << endl; 
  
  while(!input.eof()){ //To continue until there are no more infomation.
    getline(input, c[d].country_name);
    for (int i = 0; i < 7; i++){ //To get all the population of this country into an array.
      input >> c[d].population[i];
    }
    for (int i = 0; i < 7; i++){ //To get all the growth rate of this country into an array.
      input >> c[d].growth_rate[i];
    }
    input.ignore();
    d++;
  }
  input.close();
  return true;
}

void display_all(const Country c[], unsigned d){
//To display all the data or the modified data should the user changed the data already.
  cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
  cout << left << setw(15) << "Country" << setw(15) << "Metric" << setw(13) << "1960" << setw(13) << "1970"<< setw(13) << "1980" << setw(13) << "1990"<< setw(13) << "2000" << setw(13) << "2010"<< setw(13) << "2020" << endl;
  cout << endl;
  for (int j = 0; j < d; j++){ //To go through all 7 countries and its data.
    cout << setw(15) << c[j].country_name << setw(15) << "Population";
    for (int i = 0; i < 7; i++){ //To display the population of this country.
      cout << setw(12) << c[j].population[i] << " ";    
    }
    cout << endl;
    cout << setw(15) << "" << setw(15) << "Growth Rate(%)";
    for (int i = 0; i < 7; i++){ //To go through all 7 countries and its data.
      cout << setw(13) <<c[j].growth_rate[i]; //To display the population of this country.
    }
    cout << endl << endl;
  }
  cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
}

void sorting_growth_rate_country(Country arr[], unsigned d){
//To rearrange the country's populations based on the user request specific year.
  int Q;
  cout << "What year would you like to do? [0] 1960, [1] 1970, [2] 1980, [3] 1990, [4] 2000, [5] 2010, [6] 2020. (Ex. Type 0 to organize 1960): ";
  cin >> Q;
  for (int j = 1; j < d; j++){ //To go through all 7 countries and its data.
    for (int i = j; i > 0 && arr[i - 1].growth_rate[Q] > arr[i].growth_rate[Q]; i --){
      swap(arr[i - 1], arr[i]); //If the country growth rate is lower than, then it would be swap.
    }
  }
}

void sorting_population_country(Country arr[], unsigned d){
//To rearrange the country's populations based on the user request specific year.
  int W;
  cout << "What year would you like to do? [0] 1960, [1] 1970, [2] 1980, [3] 1990, [4] 2000, [5] 2010, [6] 2020. (Ex. Type 0 to organize 1960): ";
  cin >> W;
  for (int j = 1; j < d; j++){ //To go through all 7 countries and its data.
    for (int i = j; i > 0 && arr[i - 1].population[W] > arr[i].population[W]; i --){
      swap(arr[i - 1], arr[i]); //If the country population is lower than, then it would be swap.
    }
  }
}

void remove_country(Country arr[], unsigned& d, string value){
//To remove the country based on the user request specific country.
  int index = 0;
  while (index < d && arr[index].country_name != value){ //If it is not the country the user request. Then, it will would go to the next country.
    index++;
  }
  if (index <= d){ //If it is, then it would move to remove it.
    for (int i = index; i < d - 1; i++){
      arr[i] = arr[i + 1]; 
    }
    d--;
  }
}

void filter_growth_rate(Country arr[], unsigned& d, int value){
//To find which country have the amount needed based on the user request specific growth rate %
  for (int j = 0; j < d; j++){ //To go through all 7 countries and its data.
    if (value >= arr[j].growth_rate_average){ //If the country's growth rate is lower than the user request. Then, it will be remove.
      remove_country(arr, d, arr[j].country_name);
      j--;
   }
  }
}

void analysis_within(Country arr[], unsigned& d, string value){
//To find the average growth rate based on the user request specific country.
  int index = 0;
  while (index < d && arr[index].country_name != value){ //If it is not the country the user request. Then, it will would go to the next country.
    index ++;
  }
  cout << "The average growth rate of " <<arr[index].country_name << "is " <<arr[index].growth_rate_average << "%" << endl;
}


void analysis_mutiple(Country arr[], unsigned& d){
//To find which country have the highest growth rate based on the user request specific year.
  int E;
  double placement_growth_rate = -1.00; //A placeholder for the growth rate.
  string placement_country; //A placeholder for the country
  cout << "What year would you like to do? [0] 1960, [1] 1970, [2] 1980, [3] 1990, [4] 2000, [5] 2010, [6] 2020. (Ex. Type 1 to find the country with it highest growth rate): ";
  cin >> E;
  if (E == 0){ 
    cout << "Sorry, there are no countries that have the highest growth in that year. ";
    return;
  }
  for (int j = 0; j < d; j++){ 
    if (arr[j].growth_rate[E] > placement_growth_rate){ //If the new growth rate from the array is higher than the current growth rate, then it would be replace with the country as well.
      placement_growth_rate = arr[j].growth_rate[E];
      placement_country = arr[j].country_name;
    }
  }  
  cout << "In this year, " << placement_country << " have the higest growth rate of " << placement_growth_rate << "%" << endl;
}

void growth_rate_average_calculation(Country arr[], unsigned& d){
//To calculate all the country average growth rate based on the 7 decade.
  for (int j = 0; j < d; j++){ //To go through all 7 countries and its data.
    for (int i = 0; i < 7; i++){
      arr[j].growth_rate_average += arr[j].growth_rate[i]; //To add up all the current country growth rate in the past 7 decade.
    }
    arr[j].growth_rate_average = arr[j].growth_rate_average / 7.00; //To divide them to find the average.
  }
}



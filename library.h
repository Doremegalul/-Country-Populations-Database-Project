#include <string>
#include <iostream>
using namespace std;

struct Country {
  string country_name;
  int population[7];
  double growth_rate[7];
  double growth_rate_average;
};

bool collect_data(Country c[],unsigned& d);

void display_all(const Country c[],unsigned d);

void sorting_growth_rate_country(Country arr[], unsigned d);
void sorting_population_country(Country arr[], unsigned d);

void remove_country(Country arr[], unsigned& d, string value);

void filter_growth_rate(Country arr[], unsigned& d, int value);

void analysis_within(Country arr[], unsigned& d, string value);
void analysis_mutiple(Country arr[], unsigned& d);

void growth_rate_average_calculation(Country arr[], unsigned& d);
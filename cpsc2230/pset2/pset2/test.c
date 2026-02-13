#define _GNU_SOURCE

// SEE THIS FILE FOR DECLARATIONS AND DOCUMENTATION OF SUGGESTED FUNCTIONS
#include "tsp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "location.h"

city cities[] = {
    {"HVN", {41.26388889, -72.88694444}, 0},
    {"ALB", {42.74916667, -73.80194444}, 1},
    {"MHT", {42.93277778, -71.43583333}, 2},
    {"BDL", {41.93916667, -72.68333333}, 3},
    {"ORH", {42.26722222, -71.87555556}, 4},
    {"PVD", {41.72388889, -71.42833333}, 5},
  };

int main() {
    
    size_t len = 6;
    printf("flags: none\n");

    FILE *in = fopen("ne_6.dat", "r");

    read_file(in, len, cities);

    normalize_start(len, cities);
    normalize_direction(len, cities);

    calculate_total(len, cities);
    double total = calculate_total(len, cities);
    printf("%-10s: %12.2f ", "froggies", total);
    print_tour(len, cities);

}

int read_file(FILE *in, size_t n, city cities[])
{
    char name_buffer[50];
    
    for (int i = 0; i < n; i++) {
        // Read: name (until comma), comma+latitude, comma+longitude
        if (fscanf(in, "%49[^,],%lf,%lf\n", name_buffer, &cities[i].loc.lat, &cities[i].loc.lon) != 3) {
            fprintf(stderr, "Error reading line %d\n", i+1);
            return 1;
        }
        
        // Allocate and copy the name
        cities[i].name = strdup(name_buffer);
        if (cities[i].name == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        
        cities[i].index = i;
    }
    
    return 0;
}

void print_tour(size_t n, city cities[])
{
  if (n == 0)
    {
      return;
    }
  
  fprintf(stdout, "%s", cities[0].name);
  for (size_t i = 1; i < n; i++)
    {
      fprintf(stdout, " %s", cities[i].name);
    }
  fprintf(stdout, " %s\n", cities[0].name);
}




void normalize_start(size_t n, city tour[])
{
  int i = 0;
  while (i < n && tour[i].index != 0){
    i++;
  }
  swap(tour, i, 0);
}

void normalize_direction(size_t n, city tour[])
{
  if (tour[1].index >= tour[n-1].index) {
    swap(tour, 1, n-1);
  }
}

double calculate_total(size_t n, city tour[])
{

  double tot = 0.0;

  for (int i = 0; i < n-1; i++){
    tot += location_distance(&tour[i].loc, &tour[i+1].loc);
    // printf("adding: %f from %s and %s\n",location_distance(&tour[i].loc, &tour[i+1].loc), tour[i].name, tour[i+1].name);
    // printf("total: %f\n\n",tot);
  }
  // add distance from last city back to first
  tot += location_distance(&tour[n-1].loc, &tour[0].loc);
  return tot;
}

void swap(city arr[], size_t i, size_t j)
{
  if (i != j)
    {
      city temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
}
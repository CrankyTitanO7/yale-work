/**
 * tsp.c
 * Builds tours of cities in input according to one of three possible
 * heuristics.  Names of cities are given on the command line along
 * with the heuristics to use and the name of a file containing the
 * locations (latitude, longitude) of the cities.  For example,
 *
 * ./TSP ne_6.dat -given -nearest -insert HVN ALB MHT BDL ORH PVD
 *
 * where ne_6.dat could contain
 *
 * HVN,41.26388889,-72.88694444
 * ALB,42.74916667,-73.80194444
 * MHT,42.93277778,-71.43583333
 * BDL,41.93916667,-72.68333333
 * ORH,42.26722222,-71.87555556
 * PVD,41.72388889,-71.42833333   
 *
 * @author CPSC 223 Staff and you
 * @version 2025.01.31.0
 */

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

size_t length = 6;



int main(int argc, char **argv)
{
  city *cities = malloc(length * sizeof(city));


  // the index on the command line of the origin city
  // TODO: this is hard-coded as if there is always one method
  // after the filename; fix that to account for more than one
  size_t origin = 3;

  while (argv[origin][0] == '-') {
    origin ++;
    if (origin >= argc){
      fprintf(stderr, "Error reading arguments: too many flags, not enough cities\n");
      return(1);
    }
  }

  if (argc-origin < 2) {
    fprintf(stderr, "must be more than 2 cities\n");
    return(1);
  }
  // printf("%d\n", origin);

  // the number of cities on the command line
  size_t num_cities = argc - origin;

  FILE *in = fopen(argv[1], "r");

  // TODO: maybe add some more error checking here
  
  // initialize names and indices of cities in the tour
  // TODO: read coordinates from the file and make this work for any
  // cities on the command line; you will need to do something
  // different to allocate and initialize the array since this assumes
  // there are 6 (HVN ALB MHT BDL ORH PVD), but you can use this to test
  // the algorithms without having to worry about reading input
  // city cities[] = {
  //   {"HVN", {41.26388889, -72.88694444}, 0},
  //   {"ALB", {42.74916667, -73.80194444}, 1},
  //   {"MHT", {42.93277778, -71.43583333}, 2},
  //   {"BDL", {41.93916667, -72.68333333}, 3},
  //   {"ORH", {42.26722222, -71.87555556}, 4},
  //   {"PVD", {41.72388889, -71.42833333}, 5},
  // };

  

  read_file(in, num_cities, cities);

  normalize_start(num_cities, cities);
  normalize_direction(num_cities, cities);

  // iterate over methods requested on command line
  for (size_t a = 2; a < origin; a++)
    {
      if (strcmp(argv[a], "-insert") == 0)
        {
          route_insert(num_cities, cities);
        }
      else if (strcmp(argv[a], "-nearest") == 0)
        {
          route_nearest(num_cities, cities);
        }
      else if (strcmp(argv[a], "-given") == 0)
        {
          // cities[];
        }
      

      double total = calculate_total(num_cities, cities);
      printf("%-10s: %12.2f ", argv[a], total);
      print_tour(num_cities, cities);
    }

  // TODO: there may be other opportunities for error checking!

  fclose(in);
  for (int i = 0; i < num_cities; i++) {
    free(cities[i].name);
  }
  free(cities);
  
  return 0;
}

void route_insert(size_t n, city tour[])
{
  size_t orig;
  size_t dest;
  find_closest_pair(n, tour, &orig, &dest);
  swap(tour, 0, orig);
  swap(tour, 1, dest);

  // print_tour(n, tour);

  size_t cand;
  size_t pt;
  int m;

  for (int i = 2; i < n; i++){
    cand = find_closest_to_tour(n, tour, i);
    pt = find_insertion_point(n, tour, i, cand);
    m = cand;
    while (m != pt) {
      swap(tour, m, m-1);
      m --;
    }
    // print_tour(n, tour);
  }
}

void find_closest_pair(size_t n, city tour[], size_t *best_orig, size_t *best_dest)
{
  size_t origCand = 0;
  size_t destCand = find_closest_city(tour, 0, 1, n);
  double win = location_distance(&tour[origCand].loc, &tour[destCand].loc);
  double cand;

  for (int i = 1; i < n; i++){
    cand = location_distance(&tour[i].loc, &tour[find_closest_city(tour, i, 0, n)].loc);
    if (cand < win) {
      origCand = i;
      win = cand;
      destCand = find_closest_city(tour, i, 0, n);
    }
  }

  *best_orig = origCand;
  *best_dest = destCand;

  // printf("closest pair: %s + %s\n", tour[origCand].name, tour[destCand].name);
}

size_t find_closest_to_tour(size_t n, city tour[], size_t tour_len)
{
  size_t locat = tour_len;
  double win = location_distance(&tour[0].loc, &tour[tour_len].loc);
  double cand;

  for (int i = tour_len; i < n; i++) {
    for (int j = 0; j < tour_len; j ++){
      cand = location_distance(&tour[j].loc, &tour[i].loc);
      if (cand < win) {
        win = cand;
        locat = i;
      }
    }
  }
  // printf("BOO %s\n", tour[locat].name);
  return locat;
}


size_t find_insertion_point(size_t n, city tour[], size_t subtour_len, size_t next)
{
  size_t ans;
  // step 1: swap to end of subtour
  swap(tour, next, subtour_len);

  double winner = calculate_total(subtour_len+1, tour);
  double cand;

  ans = subtour_len;

  int i = (int) subtour_len;

  // step 2: for each swap, determine the total distance

  while (i > 0) {
    swap(tour, i, i-1);
    cand = calculate_total(subtour_len+1, tour);
    if (cand <= winner) {
      winner = cand;
      ans = i-1;
    }
    i --;
  }

  // step 2.5: return to ans position
  while (i < next) {
    swap(tour, i, i+1);
    i++;
  }
  // step 3: return the value
  // printf("inserting at position %ld\n", ans);
  return ans;
}

void route_nearest(size_t n, city tour[])
{
  size_t next;
  for (size_t i = 0; i < n-1; i++) {
    next = find_closest_city(tour, i, i+1, n);
    swap(tour, next, i+1);
  }
}

size_t find_closest_city(city tour[], size_t c, size_t from, size_t to)
{
  int i = from; 

  const location *locA = &tour[c].loc;
  city cityB;

  int dist;

  double win = location_distance(locA, &tour[from].loc);
  int id = from;

  while (i < to){
    if (i != c){
      cityB = tour[i];
      dist = location_distance(locA, &cityB.loc);
      if (dist < win) {
        id = i;
        win = dist;
      }
    }
    i ++;
  }
  return id;
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

// city cities[] = {
//     {"HVN", {41.26388889, -72.88694444}, 0},
//     {"ALB", {42.74916667, -73.80194444}, 1},
//     {"MHT", {42.93277778, -71.43583333}, 2},
//     {"BDL", {41.93916667, -72.68333333}, 3},
//     {"ORH", {42.26722222, -71.87555556}, 4},
//     {"PVD", {41.72388889, -71.42833333}, 5},
//   };

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

        if (i >= length) {
          length *= 2;
          cities = realloc(cities, length * sizeof(cities));
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

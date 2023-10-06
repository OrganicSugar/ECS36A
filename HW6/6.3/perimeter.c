#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct coordinate_struct {
  int x_coordinate;
  int y_coordinate;
} Coordinate;


void findPerimeter (FILE* file, Coordinate* points, int pointCount) {
  int i;
  double x1, x2, y1, y2;
  double distance, perimeter = 0;
  for (i = 0; i < (pointCount - 1); ++i) {
    // Sets all the needed points for distance forumla
    x1 = points[i].x_coordinate;
    x2 = points[i + 1].x_coordinate;
    y1 = points[i].y_coordinate;
    y2 = points[i + 1].y_coordinate;
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));  // Distance Forumla to calculate the distance
    perimeter += distance;  // Adding it to the perimeter
    //printf("The perimeter is %.2f\n", perimeter);
  }
  // Finds the last distance for the last point and the first point
  x1 = points[i].x_coordinate;
  x2 = points[0].x_coordinate;
  y1 = points[i].y_coordinate;
  y2 = points[0].y_coordinate;
  distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  perimeter += distance;
  printf("The perimeter is %.2f\n", perimeter);
}


void readFile (FILE* file) {
  int num;
  int i = 0;
  int pointCount = 0;
  // Reads the file and sets it to the array of structs
  fread(&pointCount, sizeof(int), 1, file);
  Coordinate points[pointCount];
  while(!feof(file)) {
    fread(&num, sizeof(int), 1, file);
    points[i].x_coordinate = num;
    fread(&num, sizeof(int), 1, file);
    points[i].y_coordinate = num;
    i++;
  }
  findPerimeter(file, points, pointCount);
}


int main(int argc, char* argv[]) {
  FILE* file = fopen(argv[1], "rb");
  readFile(file);
  fclose(file);
  return 0;
}

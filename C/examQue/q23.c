#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a hotel
struct Hotel
{
  char name[50];
  char address[100];
  int grade;
  double roomCharge;
  int numberOfRooms;
};

// Function to print hotels of a given grade in order of room charges
void printHotelsByGrade(struct Hotel hotels[], int numHotels, int targetGrade)
{
  // Filter hotels by grade
  struct Hotel filteredHotels[numHotels];
  int numFilteredHotels = 0;
  for (int i = 0; i < numHotels; i++)
  {
    if (hotels[i].grade == targetGrade)
    {
      filteredHotels[numFilteredHotels++] = hotels[i];
    }
  }

  // Sort filtered hotels by room charges using bubble sort
  for (int i = 0; i < numFilteredHotels - 1; i++)
  {
    for (int j = 0; j < numFilteredHotels - i - 1; j++)
    {
      if (filteredHotels[j].roomCharge > filteredHotels[j + 1].roomCharge)
      {
        // Swap hotels
        struct Hotel temp = filteredHotels[j];
        filteredHotels[j] = filteredHotels[j + 1];
        filteredHotels[j + 1] = temp;
      }
    }
  }

  // Print the sorted list of hotels
  printf("Hotels of grade %d in order of room charges:\n", targetGrade);
  for (int i = 0; i < numFilteredHotels; i++)
  {
    printf("Hotel Name: %s\n", filteredHotels[i].name);
    printf("Address: %s\n", filteredHotels[i].address);
    printf("Room Charge: %.2f\n", filteredHotels[i].roomCharge);
    printf("Number of Rooms: %d\n", filteredHotels[i].numberOfRooms);
    printf("\n");
  }
}

int main()
{
  // Example data for hotels
  struct Hotel hotels[] = {
      {"Hotel A", "Address A", 3, 100.0, 50},
      {"Hotel B", "Address B", 2, 80.0, 40},
      {"Hotel C", "Address C", 3, 120.0, 60},
      {"Hotel D", "Address D", 4, 150.0, 70},
      {"Hotel E", "Address E", 3, 90.0, 45}};
  int numHotels = sizeof(hotels) / sizeof(hotels[0]);

  // Print hotels of grade 3 in order of room charges
  printHotelsByGrade(hotels, numHotels, 3);

  return 0;
}

//Perez Marcelo Cristopher - 3CV4
// C++ program to solve fractional Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
	int profit, weight;

	// Constructor
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

// Comparison function to sort Item
// according to profit/weight ratio
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
void fractionalKnapsack(int W, struct Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;
	int peso;
	// Looping through all items
	for (int i = 0; i < N; i++) {
		
		// If adding Item won't overflow,
		// add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			peso=arr[i].weight;
			break;
		}
	}

	// Returning final value
	cout<<"Ganancia: "<<finalvalue<<endl;
	cout<<"Peso: "<<W+peso<<endl;
	
}

// Driver code
int main()
{
	int W = 100;
	Item arr[] = {{ 20, 10 }, { 66, 30 }, { 30, 20 }, { 40, 40 }, { 60, 50 }};
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	fractionalKnapsack(W, arr, N);
	return 0;
}

//El programa funciona correctamente ya que tendriamos que nuestra ganancia maxima esta dada por:
//$164 con un peso maximo de 90kg, el cual no arrebasa el peso maximo del objeto.



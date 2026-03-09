#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float height;
	char weightunit, heightunit;
	float weight;
	cout << " Enter your weight ";
	cin >> weight;
	cout << "Is it (k) kg or (p) pound? ";
	cin >> weightunit;
	if (weightunit == 'p' || weightunit == 'P')
	{
		weight = weight * 0.453592;
		weight = round(weight);
	}
	else if (weightunit == 'k' || weightunit == 'K')
	{

	}
	else
	{
		cout << " Invalid weight unit !";
	}
	cout << " Weight in kg = " << weight << endl;
	cout << " Enter your height " << endl;
	cin >> height;
	cout << "Is it (c) cm or (i) inch? ";
	cin >> heightunit;
	if (heightunit == 'i' || heightunit == 'I')
	{
		height = (height * 2.54) / 100;
	
	}
	else if (heightunit == 'c'|| heightunit == 'C')
	{
		height = height / 100;

	}
	else
	{
		cout << "Invalid height unit " << endl;
	}
	cout << " Height in m = " << height << endl;







}

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    const int SLICES_PER_PIZZA = 8;
    const double TAX_RATE = 0.07;
    const double DELIVERY_RATE = 0.20;

    int people;
    double slicesPerPerson;
    double pizzaCost;

    int pizzasNeeded;
    double pizzaTotal;
    double tax;
    double delivery;
    double totalCost;

    int entries = 0;
    int totalPizzas = 0;
    int maxPeople = 0;
    double maxTotalCost = 0.0;

    char runAgain = 'Y';

    cout << "Welcome to the Pizza Party Calculator!" << endl;

    while (runAgain == 'Y' || runAgain == 'y') {
        cout << endl;
        cout << "Enter number of people, average slices per person, and cost of one pizza: ";
        cin >> people >> slicesPerPerson >> pizzaCost;

        pizzasNeeded = static_cast<int>(ceil((people * slicesPerPerson) / SLICES_PER_PIZZA));

        pizzaTotal = pizzasNeeded * pizzaCost;
        tax = pizzaTotal * TAX_RATE;
        delivery = (pizzaTotal + tax) * DELIVERY_RATE;
        totalCost = pizzaTotal + tax + delivery;

        cout << fixed << setprecision(2);
        cout << endl;
        cout << "Pizzas needed: " << pizzasNeeded << endl;
        cout << "Cost of pizzas: $" << pizzaTotal << endl;
        cout << "Sales tax: $" << tax << endl;
        cout << "Delivery charge: $" << delivery << endl;
        cout << "Total cost: $" << totalCost << endl;

        entries = entries + 1;
        totalPizzas = totalPizzas + pizzasNeeded;

        if (people > maxPeople) {
            maxPeople = people;
        }

        if (totalCost > maxTotalCost) {
            maxTotalCost = totalCost;
        }

        cout << endl;
        cout << "Do you want to enter another party? Y/N: ";
        cin >> runAgain;
    }

    cout << endl;
    cout << "Party Summary" << endl;
    cout << "-------------" << endl;

    cout << "Number of party entries: " << entries << endl;

    cout << fixed << setprecision(1);
    cout << "Average number of pizzas: " << static_cast<double>(totalPizzas) / entries << endl;

    cout << "Maximum number of people: " << maxPeople << endl;

    cout << fixed << setprecision(2);
    cout << "Maximum total cost: $" << maxTotalCost << endl;

    cout << endl;
    cout << "Goodbye!" << endl;

    return 0;
}

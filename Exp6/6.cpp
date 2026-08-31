#include <iostream>
#include <vector>
#include <algorithm>
// Aariv Grover 25/DA/001
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (int i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    if (!(cin >> n)) return 0;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double maxVal = fractionalKnapsack(capacity, items);

    cout << "Maximum value in knapsack: " << maxVal << "\n";

    return 0;
}
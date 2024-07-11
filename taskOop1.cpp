#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Car {
    string name;
    int year;
    double engineVolume;
    double price;
};

struct SortByName {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.name < car2.name;
    }
};

struct SortByYear {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.year < car2.year;
    }
};

struct SortByEngineVolume {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.engineVolume < car2.engineVolume;
    }
};

struct SortByPrice {
    bool operator()(const Car& car1, const Car& car2) const {
        return car1.price < car2.price;
    }
};

struct SearchByName {
    string name;
    SearchByName(const string& name) : name(name) {}

    bool operator()(const Car& car) const {
        return car.name == name;
    }
};

struct SearchByYear {
    int year;
    SearchByYear(int year) : year(year) {}

    bool operator()(const Car& car) const {
        return car.year == year;
    }
};

struct SearchByEngineVolume {
    double engineVolume;
    SearchByEngineVolume(double engineVolume) : engineVolume(engineVolume) {}

    bool operator()(const Car& car) const {
        return car.engineVolume == engineVolume;
    }
};

struct SearchByPrice {
    double price;
    SearchByPrice(double price) : price(price) {}

    bool operator()(const Car& car) const {
        return car.price == price;
    }
};

int main() {
    vector<Car> cars;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a car" << endl;
        cout << "2. Delete a car" << endl;
        cout << "3. Display all cars" << endl;
        cout << "4. Sort cars" << endl;
        cout << "5. Search for a car" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an action: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Car car;
            cout << "Enter the car name: ";
            getline(cin, car.name);
            cout << "Enter the year of manufacture: ";
            cin >> car.year;
            cout << "Enter the engine volume: ";
            cin >> car.engineVolume;
            cout << "Enter the price: ";
            cin >> car.price;
            cars.push_back(car);
            cout << "Car added!" << endl;
            break;
        }
        case 2: {
            if (cars.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }
            cout << "Enter the name of the car to delete: ";
            string name;
            getline(cin, name);
            auto it = find_if(cars.begin(), cars.end(), SearchByName(name));
            if (it != cars.end()) {
                cars.erase(it);
                cout << "Car deleted!" << endl;
            }
            else {
                cout << "Car not found." << endl;
            }
            break;
        }
        case 3: {
            if (cars.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }
            cout << "List of cars:" << endl;
            for (const auto& car : cars) {
                cout << "Name: " << car.name << endl;
                cout << "Year of manufacture: " << car.year << endl;
                cout << "Engine volume: " << car.engineVolume << endl;
                cout << "Price: " << car.price << endl;
                cout << endl;
            }
            break;
        }
        case 4: {
            if (cars.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }
            cout << "1. Sort by name" << endl;
            cout << "2. Sort by year of manufacture" << endl;
            cout << "3. Sort by engine volume" << endl;
            cout << "4. Sort by price" << endl;
            cout << "Choose a parameter for sorting: ";

            int sortChoice;
            cin >> sortChoice;
            cin.ignore();

            switch (sortChoice) {
            case 1:
                sort(cars.begin(), cars.end(), SortByName());
                cout << "Cars sorted by name." << endl;
                break;
            case 2:
                sort(cars.begin(), cars.end(), SortByYear());
                cout << "Cars sorted by year of manufacture." << endl;
                break;
            case 3:
                sort(cars.begin(), cars.end(), SortByEngineVolume());
                cout << "Cars sorted by engine volume." << endl;
                break;
            case 4:
                sort(cars.begin(), cars.end(), SortByPrice());
                cout << "Cars sorted by price." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            break;
        }
        case 5: {
            if (cars.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }
            cout << "1. Search by name" << endl;
            cout << "2. Search by year of manufacture" << endl;
            cout << "3. Search by engine volume" << endl;
            cout << "4. Search by price" << endl;
            cout << "Choose a parameter for searching: ";

            int searchChoice;
            cin >> searchChoice;
            cin.ignore();

            switch (searchChoice) {
            case 1: {
                cout << "Enter the car name: ";
                string name;
                getline(cin, name);
                auto it = find_if(cars.begin(), cars.end(), SearchByName(name));
                if (it != cars.end()) {
                    cout << "Found car:" << endl;
                    cout << "Name: " << it->name << endl;
                    cout << "Year of manufacture: " << it->year << endl;
                    cout << "Engine volume: " << it->engineVolume << endl;
                    cout << "Price: " << it->price << endl;
                }
                else {
                    cout << "Car not found." << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter the year of manufacture: ";
                int year;
                cin >> year;
                auto it = find_if(cars.begin(), cars.end(), SearchByYear(year));
                if (it != cars.end()) {
                    cout << "Found car:" << endl;
                    cout << "Name: " << it->name << endl;
                    cout << "Year of manufacture: " << it->year << endl;
                    cout << "Engine volume: " << it->engineVolume << endl;
                    cout << "Price: " << it->price << endl;
                }
                else {
                    cout << "Car not found." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter the engine volume: ";
                double engineVolume;
                cin >> engineVolume;
                auto it = find_if(cars.begin(), cars.end(), SearchByEngineVolume(engineVolume));
                if (it != cars.end()) {
                    cout << "Found car:" << endl;
                    cout << "Name: " << it->name << endl;
                    cout << "Year of manufacture: " << it->year << endl;
                    cout << "Engine volume: " << it->engineVolume << endl;
                    cout << "Price: " << it->price << endl;
                }
                else {
                    cout << "Car not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter the price: ";
                double price;
                cin >> price;
                auto it = find_if(cars.begin(), cars.end(), SearchByPrice(price));
                if (it != cars.end()) {
                    cout << "Found car:" << endl;
                    cout << "Name: " << it->name << endl;
                    cout << "Year of manufacture: " << it->year << endl;
                    cout << "Engine volume: " << it->engineVolume << endl;
                    cout << "Price: " << it->price << endl;
                }
                else {
                    cout << "Car not found." << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            break;
        }
        case 0:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}
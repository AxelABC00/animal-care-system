#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Animal {
public:
    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void bathe() = 0;
    virtual void status() const = 0;
    virtual void draw() const = 0;
    virtual ~Animal() {} 
};


class Dog : public Animal {
private:
    string name;
    int hunger;
    int happiness;
    int cleanliness;

public:
    Dog(const string& _name) : name(_name), hunger(0), happiness(5), cleanliness(5) {}

    void feed() override {
        hunger -= 3;
        if (hunger < 0) hunger = 0;
        happiness += 2;
        if (happiness > 10) happiness = 10;
        cout << name << " has been fed.\n";
    }

    void play() override {
        hunger += 2;
        if (hunger > 10) hunger = 10;
        happiness += 3;
        if (happiness > 10) happiness = 10;
        cout << name << " is happy playing.\n";
    }

    void bathe() override {
        cleanliness += 4;
        if (cleanliness > 10) cleanliness = 10;
        happiness += 2;
        if (happiness > 10) happiness = 10;
        cout << name << " has taken a bath.\n";
    }

    void status() const override {
        cout << "Dog Name: " << name << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Cleanliness: " << cleanliness << endl;
    }

    void draw() const override {
        cout << "\n      / \\__" << endl;
        cout << "     (    @\\___" << endl;
        cout << "     /         O" << endl;
        cout << "   /   (_____/" << endl;
        cout << " /_____/   U" << endl;
        cout << "  |    |" << endl;
    }
};


class Cat : public Animal {
private:
    string name;
    int hunger;
    int happiness;
    int cleanliness;

public:
    Cat(const string& _name) : name(_name), hunger(0), happiness(5), cleanliness(5) {}

    void feed() override {
        hunger -= 2;
        if (hunger < 0) hunger = 0;
        happiness += 1;
        if (happiness > 10) happiness = 10;
        cout << name << " has been fed.\n";
    }

    void play() override {
        hunger += 1;
        if (hunger > 10) hunger = 10;
        happiness += 2;
        if (happiness > 10) happiness = 10;
        cout << name << " is happy playing.\n";
    }

    void bathe() override {
        cout << name << " is a cat. Cats don't like to take baths!\n";
    }

    void status() const override {
        cout << "Cat Name: " << name << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Cleanliness: " << cleanliness << endl;
    }

    void draw() const override {
        cout << "\n  /\\_/\\" << endl;
        cout << " ( o.o )" << endl;
        cout << "  > ^ <  " << endl;
    }
};

int main() {
    cout << "Welcome to the Pet Care Game!\n";

    vector<Animal*> animals;

    int numAnimals;
    cout << "How many animals do you have? ";
    cin >> numAnimals;

    for (int i = 0; i < numAnimals; ++i) {
        cout << "Enter the type of animal " << i + 1 << " (dog, cat): ";
        string animalType;
        cin >> animalType;

        cout << "Enter the name of animal " << i + 1 << ": ";
        string animalName;
        cin >> animalName;

        if (animalType == "dog") {
            animals.push_back(new Dog(animalName));
        } else if (animalType == "cat") {
            animals.push_back(new Cat(animalName));
        } else {
            cout << "Invalid animal type. Please choose dog or cat.\n";
            --i; 
        }
    }

    for (const Animal* animal : animals) {
        animal->draw();
    }

    int choice;
    do {
        cout << "\nChoose an action:\n";
        cout << "1. Feed an animal\n";
        cout << "2. Play with an animal\n";
        cout << "3. Bathe an animal\n";
        cout << "4. Check an animal's status\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the index of the animal to feed (1-" << numAnimals << "): ";
                int index;
                cin >> index;
                if (index >= 1 && index <= numAnimals) {
                    animals[index - 1]->feed();
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 2: {
                cout << "Enter the index of the animal to play with (1-" << numAnimals << "): ";
                int index;
                cin >> index;
                if (index >= 1 && index <= numAnimals) {
                    animals[index - 1]->play();
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 3: {
                cout << "Enter the index of the animal to bathe (1-" << numAnimals << "): ";
                int index;
                cin >> index;
                if (index >= 1 && index <= numAnimals) {
                    animals[index - 1]->bathe();
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 4: {
                cout << "Enter the index of the animal to check status (1-" << numAnimals << "): ";
                int index;
                cin >> index;
                if (index >= 1 && index <= numAnimals) {
                    animals[index - 1]->status();
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 5:
                cout << "Thanks for playing!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}

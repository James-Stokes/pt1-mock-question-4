///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////

// ***** QUESTION 4 ****
// Question 4 has 3 parts (you do NOT need to include each class in a separate file!)
// 4.1 Create a virtual base class "Animal" which has two methods, name() and does(). 
// 4.2 From class "Animal", derive a concrete class "Bird" and "Dog".  Print appropriate message for
//     each method.
// 4.3 Write a driver program which creates an object of each type and demonstrates POLYMORPHISM. 

#include <string>
#include <iostream>

using namespace std;

class Animal {

protected:
	int numLegs;
	string type;
	bool dead;
	int distance; // records how far an animal is away from us

public:
	Animal(int numLegs, string type) : numLegs(numLegs), type(type), dead(false), distance(0){}
	virtual void kill() {
		dead = true;
	}
	virtual void move() = 0;

	int getDistance() {
		return distance;
	}

	string getType() {
		return type;
	}

	int getLegs() {
		return numLegs;
	}

	bool isDead() {
		return dead;
	}
};

class Dog : public Animal {
public:
	Dog(int numLegs, string type) : Animal(numLegs, type) {}
	void move() {
		distance += 5;
	}
};

class Bird : public Animal {
public:
	Bird(int numLegs, string type) : Animal(numLegs, type) {}
	void move() {
		distance += 50;
	}
};

int main() {
	Animal* animalArray[2];
	animalArray[0] = new Dog(4, "Husky");
	animalArray[1] = new Bird(2, "Parrot");
	for (int i = 0; i < 2; i++) {
		cout << "type: " << animalArray[i]->getType() << " Num of legs: " << animalArray[i]->getLegs() << " Distance: " << animalArray[i]->getDistance() << " is dead? " << animalArray[i]->isDead() << endl;
		animalArray[i]->move();
	}
	animalArray[1]->kill();
	for (int i = 0; i < 2; i++) {
		cout << "type: " << animalArray[i]->getType() << " Num of legs: " << animalArray[i]->getLegs() << " Distance: " << animalArray[i]->getDistance() << " is dead? " << animalArray[i]->isDead() << endl;
	}
	return 0;
}
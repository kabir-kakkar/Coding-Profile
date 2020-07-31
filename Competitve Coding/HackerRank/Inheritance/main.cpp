#include <bits/stdc++.h>
using namespace std;

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}
};

class Student : public Person{
	private:
		vector<int> testScores;
	public:
        /*
        *   Class Constructor
        *
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student (string fN, string lN, int id, vector<int> scores) : Person(fN, lN, id), testScores(scores) {

        }
        /*
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate () {
            int average = accumulate(testScores.begin(), testScores.end(), 0.0)/testScores.size();

            // Assign letter grade
            if (average >= 90.0) {
                return  'O';
            } else if (average >= 80.0) {
                return  'E';
            } else if (average >= 70.0) {
                return  'A';
            } else if (average >= 55.0) {
                return  'P';
            } else if (average >= 40.0) {
                return  'D';
            } else {
                return  'T';
            }
        }
};

int main() {
    freopen("input.txt", "r", stdin);

	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}

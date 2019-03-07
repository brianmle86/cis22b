/**
 Lab 3: Using object oriented methods, this program
 asks a user 10 questions and tells them if they got
 it right or wrong. The questions are stored in an
 array of Question objects.
 
Author: Brian Le
Date:
    Due: 02/8/19
    Completed: 02/15/19
*/

#include<iostream>
#include "Question.h"
using namespace std;
const int NUM_QUESTIONS = 10;

void displayQuestion(Question [], int);
void gameloop(Question [], int &);

int main() {
    int points;
    Question questions[NUM_QUESTIONS];
    
    questions[0].setQuestion("What is the capital of California?");
    questions[0].setAnswer1("1) Sacramento");
    questions[0].setAnswer2("2) San Jose");
    questions[0].setAnswer3("3) Santa Clara");
    questions[0].setAnswer4("4) Sunnyvale");
    questions[0].setCorrect(1);

    questions[1].setQuestion("What is the capital of Georgia?");
    questions[1].setAnswer1("1) Augusta");
    questions[1].setAnswer2("2) Atlanta");
    questions[1].setAnswer3("3) Louisville");
    questions[1].setAnswer4("4) Milledgeville");
    questions[1].setCorrect(2);

    questions[2].setQuestion("What is the capital of Vermont?");
    questions[2].setAnswer1("1) Montpelier");
    questions[2].setAnswer2("2) Burlington");
    questions[2].setAnswer3("3) Windsor");
    questions[2].setAnswer4("4) Rutland");
    questions[2].setCorrect(1);

    questions[3].setQuestion("What is the capital of Kansas?");
    questions[3].setAnswer1("1) Kansas City");
    questions[3].setAnswer2("2) Salina");
    questions[3].setAnswer3("3) Lawrence");
    questions[3].setAnswer4("4) Topeka");
    questions[3].setCorrect(4);

    questions[4].setQuestion("What is the capital of Virginia?");
    questions[4].setAnswer1("1) Virginia Beach");
    questions[4].setAnswer2("2) Jamestown");
    questions[4].setAnswer3("3) Richmond");
    questions[4].setAnswer4("4) Norfolk");
    questions[4].setCorrect(3);

    questions[5].setQuestion("What is the capital of Maine?");
    questions[5].setAnswer1("1) Augusta");
    questions[5].setAnswer2("2) Belgrade");
    questions[5].setAnswer3("3) Winthrop");
    questions[5].setAnswer4("4) Gardiner");
    questions[5].setCorrect(1);

    questions[6].setQuestion("What is the capital of Oregon?");
    questions[6].setAnswer1("1) Dallas");
    questions[6].setAnswer2("2) Salem");
    questions[6].setAnswer3("3) Sublimitv");
    questions[6].setAnswer4("4) Silverton");
    questions[6].setCorrect(2);

    questions[7].setQuestion("What is the capital of Wyoming?");
    questions[7].setAnswer1("1) Jackson");
    questions[7].setAnswer2("2) Casper");
    questions[7].setAnswer3("3) Altvan");
    questions[7].setAnswer4("4) Cheyenne");
    questions[7].setCorrect(4);

    questions[8].setQuestion("What is the capital of Texas?");
    questions[8].setAnswer1("1) San Antonio");
    questions[8].setAnswer2("2) Dallas");
    questions[8].setAnswer3("3) Houston");
    questions[8].setAnswer4("4) Austin");
    questions[8].setCorrect(4);

    questions[9].setQuestion("What is the capital of Washington?");
    questions[9].setAnswer1("1) Washington D.C.");
    questions[9].setAnswer2("2) Olympia");
    questions[9].setAnswer3("3) Tumwater");
    questions[9].setAnswer4("4) Seattle");
    questions[9].setCorrect(2);

    gameloop(questions, points);
    cout << "\nYour score is " << points << "/"
         << NUM_QUESTIONS << "!\n";
}
/**
 This function displays the question
 and the choices for the player.
 */
void displayQuestion(Question ques[], int i) {
    cout << endl;
    for(int j = 0; j < 35; j++)
        cout << "=";
    cout << endl;
    cout << ques[i].getQuestion() << endl;
    cout << ques[i].getAnswer1() << endl;
    cout << ques[i].getAnswer2() << endl;
    cout << ques[i].getAnswer3() << endl;
    cout << ques[i].getAnswer4() << endl;

}

/**
 This function calls displayQuestion
 10 times and tells the player if they 
 got the question right or wrong. It informs
 the player if the correct answer if they
 got it wrong.
 */
void gameloop(Question ques[], int &points) {
    for(int i = 0; i < 10; i++) {
        int ans;
        displayQuestion(ques, i);
        cout << "Enter your answer(1-4): ";
        cin >> ans;
        
        if(ans == ques[i].getCorrectAnswer()) {
            cout << "\n----\nCorrect!\n";
            points++;
        }
        else {
            cout << "\n----\nIncorrect!\n";
            cout << "The correct answer is: ";
            cout << ques[i].getCorrectAnswer()
                 << endl;
        }
    }
}

Question::Question() {
}

//constructor
Question::Question(string question, string answer1, string answer2, string answer3, string answer4,
        unsigned short int correctAnswer) {
    setQuestion(question);
    setAnswer1(answer1);
    setAnswer2(answer2);
    setAnswer3(answer3);
    setAnswer4(answer4);
    setCorrect(correctAnswer);
}
void Question::setQuestion(string ques) {
    question = ques;
}
void Question::setAnswer1(string ans) {
    answer1 = ans;
}
void Question::setAnswer2(string ans) {
    answer2 = ans;
}
void Question::setAnswer3(string ans) {
    answer3 = ans;
}
void Question::setAnswer4(string ans) {
    answer4 = ans;
}
void Question::setCorrect(unsigned short int correct) {
    correctAnswer = correct;
}
string Question::getQuestion() {
    return question;
}
string Question::getAnswer1() {
    return answer1;
}
string Question::getAnswer2() {
    return answer2;
}
string Question::getAnswer3() {
    return answer3;
}
string Question::getAnswer4() {
    return answer4;
}
unsigned short int Question::getCorrectAnswer() {
    return correctAnswer;
}

/**
OUTPUT:

===================================
What is the capital of California?
1) Sacramento
2) San Jose
3) Santa Clara
4) Sunnyvale
Enter your answer(1-4): 1

----
Correct!

===================================
What is the capital of Georgia?
1) Augusta
2) Atlanta
3) Louisville
4) Milledgeville
Enter your answer(1-4): 2

----
Correct!

===================================
What is the capital of Vermont?
1) Montpelier
2) Burlington
3) Windsor
4) Rutland
Enter your answer(1-4): 3

----
Incorrect!
The correct answer is: 1

===================================
What is the capital of Kansas?
1) Kansas City
2) Salina
3) Lawrence
4) Topeka
Enter your answer(1-4): 4

----
Correct!

===================================
What is the capital of Virginia?
1) Virginia Beach
2) Jamestown
3) Richmond
4) Norfolk
Enter your answer(1-4): 1

----
Incorrect!
The correct answer is: 3

===================================
What is the capital of Maine?
1) Augusta
2) Belgrade
3) Winthrop
4) Gardiner
Enter your answer(1-4): 2

----
Incorrect!
The correct answer is: 1

===================================
What is the capital of Oregon?
1) Dallas
2) Salem
3) Sublimitv
4) Silverton
Enter your answer(1-4): 3

----
Incorrect!
The correct answer is: 2

===================================
What is the capital of Wyoming?
1) Jackson
2) Casper
3) Altvan
4) Cheyenne
Enter your answer(1-4): 4

----
Correct!

===================================
What is the capital of Texas?
1) San Antonio
2) Dallas
3) Houston
4) Austin
Enter your answer(1-4): 1

----
Incorrect!
The correct answer is: 4

===================================
What is the capital of Washington?
1) Washington D.C.
2) Olympia
3) Tumwater
4) Seattle
Enter your answer(1-4): 2

----
Correct!

Your score is 5/10!
*/

#include <iostream>
#include <cstdlib>
using namespace std;

enum enLevel {Easy = 1, Med = 2, Hard = 3, Mix = 4};
enum enOpType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stQuestion
{
    int num1;
    int num2;
    enOpType opType;
    enLevel level;
    int correctAnswer;
    int playerAnswer;
    bool answerResult;
};
struct stQuiz
{
    stQuestion QuestionList[100];
    int qNum;
    string qLevel;
    string qOpType;
    int rightAnswers = 0;
    int wrongAnswers = 0;
    bool isPass;
};

int main()
{    
    return 0;
}
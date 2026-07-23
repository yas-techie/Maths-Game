#include <iostream>
#include <cstdlib>
using namespace std;

int readNumber(string message)
{
    int num;
    do
    {
        cout<<message;
        cin>>num;
    } while (num < 0);
    return num;
}
int randomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enum enLevel {Easy = 1, Med = 2, Hard = 3, Mix = 4};
enum enOpType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

enLevel readLevel()
{
    int level;
    do
    {
        level = readNumber("Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ");
    } while (level < 1 || level > 4);
    
    return (enLevel) level;
}
enLevel GetRandomLevel()
{
    enLevel level = (enLevel) randomNumber(1, 3);
    return level;
}

enOpType readOpType()
{
    int opType;
    do
    {
        opType = readNumber("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ");
    } while (opType < 1 || opType > 5);
    
    return (enOpType) opType;
}
enOpType GetRandomOperationType()
{
    enOpType opType = (enOpType) randomNumber(1, 4);
    return opType;
}

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
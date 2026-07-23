#include <iostream>
#include <cstdlib>
using namespace std;

void resetScreen()
{
    system("cls");
    system("color 0F");
}
void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F"); // Turn screen green if the answer is correct.
    else
    {
        system("color 4F"); // Turn screen red if the answer is wrong.
        cout << "\a"; // Play an alert sound.
    }
}


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

string printLevel(enLevel level)
{
    string arrLevelText[4] = { "Easy","Med","Hard","Mix" };
    return arrLevelText[level - 1];
}
int gameLevel(enLevel level)
{
    switch (level)
    {
    case enLevel::Easy:
        return randomNumber(1, 10);
        break;

    case enLevel::Med:
        return randomNumber(10, 50);
        break; 
        
    case enLevel::Hard:
        return randomNumber(50, 100);
        break;

    case enLevel::Mix:
        return randomNumber(1, 100);
        break;     
    }
    return randomNumber(1, 100);
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

string printType(enOpType opType)
{
    switch (opType)
    {
    case enOpType::Add:
        return "+";
        break;

    case enOpType::Sub:
        return "-";
        break; 
        
    case enOpType::Mul:
        return "x";
        break;

    case enOpType::Div:
        return "/";
        break;    
        
    case enOpType::MixOp:
        return "Mix";
        break;     
    }
    return "Mix";
}
int calacNumber(enOpType opType, int num1, int num2)
{
    switch (opType)
    {
    case enOpType::Add:
        return num1 + num2;
        break;

    case enOpType::Sub:
        return num1 - num2;
        break; 
        
    case enOpType::Mul:
        return num1 * num2;
        break;

    case enOpType::Div:
        return num1 / num2;
        break;       
    }
    return num1 + num2;
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

bool isCorrect(stQuestion q)
{
    return (q.correctAnswer == q.playerAnswer);
}

void generateQuestion(stQuiz& quiz, stQuestion& q)
{
    q.num1 = gameLevel(q.level);
    q.num2 = gameLevel(q.level);
    cout<< q.num1 <<endl;
    cout<< q.num2  << " " << printType(q.opType) <<endl;

    q.correctAnswer = calacNumber(q.opType, q.num1, q.num2);
    q.playerAnswer = readNumber("__________\n");
    q.answerResult = isCorrect(q);

    if (q.answerResult)
    {
        SetScreenColor(q.answerResult);
        cout<< "Right Answer :-)\n" <<endl;
        quiz.rightAnswers++;
    }
    else
    {
        SetScreenColor(q.answerResult);
        cout<< "Wrong Answer :-(" <<endl;
        cout<< "The right answer is: " << q.correctAnswer <<endl<<endl;
        quiz.wrongAnswers++;
    }
}

stQuiz playQuiz()
{
    stQuestion q;
    stQuiz quiz;
    
    quiz.qNum = readNumber("How Many Questions do you want to answer? ");
    quiz.QuestionList[quiz.qNum];

    q.level = readLevel();
    quiz.qLevel = printLevel(q.level);
    if (q.level == enLevel::Mix)
        q.level = GetRandomLevel(); 

    q.opType = readOpType();
    quiz.qOpType = printType(q.opType);
    if (q.opType == enOpType::MixOp)
        q.opType = GetRandomOperationType();

    
    for (int i = 1; i <= quiz.qNum; i++)
    {
        cout<<endl;
        cout<< "Question [" << i << "/" << quiz.qNum << "]\n" <<endl;
        generateQuestion(quiz, q);
    }
    return quiz;
}

void passFail(stQuiz quiz)
{   
    if (quiz.rightAnswers > quiz.wrongAnswers)
    {
        SetScreenColor(quiz.rightAnswers > quiz.wrongAnswers);
        cout << "\tFinal Result is Pass :-)";
    }    
    else
    {
        SetScreenColor(quiz.rightAnswers > quiz.wrongAnswers);
        cout << "\tFinal Result is Fail :-(";
    }    
}

void printQuiz(stQuiz quiz)
{
    cout << "\n________________________________________\n" <<endl;
    passFail(quiz);    
    cout << "\n________________________________________\n" <<endl;
    
    cout << "Number of Questions: " << quiz.qNum <<endl;
    cout << "Questions Level    : " << quiz.qLevel <<endl;
    cout << "OpType             : " << quiz.qOpType <<endl;
    cout << "Number of Right Answers: " << quiz.rightAnswers <<endl;
    cout << "Number of Wrong Answers: " << quiz.wrongAnswers <<endl;

    cout << "________________________________________\n" <<endl;
}

void startGame()
{
    string replay;
    do
    {
        resetScreen();
        stQuiz quiz = playQuiz();
        printQuiz(quiz);

        cout << "Do you want to play again? Y/N" <<endl;
        cin>>replay;

    } while (replay == "y" || replay == "Y");
    
}

int main()
{    
    srand((unsigned)time(NULL));

    startGame();
    
    return 0;
}
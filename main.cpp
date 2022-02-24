#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// globals
int slotIndex = 0;
string program;
int programIndex = 0;
ifstream myfile;
int loopDepth = 0;

// slot-array
vector<char> *slots = new vector<char>;

// prototypes
void programLoop();

int main(int argc, char **argv)
{
    // push a 0 at the first index
    slots->push_back(0);

    // error checking
    if (!(argc > 1))
    {
        cout << "geen bestand doorgegeven";
        exit(1);
    }
    // open the file
    myfile.open(*(argv + 1), ios::in);
    if (!myfile.is_open())
    {
        cout << "kan bestand niet lezen";
        exit(1);
    }

    // program can continue after checking

    char ch;
    while (1)
    {
        myfile >> ch;
        if (myfile.eof())
            break;
        if (ch != 0)
            program += ch;
    }

    // start the programloop
    programLoop();

    // print out the size of the vector at the end
    cout << endl
         << endl
         << slots->size() << endl;

    // free the vector
    free(slots);

    // close the file
    myfile.close();

    return 0;
}

void programLoop()
{
    do
    {
        switch (program[programIndex])
        {
        // addition and subtraction cases:
        case '+':
            slots->at(slotIndex)++;
            break;
        case '-':
            slots->at(slotIndex)--;
            break;

        // pointer mover cases:
        case '>':
            slotIndex++;
            // if the specified index does not exist yet, create it. This is what makes it dynamic
            if (slotIndex == slots->size())
                slots->push_back(0);
            break;
        case '<':
            slotIndex--;
            // break program when the index goes below 0
            if (slotIndex < 0)
            {
                cout << endl
                     << "kan niet naar een slot met een index van -1" << endl;
                exit(1);
            }
            break;

        // print cases:
        case '.':
            cout << (char)slots->at(slotIndex);
            break;
        case '\'':
            cout << (int)slots->at(slotIndex);
            break;

        case ',':
            char ch;
            cin >> ch;
            cin.get();
            slots->at(slotIndex) = (int)ch;
            break;

        // loop cases:
        case '[':
            if (slots->at(slotIndex) != 0)
                break;
            programIndex++;
            while (1)
            {
                if (program[programIndex] == ']' && loopDepth == 0)
                {
                    loopDepth = 0;
                    break;
                }
                else if (program[programIndex] == '[')
                {
                    loopDepth++;
                }
                else if (program[programIndex] == ']')
                {
                    loopDepth--;
                }
                programIndex++;
            }
            break;
        case ']':
            if (slots->at(slotIndex) == 0)
                break;
            programIndex--;
            while (1)
            {
                if (program[programIndex] == '[' && loopDepth == 0)
                {
                    loopDepth = 0;
                    break;
                }
                else if (program[programIndex] == ']')
                {
                    loopDepth++;
                }
                else if (program[programIndex] == '[')
                {
                    loopDepth--;
                }

                programIndex--;
            }
            break;

        // special cases:
        case 'n': // newline
            cout << "\n";
            break;
        }
        programIndex++;
    } while (!(programIndex >= program.length()));
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// globals
int slotIndex = 0;
string program;
int programIndex = 0;

int loopDepth = 0;

// slot-array
vector<char> *slots = new vector<char>;

// prototypes
void programLoop();
void readAsFile(char *input);
void readAsString(char *input);

int main(int argc, char **argv)
{
    // push a 0 at the first index
    slots->push_back(0);

    // error checking
    if (!(argc > 1))
    {
        cout << "Niet genoeg informatie doorgegeven";
        exit(1);
    }

    switch (**(argv + 1))
    {
    // read as file
    case 'f':
    case 'F':
    {
        readAsFile(*(argv + 2));
    }
    break;
    case 's':
    case 'S':
    {
        readAsString(*(argv + 2));
    }
    break;
    default:
    {
        readAsFile(*(argv + 1));
    }
    break;
    }

    // print out the size of the vector at the end
    cout << endl
         << endl
         << slots->size() << endl;

    // free the vector
    free(slots);

    return 0;
}

void readAsFile(char *input)
{
    ifstream myfile;
    // open the file
    myfile.open(input, ios::in);
    if (!(myfile.is_open()))
    {
        cout << "Kan bestand niet lezen";
        exit(1);
    }

    // program can continue after checking if it was even a file
    char ch;
    while (!myfile.eof())
    {
        myfile >> ch;
        program += ch;
    }
    // close the file
    myfile.close();

    // remove last character of the string, since using this technique ^ adds the last character twice
    program.pop_back();

    // start the programloop
    programLoop();
}

void readAsString(char *input)
{
    if (input == 0)
    {
        cout << "geen argument doorgegeven";
        exit(1);
    }
    // set the program string as the input
    program = input;

    /// start the program loop
    programLoop();
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
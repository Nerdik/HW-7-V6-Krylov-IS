// Variant 6

#include <iostream>


// Exercise 1 functions
int ex1CountWordNumber(char* str)
{
    char* ptr1 = str;
    int wordsNumber = 1;
    while (*ptr1 != '\0')
    {
        if(*ptr1 == ' ')
        {
            wordsNumber += 1;
        }
        ++ptr1;
    }
    return wordsNumber;
}

void ex2MiddleWordToUpperCase(char* str, int wordsNumber)
{
    char* ptr2 = str;
    int countWordToUpCase = 1;
    int middle = wordsNumber / 2 + 1;
    int upLowDiff = 'a' - 'A';
    while (countWordToUpCase <= middle)
    {
        if(*ptr2 == ' ')
        {
            countWordToUpCase += 1;
        }
        
        else if(countWordToUpCase == middle)
        {
            while (*ptr2 != ' ')
            {
                *ptr2 = *ptr2 - upLowDiff;
                ++ptr2;
            }
            break;
        }
        ++ptr2;
    }
}


void ex1()
{
    char* str = new char[255];
    std::cout << "Input text in english: ";
    std::cin.getline(str, 255);

    int wordsNumber = ex1CountWordNumber(str);

    std::cout << "Words number: " << wordsNumber << std::endl;

    ex2MiddleWordToUpperCase(str, wordsNumber);

    std::cout << "Result: " << str << std::endl;
    delete[] str;
}


// Exercise 2 functions
bool ex2VowelCheck(char simbol)
{
    const char vowels[11] = "aeiouAEIOU";
    const char* ptrVowel = vowels;

    while (*ptrVowel != '\0')
    {
        if (simbol == *ptrVowel)
        {
            return true;
        }
        ++ptrVowel;
    }
    return false;
}


void ex2()
{
    char str[255];
    std::cout << "Input text in english: ";
    std::cin.getline(str, 255);

    char c1;
    std::cout << "Input symbol c1: ";
    std::cin >> c1;

    size_t length = 1;
    char* newStr = new char[length];
    newStr[0] = '\0';

    char* ptr = str;

    while (*ptr != '\0')
    {
        char* ptrPrev = (ptr == str) ? ptr : ptr - 1;
        char* ptrNext = (*(ptr + 1) == '\0') ? ptr : ptr + 1;

        if ((*ptr != c1) || 
            ((ptr != str && ex2VowelCheck(*ptrPrev)) && 
            (*(ptr + 1) != '\0' && ex2VowelCheck(*ptrNext))))
        {
            
            length++;
            char* tmpStr = new char[length];
            char* tmpPtr = tmpStr;
            char* newPtr = newStr;

            while(*newPtr != '\0')
            {
                *tmpPtr = *newPtr;
                newPtr++;
                tmpPtr++;
            }

            delete[] newStr;
            *tmpPtr = *ptr;
            *(tmpPtr + 1) = '\0';
            newStr = tmpStr;
        }
        ptr++;
    }

    std::cout << "Result: " << newStr << std::endl;

    delete[] newStr;
}


int main()
{
    // Exercise 1.
    ex1();

    // Exercise 2.
    ex2();

    return 0;
}

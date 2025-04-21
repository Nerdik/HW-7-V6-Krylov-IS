// Variant 6

#include <iostream>
#include <cstring>


void ex1()
{
    char* str = new char[255];
    std::cout << "Input text in english: ";
    std::cin.getline(str, 255);

    char* ptr1 = str;
    int count1 = 1;
    while (*ptr1 != '\0')
    {
        if(*ptr1 == ' ')
        {
            count1 += 1;
        }
        ++ptr1;
    }

    std::cout << "Words number: " << count1 << std::endl;

    char* ptr2 = str;
    int count2 = 1;
    while (count2 <= count1 / 2 + 1)
    {
        if(*ptr2 == ' ')
        {
            count2 += 1;
        }
        
        if(count2 == count1 / 2 + 1 && *ptr2 != ' ')
        {
            *ptr2 = *ptr2 - 32;
        }
        ++ptr2;
    }

    std::cout << "Result: " << str << std::endl;
    delete[] str;
}


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

    char* newStr = new char[255];
    char* newPtr = newStr;

    char* ptr = str;

    while (*ptr != '\0')
    {
        char* ptrPrev = (ptr == str) ? ptr : ptr - 1;
        char* ptrNext = (*(ptr + 1) == '\0') ? ptr : ptr + 1;

        if ((*ptr != c1) || 
            ((ptr != str && ex2VowelCheck(*ptrPrev)) && 
            (*(ptr + 1) != '\0' && ex2VowelCheck(*ptrNext))))
        {
            *newPtr = *ptr;
            newPtr++;
        }
        ptr++;
    }
    *newPtr = '\0';

    ptrdiff_t newLength = newPtr - newStr + 1;
    char* finalStr = new char[newLength];
    char* finalPtr = finalStr;
    char* newPtr2 = newStr;

    while(*newPtr2 != '\0')
    {
        *finalPtr = *newPtr2;
        newPtr2++;
        finalPtr++;
    }
    *finalPtr = '\0';

    delete[] newStr;

    std::cout << "Result: " << finalStr << std::endl;

    delete[] finalStr;
}


int main()
{
    // Exercise 1.
    ex1();

    // // Exercise 2.
    ex2();

    return 0;
}

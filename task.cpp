// Variant 6

#include <iostream>


void ex1()
{
    char str[255];
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
}


int main()
{
    // Exercise 1.
    ex1();

    // // Exercise 2.
    // ex2();

    return 0;
}
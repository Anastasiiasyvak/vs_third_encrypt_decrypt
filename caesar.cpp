#include <iostream>
#include <cstring>

extern "C"
{
    char *encrypt(char *rawText, int key)
    {
        key = key % 26;
        int length = strlen(rawText);
        char *result = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            char currentChar = rawText[i];
            if (isupper(currentChar))
            {
                currentChar = char(int(currentChar + key - 65) % 26 + 65);
            }
            else if (islower(currentChar))
            {
                currentChar = char(int(currentChar + key - 97) % 26 + 97);
            }
            result[i] = currentChar;
        }

        result[length] = '\0';

        return result;
    }

    char *decrypt(char *encryptedText, int key)
    {
        
        int length = strlen(encryptedText);
        char *result = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            char currentChar = encryptedText[i];
            if (isupper(currentChar))
            {
                currentChar = char(int(currentChar - key - 65) % 26 + 65);
            }
            else if (islower(currentChar))
            {
                currentChar = char(int(currentChar - key - 97) % 26 + 97);
            }
            result[i] = currentChar;
        }

        result[length] = '\0';

        return result;
    }
}

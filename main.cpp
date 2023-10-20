#include <iostream>
#include <cstring>
#include <dlfcn.h> 

typedef char* (*EncryptFunction)(char*, int);
typedef char* (*DecryptFunction)(char*, int);

int main() {
    char rawText[100];
    int key = 0;
    char* encryptedText = nullptr;
    char* decryptedText = nullptr;

    // Завантаження DLL
    void* libraryHandle = dlopen("./caesar.so", RTLD_LAZY);

    if (!libraryHandle) {
        std::cerr << "Library not found: " << dlerror() << std::endl;
        return 1;
    }

    // Завантаження функцій з DLL
    EncryptFunction encrypt = reinterpret_cast<EncryptFunction>(dlsym(libraryHandle, "encrypt"));
    DecryptFunction decrypt = reinterpret_cast<DecryptFunction>(dlsym(libraryHandle, "decrypt"));

    if (!encrypt || !decrypt) {
        std::cerr << "Function not found in library: " << dlerror() << std::endl;
        dlclose(libraryHandle);
        return 1;
    }

    std::cout << "Enter the key: ";
    std::cin >> key;

    std::cin.ignore();

    std::cout << "Enter the raw text: ";
    std::cin.getline(rawText, sizeof(rawText));

    encryptedText = encrypt(rawText, key);

    std::cout << "Encrypted text: " << encryptedText << std::endl;



    decryptedText = decrypt(encryptedText, key);

    std::cout << "Decrypted text: " << decryptedText << std::endl;

    delete[] encryptedText;
    delete[] decryptedText;

    dlclose(libraryHandle);

    return 0;
}

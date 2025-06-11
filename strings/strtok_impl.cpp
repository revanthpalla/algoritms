#include <iostream>
using namespace std;

/* char* strtok_l(char* input, char delimiter)
   if we call once one token will be returned
*/

char* strtok_l(char* input, char delimiter) {
    static char* curr = NULL; // point to curr state of string
    if (input != NULL) {
        curr = input;
    }
    if (curr == NULL) {
        return NULL;
    }
    char* token = new char[strlen(curr) + 1];
    int i = 0;
    for (;curr[i] != '\0';i++) {
        if (curr[i] != delimiter) {
            token[i] = curr[i];
        } else {
            // we reached delimiter position
            token[i] = '\0';
            curr = curr + i + 1; // points to next token
            return token;
        }
    }
    token[i] = '\0';
    curr = NULL; // it didnt find delimiter single word string
    return token;
}


int main() {
    char str[50] = "Hi Revanth How are you?";
    char* token = strtok_l(str, ' ');
    while (token) {
        cout << token << endl;
        token = strtok_l(NULL, ' ');
    }
    return 0;
}
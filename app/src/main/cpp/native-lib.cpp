#include <jni.h>
#include <stdlib.h>
#include <string>

using namespace std;

string generateWord() {
    string generatedWord = "";

    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int wordLength = rand() % 10 + 3;

    for (int i = 0; i < wordLength; i++) {
        int randomCharacterIndex = rand() % 24;
        generatedWord += alphabet.at(randomCharacterIndex);
    }

    return generatedWord;
}

extern "C" JNIEXPORT jstring JNICALL

Java_com_example_kunhuang_newstring_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    string word = generateWord();
    //string word = "Hello from C++";
    return env->NewStringUTF(word.c_str());
}

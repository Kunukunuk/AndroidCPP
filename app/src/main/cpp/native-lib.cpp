#include <jni.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <vector>

using namespace std;

string generateWord() {

    ifstream inFile;
    string generatedWord = "";

    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int numberOfWords = rand() %10 + 1;
    int wordLength = rand() % 10 + 3;

    for (int len = 0; len < numberOfWords; len++) {
        for (int i = 0; i < wordLength; i++) {
            int randomCharacterIndex = rand() % 24;
            generatedWord += alphabet.at(randomCharacterIndex);
        }
    }

    return generatedWord;
}

extern "C" JNIEXPORT jstring JNICALL

Java_com_example_kunhuang_newstring_MainActivity_stringFromJNI(
        JNIEnv *env, jobject obj,
        jobject javAManager) {

    AAssetManager *mangr = AAssetManager_fromJava(env, javAManager);

    string word = generateWord();
    //string word = "Hello from C++";
    return env->NewStringUTF(word.c_str());
}

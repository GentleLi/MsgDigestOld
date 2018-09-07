//
// Created by admin on 2018/9/7.
//

#include "digest.h"
#include "verify.h"

/*
 * Class:     me_study_msgdigest_digest_MD5Helper
 * Method:    getFileMd5
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_me_study_msgdigest_digest_MD5Helper_getFileMd5
        (JNIEnv *env, jclass clz, jstring file_path) {

    char info[33] = {0};
    char input_str[500] = {0};
    sprintf(input_str, "%s", env->GetStringUTFChars(file_path, NULL));
    GetFileMD5(input_str, info);

    return env->NewStringUTF(info);
}


/*
 * Class:     me_study_msgdigest_digest_MD5Helper
 * Method:    getShaOne
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_me_study_msgdigest_digest_MD5Helper_getShaOne
        (JNIEnv *env, jclass clz, jstring file_path) {

    char input_str[500] = {0};
    sprintf(input_str, "%s", env->GetStringUTFChars(file_path, NULL));
    std::string sha = getSha1(input_str);
    return env->NewStringUTF(sha.c_str());

}
//
// Created by admin on 2018/9/7.
//
#include "jni.h"

#ifndef MSGDIGEST_DIGEST_H
#define MSGDIGEST_DIGEST_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     me_study_msgdigest_digest_MD5Helper
 * Method:    getFileMd5
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_me_study_msgdigest_digest_MD5Helper_getFileMd5
        (JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif //MSGDIGEST_DIGEST_H

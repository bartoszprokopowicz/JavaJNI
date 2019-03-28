#include "JNI.h"
#include <iostream>
#include <functional>
#include <numeric> 

JNIEXPORT jdouble JNICALL Java_JNI_multi01 (JNIEnv *env, jobject klasa, jdoubleArray a, jdoubleArray b)
{
	int lengthA = env->GetArrayLength(a);
	double *aLib = new double[lengthA];

	int lengthB = env->GetArrayLength(b);
	double *bLib = new double[lengthB];
	
	aLib = env->GetDoubleArrayElements(a, 0);
	bLib = env->GetDoubleArrayElements(b, 0);

	jdouble jsum;
	double sum = 0;

	if (lengthA > lengthB)
	{
		for (int i = 0; i < lengthB; i++)
		{
			sum += aLib[i] * bLib[i];
		}
	}
	else
	{
		for (int i = 0; i < lengthA; i++)
		{
			sum += aLib[i] * bLib[i];
		}
	}

	jsum = static_cast<jdouble>(sum);

	return jsum;
}

JNIEXPORT jdouble JNICALL Java_JNI_multi02 (JNIEnv *env, jobject klasa, jdoubleArray a)
{

}

JNIEXPORT void JNICALL Java_JNI_multi03 (JNIEnv *env, jobject klasa)
{

}
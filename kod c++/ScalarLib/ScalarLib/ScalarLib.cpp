// ScalarLib.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "JNI.h"

JNIEXPORT jdouble JNICALL Java_JNI_multi01(JNIEnv *env, jobject klasa, jdoubleArray a, jdoubleArray b)
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

JNIEXPORT jdouble JNICALL Java_JNI_multi02(JNIEnv *env, jobject klasa, jdoubleArray a)
{
	jdoubleArray b;
	jfieldID fid;

	int lengthA = env->GetArrayLength(a);
	double *aLib = new double[lengthA];

	jclass cls = env->GetObjectClass(klasa);
	fid = env->GetFieldID(cls, "b", "[D");
	if (fid == NULL) { return NULL; }
	b = (jdoubleArray)env->GetObjectField(klasa, fid);
	
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

JNIEXPORT void JNICALL Java_JNI_multi03(JNIEnv *env, jobject klasa)
{
	jdoubleArray a;
	jdoubleArray b;
	jfieldID fid;
	jclass cls;

	cls = env->GetObjectClass(klasa);
	fid = env->GetFieldID(cls, "a", "[D");
	if (fid == NULL) { return; }
	a = (jdoubleArray)env->GetObjectField(klasa, fid);

	int lengthA = env->GetArrayLength(a);
	double *aLib = new double[lengthA];

	cls = env->GetObjectClass(klasa);
	fid = env->GetFieldID(cls, "b", "[D");
	if (fid == NULL) { return; }
	b = (jdoubleArray)env->GetObjectField(klasa, fid);

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

	jsum = static_cast<double>(sum);

	cls = env->GetObjectClass(klasa);
	fid = env->GetFieldID(cls, "c", "D");
	if (fid == NULL) { return; }
	env->SetDoubleField(klasa, fid, jsum);
}


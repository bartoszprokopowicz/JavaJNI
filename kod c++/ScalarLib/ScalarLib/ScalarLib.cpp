// ScalarLib.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "JNI.h"

JNIEXPORT jobject JNICALL Java_JNI_multi01(JNIEnv *env, jobject klasa, jobjectArray a, jobjectArray b)
{
	jobject ao;
	jobject bo;
	jclass ca;
	jmethodID doubleValue;
	jdouble jsum;

	double *aLib;
	double *bLib;
	double sum;

	int lengthA = env->GetArrayLength(a);
	int lengthB = env->GetArrayLength(b);
	ao = env->GetObjectArrayElement(a, 0);
	bo = env->GetObjectArrayElement(b, 0);

	ca = env->GetObjectClass(ao);
	doubleValue = env->GetMethodID(ca, "doubleValue", "()D");

	if (doubleValue == NULL)
		return NULL;

	aLib = new double[lengthA];
	bLib = new double[lengthB];

	sum = 0;
	
	if (lengthA > lengthB)
	{
		for (int i = 0; i < lengthB; i++)
		{
			ao = env->GetObjectArrayElement(a, i);
			aLib[i] = env->CallDoubleMethod(ao, doubleValue);
			
			bo = env->GetObjectArrayElement(b, i);
			bLib[i] = env->CallDoubleMethod(bo, doubleValue);

			sum += aLib[i] * bLib[i];
		}
	}
	else
	{
		for (int i = 0; i < lengthA; i++)
		{
			ao = env->GetObjectArrayElement(a, i);
			aLib[i] = env->CallDoubleMethod(ao, doubleValue);

			bo = env->GetObjectArrayElement(b, i);
			bLib[i] = env->CallDoubleMethod(bo, doubleValue);

			sum += aLib[i] * bLib[i];
		}
	}
	
	jsum = static_cast<jdouble>(sum);

	jmethodID init = env->GetMethodID(ca, "<init>", "(D)V");
	jobject x = env->NewObject(ca, init, jsum);

	delete aLib, bLib;
	env->DeleteLocalRef(ca);
	env->DeleteLocalRef(ao);
	env->DeleteLocalRef(bo);

	return x;
}

JNIEXPORT jobject JNICALL Java_JNI_multi02(JNIEnv *env, jobject klasa, jobjectArray a)
{
	jobjectArray b;
	jobject ao;
	jobject bo;
	jclass cls;
	jclass ca;
	jdouble jsum;
	jfieldID fid;
	jmethodID doubleValue;

	double *aLib;
	double *bLib;
	double sum;

	cls = env->GetObjectClass(klasa);
	fid = env->GetFieldID(cls, "b", "[Ljava/lang/Double;");
	if (fid == NULL) 
		return NULL;

	b = (jobjectArray)env->GetObjectField(klasa, fid);
	
	int lengthA = env->GetArrayLength(a);
	int lengthB = env->GetArrayLength(b);
	aLib = new double[lengthA];
	bLib = new double[lengthB];

	ao = env->GetObjectArrayElement(a, 0);
	bo = env->GetObjectArrayElement(b, 0);

	ca = env->GetObjectClass(ao);
	doubleValue = env->GetMethodID(ca, "doubleValue", "()D");

	sum = 0;

	if (lengthA > lengthB)
	{
		for (int i = 0; i < lengthB; i++)
		{
			ao = env->GetObjectArrayElement(a, i);
			aLib[i] = env->CallDoubleMethod(ao, doubleValue);

			bo = env->GetObjectArrayElement(b, i);
			bLib[i] = env->CallDoubleMethod(bo, doubleValue);

			sum += aLib[i] * bLib[i];
		}
	}
	else
	{
		for (int i = 0; i < lengthA; i++)
		{
			ao = env->GetObjectArrayElement(a, i);
			aLib[i] = env->CallDoubleMethod(ao, doubleValue);

			bo = env->GetObjectArrayElement(b, i);
			bLib[i] = env->CallDoubleMethod(bo, doubleValue);

			sum += aLib[i] * bLib[i];
		}
	}

	jsum = static_cast<jdouble>(sum);
	jmethodID init = env->GetMethodID(ca, "<init>", "(D)V");
	jobject x = env->NewObject(ca, init, jsum);

	delete aLib, bLib;
	env->DeleteLocalRef(ca);
	env->DeleteLocalRef(ao);
	env->DeleteLocalRef(bo);

	return x;
}

JNIEXPORT void JNICALL Java_JNI_multi03(JNIEnv *env, jobject klasa)
{
	jobjectArray a;
	jobjectArray b;
	jobject ao;
	jobject bo;
	jclass cls;
	jclass ca;
	jdouble jsum;
	jfieldID fid;
	jmethodID doubleValue;

	double *aLib;
	double *bLib;
	double sum;

	cls = env->GetObjectClass(klasa);

	fid = env->GetFieldID(cls, "a", "[Ljava/lang/Double;");
	if (fid == NULL)
		return;
	a = (jobjectArray)env->GetObjectField(klasa, fid);

	fid = env->GetFieldID(cls, "b", "[Ljava/lang/Double;");
	if (fid == NULL)
		return;
	b = (jobjectArray)env->GetObjectField(klasa, fid);

	int lengthA = env->GetArrayLength(a);
	int lengthB = env->GetArrayLength(b);
	aLib = new double[lengthA];
	bLib = new double[lengthB];

	ao = env->GetObjectArrayElement(a, 0);
	bo = env->GetObjectArrayElement(b, 0);

	ca = env->GetObjectClass(ao);
	doubleValue = env->GetMethodID(ca, "doubleValue", "()D");

	sum = 0;

	if (lengthA > lengthB)
	{
		for (int i = 0; i < lengthB; i++)
		{
			ao = env->GetObjectArrayElement(a, i);
			aLib[i] = env->CallDoubleMethod(ao, doubleValue);

			bo = env->GetObjectArrayElement(b, i);
			bLib[i] = env->CallDoubleMethod(bo, doubleValue);

			sum += aLib[i] * bLib[i];
		}
	}
	else
	{
		for (int i = 0; i < lengthA; i++)
		{
			ao = env->GetObjectArrayElement(a, i);
			aLib[i] = env->CallDoubleMethod(ao, doubleValue);

			bo = env->GetObjectArrayElement(b, i);
			bLib[i] = env->CallDoubleMethod(bo, doubleValue);

			sum += aLib[i] * bLib[i];
		}
	}

	jsum = static_cast<jdouble>(sum);
	fid = env->GetFieldID(cls, "c", "Ljava/lang/Double;");
	if (fid == NULL) 
		return;

	jmethodID init = env->GetMethodID(ca, "<init>", "(D)V");
	jobject x = env->NewObject(ca, init, jsum);

	env->SetObjectField(klasa, fid, x);

	delete aLib, bLib;
	env->DeleteLocalRef(ca);
	env->DeleteLocalRef(ao);
	env->DeleteLocalRef(bo);
	env->DeleteLocalRef(x);
}


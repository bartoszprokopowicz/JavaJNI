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

	doubleValue = NULL;
	jsum = NULL;

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
	env->DeleteLocalRef(b);
	env->DeleteLocalRef(cls);

	jsum = NULL;
	fid = NULL;
	doubleValue = NULL;

	return x;
}

JNIEXPORT void JNICALL Java_JNI_multi03(JNIEnv *env, jobject klasa)
{
	jobjectArray a;
	jobjectArray b;
	jclass cls;
	jclass clsD;
	jdouble jsum;
	jfieldID faid;
	jfieldID fbid;
	jmethodID doubleValue;
	jmethodID multi04;

	double aLib[] = { 1.0, 2.0, 3.0, 4.0 };
	double bLib[] = { 1.0, 2.0, 3.0 };

	int aLibSize = sizeof(aLib) / sizeof(aLib[0]);
	int bLibSize = sizeof(bLib) / sizeof(bLib[0]);
	
	clsD = env->FindClass("java/lang/Double");
	if (clsD == NULL)
		return;

	cls = env->GetObjectClass(klasa);

	jmethodID init = env->GetMethodID(clsD, "<init>", "(D)V");

	multi04 = env->GetMethodID(cls, "multi04", "()V");
	if (multi04 == NULL)
		return;

	faid = env->GetFieldID(cls, "a", "[Ljava/lang/Double;");
	if (faid == NULL)
		return;
	fbid = env->GetFieldID(cls, "b", "[Ljava/lang/Double;");
	if (fbid == NULL)
		return;

	a = env->NewObjectArray(aLibSize, clsD, NULL);
	b = env->NewObjectArray(bLibSize, clsD, NULL);
	
	for (int i = 0; i < aLibSize; i++)
	{
		jobject av = env->NewObject(clsD, init, static_cast<jdouble>(aLib[i]));
		env->SetObjectArrayElement(a, i, av);
	}

	for (int i = 0; i < bLibSize; i++)
	{
		jobject bv = env->NewObject(clsD, init, static_cast<jdouble>(bLib[i]));
		env->SetObjectArrayElement(b, i, bv);
	}
	
	env->SetObjectField(klasa, faid, a);
	env->SetObjectField(klasa, fbid, b);	
	
	env->CallVoidMethod(klasa, multi04);
	
	env->DeleteLocalRef(clsD);
	env->DeleteLocalRef(a);
	env->DeleteLocalRef(b);
	env->DeleteLocalRef(cls);
	
	jsum = NULL;
	faid = NULL;
	fbid = NULL;
	doubleValue = NULL;
	multi04 = NULL;
}


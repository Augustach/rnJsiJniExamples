#include <iostream>
#include <utility>
#include <jsi/jsi.h>
#include <jni.h>
#include "helpers.cpp"
#include <jni.h>
#include <jni.h>
#include <jni.h>
#include <jni.h>

// global ref to Java Virtual Machine
// used to get JNI current env
JavaVM *jvm;
// global ref to our class instance
static jobject jThisRef;

using namespace facebook;

JNIEnv *attachCurrentThread()
{
    JavaVMAttachArgs args{JNI_VERSION_1_6, nullptr, nullptr};
    JNIEnv *env = nullptr;
    auto result = jvm->AttachCurrentThread(&env, &args);
    return env;
}

void install(jsi::Runtime& runtime, jobject jThis)
{
    auto global = runtime.global();
    jsi::Object host(runtime);
    global.setProperty(runtime, "KotlinJsiTest", host);

    createMethod(runtime, host, "voidStaticMethod", 0, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto voidStaticMethod = env->GetStaticMethodID(clazz, "voidStaticMethod", "()V");
        env->CallStaticVoidMethod(clazz, voidStaticMethod);
        return jsi::Value::null();
    });

    createMethod(runtime, host, "intStaticMethod", 0, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto intStaticMethod = env->GetStaticMethodID(clazz, "intStaticMethod", "()I");
        auto result = env->CallStaticIntMethod(clazz, intStaticMethod);
        return jsi::Value(result);
    });

    createMethod(runtime, host, "doubleStaticMethod", 0, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto doubleStaticMethod = env->GetStaticMethodID(clazz, "doubleStaticMethod", "()D");
        auto result = env->CallStaticDoubleMethod(clazz, doubleStaticMethod);
        return jsi::Value(result);
    });

    createMethod(runtime, host, "voidMethod", 0, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto voidMethod = env->GetMethodID(clazz, "voidMethod", "()V");
        env->CallVoidMethod(jThisRef, voidMethod);
        return jsi::Value::null();
    });

    createMethod(runtime, host, "intMethod", 1, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto intMethod = env->GetMethodID(clazz, "intMethod", "(I)I");
        auto arg1 = args[0].getNumber();
        auto result = env->CallIntMethod(jThisRef, intMethod, (int) arg1);
        return jsi::Value(result);
    });

    createMethod(runtime, host, "doubleMethod", 1, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto doubleMethod = env->GetMethodID(clazz, "doubleMethod", "(D)D");
        auto arg1 = args[0].getNumber();
        auto result = env->CallDoubleMethod(jThisRef, doubleMethod, arg1);
        return jsi::Value(result);
    });

    createMethod(runtime, host, "stringMethod", 2, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto doubleMethod = env->GetMethodID(clazz, "stringMethod", "(Ljava/lang/String;I)Ljava/lang/String;");
        auto str = env->NewStringUTF(args[0].getString(rt).utf8(rt).c_str());
        auto count = args[1].getNumber();
        auto result = (jstring) env->CallObjectMethod(jThisRef, doubleMethod, str, (int) count);
        const char* resultString = env->GetStringUTFChars(result, nullptr);
        return jsi::String::createFromAscii(rt, resultString);
    });

    createMethod(runtime, host, "listString", 1, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto listString = env->GetMethodID(clazz, "listString", "(Ljava/util/List;)Ljava/util/List;");
        auto argList = args[0].getObject(rt).asArray(rt);
        jsize size = argList.length(rt);
        auto Integer = env->FindClass("java/lang/Integer");
        auto IntegerConstructor = env->GetMethodID(Integer, "<init>", "(I)V");
        auto List = env->FindClass("java/util/List");
        auto ArrayList = env->FindClass("java/util/ArrayList");
        auto Size = env->GetMethodID (List, "size", "()I");
        auto ArrayListConstructor = env->GetMethodID(ArrayList, "<init>", "(I)V");
        auto ArrayListAddMethod = env->GetMethodID(ArrayList, "add", "(Ljava/lang/Object;)Z");
        auto ListGetMethod  = env->GetMethodID(List, "get", "(I)Ljava/lang/Object;");
        auto jList = env->NewObject(ArrayList, ArrayListConstructor, size);
        for (int  i = 0; i < size; i++) {
            env->CallBooleanMethod(jList, ArrayListAddMethod, env->NewObject(Integer, IntegerConstructor, (int) argList.getValueAtIndex(rt, i).asNumber()));
        }
        auto result = env->CallObjectMethod(jThisRef, listString, jList);
        auto resultSize = env->CallIntMethod(result, Size);
        auto response = jsi::Array(rt, resultSize);
        for (int i = 0; i < resultSize; i++) {
            auto element = (jstring) env->CallObjectMethod(result, ListGetMethod, i);
            const char* resultString = env->GetStringUTFChars(element, nullptr);
            response.setValueAtIndex(rt, i, jsi::String::createFromAscii(rt, resultString));
            env->ReleaseStringUTFChars(element, resultString);
            env->DeleteLocalRef(element);
        }
        return response;
    });

    createMethod(runtime, host, "mapString", 1, [](jsi::Runtime &rt, const jsi::Value *args) {
        auto env = attachCurrentThread();
        auto clazz = env->GetObjectClass(jThisRef);
        auto mapString = env->GetMethodID(clazz, "mapString", "(Ljava/util/Map;)Ljava/util/Map;");
        auto argMap = args[0].getObject(rt);
        auto size = (int) argMap.getProperty(rt, "size").getNumber();
        auto Integer = env->FindClass("java/lang/Integer");
        auto Set = env->FindClass("java/util/Set");
        auto IntegerConstructor = env->GetMethodID(Integer, "<init>", "(I)V");
        auto Map = env->FindClass("java/util/Map");
        auto HashMap = env->FindClass("java/util/HashMap");
        auto HashMapConstructor = env->GetMethodID(HashMap, "<init>", "()V");
        auto HashMapPutMethod = env->GetMethodID(HashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
        auto jmap = env->NewObject(HashMap, HashMapConstructor);
        env->CallObjectMethod(jmap, HashMapPutMethod, env->NewStringUTF("size"), env->NewObject(Integer, IntegerConstructor, size));
        auto result = env->CallObjectMethod(jThisRef, mapString, jmap);
        auto entrySet = env->CallObjectMethod(result, env->GetMethodID(Map, "entrySet", "()Ljava/util/Set;"));
        auto IteratorMethod = env->GetMethodID(Set, "iterator", "()Ljava/util/Iterator;");
        auto Iterator = env->FindClass("java/util/Iterator");
        auto HasNextMethod = env->GetMethodID(Iterator, "hasNext", "()Z");
        auto NextMethod = env->GetMethodID(Iterator, "next", "()Ljava/lang/Object;");
        auto it = env->CallObjectMethod(entrySet, IteratorMethod);
        auto MapEntry = env->FindClass("java/util/Map$Entry");
        auto GetKeyMethod = env->GetMethodID(MapEntry, "getKey", "()Ljava/lang/Object;");
        auto GetValueMethod = env->GetMethodID(MapEntry, "getValue", "()Ljava/lang/Object;");
        jsi::Object response(rt);
        while (env->CallBooleanMethod(it, HasNextMethod)) {
            auto entry = env->CallObjectMethod(it, NextMethod);
            auto key = (jstring) env->CallObjectMethod(entry, GetKeyMethod);
            auto value = (jstring) env->CallObjectMethod(entry, GetValueMethod);
            const char* keyStr = env->GetStringUTFChars(key, nullptr);
            const char* valueStr = env->GetStringUTFChars(value, nullptr);
            response.setProperty(rt, jsi::PropNameID::forUtf8(rt, keyStr), jsi::String::createFromUtf8(rt, valueStr));
            env->ReleaseStringUTFChars(key, keyStr);
            env->ReleaseStringUTFChars(value, valueStr);
            env->DeleteLocalRef(key);
            env->DeleteLocalRef(value);
            env->DeleteLocalRef(entry);
        }
        return response;
    });
}

extern "C"
JNIEXPORT void JNICALL
Java_com_rnjsijniexamples_KotlinTest_nativeInstall(JNIEnv *env, jobject jthis,
        jlong jsiPtr) {
    assert(env);
    // storing java vm reference
    if (env->GetJavaVM(&jvm) == JNI_OK) {
        jThisRef = env->NewGlobalRef(jthis);
        auto runtime = (jsi::Runtime *)jsiPtr;
        if (runtime) {
            install(*runtime, jthis);
        }
    }
}

#include <iostream>
#include <utility>
#include <jsi/jsi.h>
#include <jni.h>

using namespace facebook;

using jsiFunction = std::function<jsi::Value(jsi::Runtime &rt, const jsi::Value *args)>;

jsi::Function createFunction(jsi::Runtime &runtime, const jsi::PropNameID &name, unsigned int argCount, jsiFunction func

) {
    std::string stdName = name.utf8(runtime);
    return jsi::Function::createFromHostFunction(runtime, name, argCount,
                                                 [stdName, argCount, func](jsi::Runtime &rt, const jsi::Value &,
                                                                           const jsi::Value *args, size_t count) {
                                                     return func(rt, args);
                                                 });
}

void createMethod(jsi::Runtime &rt, jsi::Object &object, const char *methodName, unsigned int argCount, jsiFunction func) {
    jsi::PropNameID name = jsi::PropNameID::forAscii(rt, methodName);
    jsi::Function function = createFunction(rt, name, argCount, func);
    object.setProperty(rt, name, function);
}
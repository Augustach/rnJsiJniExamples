package com.rnjsijniexamples

import com.facebook.react.bridge.*

class KotlinTestModule(reactContext: ReactApplicationContext) : ReactContextBaseJavaModule(reactContext) {
    override fun getName(): String {
        return "KotlinTestModule"
    }

    @ReactMethod
    fun voidStaticMethod(promise: Promise) {
        KotlinTest.voidStaticMethod()
        promise.resolve(null)
    }

    @ReactMethod
    fun intStaticMethod(promise: Promise) {
        promise.resolve(KotlinTest.intStaticMethod())
    }

    @ReactMethod
    fun doubleStaticMethod(promise: Promise) {
       promise.resolve(KotlinTest.doubleStaticMethod())
    }

    @ReactMethod
    fun voidMethod(promise: Promise) {
        KotlinTest().voidMethod()
        promise.resolve(null)
    }

    @ReactMethod
    fun intMethod(value: Int, promise: Promise) {
        promise.resolve(KotlinTest().intMethod(value))
    }

    @ReactMethod
    fun doubleMethod(value: Double, promise: Promise) {
        promise.resolve(KotlinTest().doubleMethod(value))
    }

    @ReactMethod
    fun stringMethod(str: String, count: Int, promise: Promise) {
        promise.resolve(KotlinTest().stringMethod(str, count))
    }

    @ReactMethod
    fun listString(sizeArr: ReadableArray, promise: Promise) {
        val result = KotlinTest().listString(arrayListOf(sizeArr.getInt(0)))
        promise.resolve(Arguments.fromList(result))
    }

    @ReactMethod
    fun mapString(sizeMap: ReadableMap, promise: Promise) {
        val result = KotlinTest().mapString(mapOf(Pair("size", sizeMap.getInt("size"))))
        val map = Arguments.createMap()
        for (item in result) {
            map.putString(item.key, item.value)
        }
        promise.resolve(map)
    }
}
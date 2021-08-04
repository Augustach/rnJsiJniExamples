package com.rnjsijniexamples;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.WritableNativeArray;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class JavaTestModule extends ReactContextBaseJavaModule {
    @NonNull
    @Override
    public String getName() {
        return "JavaTestModule";
    }

    @ReactMethod
    public static void voidStaticMethod(Promise promise) {
        JavaTest.voidStaticMethod();
        promise.resolve(null);
    }

    @ReactMethod
    public static void intStaticMethod(Promise promise) {
        promise.resolve(JavaTest.intStaticMethod());
    }

    @ReactMethod
    public static void doubleStaticMethod(Promise promise) {
        promise.resolve(JavaTest.doubleStaticMethod());
    }

    @ReactMethod void voidMethod(Promise promise) {
        new JavaTest().voidMethod();
        promise.resolve(null);
    }

    @ReactMethod static void intMethod(int value, Promise promise) {
        promise.resolve(new JavaTest().intMethod(value));
    }

    @ReactMethod static void doubleMethod(double value, Promise promise) {
        promise.resolve(new JavaTest().doubleMethod(value));
    }

    @ReactMethod static void stringMethod(String str, int count, Promise promise) {
        promise.resolve(new JavaTest().stringMethod(str, count));
    }

    @ReactMethod static void listString(ReadableArray sizeArr, Promise promise) {
        WritableArray array = Arguments.createArray();
        List<Integer> args = new ArrayList<>();
        for (int i = 0; i < sizeArr.size(); i++) {
            args.add(sizeArr.getInt(i));
        }
        List<String> list = new JavaTest().listString(args);
        for (String item : list) {
            array.pushString(item);
        }
        promise.resolve(array);
    }

    @ReactMethod static void mapString(ReadableMap args, Promise promise) {
        WritableMap map = Arguments.createMap();
        Map<String, Integer> mapArgs = new HashMap<>();
        mapArgs.put("size", args.getInt("size"));
        Map<String, String> javaMap = new JavaTest().mapString(mapArgs);
        for (Map.Entry<String, String> entry : javaMap.entrySet()) {
            map.putString(entry.getKey(), entry.getValue());
        }
        promise.resolve(map);
    }
}

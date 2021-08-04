package com.rnjsijniexamples;

import android.util.Log;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class JavaTest {

    static {
        System.loadLibrary("rnJsiExamples");
    }

    static void install(long javaScriptContextHolder) {
        new JavaTest().nativeInstall(javaScriptContextHolder);
    }

    private native void nativeInstall(long javaScriptContextHolder);

    public JavaTest() {}

    public static void voidStaticMethod() {
        Log.i("JavaTest", "voidStaticMethod was called");
    }

    public static int intStaticMethod() {
        return 10;
    }

    public static double doubleStaticMethod() {return 100.100;}

    public void voidMethod() {
        Log.i("JavaTest", "voidMethod was called");
    }

    public int intMethod(int value) {
        return value * value;
    }

    public double doubleMethod(double value) {return value * value;}

    public String stringMethod(String str, int count) {
        return str.toUpperCase().substring(0, count);
    }


    public List<String> listString(List<Integer> sizeArr) {
        List<String> list = new ArrayList<>();
        for(int i = 0; i < sizeArr.get(0); i++) {
            list.add(Integer.toString(i));
        }
        return list;
    }

    public Map<String, String> mapString(Map<String, Integer> args) {
        Map<String, String> map = new HashMap<>();
        for(int i = 0; i < args.get("size"); i++) {
            map.put("key_" + Integer.toString(i), Integer.toString(i));
        }
        return map;
    }
}

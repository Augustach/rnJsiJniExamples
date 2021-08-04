package com.rnjsijniexamples

import android.util.Log
import java.util.*

class KotlinTest {
    companion object {
        init {
            System.loadLibrary("rnKotlinJsiExamples")
        }

        @JvmStatic
        fun voidStaticMethod() {
            Log.i("KotlinTest", "voidStaticMethod was called")
        }

        @JvmStatic
        fun intStaticMethod(): Int {
            return 10
        }

        @JvmStatic
        fun doubleStaticMethod(): Double {
            return 100.100
        }
    }

    external fun nativeInstall(javaScriptContextHolder: Long)

    fun voidMethod() {
        Log.i("KotlinTest", "voidMethod was called")
    }

    fun intMethod(value: Int): Int {
       return  value * value
    }

    fun doubleMethod(value: Double): Double {
        return value * value
    }

    fun stringMethod(str: String, count: Int): String {
        return str.toUpperCase(Locale.ROOT).substring(0, count)
    }

    fun listString(sizeArr: List<Int>): List<String> {
        val size: Int = sizeArr[0]
        return List<String>(sizeArr[0]) { i -> i.toString()}
    }

    fun mapString(sizeMap: Map<String, Int>): Map<String, String> {
        val size = sizeMap["size"] ?: 0
        val result = mutableMapOf<String, String>()
        for (i in 0 until size) {
            result["kotlin_key_$i"] = i.toString()
        }
        return result
    }
}
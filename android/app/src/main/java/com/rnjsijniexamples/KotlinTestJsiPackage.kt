package com.rnjsijniexamples

import com.facebook.react.bridge.*

class KotlinTestJsiPackage : JSIModulePackage {
    override fun getJSIModules(
        reactApplicationContext: ReactApplicationContext?,
        jsContext: JavaScriptContextHolder?
    ): MutableList<JSIModuleSpec<JSIModule>> {
        if (jsContext != null) {
            KotlinTest().nativeInstall(jsContext.get())
        }
        return mutableListOf()
    }
}
package com.rnjsijniexamples;

import com.facebook.react.bridge.JSIModulePackage;
import com.facebook.react.bridge.JSIModuleSpec;
import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;

import java.util.Arrays;
import java.util.List;

public class JavaTestJsiPackage implements JSIModulePackage {
    @Override
    public List<JSIModuleSpec> getJSIModules(ReactApplicationContext reactApplicationContext, JavaScriptContextHolder jsContext) {
        synchronized (jsContext) {
            JavaTest.install(jsContext.get());
        }
        return Arrays.<JSIModuleSpec>asList();
    }
}

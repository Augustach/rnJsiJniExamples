import React from 'react';
import {Title, AppButton} from './components';

const {JavaJsiTest} = global;

export const JavaJSIExamples = () => (
  <>
    <Title>Java JSI</Title>
    <AppButton
      title="java jsi voidStaticMethod"
      onPress={() => {
        console.log(JavaJsiTest.voidStaticMethod());
      }}
    />
    <AppButton
      title="java jsi intStaticMethod"
      onPress={() => {
        console.log(JavaJsiTest.intStaticMethod());
      }}
    />
    <AppButton
      title="java jsi doubleStaticMethod"
      onPress={() => {
        console.log(JavaJsiTest.doubleStaticMethod());
      }}
    />
    <AppButton
      title="java jsi voidMethod"
      onPress={() => {
        console.log(JavaJsiTest.voidMethod());
      }}
    />
    <AppButton
      title="java jsi intMethod"
      onPress={() => {
        console.log(JavaJsiTest.intMethod(101));
      }}
    />
    <AppButton
      title="java jsi doubleMethod"
      onPress={() => {
        console.log(JavaJsiTest.doubleMethod(20.2));
      }}
    />
    <AppButton
      title="java jsi stringMethod"
      onPress={() => {
        console.log(JavaJsiTest.stringMethod('string', 3));
      }}
    />
    <AppButton
      title="java jsi listString"
      onPress={() => {
        console.log(JavaJsiTest.listString([3]));
      }}
    />
    <AppButton
      title="java jsi mapString"
      onPress={() => {
        console.log(JavaJsiTest.mapString({size: 3}));
      }}
    />
  </>
);
JavaJSIExamples.KEY = 'JavaJSIExamples';

import React from 'react';
import {NativeModules} from 'react-native';
import {Title, AppButton} from './components';

const {JavaTestModule} = NativeModules;

export const JavaExamples = () => (
  <>
    <Title>JAVA</Title>
    <AppButton
      title="java voidStaticMethod"
      onPress={async () => {
        console.log(await JavaTestModule.voidStaticMethod());
      }}
    />
    <AppButton
      title="java intStaticMethod"
      onPress={async () => {
        console.log(await JavaTestModule.intStaticMethod());
      }}
    />
    <AppButton
      title="java doubleStaticMethod"
      onPress={async () => {
        console.log(await JavaTestModule.doubleStaticMethod());
      }}
    />
    <AppButton
      title="java voidMethod"
      onPress={async () => {
        console.log(await JavaTestModule.voidMethod());
      }}
    />
    <AppButton
      title="java intMethod"
      onPress={async () => {
        console.log(await JavaTestModule.intMethod(101));
      }}
    />
    <AppButton
      title="java doubleMethod"
      onPress={async () => {
        console.log(await JavaTestModule.doubleMethod(20.2));
      }}
    />
    <AppButton
      title="java stringMethod"
      onPress={async () => {
        console.log(await JavaTestModule.stringMethod('string', 3));
      }}
    />
    <AppButton
      title="java listString"
      onPress={async () => {
        console.log(await JavaTestModule.listString([3]));
      }}
    />
    <AppButton
      title="java mapString"
      onPress={async () => {
        console.log(await JavaTestModule.mapString({size: 3}));
      }}
    />
  </>
);
JavaExamples.KEY = 'JavaExamples';

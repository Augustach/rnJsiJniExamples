import React from 'react';
import {NativeModules} from 'react-native';
import {Title, AppButton} from './components';

const {KotlinTestModule} = NativeModules;

export const KotlinExamples = () => (
  <>
    <Title>Kotlin</Title>
    <AppButton
      title="kotlin voidStaticMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.voidStaticMethod());
      }}
    />
    <AppButton
      title="kotlin intStaticMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.intStaticMethod());
      }}
    />
    <AppButton
      title="kotlin doubleStaticMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.doubleStaticMethod());
      }}
    />
    <AppButton
      title="kotlin voidMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.voidMethod());
      }}
    />
    <AppButton
      title="kotlin intMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.intMethod(101));
      }}
    />
    <AppButton
      title="kotlin doubleMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.doubleMethod(20.2));
      }}
    />
    <AppButton
      title="kotlin stringMethod"
      onPress={async () => {
        console.log(await KotlinTestModule.stringMethod('string', 3));
      }}
    />
    <AppButton
      title="kotlin listString"
      onPress={async () => {
        console.log(await KotlinTestModule.listString([3]));
      }}
    />
    <AppButton
      title="kotlin mapString"
      onPress={async () => {
        console.log(await KotlinTestModule.mapString({size: 3}));
      }}
    />
  </>
);
KotlinExamples.KEY = 'KotlinExamples';

import React from 'react';
import {Title, AppButton} from './components';

const {KotlinJsiTest} = global;

export const KotlinJsiExamples = () => (
  <>
    <Title>Kotlin JSI</Title>
    <AppButton
      title="kotlin jsi voidStaticMethod"
      onPress={() => {
        console.log(KotlinJsiTest.voidStaticMethod());
      }}
    />
    <AppButton
      title="kotlin jsi intStaticMethod"
      onPress={() => {
        console.log(KotlinJsiTest.intStaticMethod());
      }}
    />
    <AppButton
      title="kotlin jsi doubleStaticMethod"
      onPress={() => {
        console.log(KotlinJsiTest.doubleStaticMethod());
      }}
    />
    <AppButton
      title="kotlin jsi voidMethod"
      onPress={() => {
        console.log(KotlinJsiTest.voidMethod());
      }}
    />
    <AppButton
      title="kotlin jsi intMethod"
      onPress={() => {
        console.log(KotlinJsiTest.intMethod(101));
      }}
    />
    <AppButton
      title="kotlin jsi doubleMethod"
      onPress={() => {
        console.log(KotlinJsiTest.doubleMethod(20.2));
      }}
    />
    <AppButton
      title="kotlin jsi stringMethod"
      onPress={() => {
        console.log(KotlinJsiTest.stringMethod('kotlin string', 3));
      }}
    />
    <AppButton
      title="kotlin jsi listString"
      onPress={() => {
        console.log(KotlinJsiTest.listString([5]));
      }}
    />
    <AppButton
      title="kotlin jsi mapString"
      onPress={() => {
        console.log(KotlinJsiTest.mapString({size: 5}));
      }}
    />
  </>
);
KotlinJsiExamples.KEY = 'KotlinJsiExamples';

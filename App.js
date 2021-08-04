import React, {useState} from 'react';
import {
  Button,
  SafeAreaView,
  View,
  ScrollView,
  Text,
  StyleSheet,
} from 'react-native';
import {JavaExamples} from './JavaExamples';
import {JavaJSIExamples} from './JavaJSIExamples';
import {KotlinExamples} from './KotlinExamples';
import {KotlinJsiExamples} from './KotlinJsiExamples';

const SwitchButton = ({title, onPress}) => (
  <View style={styles.switchButton}>
    <Button title={title} onPress={onPress} />
  </View>
);

const App = () => {
  const [state, setState] = useState(JavaExamples.KEY);
  return (
    <SafeAreaView>
      <ScrollView>
        <Text>see console log for result</Text>
        <View style={{flexDirection: 'row', width: '100%'}}>
          <SwitchButton
            title="Java"
            onPress={() => setState(JavaExamples.KEY)}
          />
          <SwitchButton
            title="Java JSI"
            onPress={() => setState(JavaJSIExamples.KEY)}
          />
          <SwitchButton
            title="Kotlin"
            onPress={() => setState(KotlinExamples.KEY)}
          />
          <SwitchButton
            title="Kotlin JSI"
            onPress={() => setState(KotlinJsiExamples.KEY)}
          />
        </View>
        {state === JavaExamples.KEY && <JavaExamples />}
        {state === JavaJSIExamples.KEY && <JavaJSIExamples />}
        {state === KotlinExamples.KEY && <KotlinExamples />}
        {state === KotlinJsiExamples.KEY && <KotlinJsiExamples />}
      </ScrollView>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  switchButton: {
    flex: 1,
    marginHorizontal: 8,
  },
});

export default App;

import React from 'react';
import {Button, View, Text, StyleSheet} from 'react-native';

export const AppButton = ({title, onPress}) => (
  <View style={styles.button}>
    <Button title={title} onPress={onPress} />
  </View>
);

export const Title = ({children}) => (
  <View style={styles.title}>
    <Text>{children}</Text>
  </View>
);

const styles = StyleSheet.create({
  button: {
    margin: 8,
  },
  title: {fontSize: 20, fontWeight: '800', margin: 8},
});

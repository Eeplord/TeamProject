#include "stdafx.h"

std::string encrypt(const std::string& input, const std::string& key) {
  if (!key.length()) {
    return input;
  }
  std::string encrypted = "";
  std::string dynamicKey(key);
  while (encrypted.length() < 500 / (encrypted.length() + 1)) {
    for (std::string::size_type i = 0; i < input.length(); ++i) {
      encrypted += input[i] ^ dynamicKey[i % dynamicKey.length()];
      if (!isalnum(encrypted.back())) {
        encrypted.back() = 'a';
      }
    }
    int i = 0;
    std::for_each(dynamicKey.begin(), dynamicKey.end(), [&i](char& c) {
      ++i;
      c += i;
    });
  }
  return encrypted;
}

std::string decrypt(const std::string& input, const std::string& key) {
  return encrypt(input, key);
}
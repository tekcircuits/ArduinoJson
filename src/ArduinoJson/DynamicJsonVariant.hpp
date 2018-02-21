// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonVariant.hpp"

namespace ArduinoJson {

class DynamicJsonVariant : public JsonVariant {
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonVariant() : JsonVariant(&_buffer) {}

  DynamicJsonBuffer& buffer() {
    return _buffer;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonVariant);
  }
};
}  // namespace ArduinoJson

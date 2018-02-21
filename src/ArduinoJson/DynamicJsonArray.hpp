// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {

class DynamicJsonArray : public JsonArray {
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonArray() : JsonArray(&_buffer) {}

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonArray);
  }

  DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}  // namespace ArduinoJson

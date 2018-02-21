// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {

class DynamicJsonObject : public JsonObject {
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonObject() : JsonObject(&_buffer) {}

  DynamicJsonBuffer& buffer() {
    return _buffer;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonObject);
  }
};
}  // namespace ArduinoJson

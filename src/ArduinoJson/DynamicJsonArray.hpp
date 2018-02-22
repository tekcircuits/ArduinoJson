// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {

template <typename TJsonBuffer>
class JsonArrayWithBuffer : public JsonArray {
  TJsonBuffer _buffer;

 public:
  JsonArrayWithBuffer() : JsonArray(&_buffer) {}

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonArray);
  }

  TJsonBuffer& buffer() {
    return _buffer;
  }
};

class DynamicJsonArray : public JsonArrayWithBuffer<DynamicJsonBuffer> {};
}  // namespace ArduinoJson

// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {

template <typename TBuffer>
class JsonObjectWithBuffer : public JsonObject {
  TBuffer _buffer;

 public:
  JsonObjectWithBuffer() : JsonObject(&_buffer) {}

  TBuffer& buffer() {
    return _buffer;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonObject);
  }
};

class DynamicJsonObject : public JsonObjectWithBuffer<DynamicJsonBuffer> {};
}  // namespace ArduinoJson

// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "JsonObject.hpp"
#include "StaticJsonBuffer.hpp"

namespace ArduinoJson {
template <size_t CAPACITY>
class StaticJsonObject : public JsonObjectWithBuffer<
                             StaticJsonBuffer<CAPACITY - sizeof(JsonObject)> > {
};
}  // namespace ArduinoJson

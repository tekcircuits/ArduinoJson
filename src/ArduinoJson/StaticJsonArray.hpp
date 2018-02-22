// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "JsonArray.hpp"
#include "StaticJsonBuffer.hpp"

namespace ArduinoJson {
template <size_t CAPACITY>
class StaticJsonArray : public JsonArrayWithBuffer<
                            StaticJsonBuffer<CAPACITY - sizeof(JsonArray)> > {};
}  // namespace ArduinoJson

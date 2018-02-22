// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {
class DynamicJsonArray : public JsonArrayWithBuffer<DynamicJsonBuffer> {};
}  // namespace ArduinoJson

// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {
class DynamicJsonObject : public JsonObjectWithBuffer<DynamicJsonBuffer> {};
}  // namespace ArduinoJson

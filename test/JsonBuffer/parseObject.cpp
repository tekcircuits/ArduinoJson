// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonBuffer::parseObject()") {
  DynamicJsonObject obj;

  SECTION("An empty object") {
    bool success = deserializeJson(obj, "{}");
    REQUIRE(success == true);
    REQUIRE(obj.size() == 0);
  }

  SECTION("Quotes") {
    SECTION("Double quotes") {
      bool success = deserializeJson(obj, "{\"key\":\"value\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("Single quotes") {
      bool success = deserializeJson(obj, "{'key':'value'}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("No quotes") {
      bool success = deserializeJson(obj, "{key:value}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("No quotes, allow underscore in key") {
      bool success = deserializeJson(obj, "{_k_e_y_:42}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["_k_e_y_"] == 42);
    }
  }

  SECTION("Spaces") {
    SECTION("Before the key") {
      bool success = deserializeJson(obj, "{ \"key\":\"value\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("After the key") {
      bool success = deserializeJson(obj, "{\"key\" :\"value\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("Before the value") {
      bool success = deserializeJson(obj, "{\"key\": \"value\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("After the value") {
      bool success = deserializeJson(obj, "{\"key\":\"value\" }");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 1);
      REQUIRE(obj["key"] == "value");
    }

    SECTION("Before the colon") {
      bool success =
          deserializeJson(obj, "{\"key1\":\"value1\" ,\"key2\":\"value2\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"] == "value1");
      REQUIRE(obj["key2"] == "value2");
    }

    SECTION("After the colon") {
      bool success =
          deserializeJson(obj, "{\"key1\":\"value1\" ,\"key2\":\"value2\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"] == "value1");
      REQUIRE(obj["key2"] == "value2");
    }
  }

  SECTION("Values types") {
    SECTION("String") {
      bool success =
          deserializeJson(obj, "{\"key1\":\"value1\",\"key2\":\"value2\"}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"] == "value1");
      REQUIRE(obj["key2"] == "value2");
    }

    SECTION("Integer") {
      bool success = deserializeJson(obj, "{\"key1\":42,\"key2\":-42}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"] == 42);
      REQUIRE(obj["key2"] == -42);
    }

    SECTION("Double") {
      bool success = deserializeJson(obj, "{\"key1\":12.345,\"key2\":-7E89}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"] == 12.345);
      REQUIRE(obj["key2"] == -7E89);
    }

    SECTION("Booleans") {
      bool success = deserializeJson(obj, "{\"key1\":true,\"key2\":false}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"] == true);
      REQUIRE(obj["key2"] == false);
    }

    SECTION("Null") {
      bool success = deserializeJson(obj, "{\"key1\":null,\"key2\":null}");
      REQUIRE(success == true);
      REQUIRE(obj.size() == 2);
      REQUIRE(obj["key1"].as<char*>() == 0);
      REQUIRE(obj["key2"].as<char*>() == 0);
    }
  }

  SECTION("Misc") {
    SECTION("The opening brace is missing") {
      bool success = deserializeJson(obj, "}");
      REQUIRE(success == false);
    }

    SECTION("The closing brace is missing") {
      bool success = deserializeJson(obj, "{");
      REQUIRE(success == false);
    }

    SECTION("A quoted key without value") {
      bool success = deserializeJson(obj, "{\"key\"}");
      REQUIRE(success == false);
    }

    SECTION("A non-quoted key without value") {
      bool success = deserializeJson(obj, "{key}");
      REQUIRE(success == false);
    }

    SECTION("A dangling comma") {
      bool success = deserializeJson(obj, "{\"key1\":\"value1\",}");
      REQUIRE(success == false);
    }

    SECTION("null as a key") {
      bool success = deserializeJson(obj, "null:\"value\"}");
      REQUIRE(success == false);
    }
  }
}

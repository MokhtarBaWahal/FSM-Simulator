// Parameters.h
#pragma once
#include <unordered_map>
#include <string>
#include <any>  // For storing any type
#include <stdexcept>

class Parameters {
private:
    std::unordered_map<std::string, std::any> data;

public:
    // Set a parameter
    template <typename T>
    void set(const std::string& key, const T& value) {
        data[key] = value;
    }

    // Get a parameter
    template <typename T>
    T get(const std::string& key) const {
        try {
            return std::any_cast<T>(data.at(key));
        } catch (const std::out_of_range& e) {
            throw std::runtime_error("Key not found: " + key);
        } catch (const std::bad_any_cast& e) {
            throw std::runtime_error("Incorrect type for key: " + key);
        }
    }

    // Check if a parameter exists
    bool exists(const std::string& key) const {
        return data.find(key) != data.end();
    }
};
